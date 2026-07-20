def format_ascii_art_for_assembly(ascii_art):
    """
    Formats ASCII art for assembly programs by:
    - Converting each character to its ASCII value
    - Adding ASCII values for `\r` and `\n` at the end of each line
    - Outputting as `db` statements with comma-separated values
    """
    formatted_lines = []
    for line in ascii_art.splitlines():
        # Convert each character to its ASCII value
        ascii_values = [ord(char) for char in line.rstrip()]
        # Add \r (13) and \n (10) terminators
        ascii_values.extend([13, 10])
        # Format as a db statement
        formatted_line = f"    db {','.join(map(str, ascii_values))}"
        formatted_lines.append(formatted_line)
    return "\n".join(formatted_lines)

if __name__ == "__main__":
    axcii_art_file = 'build/scripts/ascii.txt'

    # Read the ASCII art from a file
    with open(axcii_art_file, 'r') as file:
        ascii_art = file.read()
        
    # Process the ASCII art
    formatted_output = format_ascii_art_for_assembly(ascii_art)

    # # Print the result
    # print(formatted_output)

    # Save the formatted output to a file
    output_file_path = 'src/asm/ascii.inc'
    with open(output_file_path, 'w') as output_file:
        output_file.write("agon_jukebox_ascii:\n")
        output_file.write(formatted_output)