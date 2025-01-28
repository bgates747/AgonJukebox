from setuptools import setup, Extension
import platform
import sys
import subprocess

# Use pkg-config to get the necessary compiler and linker flags for libpng
def get_libpng_flags():
    try:
        # Get include directory and library linking flags
        cflags = subprocess.check_output(['pkg-config', '--cflags', 'libpng']).decode().strip().split()
        libs = subprocess.check_output(['pkg-config', '--libs', 'libpng']).decode().strip().split()
        return cflags, libs
    except subprocess.CalledProcessError:
        print("Error: Could not find libpng via pkg-config.")
        sys.exit(1)

# Get libpng compiler and linker flags
cflags, libs = get_libpng_flags()

# Define the extension module
module = Extension(
    'agonutils',
    sources=['src/agonutils.c'],
    extra_compile_args=cflags,  # Include libpng's compiler flags
    extra_link_args=libs,       # Include libpng's linker flags
)

# Setup definition
setup(
    name='agonutils',
    version='1.0',
    description='A Python library written in C with libpng support',
    ext_modules=[module],
    platforms=sys.platform,
)
