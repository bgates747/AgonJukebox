"""Export the generated concept at native size using only RGB222 colors."""

from hashlib import sha256
from pathlib import Path
import json

from PIL import Image, __version__ as pillow_version


root = Path(__file__).resolve().parent
source = root / "art-deco-original.png"
target = root / "art-deco-512x384-agon64.png"
if target.exists():
    raise SystemExit(f"Refusing to overwrite {target}")

image = Image.open(source).convert("RGB").resize((512, 384), Image.Resampling.LANCZOS)
# Round each channel independently to its nearest RGB222 level. No dithering.
channel_lut = [((value + 42) // 85) * 85 for value in range(256)]
image = image.point(channel_lut * 3)
palette = [channel for r in (0, 85, 170, 255)
           for g in (0, 85, 170, 255)
           for b in (0, 85, 170, 255) for channel in (r, g, b)]
indices = bytes((r // 85) * 16 + (g // 85) * 4 + b // 85
                for r, g, b in image.get_flattened_data())
indexed = Image.frombytes("P", image.size, indices)
indexed.putpalette(palette)
indexed.save(target, optimize=True, bits=8)

# Check the saved artifact rather than just the in-memory conversion.
with Image.open(target) as saved:
    rgb = saved.convert("RGB")
    colors = set(rgb.get_flattened_data())
    off_palette = [color for color in colors
                   if any(channel not in (0, 85, 170, 255) for channel in color)]
    assert saved.size == (512, 384)
    assert saved.mode == "P"
    assert "transparency" not in saved.info
    assert len(colors) <= 64 and not off_palette
    assert rgb.tobytes() == image.tobytes()
    report = {
        "source": source.name,
        "source_sha256": sha256(source.read_bytes()).hexdigest(),
        "output": target.name,
        "output_sha256": sha256(target.read_bytes()).hexdigest(),
        "dimensions": list(saved.size),
        "mode": saved.mode,
        "unique_colors": len(colors),
        "allowed_channel_values": [0, 85, 170, 255],
        "off_palette_colors": len(off_palette),
        "opaque": True,
        "resampling": "LANCZOS",
        "quantization": "nearest RGB222 channel; no dithering",
        "pillow_version": pillow_version,
        "meets_requested_constraints": True,
    }
(root / "conversion.json").write_text(json.dumps(report, indent=2) + "\n")
print(json.dumps(report, indent=2))
