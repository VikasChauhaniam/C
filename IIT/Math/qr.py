import numpy as np

# Create a matrix A
A = np.array([[1, 2, 6],
              [0, 0, 7],
              [0, 5, 12]])

# Compute the QR decomposition
Q, R = np.linalg.qr(A)

print("Q matrix:")
print(Q)
print("\nR matrix:")
print(R)
