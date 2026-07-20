// rledecompress.cpp
// Compile with: g++ -std=c++17 -O2 -o rledecompress rledecompress.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

// Decode a vector of RLE-encoded data back into raw rgba2222 pixels.
std::vector<uint8_t> decodeRLE(const std::vector<uint8_t>& input) {
    std::vector<uint8_t> output;
    size_t i = 0;
    while (i < input.size()) {
        uint8_t cmd = input[i++];
        uint8_t type = cmd & 0xC0; // top two bits
        if (type == 0x40) {
            // Transparent pixel command.
            uint8_t run = cmd & 0x3F;
            // A value of zero means a single transparent pixel; otherwise, count = (run + 1)
            size_t count = (run == 0) ? 1 : (run + 1);
            for (size_t j = 0; j < count; ++j) {
                // Transparent pixel: native representation is 0x00.
                output.push_back(0x00);
            }
        } else if (type == 0x80) {
            // Opaque (non-transparent) pixel command.
            // Look ahead: if the next byte exists and its top two bits are 11, then this command
            // represents a run; otherwise, it is a literal.
            if (i < input.size() && ((input[i] & 0xC0) == 0xC0)) {
                size_t count = (cmd & 0x3F) + 1;
                uint8_t literal = input[i++];
                // The literal byte already has the proper opaque (11) alpha.
                for (size_t j = 0; j < count; ++j) {
                    output.push_back(literal);
                }
            } else {
                // Literal opaque pixel encoded in the command itself.
                uint8_t pixel = 0xC0 | (cmd & 0x3F);
                output.push_back(pixel);
            }
        } else {
            std::cerr << "Invalid command type encountered: 0x" 
                      << std::hex << static_cast<int>(type) << "\n";
            return output;
        }
    }
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: rledecompress <src file> <tgt file>\n";
        return 1;
    }
    const char* srcFile = argv[1];
    const char* tgtFile = argv[2];

    // Read the encoded file.
    std::ifstream in(srcFile, std::ios::binary);
    if (!in) {
        std::cerr << "Error: Cannot open source file " << srcFile << "\n";
        return 1;
    }
    std::vector<uint8_t> input((std::istreambuf_iterator<char>(in)),
                                std::istreambuf_iterator<char>());
    in.close();

    std::vector<uint8_t> decoded = decodeRLE(input);

    // Write the decoded data to the target file.
    std::ofstream out(tgtFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error: Cannot open target file " << tgtFile << "\n";
        return 1;
    }
    out.write(reinterpret_cast<const char*>(decoded.data()), decoded.size());
    out.close();

    return 0;
}
