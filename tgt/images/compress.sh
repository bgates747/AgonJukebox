#!/bin/bash

# Input file
INPUT="frame_01200.rgba2"

# Check if input file exists
if [[ ! -f "$INPUT" ]]; then
    echo "Error: File '$INPUT' not found."
    exit 1
fi

# Run SZIP compression
echo "Running szip..."
szip -b41 "$INPUT" "$INPUT.szip"
if [[ $? -ne 0 ]]; then
    echo "Error: szip compression failed."
    exit 1
fi
echo "szip completed: $INPUT.szip"

# Run RLE compression
echo "Running rlecompress..."
rlecompress "$INPUT" "$INPUT.rle2"
if [[ $? -ne 0 ]]; then
    echo "Error: rlecompress failed."
    exit 1
fi
echo "rlecompress completed: $INPUT.rle2"

# Run TVC compression
echo "Running tvcompress..."
tvcompress "$INPUT" "$INPUT.tvc"
if [[ $? -ne 0 ]]; then
    echo "Error: tvcompress failed."
    exit 1
fi
echo "tvcompress completed: $INPUT.tvc"

echo "All compressions completed successfully."
