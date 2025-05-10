// agoncompress.cpp
// Compile with: g++ -std=c++17 -O2 -o agoncompress agoncompress.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

// For Linux, map ESP32 allocation functions to the standard ones.
#define ps_malloc malloc
#define heap_caps_free free

// Simple debug log implementation.
extern "C" void debug_log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// Include the provided compression header.
#include "compression.h"

// Our compressed file header.
#pragma pack(push, 1)
typedef struct {
    uint8_t     marker[3];   // e.g., "AGC"
    uint8_t     type;        // compression type (we use COMPRESSION_TYPE_TURBO)
    uint32_t    orig_size;   // original uncompressed size in bytes
} CompressionFileHeader;
#pragma pack(pop)

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: agoncompress <src file> <tgt file>\n";
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

    // Allocate an initial temporary output buffer for compressed data.
    // (The header’s write function expects a pointer-to-pointer context.)
    uint32_t initialBufferSize = COMPRESSION_OUTPUT_CHUNK_SIZE; // 1024 bytes
    uint8_t* tempBuffer = (uint8_t*)malloc(initialBufferSize);
    if (!tempBuffer) {
        std::cerr << "Error: Cannot allocate temporary buffer.\n";
        return 1;
    }

    // Set up the CompressionData structure.
    CompressionData cd;
    agon_init_compression(&cd, (void*)&tempBuffer, local_write_compressed_byte);
    // At this point cd.output_count is zero.

    // Compress each byte of the input.
    for (size_t i = 0; i < input.size(); i++) {
        agon_compress_byte(&cd, input[i]);
    }
    // Flush out any remaining bits and finish.
    agon_finish_compression(&cd);

    // Prepare the file header.
    CompressionFileHeader header;
    header.marker[0] = 'A';
    header.marker[1] = 'G';
    header.marker[2] = 'C';
    header.type = COMPRESSION_TYPE_TURBO;  // 'T'
    header.orig_size = input.size();

    // Write header and compressed data to the target file.
    std::ofstream out(tgtFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error: Cannot open target file " << tgtFile << "\n";
        free(tempBuffer);
        return 1;
    }
    out.write(reinterpret_cast<char*>(&header), sizeof(header));
    out.write(reinterpret_cast<char*>(tempBuffer), cd.output_count);
    out.close();

    free(tempBuffer);

    std::cout << "Compression complete. Original size: " << input.size() 
              << " bytes, compressed size: " << cd.output_count << " bytes.\n";
    return 0;
}
