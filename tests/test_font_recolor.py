"""Known-pixel and file-boundary checks for the antialiased font colorizer."""
from pathlib import Path
import importlib.util
import tempfile
import unittest
import xml.etree.ElementTree as ET

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('recolor_font', ROOT / 'src/fonts/recolor_font.py')
recolor = importlib.util.module_from_spec(spec)
spec.loader.exec_module(recolor)


class FontColorTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix='test-font-color-')
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def source(self, pixels, name='mask.png'):
        path = self.root / name
        Image.fromarray(np.asarray(pixels, dtype=np.uint8)).save(path)
        return path

    def test_antialiased_native_sheet_endpoints_placement_and_metadata(self):
        mask = np.zeros((192, 96), dtype=np.uint8)
        # Two widely separated character slots expose atlas/cell reordering.
        for code in (65, 255):
            x, y = code % 16 * 6, code // 16 * 12
            mask[y:y + 12, x:x + 6] = [0, 85, 170, 255, 85, 0]
        source = self.source(mask)
        original = source.read_bytes()
        output = self.root / 'result'
        report = recolor.build(source, output)
        expected_colors = {
            'normal': [(0, 0, 0), (85, 85, 85), (170, 170, 85), (255, 255, 170)],
            'selected': [(255, 170, 85), (170, 85, 85), (85, 85, 0), (0, 0, 0)],
        }
        for variant in report['variants']:
            result = np.asarray(Image.open(output / variant['png']).convert('RGBA'))
            self.assertEqual(result.shape, (192, 96, 4))
            self.assertTrue(np.all(result[:, :, 3] == 255))
            for level, color in zip((0, 85, 170, 255), expected_colors[variant['name']]):
                self.assertTrue(np.all(result[:, :, :3][mask == level] == color))
            cfg = {n.get('name'): n.get('value') for n in ET.parse(output / variant['metadata']).getroot()}
            self.assertEqual((cfg['font_width'], cfg['font_height'], cfg['chars_per_row']), ('6', '12', '16'))
            self.assertEqual((cfg['ascii_start'], cfg['ascii_end'], cfg['raster_type']), ('0', '255', 'palette'))
            self.assertEqual(Path(cfg['original_font_path']), output / variant['png'])
            self.assertEqual(cfg['bg_color'], ', '.join(map(str, (*variant['background'], 255))))
        self.assertTrue(report['input_has_intermediate_coverage'])
        self.assertEqual(source.read_bytes(), original)
        self.assertEqual(len(list(output.iterdir())), 5)

    def test_alpha_mask_and_gray_alpha_are_explicit_and_opaque(self):
        pixels = np.zeros((12, 6, 4), dtype=np.uint8)
        pixels[0, :4] = [(255, 0, 0, 0), (0, 255, 0, 85), (0, 0, 255, 170), (255, 255, 0, 255)]
        source = self.source(pixels)
        with self.assertRaisesRegex(ValueError, 'grayscale pixels'):
            recolor.build(source, self.root / 'bad-gray', columns=1, rows=1)
        report = recolor.build(source, self.root / 'alpha', columns=1, rows=1, mask_channel='alpha')
        im = np.asarray(Image.open(self.root / 'alpha' / report['variants'][0]['png']).convert('RGBA'))
        self.assertEqual(im[0, :4].tolist(), [[0, 0, 0, 255], [85, 85, 85, 255],
                                             [170, 170, 85, 255], [255, 255, 170, 255]])
        pixels[0, 1] = [128, 128, 128, 128]
        pixels[0, 2:] = 0
        image = Image.fromarray(pixels)
        coverage = recolor.coverage_from_image(image)
        self.assertEqual(int(coverage[0, 1]), 16384)  # No premature 8-bit rounding.
        self.assertEqual(int(coverage[0, 0]), 0)  # Hidden red does not contaminate ink.
        inverted = recolor.coverage_from_image(image, invert=True)
        self.assertEqual(int(inverted[0, 1]), 127 * 128)

    def test_inputs_and_existing_outputs_are_protected(self):
        source = self.source(np.zeros((12, 6), dtype=np.uint8))
        with self.assertRaisesRegex(ValueError, 'expected'):
            recolor.build(source, self.root / 'wrong-grid')
        self.assertFalse((self.root / 'wrong-grid').exists())
        for variant in ('../oops=FFFFFF,000000', 'normal=FEFFFF,000000'):
            with self.assertRaises(ValueError):
                recolor.build(source, self.root / 'invalid', columns=1, rows=1, variant_specs=[variant])
        with self.assertRaisesRegex(ValueError, 'Duplicate'):
            recolor.variants_from_strings(['same=FFFFFF,000000', 'same=000000,FFFFFF'])
        existing = self.root / 'existing'
        existing.mkdir()
        sentinel = existing / 'keep.txt'
        sentinel.write_text('hand edits')
        with self.assertRaises(FileExistsError):
            recolor.build(source, existing, columns=1, rows=1)
        self.assertEqual(sentinel.read_text(), 'hand edits')
        self.assertEqual(list(existing.iterdir()), [sentinel])

    def test_repeatability_custom_pair_and_binary_source_reporting(self):
        mask = np.zeros((12, 6), dtype=np.uint8)
        mask[:, 2:4] = 255
        source = self.source(mask)
        reports = [recolor.build(source, self.root / name, columns=1, rows=1,
                   variant_specs=['inverse=#000000,#FFFFFF'], invert=True) for name in ('a', 'b')]
        for report in reports:
            self.assertFalse(report['input_has_intermediate_coverage'])
            self.assertEqual(report['variants'][0]['visible_colors'], 2)
        self.assertEqual(reports[0], reports[1])
        for filename in ('mask-inverse.png', 'colors.json'):
            self.assertEqual((self.root / 'a' / filename).read_bytes(), (self.root / 'b' / filename).read_bytes())
        im = np.asarray(Image.open(self.root / 'a/mask-inverse.png').convert('RGB'))
        self.assertTrue(np.all(im[mask == 0] == 0))
        self.assertTrue(np.all(im[mask == 255] == 255))


if __name__ == '__main__':
    unittest.main()
