// Flood fill algorithm using Breadth-First Search (BFS) to fill a connected region in a grid.
// Time complexity: O(N * M), where N and M are the dimensions of the grid, as each cell is visited at most once.
// Space complexity: O(N * M) in the worst case for the queue.

#include <vector>
#include <queue>
#include <utility>

void bfs_flood_fill(int start_row, int start_col, char new_color, std::vector<std::vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return;
    int cols = grid[0].size();

    if (start_row < 0 || start_row >= rows || start_col < 0 || start_col >= cols) return;

    char original_color = grid[start_row][start_col];
    if (original_color == new_color) return;

    std::queue<std::pair<int, int>> q;
    q.push({start_row, start_col});
    grid[start_row][start_col] = new_color;

    int dr[] = {-1, 1, 0, 0}; // Change in row for up, down
    int dc[] = {0, 0, -1, 1}; // Change in col for left, right

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int next_row = current.first + dr[i];
            int next_col = current.second + dc[i];

            if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols &&
                grid[next_row][next_col] == original_color) {
                grid[next_row][next_col] = new_color;
                q.push({next_row, next_col});
            }
        }
    }
}
