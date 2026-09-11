"""Put the supplied 16x16 atlas on integer cell pitches without resampling."""
from pathlib import Path
import hashlib
import json
import sys

from PIL import Image

HERE = Path(__file__).resolve().parent
PROJECT = HERE.parents[2]
EDITOR = PROJECT.parent / 'agon-utils/examples/font_editor/src/python'
sys.path.insert(0, str(EDITOR))
from config_manager import load_font_metadata_from_xml, save_font_metadata_to_xml
from agon_font import read_png_font


def main():
    source = HERE / 'ArtDeco_Concept_02_source.png'
    destination = HERE / 'ArtDeco_Concept_02_79x79.png'
    if destination.exists() or Path(str(destination) + '.xml').exists():
        raise FileExistsError('Keep edited assets; remove derived outputs explicitly to rebuild')
    original = Image.open(source).convert('RGB')
    if original.size != (1254, 1254):
        raise ValueError('Expected the supplied 1254x1254 candidate')
    # Round boundaries to the nearest source pixel, then add at most one pixel
    # of black padding per cell. Every original pixel appears exactly once.
    edges = [(index * 1254 + 8) // 16 for index in range(17)]
    prepared = Image.new('RGB', (1264, 1264), 'black')
    reconstructed = Image.new('RGB', original.size)
    for row in range(16):
        for column in range(16):
            box = (edges[column], edges[row], edges[column+1], edges[row+1])
            cell = original.crop(box)
            x, y = column * 79, row * 79
            prepared.paste(cell, (x, y))
            reconstructed.paste(prepared.crop((x, y, x+cell.width, y+cell.height)), box[:2])
    assert reconstructed.tobytes() == original.tobytes()
    prepared.save(destination)
    config = {
        'original_font_path': str(destination),
        'font_name': 'ArtDeco', 'font_variant': 'Concept_02', 'point_size': 79,
        'font_width': 79, 'font_height': 79,
        'font_width_mod': 79, 'font_height_mod': 79,
        'offset_left': 0, 'offset_top': 0, 'offset_width': 0, 'offset_height': 0,
        'scale_width': 0, 'scale_height': 0,
        'raster_type': 'grayscale', 'threshold': 128, 'palette': 'Agon64',
        'fg_color': '255, 255, 255, 255', 'bg_color': '0, 0, 0, 255',
        'ascii_start': 0, 'ascii_end': 255, 'chars_per_row': 16,
    }
    metadata = str(destination) + '.xml'
    save_font_metadata_to_xml(config, metadata, bitmap_config=config)
    loaded = load_font_metadata_from_xml(metadata, bitmap=True)
    loaded, atlas = read_png_font(str(destination), loaded)
    assert (loaded['font_width'], loaded['font_height']) == (79, 79)
    assert atlas.convert('RGB').tobytes() == prepared.tobytes()
    sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
    report = {
        'name': 'ArtDeco Concept 02',
        'supplied_path': 'docs/tasks/SKIN-013/ea318cc9-8eaf-4fc1-83d0-20f5c8143afa.png',
        'source': source.name, 'source_sha256': sha(source),
        'editor_image': destination.name, 'editor_image_sha256': sha(destination),
        'source_size': [1254, 1254], 'editor_size': [1264, 1264],
        'grid': [16, 16], 'cell_size': [79, 79], 'source_boundaries': edges,
        'resampling': False, 'original_pixels_preserved': True,
        'canonical_png_reader': 'PASS: exact pixels and cell geometry',
    }
    (HERE / 'provenance.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
