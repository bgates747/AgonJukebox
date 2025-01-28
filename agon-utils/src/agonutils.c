#define PY_SSIZE_T_CLEAN

#include "agonutils.h"

// Helper function to read a PNG file into RGBA format
int read_png(const char *filename, uint8_t **image_data, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return 0;
    }

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) return 0;

    png_infop info = png_create_info_struct(png);
    if (!info) return 0;

    if (setjmp(png_jmpbuf(png))) {
        fclose(fp);
        return 0;
    }

    png_init_io(png, fp);
    png_read_info(png, info);

    *width = png_get_image_width(png, info);
    *height = png_get_image_height(png, info);
    png_byte color_type = png_get_color_type(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);

    // Ensure the image is in 8-bit per channel RGBA format
    if (bit_depth == 16) png_set_strip_16(png);
    if (color_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand_gray_1_2_4_to_8(png);
    if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);

    if (color_type == PNG_COLOR_TYPE_RGB || color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    // Allocate memory for RGBA data
    *image_data = (uint8_t *)malloc(*width * *height * 4);
    if (!*image_data) {
        fclose(fp);
        png_destroy_read_struct(&png, &info, NULL);
        return 0;
    }

    png_bytep rows[*height];
    for (int y = 0; y < *height; y++) {
        rows[y] = *image_data + y * (*width * 4);
    }

    png_read_image(png, rows);

    fclose(fp);
    png_destroy_read_struct(&png, &info, NULL);
    return 1;
}

// Helper function to write RGBA data to a PNG file
int write_png(const char *filename, uint8_t *image_data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        return 0;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) return 0;

    png_infop info = png_create_info_struct(png);
    if (!info) return 0;

    if (setjmp(png_jmpbuf(png))) {
        fclose(fp);
        return 0;
    }

    png_init_io(png, fp);

    // Set image info (8-bit per channel, RGBA)
    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );

    png_write_info(png, info);

    // Write image data
    png_bytep rows[height];
    for (int y = 0; y < height; y++) {
        rows[y] = image_data + y * width * 4;
    }

    png_write_image(png, rows);
    png_write_end(png, NULL);

    fclose(fp);
    png_destroy_write_struct(&png, &info);
    return 1;
}

// Function to load a PNG file and convert it to raw RGBA bytes
uint8_t* load_png_to_rgba(const char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        return NULL;
    }

    // Read the PNG header
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        fclose(fp);
        return NULL;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_read_struct(&png, NULL, NULL);
        fclose(fp);
        return NULL;
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, NULL);
        fclose(fp);
        return NULL;
    }

    png_init_io(png, fp);
    png_read_info(png, info);

    *width = png_get_image_width(png, info);
    *height = png_get_image_height(png, info);
    png_byte color_type = png_get_color_type(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);

    // Convert palette and grayscale images to RGBA
    if (bit_depth == 16) {
        png_set_strip_16(png);
    }
    if (color_type == PNG_COLOR_TYPE_PALETTE) {
        png_set_palette_to_rgb(png);
    }
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) {
        png_set_expand_gray_1_2_4_to_8(png);
    }
    if (png_get_valid(png, info, PNG_INFO_tRNS)) {
        png_set_tRNS_to_alpha(png);
    }
    if (color_type == PNG_COLOR_TYPE_RGB || color_type == PNG_COLOR_TYPE_GRAY) {
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
    }
    if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
        png_set_gray_to_rgb(png);
    }

    png_read_update_info(png, info);

    // Allocate memory for image data (RGBA = 4 bytes per pixel)
    int row_bytes = png_get_rowbytes(png, info);
    uint8_t *image_data = (uint8_t *)malloc((*height) * row_bytes);

    png_bytep *row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * (*height));
    for (int y = 0; y < *height; y++) {
        row_pointers[y] = image_data + y * row_bytes;
    }

    // Read the image into row_pointers
    png_read_image(png, row_pointers);

    free(row_pointers);
    png_destroy_read_struct(&png, &info, NULL);
    fclose(fp);

    return image_data;
}

// Function to save raw RGBA data to a PNG file
int save_rgba_to_png(const char *filename, uint8_t *image_data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return -1;
    }

    // Initialize write structure
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        fclose(fp);
        return -1;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_write_struct(&png, NULL);
        fclose(fp);
        return -1;
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_write_struct(&png, &info);
        fclose(fp);
        return -1;
    }

    png_init_io(png, fp);

    // Write PNG header
    png_set_IHDR(
        png,
        info,
        width, height,
        8, // bit depth
        PNG_COLOR_TYPE_RGBA, // color type
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png, info);

    // Write image data
    png_bytep *row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
    for (int y = 0; y < height; y++) {
        row_pointers[y] = image_data + y * width * 4; // 4 bytes per pixel (RGBA)
    }

    png_write_image(png, row_pointers);
    png_write_end(png, NULL);

    free(row_pointers);
    png_destroy_write_struct(&png, &info);
    fclose(fp);

    return 0; // Success
}

// Function to convert RGB to HSV (normalized 0-1)
void rgb_to_hsv_internal(uint8_t r, uint8_t g, uint8_t b, float *h, float *s, float *v) {
    float r_norm = r / 255.0f;
    float g_norm = g / 255.0f;
    float b_norm = b / 255.0f;

    float max = fmaxf(fmaxf(r_norm, g_norm), b_norm);
    float min = fminf(fminf(r_norm, g_norm), b_norm);
    float delta = max - min;

    // Hue calculation
    if (delta == 0) {
        *h = 0;
    } else if (max == r_norm) {
        *h = fmodf((g_norm - b_norm) / delta, 6.0f) / 6.0f;
    } else if (max == g_norm) {
        *h = ((b_norm - r_norm) / delta + 2.0f) / 6.0f;
    } else {
        *h = ((r_norm - g_norm) / delta + 4.0f) / 6.0f;
    }
    if (*h < 0) *h += 1.0f;

    // Saturation calculation
    *s = (max == 0) ? 0 : delta / max;

    // Value calculation
    *v = max;
}

// Function to convert RGB to CMYK (normalized 0-1)
void rgb_to_cmyk_internal(uint8_t r, uint8_t g, uint8_t b, float *c, float *m, float *y, float *k) {
    float r_norm = r / 255.0f;
    float g_norm = g / 255.0f;
    float b_norm = b / 255.0f;

    *k = 1.0f - fmaxf(fmaxf(r_norm, g_norm), b_norm);

    if (*k < 1.0f) {
        *c = (1.0f - r_norm - *k) / (1.0f - *k);
        *m = (1.0f - g_norm - *k) / (1.0f - *k);
        *y = (1.0f - b_norm - *k) / (1.0f - *k);
    } else {
        *c = 0;
        *m = 0;
        *y = 0;
    }
}

void hsv_to_rgb_internal(float h, float s, float v, uint8_t *r, uint8_t *g, uint8_t *b) {
    float c = v * s;  // Chroma
    float x = c * (1.0f - fabsf(fmodf(h * 6.0f, 2.0f) - 1.0f));
    float m = v - c;

    float r_temp, g_temp, b_temp;

    if (h >= 0.0f && h < 1.0f / 6.0f) {
        r_temp = c;
        g_temp = x;
        b_temp = 0.0f;
    } else if (h >= 1.0f / 6.0f && h < 2.0f / 6.0f) {
        r_temp = x;
        g_temp = c;
        b_temp = 0.0f;
    } else if (h >= 2.0f / 6.0f && h < 3.0f / 6.0f) {
        r_temp = 0.0f;
        g_temp = c;
        b_temp = x;
    } else if (h >= 3.0f / 6.0f && h < 4.0f / 6.0f) {
        r_temp = 0.0f;
        g_temp = x;
        b_temp = c;
    } else if (h >= 4.0f / 6.0f && h < 5.0f / 6.0f) {
        r_temp = x;
        g_temp = 0.0f;
        b_temp = c;
    } else {
        r_temp = c;
        g_temp = 0.0f;
        b_temp = x;
    }

    *r = (uint8_t)((r_temp + m) * 255.0f);
    *g = (uint8_t)((g_temp + m) * 255.0f);
    *b = (uint8_t)((b_temp + m) * 255.0f);
}

void cmyk_to_rgb_internal(float c, float m, float y, float k, uint8_t *r, uint8_t *g, uint8_t *b) {
    *r = (uint8_t)(255.0f * (1.0f - c) * (1.0f - k));
    *g = (uint8_t)(255.0f * (1.0f - m) * (1.0f - k));
    *b = (uint8_t)(255.0f * (1.0f - y) * (1.0f - k));
}

// Helper function to quantize an 8-bit channel to 2-bit
uint8_t quantize_channel(uint8_t channel) {
    if (channel < 64) {
        return 0;
    } else if (channel < 128) {
        return 1;
    } else if (channel < 192) {
        return 2;
    } else {
        return 3;
    }
}

// Helper function to encode 8-bit RGBA into a 2-bit packed pixel
uint8_t eight_to_two(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    // Quantize 8-bit values to 2-bit values
    uint8_t r_q = quantize_channel(r);
    uint8_t g_q = quantize_channel(g);
    uint8_t b_q = quantize_channel(b);
    uint8_t a_q = quantize_channel(a);

    // Pack the 2-bit channels into a single byte
    return (a_q << 6) | (b_q << 4) | (g_q << 2) | r_q;
}

// Helper function to decode a 2-bit pixel into 8-bit RGBA (used for palette colors)
void two_to_eight(uint8_t pixel, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a) {
    // Extract the individual 2-bit values from the byte
    *a = (pixel >> 6) & 0b11;
    *b = (pixel >> 4) & 0b11;
    *g = (pixel >> 2) & 0b11;
    *r = pixel & 0b11;

    // Map the 2-bit values to 8-bit values (0, 85, 170, 255)
    static const uint8_t mapping[4] = {0, 85, 170, 255};
    *r = mapping[*r];
    *g = mapping[*g];
    *b = mapping[*b];
    *a = mapping[*a];
}
#include <math.h>
#include <float.h>  // For FLT_MAX (instead of INFINITY)

// Function to calculate Euclidean distance between two RGB colors in the Color struct
float get_color_distance_rgb(const Color *color1, const Color *color2) {
    return sqrtf(powf(color1->r - color2->r, 2) +
                 powf(color1->g - color2->g, 2) +
                 powf(color1->b - color2->b, 2));
}

// Function to calculate Euclidean distance between two CMYK colors in the Color struct
float get_color_distance_cmyk(const Color *color1, const Color *color2) {
    return sqrtf(powf(color1->c - color2->c, 2) +
                 powf(color1->m - color2->m, 2) +
                 powf(color1->y - color2->y, 2) +
                 powf(color1->k - color2->k, 2));
}

// Function to find the nearest RGB color in the palette
const Color* find_nearest_color_rgb_internal(const Color *target_rgb, const Palette *palette) {
    const Color *nearest_color = NULL;
    float min_distance = FLT_MAX;  // Set to max float value
    for (size_t i = 0; i < palette->size; ++i) {
        float distance = get_color_distance_rgb(target_rgb, &palette->colors[i]);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_color = &palette->colors[i];
        }
    }
    return nearest_color;
}

const Color* find_nearest_color_hsv_internal(const Color *target_hsv, const Palette *palette) {
    const Color *nearest_color = NULL;
    float min_distance = FLT_MAX;

    // Iterate through each color in the palette
    for (size_t i = 0; i < palette->size; ++i) {
        const Color *palette_color = &palette->colors[i];

        // Compute the hue distance, accounting for wrap-around
        float hue_distance = fabsf(target_hsv->h - palette_color->h);
        if (hue_distance > 0.5) {
            hue_distance = 1.0 - hue_distance;  // Wrap around the hue circle
        }

        // Compute the Euclidean distance in the HSV space
        float distance = sqrtf(powf(hue_distance, 2) +
                               powf(target_hsv->s - palette_color->s, 2) +
                               powf(target_hsv->v - palette_color->v, 2));

        // If this is the smallest distance so far, store this color as the nearest
        if (distance < min_distance) {
            min_distance = distance;
            nearest_color = palette_color;
        }
    }

    return nearest_color;
}

// Function to find the nearest CMYK color in the palette
const Color* find_nearest_color_cmyk_internal(const Color *target_cmyk, const Palette *palette) {
    const Color *nearest_color = NULL;
    float min_distance = FLT_MAX;
    for (size_t i = 0; i < palette->size; ++i) {
        float distance = get_color_distance_cmyk(target_cmyk, &palette->colors[i]);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_color = &palette->colors[i];
        }
    }
    return nearest_color;
}

// Function to read a GIMP palette file and load it into the Palette struct
int load_gimp_palette(const char *filename, Palette *palette) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return -1;
    }

    char line[256];
    size_t color_count = 0;
    size_t capacity = 256;  // Initial capacity for 256 colors

    // Allocate memory for the palette
    palette->colors = (Color *)malloc(capacity * sizeof(Color));
    if (!palette->colors) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(file);
        return -1;
    }

    // Skip header lines (lines starting with # or containing "GIMP Palette")
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || strncmp(line, "GIMP Palette", 12) == 0 || strncmp(line, "Columns", 7) == 0) {
            continue;
        }

        // Parse RGB values from each valid line
        int r, g, b;
        if (sscanf(line, "%d %d %d", &r, &g, &b) == 3) {
            // Check if we need to resize the array
            if (color_count >= capacity) {
                capacity *= 2;
                palette->colors = (Color *)realloc(palette->colors, capacity * sizeof(Color));
                if (!palette->colors) {
                    fprintf(stderr, "Error: Memory reallocation failed\n");
                    fclose(file);
                    return -1;
                }
            }

            // Store the RGB values
            palette->colors[color_count].r = (uint8_t)r;
            palette->colors[color_count].g = (uint8_t)g;
            palette->colors[color_count].b = (uint8_t)b;

            // Convert and store HSV values
            rgb_to_hsv_internal(r, g, b, &palette->colors[color_count].h, &palette->colors[color_count].s, &palette->colors[color_count].v);

            // Convert and store CMYK values
            rgb_to_cmyk_internal(r, g, b, &palette->colors[color_count].c, &palette->colors[color_count].m, &palette->colors[color_count].y, &palette->colors[color_count].k);

            color_count++;
        }
    }

    // Close the file
    fclose(file);

    // Store the final size
    palette->size = color_count;

    return 0;
}

// Function to free the palette memory
void free_palette(Palette *palette) {
    if (palette->colors) {
        free(palette->colors);
        palette->colors = NULL;
    }
    palette->size = 0;
}

void dither_atkinson(uint8_t* image_data, int width, int height, Palette *palette) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            uint8_t* pixel = &image_data[(y * width + x) * 4];  // RGBA format

            // Skip dithering for pixels with alpha channel value < 1
            if (pixel[3] < 1) continue;

            // Create a Color struct for the current pixel's RGB values
            Color current_pixel = { .r = pixel[0], .g = pixel[1], .b = pixel[2] };

            // Find the nearest RGB color in the palette
            const Color* nearest_color = find_nearest_color_rgb_internal(&current_pixel, palette);

            // Compute the error (difference between original and nearest color)
            int16_t err_r = pixel[0] - nearest_color->r;
            int16_t err_g = pixel[1] - nearest_color->g;
            int16_t err_b = pixel[2] - nearest_color->b;

            // Update the current pixel with the nearest color
            pixel[0] = nearest_color->r;
            pixel[1] = nearest_color->g;
            pixel[2] = nearest_color->b;

            // Propagate the error to neighboring pixels using Atkinson dithering
            // Divide the error by 8 using bit-shifting (err / 8 = err >> 3)
            int16_t error_r = err_r >> 3;
            int16_t error_g = err_g >> 3;
            int16_t error_b = err_b >> 3;

            // Propagate to right neighbor (x + 1)
            if (x + 1 < width) {
                uint8_t* right_pixel = &image_data[(y * width + (x + 1)) * 4];
                right_pixel[0] = clamp(right_pixel[0] + error_r);
                right_pixel[1] = clamp(right_pixel[1] + error_g);
                right_pixel[2] = clamp(right_pixel[2] + error_b);
            }

            // Propagate to right+2 neighbor (x + 2)
            if (x + 2 < width) {
                uint8_t* right2_pixel = &image_data[(y * width + (x + 2)) * 4];
                right2_pixel[0] = clamp(right2_pixel[0] + error_r);
                right2_pixel[1] = clamp(right2_pixel[1] + error_g);
                right2_pixel[2] = clamp(right2_pixel[2] + error_b);
            }

            // Propagate to bottom neighbor (y + 1)
            if (y + 1 < height) {
                uint8_t* bottom_pixel = &image_data[((y + 1) * width + x) * 4];
                bottom_pixel[0] = clamp(bottom_pixel[0] + error_r);
                bottom_pixel[1] = clamp(bottom_pixel[1] + error_g);
                bottom_pixel[2] = clamp(bottom_pixel[2] + error_b);
            }

            // Propagate to bottom-right neighbor (y + 1, x + 1)
            if (x + 1 < width && y + 1 < height) {
                uint8_t* bottom_right_pixel = &image_data[((y + 1) * width + (x + 1)) * 4];
                bottom_right_pixel[0] = clamp(bottom_right_pixel[0] + error_r);
                bottom_right_pixel[1] = clamp(bottom_right_pixel[1] + error_g);
                bottom_right_pixel[2] = clamp(bottom_right_pixel[2] + error_b);
            }

            // Propagate to bottom-right+2 neighbor (y + 1, x + 2)
            if (x + 2 < width && y + 1 < height) {
                uint8_t* bottom_right2_pixel = &image_data[((y + 1) * width + (x + 2)) * 4];
                bottom_right2_pixel[0] = clamp(bottom_right2_pixel[0] + error_r);
                bottom_right2_pixel[1] = clamp(bottom_right2_pixel[1] + error_g);
                bottom_right2_pixel[2] = clamp(bottom_right2_pixel[2] + error_b);
            }
        }
    }
}

void extrapolate_color(const Color *orig, const Color *matched, Color *extrapolated) {
    extrapolated->r = clamp(orig->r + (orig->r - matched->r));
    extrapolated->g = clamp(orig->g + (orig->g - matched->g));
    extrapolated->b = clamp(orig->b + (orig->b - matched->b));
}

void dither_bayer(uint8_t* image_data, int width, int height, Palette *palette) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            uint8_t* pixel = &image_data[(y * width + x) * 4];  // RGBA format

            // Skip dithering for pixels with alpha channel value < 1
            if (pixel[3] < 1) continue;

            // Get the Bayer threshold value for the current pixel position
            uint8_t threshold = bayer_matrix[x % 4][y % 4];

            // Create a Color struct for the current pixel's RGB values
            Color current_pixel = { .r = pixel[0], .g = pixel[1], .b = pixel[2] };

            // Find the nearest RGB color in the palette (initial color1)
            const Color* color1 = find_nearest_color_rgb_internal(&current_pixel, palette);

            // Extrapolate a second color (color2) based on the error from color1
            Color extrapolated_color;
            extrapolate_color(&current_pixel, color1, &extrapolated_color);

            const Color* color2 = find_nearest_color_rgb_internal(&extrapolated_color, palette);

            // Calculate distances
            float err1 = get_color_distance_rgb(&current_pixel, color1);
            float err2 = get_color_distance_rgb(&current_pixel, color2);

            // Determine the relative probability of choosing color1 vs color2
            if (err1 || err2) {
                const int proportion2 = (255 * err2) / (err1 + err2);
                if (threshold > proportion2) {
                    color1 = color2;  // Use the alternative color2
                }
            }

            // Update the pixel with the final color
            pixel[0] = color1->r;
            pixel[1] = color1->g;
            pixel[2] = color1->b;
        }
    }
}

// Floyd-Steinberg dithering
void dither_floyd_steinberg(uint8_t* image_data, int width, int height, Palette *palette) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pixel_index = (y * width + x) * 4;  // RGBA format
            uint8_t *pixel = &image_data[pixel_index];

            // Skip pixels with alpha less than full (i.e., partially transparent)
            if (pixel[3] < 1) {
                continue;
            }

            // Create a temporary Color struct for the current pixel's RGB values
            Color current_pixel = {
                .r = pixel[0],  // Red
                .g = pixel[1],  // Green
                .b = pixel[2],  // Blue
                .h = 0.0f,      // Not used for RGB matching
                .s = 0.0f,      // Not used for RGB matching
                .v = 0.0f,      // Not used for RGB matching
                .c = 0.0f,      // Not used for RGB matching
                .m = 0.0f,      // Not used for RGB matching
                .y = 0.0f,      // Not used for RGB matching
                .k = 0.0f       // Not used for RGB matching
            };

            // Find the nearest RGB color in the palette
            const Color* nearest_color = find_nearest_color_rgb_internal(&current_pixel, palette);

            // Store the original pixel values
            uint8_t old_r = pixel[0];
            uint8_t old_g = pixel[1];
            uint8_t old_b = pixel[2];

            // Set the pixel to the nearest palette color
            pixel[0] = nearest_color->r;  // Red
            pixel[1] = nearest_color->g;  // Green
            pixel[2] = nearest_color->b;  // Blue

            // Calculate the error for each channel (RGB)
            int error_r = old_r - nearest_color->r;
            int error_g = old_g - nearest_color->g;
            int error_b = old_b - nearest_color->b;

            // Distribute the error to neighboring pixels (Floyd-Steinberg dithering)
            if (x + 1 < width) {
                int neighbor_index = (y * width + (x + 1)) * 4;
                image_data[neighbor_index + 0] = clamp(image_data[neighbor_index + 0] + (error_r * 7 / 16));
                image_data[neighbor_index + 1] = clamp(image_data[neighbor_index + 1] + (error_g * 7 / 16));
                image_data[neighbor_index + 2] = clamp(image_data[neighbor_index + 2] + (error_b * 7 / 16));
            }
            if (y + 1 < height) {
                if (x > 0) {
                    int neighbor_index = ((y + 1) * width + (x - 1)) * 4;
                    image_data[neighbor_index + 0] = clamp(image_data[neighbor_index + 0] + (error_r * 3 / 16));
                    image_data[neighbor_index + 1] = clamp(image_data[neighbor_index + 1] + (error_g * 3 / 16));
                    image_data[neighbor_index + 2] = clamp(image_data[neighbor_index + 2] + (error_b * 3 / 16));
                }
                int neighbor_index = ((y + 1) * width + x) * 4;
                image_data[neighbor_index + 0] = clamp(image_data[neighbor_index + 0] + (error_r * 5 / 16));
                image_data[neighbor_index + 1] = clamp(image_data[neighbor_index + 1] + (error_g * 5 / 16));
                image_data[neighbor_index + 2] = clamp(image_data[neighbor_index + 2] + (error_b * 5 / 16));
                if (x + 1 < width) {
                    int neighbor_index = ((y + 1) * width + (x + 1)) * 4;
                    image_data[neighbor_index + 0] = clamp(image_data[neighbor_index + 0] + (error_r * 1 / 16));
                    image_data[neighbor_index + 1] = clamp(image_data[neighbor_index + 1] + (error_g * 1 / 16));
                    image_data[neighbor_index + 2] = clamp(image_data[neighbor_index + 2] + (error_b * 1 / 16));
                }
            }
        }
    }
}

// Convert a PNG image to use a custom palette by matching RGB colors
void convert_image_rgb(uint8_t *image_data, int width, int height, Palette *palette, bool has_transparent_color, const uint8_t transparent_rgb[3]) {
    // Loop over every pixel in the image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pixel_index = (y * width + x) * 4;  // Assuming RGBA format

            uint8_t r = image_data[pixel_index];
            uint8_t g = image_data[pixel_index + 1];
            uint8_t b = image_data[pixel_index + 2];
            uint8_t a = image_data[pixel_index + 3];

            // Handle transparency based on alpha or a specific transparent color
            if (a < 1 || (has_transparent_color && r == transparent_rgb[0] && g == transparent_rgb[1] && b == transparent_rgb[2])) {
                image_data[pixel_index + 3] = 0;  // Fully transparent
                continue;
            }

            // Create a temporary Color struct for the current pixel's RGB values
            Color current_pixel = {r, g, b, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
            rgb_to_hsv_internal(r, g, b, &current_pixel.h, &current_pixel.s, &current_pixel.v);
            rgb_to_cmyk_internal(r, g, b, &current_pixel.c, &current_pixel.m, &current_pixel.y, &current_pixel.k);

            // Find the nearest RGB color in the palette
            const Color *nearest_rgb = find_nearest_color_rgb_internal(&current_pixel, palette);

            // Update the image data with the nearest RGB color
            image_data[pixel_index] = nearest_rgb->r;
            image_data[pixel_index + 1] = nearest_rgb->g;
            image_data[pixel_index + 2] = nearest_rgb->b;
        }
    }

    // Free the palette memory
    free_palette(palette);
}

// Convert a PNG image to use a custom palette by matching HSV colors
void convert_image_hsv(uint8_t *image_data, int width, int height, Palette *palette, bool has_transparent_color, const uint8_t transparent_rgb[3]) {
    // Loop over every pixel in the image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pixel_index = (y * width + x) * 4;  // Assuming RGBA format

            uint8_t r = image_data[pixel_index];
            uint8_t g = image_data[pixel_index + 1];
            uint8_t b = image_data[pixel_index + 2];
            uint8_t a = image_data[pixel_index + 3];

            // Handle transparency based on alpha or a specific transparent color
            if (a < 1 || (has_transparent_color && r == transparent_rgb[0] && g == transparent_rgb[1] && b == transparent_rgb[2])) {
                image_data[pixel_index + 3] = 0;  // Fully transparent
                continue;
            }

            // Convert the current pixel's RGB values to HSV
            Color current_pixel;
            rgb_to_hsv_internal(r, g, b, &current_pixel.h, &current_pixel.s, &current_pixel.v);

            // Find the nearest HSV color in the palette
            const Color *nearest_hsv = find_nearest_color_hsv_internal(&current_pixel, palette);

            // Convert the nearest HSV color back to RGB for output
            uint8_t nearest_r, nearest_g, nearest_b;
            hsv_to_rgb_internal(nearest_hsv->h, nearest_hsv->s, nearest_hsv->v, &nearest_r, &nearest_g, &nearest_b);

            // Update the image data with the nearest RGB color
            image_data[pixel_index] = nearest_r;
            image_data[pixel_index + 1] = nearest_g;
            image_data[pixel_index + 2] = nearest_b;
        }
    }

    // Free the palette memory
    free_palette(palette);
}

// Convert a PNG image to use a custom palette by matching CMYK colors
void convert_image_cmyk(uint8_t *image_data, int width, int height, Palette *palette, bool has_transparent_color, const uint8_t transparent_rgb[3]) {
    // Loop over every pixel in the image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pixel_index = (y * width + x) * 4;  // Assuming RGBA format

            uint8_t r = image_data[pixel_index];
            uint8_t g = image_data[pixel_index + 1];
            uint8_t b = image_data[pixel_index + 2];
            uint8_t a = image_data[pixel_index + 3];

            // Handle transparency based on alpha or a specific transparent color
            if (a < 1 || (has_transparent_color && r == transparent_rgb[0] && g == transparent_rgb[1] && b == transparent_rgb[2])) {
                image_data[pixel_index + 3] = 0;  // Fully transparent
                continue;
            }

            // Convert the current pixel's RGB values to CMYK
            Color current_pixel;
            rgb_to_cmyk_internal(r, g, b, &current_pixel.c, &current_pixel.m, &current_pixel.y, &current_pixel.k);

            // Find the nearest CMYK color in the palette
            const Color *nearest_cmyk = find_nearest_color_cmyk_internal(&current_pixel, palette);

            // Convert the nearest CMYK color back to RGB for output
            uint8_t nearest_r, nearest_g, nearest_b;
            cmyk_to_rgb_internal(nearest_cmyk->c, nearest_cmyk->m, nearest_cmyk->y, nearest_cmyk->k, &nearest_r, &nearest_g, &nearest_b);

            // Update the image data with the nearest RGB color
            image_data[pixel_index] = nearest_r;
            image_data[pixel_index + 1] = nearest_g;
            image_data[pixel_index + 2] = nearest_b;
        }
    }

    // Free the palette memory
    free_palette(palette);
}

// Helper function to clamp values between 0 and 255
inline uint8_t clamp(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return (uint8_t)value;
}

// Function: Convert a PNG image to 2-bit RGBA and save it to a file
static PyObject* img_to_rgba2(PyObject *self, PyObject *args) {
    const char *input_filepath, *output_filepath;

    // Parse arguments: input PNG file and output RGBA2 file
    if (!PyArg_ParseTuple(args, "ss", &input_filepath, &output_filepath)) {
        return NULL;
    }

    // Open the input PNG file (use your libpng helpers for loading)
    uint8_t *image_data;
    int width, height;
    if (!read_png(input_filepath, &image_data, &width, &height)) {
        PyErr_SetString(PyExc_IOError, "Failed to load PNG file.");
        return NULL;
    }

    // Open the output RGBA2 file for writing
    FILE *file = fopen(output_filepath, "wb");
    if (!file) {
        PyErr_SetString(PyExc_IOError, "Could not open output file for writing.");
        free(image_data);
        return NULL;
    }

    // Process each pixel in the image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pixel_index = (y * width + x) * 4;  // 4 bytes per pixel (RGBA)

            // Extract the r, g, b, a values from the raw data
            uint8_t r = image_data[pixel_index + 0];
            uint8_t g = image_data[pixel_index + 1];
            uint8_t b = image_data[pixel_index + 2];
            uint8_t a = image_data[pixel_index + 3];

            // Use the helper function to encode 8-bit RGBA into a 2-bit packed pixel
            uint8_t packed_pixel = eight_to_two(r, g, b, a);

            // Write the packed pixel to the file
            fwrite(&packed_pixel, sizeof(uint8_t), 1, file);
        }
    }

    fclose(file);
    free(image_data);
    Py_RETURN_NONE;
}

// Function: Convert RGBA2 binary file to PNG
static PyObject* rgba2_to_img(PyObject *self, PyObject *args) {
    const char *input_filepath, *output_filepath;
    int int_width, int_height;  // Still use int for parsing arguments
    size_t width, height;       // Use size_t for internal processing

    // Parse arguments: input RGBA2 file, width, height, and output PNG file
    if (!PyArg_ParseTuple(args, "ssii", &input_filepath, &output_filepath, &int_width, &int_height)) {
        return NULL;
    }

    // Convert width and height to size_t
    width = (size_t)int_width;
    height = (size_t)int_height;

    // Open the input RGBA2 file for reading
    FILE *file = fopen(input_filepath, "rb");
    if (!file) {
        PyErr_SetString(PyExc_IOError, "Could not open input RGBA2 file for reading.");
        return NULL;
    }

    // Allocate memory for RGBA8 image data
    size_t image_size = width * height * 4;
    uint8_t *image_data = (uint8_t *)malloc(image_size);
    if (!image_data) {
        fclose(file);
        PyErr_SetString(PyExc_MemoryError, "Unable to allocate memory for image data.");
        return NULL;
    }

    // Read and decode each packed byte
    for (size_t i = 0; i < width * height; ++i) {
        uint8_t packed_pixel;
        fread(&packed_pixel, sizeof(uint8_t), 1, file);

        // Use the helper function to decode the 2-bit packed pixel to 8-bit RGBA
        uint8_t r, g, b, a;
        two_to_eight(packed_pixel, &r, &g, &b, &a);

        // Store the expanded 8-bit values in the image data
        image_data[i * 4 + 0] = r;
        image_data[i * 4 + 1] = g;
        image_data[i * 4 + 2] = b;
        image_data[i * 4 + 3] = a;
    }

    fclose(file);

    // Write the PNG image using your libpng helper
    if (!write_png(output_filepath, image_data, width, height)) {
        PyErr_SetString(PyExc_IOError, "Failed to save PNG file.");
        free(image_data);
        return NULL;
    }

    free(image_data);
    Py_RETURN_NONE;
}

// Function: Convert a PNG image to 8-bit RGBA and save it to a file
static PyObject* img_to_rgba8(PyObject *self, PyObject *args) {
    const char *input_filepath, *output_filepath;

    // Parse arguments: input PNG file and output RGBA8 file
    if (!PyArg_ParseTuple(args, "ss", &input_filepath, &output_filepath)) {
        return NULL;
    }

    // Open the input PNG file (use your libpng helpers for loading)
    uint8_t *image_data;
    int width, height;
    if (!read_png(input_filepath, &image_data, &width, &height)) {
        PyErr_SetString(PyExc_IOError, "Failed to load PNG file.");
        return NULL;
    }

    // Open the output RGBA8 file for writing
    FILE *file = fopen(output_filepath, "wb");
    if (!file) {
        PyErr_SetString(PyExc_IOError, "Could not open output file for writing.");
        free(image_data);
        return NULL;
    }

    // Write RGBA8 data directly to file
    fwrite(image_data, sizeof(uint8_t), width * height * 4, file);

    fclose(file);
    free(image_data);
    Py_RETURN_NONE;
}

// Function: Convert an RGBA8 binary file to PNG
static PyObject* rgba8_to_img(PyObject *self, PyObject *args) {
    const char *input_filepath, *output_filepath;
    int width, height;

    // Parse arguments: input RGBA8 file, width, height, and output PNG file
    if (!PyArg_ParseTuple(args, "ssii", &input_filepath, &output_filepath, &width, &height)) {
        return NULL;
    }

    // Open the input RGBA8 file for reading
    FILE *file = fopen(input_filepath, "rb");
    if (!file) {
        PyErr_SetString(PyExc_IOError, "Could not open input RGBA8 file for reading.");
        return NULL;
    }

    // Allocate memory for RGBA8 image data
    size_t image_size = width * height * 4;
    uint8_t *image_data = (uint8_t *)malloc(image_size);
    if (!image_data) {
        fclose(file);
        PyErr_SetString(PyExc_MemoryError, "Unable to allocate memory for image data.");
        return NULL;
    }

    // Read RGBA8 data from file
    fread(image_data, sizeof(uint8_t), image_size, file);
    fclose(file);

    // Write the PNG image using your libpng helper
    if (!write_png(output_filepath, image_data, width, height)) {
        PyErr_SetString(PyExc_IOError, "Failed to save PNG file.");
        free(image_data);
        return NULL;
    }

    free(image_data);
    Py_RETURN_NONE;
}

// Function: Convert image colors to use a specified palette and save it as a PNG file
static PyObject* convert_to_palette(PyObject *self, PyObject *args, PyObject *kwargs) {
    const char *src_file, *tgt_file, *palette_file, *method;
    PyObject *transparent_color = NULL;

    // Parse arguments (source file, target file, palette file, method, transparent color)
    static char *kwlist[] = {"src_file", "tgt_file", "palette_file", "method", "transparent_color", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ssss|O", kwlist, &src_file, &tgt_file, &palette_file, &method, &transparent_color)) {
        return NULL;
    }

    // Load the palette from the GIMP palette file
    Palette palette;
    if (load_gimp_palette(palette_file, &palette) != 0) {
        PyErr_SetString(PyExc_IOError, "Failed to load palette file");
        return NULL;
    }

    // Load image using the helper function (read_png)
    uint8_t *image_data;
    int width, height;
    if (!read_png(src_file, &image_data, &width, &height)) {
        PyErr_SetString(PyExc_IOError, "Failed to load source PNG file");
        free_palette(&palette);
        return NULL;
    }

    // Default to NULL if no transparent color is provided
    uint8_t transparent_rgb[3] = {255, 255, 255};  // Default to white
    bool has_transparent_color = false;

    // If a transparent color is provided, handle the 4-tuple format (R, G, B, A)
    if (transparent_color) {
        if (!PyTuple_Check(transparent_color) || PyTuple_Size(transparent_color) != 4) {
            PyErr_SetString(PyExc_TypeError, "transparent_color must be a tuple of 4 integers (R, G, B, A)");
            free(image_data);
            free_palette(&palette);
            return NULL;
        }
        int alpha = (int)PyLong_AsLong(PyTuple_GetItem(transparent_color, 3));
        if (alpha == 0) {
            // If alpha is 0, we skip transparency handling
            has_transparent_color = false;
        } else {
            // Otherwise we use the RGB values for transparency
            for (int i = 0; i < 3; ++i) {
                transparent_rgb[i] = (uint8_t)PyLong_AsLong(PyTuple_GetItem(transparent_color, i));
            }
            has_transparent_color = true;
        }
    }

    // Call the appropriate conversion or dithering function based on the method
    if (strcasecmp(method, "RGB") == 0) {
        convert_image_rgb(image_data, width, height, &palette, has_transparent_color, transparent_rgb);
    } else if (strcasecmp(method, "HSV") == 0) {
        convert_image_hsv(image_data, width, height, &palette, has_transparent_color, transparent_rgb);
    } else if (strcasecmp(method, "CMYK") == 0) {
        convert_image_cmyk(image_data, width, height, &palette, has_transparent_color, transparent_rgb);
    } else if (strcasecmp(method, "atkinson") == 0) {
        dither_atkinson(image_data, width, height, &palette);
    } else if (strcasecmp(method, "bayer") == 0) {
        dither_bayer(image_data, width, height, &palette);
    } else if (strcasecmp(method, "floyd") == 0) {
        dither_floyd_steinberg(image_data, width, height, &palette);
    } else {
        PyErr_SetString(PyExc_ValueError, "Invalid method. Must be 'RGB', 'HSV', 'CMYK', 'bayer', or 'floyd'");
        free(image_data);
        free_palette(&palette);
        return NULL;
    }

    // Write the PNG file
    if (!write_png(tgt_file, image_data, width, height)) {
        PyErr_SetString(PyExc_IOError, "Failed to save target PNG file");
        free(image_data);
        free_palette(&palette);
        return NULL;
    }

    // Free memory
    free(image_data);
    free_palette(&palette);
    Py_RETURN_NONE;
}

void quantize_to_rgb565(uint8_t *image_data, int width, int height) {
    // Iterate through each pixel in the image (RGBA = 4 bytes per pixel)
    for (int i = 0; i < width * height * 4; i += 4) {
        uint8_t r = image_data[i];     // Red channel
        uint8_t g = image_data[i + 1]; // Green channel
        uint8_t b = image_data[i + 2]; // Blue channel

        // Quantize the color channels to RGB565
        uint8_t r5 = round(r / 32) * 32;
        uint8_t g6 = round(g / 64) * 64;
        uint8_t b5 = round(b / 32) * 32;

        // Write the quantized RGB values back to the image data
        image_data[i] = r5;
        image_data[i + 1] = g6;
        image_data[i + 2] = b5;

    }
}

// Function: Convert image colors to RGB565 and save it as a PNG file
static PyObject* convert_to_rgb565(PyObject *self, PyObject *args, PyObject *kwargs) {
    const char *src_file, *tgt_file;

    // Parse arguments (source file, target file)
    static char *kwlist[] = {"src_file", "tgt_file", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ss", kwlist, &src_file, &tgt_file)) {
        return NULL;
    }

    // Load image using the helper function (read_png)
    uint8_t *image_data;
    int width, height;
    if (!read_png(src_file, &image_data, &width, &height)) {
        PyErr_SetString(PyExc_IOError, "Failed to load source PNG file");
        return NULL;
    }
    
    // Convert the image data to RGB565 format
    quantize_to_rgb565(image_data, width, height);

    // Write the PNG file
    if (!write_png(tgt_file, image_data, width, height)) {
        PyErr_SetString(PyExc_IOError, "Failed to save target PNG file");
        free(image_data);
        return NULL;
    }

    // Free memory
    free(image_data);
    Py_RETURN_NONE;
}

// Helper function: Convert a Color struct to a Python tuple (RGB, HSV, CMYK, Name)
PyObject* convert_color_to_python(const Color *color) {
    if (color == NULL) {
        Py_RETURN_NONE;
    }

    // Convert the Color struct to a Python tuple, including the name
    return Py_BuildValue(
        "(iii)(fff)(ffff)s", 
        color->r, color->g, color->b,           // RGB
        color->h, color->s, color->v,           // HSV
        color->c, color->m, color->y, color->k, // CMYK
        color->name                             // Name (if available)
    );
}

// Helper function: Parse Python arguments into a Color struct (internal use)
int parse_color(PyObject *args, Color *color) {
    int r, g, b;

    if (!PyArg_ParseTuple(args, "iii", &r, &g, &b)) {
        PyErr_SetString(PyExc_TypeError, "Expected three integers for RGB values");
        return 0; // Return 0 on failure
    }

    // Ensure the values are in the valid range for RGB (0-255)
    color->r = (uint8_t) (r & 0xFF);
    color->g = (uint8_t) (g & 0xFF);
    color->b = (uint8_t) (b & 0xFF);

    return 1; // Return 1 on success
}


// Python-accessible function: Convert RGB to HSV (normalized 0-1)
static PyObject* rgb_to_hsv(PyObject *self, PyObject *args) {
    uint8_t r, g, b;
    float h, s, v;

    // Parse Python arguments (three integers for RGB)
    if (!PyArg_ParseTuple(args, "bbb", &r, &g, &b)) {
        return NULL;
    }

    // Call the internal version of the function
    rgb_to_hsv_internal(r, g, b, &h, &s, &v);

    // Return the HSV values as a Python tuple
    return Py_BuildValue("fff", h, s, v);
}

// Python-accessible function: Convert RGB to CMYK (normalized 0-1)
static PyObject* rgb_to_cmyk(PyObject *self, PyObject *args) {
    uint8_t r, g, b;
    float c, m, y, k;

    // Parse Python arguments (three integers for RGB)
    if (!PyArg_ParseTuple(args, "bbb", &r, &g, &b)) {
        return NULL;
    }

    // Call the internal version of the function
    rgb_to_cmyk_internal(r, g, b, &c, &m, &y, &k);

    // Return the CMYK values as a Python tuple
    return Py_BuildValue("ffff", c, m, y, k);
}

// Python-accessible function: Convert HSV to RGB
static PyObject* hsv_to_rgb(PyObject *self, PyObject *args) {
    float h, s, v;
    uint8_t r, g, b;

    // Parse Python arguments (three floats for HSV)
    if (!PyArg_ParseTuple(args, "fff", &h, &s, &v)) {
        return NULL;
    }

    // Call the internal version of the function
    hsv_to_rgb_internal(h, s, v, &r, &g, &b);

    // Return the RGB values as a Python tuple
    return Py_BuildValue("bbb", r, g, b);
}

// Python-accessible function: Convert CMYK to RGB
static PyObject* cmyk_to_rgb(PyObject *self, PyObject *args) {
    float c, m, y, k;
    uint8_t r, g, b;

    // Parse Python arguments (four floats for CMYK)
    if (!PyArg_ParseTuple(args, "ffff", &c, &m, &y, &k)) {
        return NULL;
    }

    // Call the internal version of the function
    cmyk_to_rgb_internal(c, m, y, k, &r, &g, &b);

    // Return the RGB values as a Python tuple
    return Py_BuildValue("bbb", r, g, b);
}

// Function to find the nearest RGB color in the palette
// const Color* find_nearest_color_rgb(const Color *target_rgb, const Palette *palette);
static PyObject* find_nearest_color_rgb(PyObject *self, PyObject *args) {
    PyObject *py_target_rgb, *py_palette;
    
    if (!PyArg_ParseTuple(args, "OO", &py_target_rgb, &py_palette)) {
        return NULL;
    }

    Color target_rgb;
    Palette *palette = (Palette *) PyCapsule_GetPointer(py_palette, "Palette");

    if (!parse_color(py_target_rgb, &target_rgb)) {
        PyErr_SetString(PyExc_ValueError, "Invalid target RGB color format");
        return NULL;
    }

    const Color *nearest_color = find_nearest_color_rgb_internal(&target_rgb, palette);
    return convert_color_to_python(nearest_color);
}

// Function to find the nearest HSV color in the palette
// const Color* find_nearest_color_hsv(const Color *target_hsv, const Palette *palette);
static PyObject* find_nearest_color_hsv(PyObject *self, PyObject *args) {
    PyObject *py_target_hsv, *py_palette;

    if (!PyArg_ParseTuple(args, "OO", &py_target_hsv, &py_palette)) {
        return NULL;
    }

    Color target_hsv;
    Palette *palette = (Palette *) PyCapsule_GetPointer(py_palette, "Palette");

    if (!parse_color(py_target_hsv, &target_hsv)) {
        PyErr_SetString(PyExc_ValueError, "Invalid target HSV color format");
        return NULL;
    }

    const Color *nearest_color = find_nearest_color_hsv_internal(&target_hsv, palette);
    return convert_color_to_python(nearest_color);
}

// Function to find the nearest CMYK color in the palette
// const Color* find_nearest_color_cmyk(const Color *target_cmyk, const Palette *palette);
static PyObject* find_nearest_color_cmyk(PyObject *self, PyObject *args) {
    PyObject *py_target_cmyk, *py_palette;

    if (!PyArg_ParseTuple(args, "OO", &py_target_cmyk, &py_palette)) {
        return NULL;
    }

    Color target_cmyk;
    Palette *palette = (Palette *) PyCapsule_GetPointer(py_palette, "Palette");

    if (!parse_color(py_target_cmyk, &target_cmyk)) {
        PyErr_SetString(PyExc_ValueError, "Invalid target CMYK color format");
        return NULL;
    }

    const Color *nearest_color = find_nearest_color_cmyk_internal(&target_cmyk, palette);
    return convert_color_to_python(nearest_color);
}

// API Function: Converts a CSV file to a Palette object with color names
static PyObject* csv_to_palette(PyObject *self, PyObject *args) {
    const char *csv_filepath;

    // Parse the Python argument (CSV file path)
    if (!PyArg_ParseTuple(args, "s", &csv_filepath)) {
        PyErr_SetString(PyExc_TypeError, "Expected a CSV file path string");
        return NULL;
    }

    // Open the CSV file
    FILE *file = fopen(csv_filepath, "r");
    if (!file) {
        PyErr_SetString(PyExc_IOError, "Could not open the CSV file");
        return NULL;
    }

    // Allocate memory for the Palette
    Palette *palette = (Palette *)malloc(sizeof(Palette));
    if (!palette) {
        PyErr_SetString(PyExc_MemoryError, "Unable to allocate memory for the Palette");
        fclose(file);
        return NULL;
    }

    // Temporary storage for reading each line in the CSV
    char line[256];
    size_t capacity = 256;  // Initial capacity for the palette colors
    size_t color_count = 0;

    // Allocate memory for the colors array
    palette->colors = (Color *)malloc(capacity * sizeof(Color));
    if (!palette->colors) {
        PyErr_SetString(PyExc_MemoryError, "Unable to allocate memory for colors");
        free(palette);
        fclose(file);
        return NULL;
        }
    // Read the CSV file line by line
    while (fgets(line, sizeof(line), file)) {
        if (color_count >= capacity) {
            capacity *= 2;  // Double the capacity if needed
            palette->colors = (Color *)realloc(palette->colors, capacity * sizeof(Color));
            if (!palette->colors) {
                PyErr_SetString(PyExc_MemoryError, "Memory reallocation failed");
                fclose(file);
                return NULL;
            }
        }

        // Parse the CSV line (expecting "r,g,b,h,s,v,c,m,y,k,hex,name")
        uint8_t r, g, b;
        char name[64];  // For the color name
        char hex[8];    // For the hex code
        float h, s, v, c, m, y, k;

        // Parse the fields correctly, skipping over HSV and CMYK as needed
        if (sscanf(line, "%hhu,%hhu,%hhu,%f,%f,%f,%f,%f,%f,%f,%7[^,],%63[^\n]", 
                &r, &g, &b, &h, &s, &v, &c, &m, &y, &k, hex, name) == 12) {
            // Fill in the RGB values
            palette->colors[color_count].r = r;
            palette->colors[color_count].g = g;
            palette->colors[color_count].b = b;

            // Convert RGB to HSV
            rgb_to_hsv_internal(r, g, b, &palette->colors[color_count].h, &palette->colors[color_count].s, &palette->colors[color_count].v);

            // Convert RGB to CMYK
            rgb_to_cmyk_internal(r, g, b, &palette->colors[color_count].c, &palette->colors[color_count].m, &palette->colors[color_count].y, &palette->colors[color_count].k);

            // Store the color name
            snprintf(palette->colors[color_count].name, sizeof(palette->colors[color_count].name), "%s", name);
            palette->colors[color_count].name[sizeof(palette->colors[color_count].name) - 1] = '\0';  // Ensure null-termination

            // Increment the color count
            color_count++;
        }
    }

    // Close the file
    fclose(file);

    // Set the palette size
    palette->size = color_count;

    // Return the Palette object to Python
    PyObject *palette_py = PyCapsule_New((void *)palette, "Palette", NULL);
    return palette_py;
}

static PyObject* process_image_with_palette(PyObject* self, PyObject* args) {
    const char* palette_filepath;
    float hue;
    int width, height;

    if (!PyArg_ParseTuple(args, "sfii", &palette_filepath, &hue, &width, &height)) {
        return NULL;
    }

    Palette palette;
    if (load_gimp_palette(palette_filepath, &palette) != 0) {
        return PyErr_Format(PyExc_RuntimeError, "Failed to load palette");
    }

    uint8_t* image_data = malloc(width * height * 4);
    if (!image_data) {
        return PyErr_NoMemory();
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Full saturation and value at top-left, decreasing towards bottom-right
            float saturation = (float)(height - y) / height;
            float value = (float)(width - x) / width;
            Color target_color;
            target_color.h = hue;
            target_color.s = saturation;
            target_color.v = value;

            const Color* nearest_color = find_nearest_color_hsv_internal(&target_color, &palette);

            // Fill the image data with the nearest palette color
            int index = (y * width + x) * 4;
            image_data[index] = nearest_color->r;
            image_data[index + 1] = nearest_color->g;
            image_data[index + 2] = nearest_color->b;
            image_data[index + 3] = 255;  // Alpha (fully opaque)
        }
    }

    PyObject* result = Py_BuildValue("y#", image_data, width * height * 4);
    free(image_data);
    return result;
}

// Function: Simple hello world function
static PyObject* hello(PyObject* self, PyObject* args) {
    printf("Hello, World!\n");
    Py_RETURN_NONE;
}

// Define the methods callable from Python
static PyMethodDef MyMethods[] = {
    // void convert_to_palette(const char *src_file, const char *tgt_file, const char *palette_file, const char *method, uint8_t *transparent_rgb);
    {"convert_to_palette", (PyCFunction)convert_to_palette, METH_VARARGS | METH_KEYWORDS, 
     "Convert image to palette"},

    // void convert_to_rgb565(const char *src_file, const char *tgt_file);
    {"convert_to_rgb565", (PyCFunction)convert_to_rgb565, METH_VARARGS | METH_KEYWORDS, 
     "Convert image to RGB565"},

    // void img_to_rgba2(const char *input_filepath, const char *output_filepath);
    {"img_to_rgba2", img_to_rgba2, METH_VARARGS, 
     "Convert an image to 2-bit RGBA and save to a file"},
    
    // void img_to_rgba8(const char *input_filepath, const char *output_filepath);
    {"img_to_rgba8", img_to_rgba8, METH_VARARGS, 
     "Convert an image to RGBA8 and save to a file"},
    
    // void rgba8_to_img(const char *input_filepath, const char *output_filepath, int width, int height);
    {"rgba8_to_img", rgba8_to_img, METH_VARARGS, 
     "Convert RGBA8 binary file to image"},
    
    // void rgba2_to_img(const char *input_filepath, const char *output_filepath, int width, int height);
    {"rgba2_to_img", rgba2_to_img, METH_VARARGS, 
     "Convert RGBA2 binary file to image"},

    // Converts RGB to HSV (normalized 0-1)
    // float rgb_to_hsv(uint8_t r, uint8_t g, uint8_t b, float *h, float *s, float *v);
    {"rgb_to_hsv", rgb_to_hsv, METH_VARARGS, "Convert RGB to HSV"},
    
    // Converts RGB to CMYK (normalized 0-1)
    // float rgb_to_cmyk(uint8_t r, uint8_t g, uint8_t b, float *c, float *m, float *y, float *k);
    {"rgb_to_cmyk", rgb_to_cmyk, METH_VARARGS, "Convert RGB to CMYK"},
    
    // Converts HSV to RGB
    // void hsv_to_rgb(float h, float s, float v, uint8_t *r, uint8_t *g, uint8_t *b);
    {"hsv_to_rgb", hsv_to_rgb, METH_VARARGS, "Convert HSV to RGB"},
    
    // Converts CMYK to RGB
    // void cmyk_to_rgb(float c, float m, float y, float k, uint8_t *r, uint8_t *g, uint8_t *b);
    {"cmyk_to_rgb", cmyk_to_rgb, METH_VARARGS, "Convert CMYK to RGB"},

    // Function: Find the nearest RGB color in the palette
    // const Color* find_nearest_color_rgb(const Color *target_rgb, const Palette *palette);
    {"find_nearest_color_rgb", find_nearest_color_rgb, METH_VARARGS, "Find the nearest RGB color in the palette"},

    // Function: Find the nearest HSV color in the palette
    // const Color* find_nearest_color_hsv(const Color *target_hsv, const Palette *palette);
    {"find_nearest_color_hsv", find_nearest_color_hsv, METH_VARARGS, "Find the nearest HSV color in the palette"},

    // Function: Find the nearest CMYK color in the palette
    // const Color* find_nearest_color_cmyk(const Color *target_cmyk, const Palette *palette);
    {"find_nearest_color_cmyk", find_nearest_color_cmyk, METH_VARARGS, "Find the nearest CMYK color in the palette"},

    // Function: Convert a CSV file to a Palette object
    // Palette* csv_to_palette(const char *csv_filepath);
    {"csv_to_palette", csv_to_palette, METH_VARARGS, "Convert a CSV file to a Palette object"},

    // Function: Process an image with a palette
    // uint8_t* process_image_with_palette(const char* palette_filepath, float hue, int width, int height);
    {"process_image_with_palette", process_image_with_palette, METH_VARARGS, "Process an image with a palette"},
    
    // void hello(void);
    {"hello", hello, METH_NOARGS, 
     "Print Hello World"},
    
    {NULL, NULL, 0, NULL}  // Sentinel value to indicate end of methods array
};

// Module definition
static struct PyModuleDef agonutilsmodule = {
    PyModuleDef_HEAD_INIT,
    "agonutils",  // Module name
    NULL,
    -1,
    MyMethods  // Method table
};

// Module initialization function
PyMODINIT_FUNC PyInit_agonutils(void) {
    return PyModule_Create(&agonutilsmodule);
}
