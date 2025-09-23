// Flood fill algorithm using Depth First Search (DFS) to fill a connected region in a grid.
// This is a recursive implementation.
// Time complexity: O(N * M), where N and M are the dimensions of the grid, as each cell is visited at most once.
// Space complexity: O(N * M) in the worst case for the recursion stack (e.g., a long, snake-like path).

#include <vector>

// Helper function for the recursive DFS traversal.
void dfs_flood_fill_recursive(int row, int col, char new_color, char original_color, std::vector<std::vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Base cases for recursion: check for out-of-bounds or if the cell is not of the original color.
    if (row < 0 || row >= rows || col < 0 || col >= cols ||
        grid[row][col] != original_color) {
        return;
    }

    // Change the color of the current cell.
    grid[row][col] = new_color;

    // Recursive calls for all 4 neighbors.
    dfs_flood_fill_recursive(row + 1, col, new_color, original_color, grid);
    dfs_flood_fill_recursive(row - 1, col, new_color, original_color, grid);
    dfs_flood_fill_recursive(row, col + 1, new_color, original_color, grid);
    dfs_flood_fill_recursive(row, col - 1, new_color, original_color, grid);
}

// Main function to initiate the flood fill.
void dfs_flood_fill(int start_row, int start_col, char new_color, std::vector<std::vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return;
    int cols = grid[0].size();

    if (start_row < 0 || start_row >= rows || start_col < 0 || start_col >= cols) return;

    char original_color = grid[start_row][start_col];

    // No need to fill if the starting cell already has the new color.
    if (original_color == new_color) {
        return;
    }

    dfs_flood_fill_recursive(start_row, start_col, new_color, original_color, grid);
}
