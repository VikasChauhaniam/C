#include <iostream>
#include <vector>
#include <cmath>

// Function to compute the dot product of two vectors
double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to normalize a vector
void normalize(std::vector<double>& v) {
    double length = 0.0;
    for (double value : v) {
        length += value * value;
    }
    length = std::sqrt(length);
    
    for (double& value : v) {
        value /= length;
    }
}

// Function to perform QR decomposition using Gram-Schmidt process
void qrDecomposition(std::vector<std::vector<double>>& A,
                     std::vector<std::vector<double>>& Q,
                     std::vector<std::vector<double>>& R) {
    size_t m = A.size();
    size_t n = A[0].size();

    Q.resize(m, std::vector<double>(n, 0.0));
    R.resize(n, std::vector<double>(n, 0.0));

    for (size_t j = 0; j < n; ++j) {
        std::vector<double> v(m, 0.0);
        for (size_t i = 0; i < m; ++i) {
            v[i] = A[i][j];
        }

        for (size_t k = 0; k < j; ++k) {
            R[k][j] = dotProduct(Q[k], v);
            for (size_t i = 0; i < m; ++i) {
                v[i] -= R[k][j] * Q[k][i];
            }
        }

        normalize(v);
        for (size_t i = 0; i < m; ++i) {
            Q[j][i] = v[i];
        }
    }
}

int main() {
    // Define a matrix A
    std::vector<std::vector<double>> A = {
        {1, 2, 6},
        {0, 0, 7},
        {0, 5, 12}
    };

    std::vector<std::vector<double>> Q, R;

    // Perform QR decomposition
    qrDecomposition(A, Q, R);

    // Print the matrices Q and R
    std::cout << "Matrix Q:" << std::endl;
    for (const auto& row : Q) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix R:" << std::endl;
    for (const auto& row : R) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
