import re

# Function to scan header file for prototypes
def extract_prototypes(header_file):
    prototypes = []
    pattern = re.compile(r'^[\w\s\*\(\)]+\([\w\s,\*\[\]]*\);')  # Basic pattern for function prototypes

    with open(header_file, 'r') as file:
        for line in file:
            match = pattern.match(line.strip())
            if match:
                prototypes.append(line.strip())
    
    return prototypes

# Function to find and extract implementations from code file
def extract_implementations(code_file, prototypes, temp_code_file):
    buffer = []
    code_lines = []

    with open(code_file, 'r') as file:
        code_lines = file.readlines()

    # For each prototype, find the corresponding function implementation
    for proto in prototypes:
        # Remove the trailing semicolon and strip whitespace for the flexible pattern
        proto_pattern = re.escape(proto[:-1].strip())  
        pattern = re.compile(f'{proto_pattern}\s*\{{')  # Match function signature ending with an opening brace '{'

        # Start searching for the function definition in the source file
        start_line = None
        for i, line in enumerate(code_lines):
            if pattern.search(line.strip()):
                start_line = i
                print(f"Function '{proto}' found at line {i + 1}")
                break

        if start_line is not None:
            # Now, find the end of the function based on a line containing only '}'
            for j in range(start_line, len(code_lines)):
                buffer.append(code_lines[j])

                # Match a closing brace '}' with optional ';' and no leading whitespace
                if re.match(r'^\s*\}\s*;?\s*$', code_lines[j]):
                    print(f"Function '{proto}' ends at line {j + 1}")
                    buffer.append(code_lines[j].strip())  # Strip leading whitespace before writing the closing brace
                    buffer.append('\n\n')  # Add a newline for separation
                    break

    # Write the extracted functions to a temporary file
    with open(temp_code_file, 'w') as temp_file:
        temp_file.writelines(buffer)

    print(f"Functions written to {temp_code_file}")

# Main execution flow
if __name__ == "__main__":
    header_file = 'src/agonutils.h'  # Path to the header file
    code_file = 'src/agonutils.c'    # Path to the code file
    temp_code_file = 'src/temp.c'    # Temp file to store extracted implementations

    # Extract function prototypes from header file
    prototypes = extract_prototypes(header_file)
    print(f"Extracted prototypes: {prototypes}")

    # Extract and save the corresponding implementations from the code file
    extract_implementations(code_file, prototypes, temp_code_file)
