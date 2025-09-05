#include <vector>
#include <cmath>
#include <algorithm>

// Computes the rank of a matrix using Gaussian elimination.
// Time complexity: O(n*m*min(n,m)) for n x m matrix.
// Space complexity: O(n) for bookkeeping, plus O(n*m) for matrix copy.
const double EPS = 1e-9;

int rank(std::vector<std::vector<double>> matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();

    int rank = 0;
    std::vector<bool> row_selected(n, false);
    for (int i = 0; i < m; ++i) { // iterate over columns
        int j;
        for (j = 0; j < n; ++j) { // find a pivot row
            if (!row_selected[j] && std::abs(matrix[j][i]) > EPS)
                break;
        }

        if (j != n) { // pivot found in row j at column i
            rank++;
            row_selected[j] = true;

            // Use pivot at (j, i) to eliminate other rows
            for (int k = 0; k < n; ++k) {
                if (k != j) {
                    double factor = matrix[k][i] / matrix[j][i];
                    for (int p = i; p < m; ++p) {
                        matrix[k][p] -= matrix[j][p] * factor;
                    }
                }
            }
        }
    }
    return rank;
}
