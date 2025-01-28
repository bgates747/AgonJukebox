#pragma once

#include <Python.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <stdbool.h>

typedef struct {
    uint8_t r, g, b;  // RGB values
    float h, s, v;    // HSV values
    float c, m, y, k; // CMYK values
    char name[64];    // Color name
} Color;

typedef struct {
    Color *colors;  // Array of colors
    size_t size;    // Number of colors in the palette
} Palette;

static const uint8_t bayer_matrix[4][4] = {
    {   0, 136,  34, 170 },
    { 204,  68, 238, 102 },
    {  51, 187,  17, 153 },
    { 255, 119, 221,  85 }
};

// ===========================
// Function prototypes
// ===========================
// 1. Image I/O (Reading and Writing PNG)
// ---------------------------
int read_png(const char *filename, uint8_t **image_data, int *width, int *height);
int write_png(const char *filename, uint8_t *image_data, int width, int height);
uint8_t* load_png_to_rgba(const char *filename, int *width, int *height);
int save_rgba_to_png(const char *filename, uint8_t *image_data, int width, int height);

// ===========================
// 2. Color Conversion and Quantization
// ---------------------------
void rgb_to_hsv_internal(uint8_t r, uint8_t g, uint8_t b, float *h, float *s, float *v);
void rgb_to_cmyk_internal(uint8_t r, uint8_t g, uint8_t b, float *c, float *m, float *y, float *k);
void hsv_to_rgb_internal(float h, float s, float v, uint8_t *r, uint8_t *g, uint8_t *b);
void cmyk_to_rgb_internal(float c, float m, float y, float k, uint8_t *r, uint8_t *g, uint8_t *b);
uint8_t quantize_channel(uint8_t channel);
uint8_t eight_to_two(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void two_to_eight(uint8_t pixel, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);
int parse_color(PyObject *args, Color *color);
void quantize_to_rgb565(uint8_t *image_data, int width, int height);

// ===========================
// 3. Color Distance Calculations
// ---------------------------
float get_color_distance_rgb(const Color *color1, const Color *color2);
// float get_color_distance_hsv(const Color *color1, const Color *color2);
float get_color_distance_cmyk(const Color *color1, const Color *color2);

// ===========================
// 4. Palette Color Finding
// ---------------------------
int load_gimp_palette(const char *filename, Palette *palette);
const Color* find_nearest_color_rgb_internal(const Color *target_rgb, const Palette *palette);
const Color* find_nearest_color_hsv_internal(const Color *target_hsv, const Palette *palette);
const Color* find_nearest_color_cmyk_internal(const Color *target_cmyk, const Palette *palette);

// ===========================
// 5. Dithering Functions
// ---------------------------
void dither_atkinson(uint8_t* image_data, int width, int height, Palette *palette);
void dither_bayer(uint8_t* image_data, int width, int height, Palette *palette);
void dither_floyd_steinberg(uint8_t* image_data, int width, int height, Palette *palette);
// ===========================
// 6. Image Conversion Functions
// ---------------------------
void convert_image_rgb(uint8_t *image_data, int width, int height, Palette *palette, bool has_transparent_color, const uint8_t transparent_rgb[3]);
void convert_image_hsv(uint8_t *image_data, int width, int height, Palette *palette, bool has_transparent_color, const uint8_t transparent_rgb[3]);
void convert_image_cmyk(uint8_t *image_data, int width, int height, Palette *palette, bool has_transparent_color, const uint8_t transparent_rgb[3]);

// ===========================
// 8. Utility Functions
// ---------------------------
inline uint8_t clamp(int value);
