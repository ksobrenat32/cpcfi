// Solves the assignment problem (minimum weight bipartite matching) using the Hungarian algorithm.
// Assumes a square cost matrix.
// Time Complexity: O(N^3)
// Space Complexity: O(N^2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Hungarian {
    int n;
    vector<vector<long long>> cost_matrix;
    vector<long long> label_x, label_y, slack;
    vector<int> match_y, parent_x;
    vector<bool> S, T;

    Hungarian(const vector<vector<long long>>& costs) : n(costs.size()), cost_matrix(costs) {
        label_x.assign(n, 0);
        label_y.assign(n, 0);
        slack.assign(n, 0);
        match_y.assign(n, -1);
        parent_x.assign(n, 0);
        S.assign(n, false);
        T.assign(n, false);
    }

    void augment(int root) {
        fill(S.begin(), S.end(), false);
        fill(T.begin(), T.end(), false);
        fill(parent_x.begin(), parent_x.end(), -1);

        S[root] = true;
        parent_x[root] = -2;

        for (int y = 0; y < n; ++y) {
            slack[y] = label_x[root] + label_y[y] - cost_matrix[root][y];
            parent_x[y] = root;
        }

        while (true) {
            int y = -1;
            long long min_slack = INF;
            for (int j = 0; j < n; ++j) {
                if (!T[j] && slack[j] < min_slack) {
                    min_slack = slack[j];
                    y = j;
                }
            }

            if (min_slack > 0) {
                for (int i = 0; i < n; ++i) if (S[i]) label_x[i] -= min_slack;
                for (int j = 0; j < n; ++j) if (T[j]) label_y[j] += min_slack;
                for (int j = 0; j < n; ++j) if (!T[j]) slack[j] -= min_slack;
            }

            T[y] = true;
            int x = match_y[y];

            if (x == -1) { // Augmenting path found
                while (y != -1) {
                    int prev_x = parent_x[y];
                    int prev_y = match_y[prev_x];
                    match_y[y] = prev_x;
                    y = prev_y;
                }
                return;
            }

            S[x] = true;
            for (int j = 0; j < n; ++j) {
                if (!T[j]) {
                    long long new_slack = label_x[x] + label_y[j] - cost_matrix[x][j];
                    if (slack[j] > new_slack) {
                        slack[j] = new_slack;
                        parent_x[j] = x;
                    }
                }
            }
        }
    }

    pair<long long, vector<int>> solve() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                label_x[i] = max(label_x[i], cost_matrix[i][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            augment(i);
        }

        long long total_cost = 0;
        vector<int> assignment(n);
        for (int y = 0; y < n; ++y) {
            int x = match_y[y];
            assignment[x] = y;
            total_cost += cost_matrix[x][y];
        }

        // This implementation finds max weight matching. To find min cost, negate costs.
        // The user should provide a negated cost matrix for min cost problems.

        return {total_cost, assignment};
    }
};
