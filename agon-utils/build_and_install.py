import os
import shutil
import subprocess
import sys

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
    """Install the project into the virtual environment."""
    print("Installing the project in the virtual environment...")
    result = subprocess.run([sys.executable, '-m', 'pip', 'install', '.', '--no-deps'], check=True)
    if result.returncode == 0:
        print("Install successful!")
    else:
        print("Install failed!")
        sys.exit(result.returncode)

def test_install():
    """Test the installed package by importing it and calling a function."""
    print("Testing the installed package...")
    try:
        import agonutils
        agonutils.hello()
        print("Package works!")
    except Exception as e:
        print("Package failed to run!")
        print(e)
        sys.exit(1)

if __name__ == '__main__':
    clean_build()
    build_project()
    local_install()
    test_install()
