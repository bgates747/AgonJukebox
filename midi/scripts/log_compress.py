import matplotlib.pyplot as plt
import numpy as np

def old_log_compress(x, A, B, C):
    """Old version: early division loses precision"""
    s = x / A
    y = np.sign(s) * ((np.abs(s) * 127) / (np.abs(s) + C)) * (B / 127)
    return y

def new_log_compress(x, A, B, C):
    """New version: defers division for better precision"""
    abs_x = np.abs(x)
    y = (abs_x * 127) / (abs_x + A * C)
    y *= np.sign(x)
    y = y * B / 127
    return y

def plot_compression(func, A, B, C, label):
    r = 128 * A * 2
    x = np.arange(-r, r)
    y = func(x, A, B, C)
    s = x / A
    y_input = np.clip(s, -127, 127)

    plt.figure(figsize=(10, 5))
    plt.plot(x, y, label=label)
    plt.plot(x, y_input, '--', color='gray', label='Input level normalized and clamped to ±127')
    plt.title('Log-like Compression Function')
    plt.xlabel('Raw Input Sample Value')
    plt.ylabel('Output Sample Value')
    plt.yticks(np.arange(-128, 129, 32))
    plt.xticks(np.arange(-r, r + 1, 32 * A))
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    # Parameters
    A = 1   # Normalization factor
    B = 128+32  # Makeup gain (127 = unity)
    C = 32   # Compression curve shaping constant

    # Choose which function to visualize
    use_new = True  # Set to False to view the old version

    if use_new:
        plot_compression(new_log_compress, A, B, C, f'New log_compress (A={A}, B={B}, C={C})')
    else:
        plot_compression(old_log_compress, A, B, C, f'Old log_compress (A={A}, B={B}, C={C})')
