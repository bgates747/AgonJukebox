#!/bin/bash

# Function to display usage instructions
usage() {
    echo "Usage: $0 -p <project_name>"
    exit 1
}

# Parse command line arguments
while getopts ":p:" opt; do
    case ${opt} in
        p )
            PROJECT_NAME=$OPTARG
            ;;
        \? )
            echo "Invalid option: $OPTARG" 1>&2
            usage
            ;;
        : )
            echo "Invalid option: $OPTARG requires an argument" 1>&2
            usage
            ;;
    esac
done

# Check if project name is set
if [ -z "$PROJECT_NAME" ]; then
    echo "Error: Project name is required."
    usage
fi

# Check if directory already exists
if [ -d "$PROJECT_NAME" ]; then
    read -p "Directory $PROJECT_NAME already exists. Do you want to overwrite it? (y/n) " choice
    case "$choice" in 
      y|Y ) echo "Overwriting $PROJECT_NAME...";;
      n|N ) echo "Canceling..."; exit 1;;
      * ) echo "Invalid choice. Canceling..."; exit 1;;
    esac
    rm -rf "$PROJECT_NAME"
fi

# Detect the Python version
PYTHON_VERSION=$(python3 -c 'import sys; print(f"{sys.version_info.major}.{sys.version_info.minor}")')

# Create the project directory structure
echo "Creating project directory structure..."
mkdir -p $PROJECT_NAME/{src,tests,.vscode}

# Navigate into the project directory
cd $PROJECT_NAME

# Create setup.py file for building the Python C extension
cat <<EOL > setup.py
from setuptools import setup, Extension
import platform
import sys

module = Extension('$PROJECT_NAME', sources=['src/$PROJECT_NAME.c'])

setup(
    name='$PROJECT_NAME',
    version='1.0',
    description='A Python library written in C',
    ext_modules=[module],
    platforms=sys.platform,
)
EOL

# Create the C source file with a Hello World function
cat <<EOL > src/$PROJECT_NAME.c
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Function that prints Hello World and system information
static PyObject* hello(PyObject* self, PyObject* args) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    
    printf("Hello, World!\\n");
    printf("Package Name: $PROJECT_NAME\\n");
    printf("Build Time: %s", asctime(t));
    printf("Host: %s\\n", hostname);
    printf("Running on: %s\\n", Py_GetPlatform());
    printf("Python Version: %s\\n", Py_GetVersion());
    
    Py_RETURN_NONE;
}

// Method definition
static PyMethodDef MyMethods[] = {
    {"hello", hello, METH_NOARGS, "Print Hello World and system information"},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef ${PROJECT_NAME}module = {
    PyModuleDef_HEAD_INIT,
    "$PROJECT_NAME",  // Module name
    NULL,
    -1,
    MyMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_$PROJECT_NAME(void) {
    return PyModule_Create(&${PROJECT_NAME}module);
}
EOL

# Create the build_and_install.py file
cat <<EOL > build_and_install.py
import os
import shutil
import subprocess
import sys
import site

def clean_build():
    """Remove the build directory if it exists."""
    build_dir = 'build'
    if os.path.exists(build_dir):
        print(f"Cleaning {build_dir} directory...")
        shutil.rmtree(build_dir)
    else:
        print(f"{build_dir} directory not found, nothing to clean.")

def build_project():
    """Run the setup.py build command."""
    print("Building the project...")
    result = subprocess.run([sys.executable, 'setup.py', 'build'], check=True)
    if result.returncode == 0:
        print("Build successful!")
    else:
        print("Build failed!")
        sys.exit(result.returncode)

def local_install():
    """Run the setup.py install command in the virtual environment."""
    print("Installing the project in the virtual environment...")
    result = subprocess.run([sys.executable, 'setup.py', 'install'], check=True)
    if result.returncode == 0:
        print("Install successful!")
    else:
        print("Install failed!")
        sys.exit(result.returncode)

def set_pythonpath():
    """Set the PYTHONPATH to the user's local site-packages directory."""
    user_site = site.getusersitepackages()
    current_pythonpath = os.environ.get('PYTHONPATH', '')

    if user_site not in current_pythonpath:
        os.environ['PYTHONPATH'] = f"\${current_pythonpath}:\${user_site}" if current_pythonpath else user_site
        print(f"PYTHONPATH set to: \${os.environ['PYTHONPATH']}")
    else:
        print(f"PYTHONPATH already set to: \${os.environ['PYTHONPATH']}")

def test_install():
    """Test the installed package by importing it and calling a function."""
    print("Testing the installed package...")
    result = subprocess.run([sys.executable, '-c', 'import $PROJECT_NAME; $PROJECT_NAME.hello()'], check=True)
    if result.returncode == 0:
        print("Package works!")
    else:
        print("Package failed to run!")
        sys.exit(result.returncode)

if __name__ == '__main__':
    clean_build()
    build_project()
    local_install()
    set_pythonpath()
    test_install()
EOL

echo "build_and_install.py created successfully."


# Create a README file
cat <<EOL > README.md
# $PROJECT_NAME

A Python library written in C.

## Installation

To install the library:

\`\`\`bash
python setup.py install
\`\`\`

## Usage

\`\`\`python
import $PROJECT_NAME
$PROJECT_NAME.hello()
\`\`\`
EOL

# Create a basic .gitignore file
cat <<EOL > .gitignore
# Python and build artifacts
*.pyc
__pycache__/
build/
dist/
*.egg-info/
*.so
.vscode/
.venv/
EOL

# Create VS Code configuration files
echo "Creating VS Code configuration..."
cat <<EOL > .vscode/settings.json
{
    "python.defaultInterpreterPath": "\${workspaceFolder}/.venv/bin/python",
    "python.testing.unittestEnabled": true,
    "python.analysis.extraPaths": [
        "\${workspaceFolder}/.venv/lib/python$PYTHON_VERSION/site-packages"
    ]
}
EOL

cat <<EOL > .vscode/tasks.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build $PROJECT_NAME",
            "type": "shell",
            "command": "python setup.py build",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": []
        }
    ]
}
EOL

# Initialize Git repository
echo "Initializing Git repository..."
git init

# Set up a virtual environment named .venv
echo "Setting up Python virtual environment..."
python3 -m venv .venv
source .venv/bin/activate

# Install basic dependencies
echo "Installing basic dependencies..."
pip install --upgrade pip setuptools

# Create a basic test file
cat <<EOL > tests/test_$PROJECT_NAME.py
import $PROJECT_NAME

def test_hello():
    $PROJECT_NAME.hello()
    print("Hello function works!")

if __name__ == '__main__':
    $PROJECT_NAME.hello()
EOL

# Success message
echo "Project setup complete. Activate your virtual environment by running:"
echo "source .venv/bin/activate"
