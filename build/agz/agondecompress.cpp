// agondecompress.cpp
// Compile with: g++ -std=c++17 -O2 -o agondecompress agondecompress.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

// For Linux, map ESP32 allocation functions to standard ones.
#define ps_malloc malloc
#define heap_caps_free free

// Simple debug log implementation.
extern "C" void debug_log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

#include "compression.h"

// The compressed file header structure.
#pragma pack(push, 1)
typedef struct {
    uint8_t     marker[3];   // Expect "AGC"
    uint8_t     type;        // Should be COMPRESSION_TYPE_TURBO ('T')
    uint32_t    orig_size;   // Original uncompressed size
} CompressionFileHeader;
#pragma pack(pop)

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: agondecompress <src file> <tgt file>\n";
        return 1;
    }
    const char* srcFile = argv[1];
    const char* tgtFile = argv[2];

    // Read entire compressed file into a vector.
    std::ifstream in(srcFile, std::ios::binary);
    if (!in) {
        std::cerr << "Error: Cannot open source file " << srcFile << "\n";
        return 1;
    }
    std::vector<uint8_t> compFileData((std::istreambuf_iterator<char>(in)),
                                      std::istreambuf_iterator<char>());
    in.close();

    if (compFileData.size() < sizeof(CompressionFileHeader)) {
        std::cerr << "Error: File too small to contain header.\n";
        return 1;
    }

    // Extract the header.
    CompressionFileHeader header;
    memcpy(&header, compFileData.data(), sizeof(header));

    // Verify the marker and type.
    if (header.marker[0] != 'A' || header.marker[1] != 'G' || header.marker[2] != 'C') {
        std::cerr << "Error: Invalid file marker.\n";
        return 1;
    }
    if (header.type != COMPRESSION_TYPE_TURBO) {
        std::cerr << "Error: Unsupported compression type.\n";
        return 1;
    }
    uint32_t orig_size = header.orig_size;

    // The remaining data is the compressed stream.
    size_t compDataOffset = sizeof(CompressionFileHeader);
    std::vector<uint8_t> compData(compFileData.begin() + compDataOffset, compFileData.end());

    // Allocate an output buffer to hold the decompressed data.
    uint8_t* tempBuffer = (uint8_t*)malloc(orig_size);
    if (!tempBuffer) {
        std::cerr << "Error: Cannot allocate decompression buffer.\n";
        return 1;
    }

    // Set up the DecompressionData structure.
    DecompressionData dd;
    agon_init_decompression(&dd, (void*)&tempBuffer, local_write_decompressed_byte, orig_size);

    // Feed each compressed byte into the decompressor.
    for (size_t i = 0; i < compData.size(); i++) {
        agon_decompress_byte(&dd, compData[i]);
    }

    // Write the decompressed data to the target file.
    std::ofstream out(tgtFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error: Cannot open target file " << tgtFile << "\n";
        free(tempBuffer);
        return 1;
    }
    out.write(reinterpret_cast<char*>(tempBuffer), dd.output_count);
    out.close();

    free(tempBuffer);

    std::cout << "Decompression complete. Decompressed size: " << dd.output_count << " bytes.\n";
    return 0;
}
