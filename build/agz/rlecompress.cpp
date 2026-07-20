// rlecompress.cpp
// Compile with: g++ -std=c++17 -O2 -o rlecompress rlecompress.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

// Encode a vector of 8-bit rgba2222 pixels using our RLE scheme.
std::vector<uint8_t> encodeRLE(const std::vector<uint8_t>& input) {
    std::vector<uint8_t> output;
    size_t i = 0;
    while (i < input.size()) {
        uint8_t pixel = input[i];
        // In our rgba2222, opaque (non-transparent) pixels have alpha bits 11,
        // and transparent pixels have alpha bits 00.
        bool transparent = ((pixel & 0xC0) == 0x00);
        uint8_t color = pixel & 0x3F; // 6-bit colour
        // Count how many identical pixels in a row, capping at 64.
        size_t count = 1;
        while (i + count < input.size() && input[i + count] == pixel && count < 64) {
            ++count;
        }
        
        if (transparent) {
            // Transparent pixel run.
            if (count == 1) {
                // Single transparent pixel is always encoded as 0x40.
                output.push_back(0x40);
            } else {
                // For a run, encode one byte with top bits 01 and lower 6 bits = (count - 1)
                uint8_t cmd = 0x40 | static_cast<uint8_t>(count - 1);
                output.push_back(cmd);
            }
        } else {
            // Opaque (non-transparent) pixel.
            if (count == 1) {
                // Literal opaque pixel: encode as 0x80 OR the colour.
                uint8_t cmd = 0x80 | color;
                output.push_back(cmd);
            } else {
                // Run of opaque pixels: first byte is 0x80 OR (count - 1), second byte is
                // the literal opaque pixel (which in native form is 0xC0 OR colour).
                uint8_t cmd = 0x80 | static_cast<uint8_t>(count - 1);
                output.push_back(cmd);
                uint8_t literal = 0xC0 | color;
                output.push_back(literal);
            }
        }
        i += count;
    }
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: rlecompress <src file> <tgt file>\n";
        return 1;
    }
    const char* srcFile = argv[1];
    const char* tgtFile = argv[2];

    // Read entire source file into a vector.
    std::ifstream in(srcFile, std::ios::binary);
    if (!in) {
        std::cerr << "Error: Cannot open source file " << srcFile << "\n";
        return 1;
    }
    std::vector<uint8_t> input((std::istreambuf_iterator<char>(in)),
                                std::istreambuf_iterator<char>());
    in.close();

    std::vector<uint8_t> encoded = encodeRLE(input);

    // Write encoded data to target file.
    std::ofstream out(tgtFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error: Cannot open target file " << tgtFile << "\n";
        return 1;
    }
    out.write(reinterpret_cast<const char*>(encoded.data()), encoded.size());
    out.close();

    return 0;
}
