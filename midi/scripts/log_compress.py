import matplotlib.pyplot as plt
import numpy as np

# Constants
C = 2
r = 127 * 14
x = np.arange(-r, r)
y = (x * 127) / (np.abs(x) + C)

# Plot
plt.figure(figsize=(10, 5))
plt.plot(x, y, label=f'Compressed output (C={C})')
plt.axhline(127, color='red', linestyle='--', label='Max amplitude (127)')
plt.axhline(-127, color='red', linestyle='--')
plt.title('Log-like Compression Function')
plt.xlabel('Input Sample Value')
plt.ylabel('Output Sample Value')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
