# lines_rgba2_writer.py

output_file = "lines.rgba2"

# Define the pattern (8 bytes)
pattern = bytes([243, 255, 243, 255, 243, 255, 243, 255])

# Repeat the pattern 8 times
data = pattern * 8  # (8 bytes * 8 repetitions = 64 bytes)

# Write to file
with open(output_file, "wb") as f:
    f.write(data)

print(f"Wrote {len(data)} bytes to {output_file}")
