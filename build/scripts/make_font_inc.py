import os

# Dictionary of names for non-printable characters
NON_PRINTABLE_NAMES = {
    0x00: "NULL",
    0x01: "START_OF_HEADING",
    0x02: "START_OF_TEXT",
    0x03: "END_OF_TEXT",
    0x04: "END_OF_TRANSMISSION",
    0x05: "ENQUIRY",
    0x06: "ACKNOWLEDGE",
    0x07: "BELL",
    0x08: "BACKSPACE",
    0x09: "HORIZONTAL_TAB",
    0x0A: "LINE_FEED",
    0x0B: "VERTICAL_TAB",
    0x0C: "FORM_FEED",
    0x0D: "CARRIAGE_RETURN",
    0x0E: "SHIFT_OUT",
    0x0F: "SHIFT_IN",
    0x10: "DATA_LINK_ESCAPE",
    0x11: "DEVICE_CONTROL_1",
    0x12: "DEVICE_CONTROL_2",
    0x13: "DEVICE_CONTROL_3",
    0x14: "DEVICE_CONTROL_4",
    0x15: "NEGATIVE_ACKNOWLEDGE",
    0x16: "SYNCHRONOUS_IDLE",
    0x17: "END_OF_TRANSMISSION_BLOCK",
    0x18: "CANCEL",
    0x19: "END_OF_MEDIUM",
    0x1A: "SUBSTITUTE",
    0x1B: "ESCAPE",
    0x1C: "FILE_SEPARATOR",
    0x1D: "GROUP_SEPARATOR",
    0x1E: "RECORD_SEPARATOR",
    0x1F: "UNIT_SEPARATOR",
    0x7F: "DELETE"
}

def generate_asm(input_font_path, output_font_path, width, height):
    """Generates an assembly file from a font file."""
    with open(input_font_path, 'rb') as f:
        font_data = f.read()

    # Ensure that the font data length is correct based on width and height
    expected_length = width * height * 256 // 8
    if len(font_data) != expected_length:
        raise ValueError(f"Font file size mismatch: expected {expected_length} bytes, got {len(font_data)} bytes")

    # Create the output directory if it doesn't exist
    os.makedirs(os.path.dirname(output_font_path), exist_ok=True)

    with open(output_font_path, 'w') as out_file:
        for i in range(0, len(font_data), width):
            # Get the next character's bitmap data
            char_data = font_data[i:i + width]
            char_code = i // width  # Assuming the character codes are sequential starting from 0

            # Check if the character is printable, otherwise use a name from the dictionary
            if 32 <= char_code <= 126:
                char_name = chr(char_code)  # Printable characters
            else:
                char_name = NON_PRINTABLE_NAMES.get(char_code, f"NON_PRINTABLE_{char_code}")

            # Write the character header
            out_file.write(f"; {char_code} {char_name}\n")

            # Write each row of the character's bitmap data
            for byte in char_data:
                out_file.write(f"    db %{byte:08b}\n")

            out_file.write("\n")  # Add a blank line between characters

    print(f"Assembly file has been generated: {output_font_path}")

# Example usage:
if __name__ == "__main__":
    # Input parameters: font file path, output file path, width, and height
    input_path = 'src/fonts/Lat2-VGA8_8x8.font'  # Input font file
    output_path = 'src/fonts/Lat2-VGA8_8x8.font.inc'  # Output assembly file
    width = 8  # Character width
    height = 8  # Character height

    generate_asm(input_path, output_path, width, height)
