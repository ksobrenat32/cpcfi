#include <vector>
#include <cmath>
#include <algorithm>

// Calculates matrix determinant via Gaussian elimination with partial pivoting.
// Time: O(n^3), Space: O(1) (modifies matrix in-place)
double determinant(std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    double det = 1.0;
    const double EPS = 1e-9;

    for (int i = 0; i < n; ++i) {
        int pivot_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(matrix[j][i]) > std::abs(matrix[pivot_row][i])) {
                pivot_row = j;
            }
        }

        if (std::abs(matrix[pivot_row][i]) < EPS) return 0.0;

        if (pivot_row != i) {
            std::swap(matrix[i], matrix[pivot_row]);
            det *= -1.0;
        }

        det *= matrix[i][i];

        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; ++k) {
                matrix[j][k] -= matrix[i][k] * factor;
            }
        }
    }
    return det;
}
