// Solves the "lava maze" problem: find the shortest path for a player to an exit on a grid
// while escaping a spreading substance (e.g., lava from monster 'M').
// This is solved using two separate Breadth-First Searches (BFS).
// 1. A multi-source BFS is run from all initial lava sources ('M') to calculate the time it takes for lava to reach each cell.
// 2. A single-source BFS is run for the player ('A'). A move is valid only if the player can reach a cell
//    strictly before the lava does.
// Time complexity: O(N * M), where N and M are the dimensions of the grid, as each cell is visited a constant number of times.
// Space complexity: O(N * M) for storing the grid, distances, and queues.

#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

const int INF_TIME = 1e9;

struct MazeResult {
    bool is_possible;
    std::string path;
};

struct Cell {
    int row, col;
};

MazeResult solve_lava_maze(const std::vector<std::string>& maze) {
    int rows = maze.size();
    if (rows == 0) return {false, ""};
    int cols = maze[0].size();

    auto is_valid = [&](int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols && maze[r][c] != '#';
    };

    // --- Step 1: Lava BFS to calculate lava arrival times ---
    std::vector<std::vector<int>> lava_time(rows, std::vector<int>(cols, INF_TIME));
    std::queue<Cell> q_lava;
    Cell start_pos;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (maze[r][c] == 'M') {
                q_lava.push({r, c});
                lava_time[r][c] = 0;
            }
            if (maze[r][c] == 'A') {
                start_pos = {r, c};
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char move_chars[] = {'U', 'D', 'L', 'R'};

    while (!q_lava.empty()) {
        Cell u = q_lava.front();
        q_lava.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = u.row + dr[i];
            int nc = u.col + dc[i];
            if (is_valid(nr, nc) && lava_time[nr][nc] == INF_TIME) {
                lava_time[nr][nc] = lava_time[u.row][u.col] + 1;
                q_lava.push({nr, nc});
            }
        }
    }

    // --- Step 2: Player BFS to find the shortest valid path ---
    std::vector<std::vector<int>> player_time(rows, std::vector<int>(cols, INF_TIME));
    std::vector<std::vector<Cell>> predecessor(rows, std::vector<Cell>(cols, {-1, -1}));
    std::queue<Cell> q_player;
    Cell exit_pos = {-1, -1};

    if (is_valid(start_pos.row, start_pos.col) && 0 < lava_time[start_pos.row][start_pos.col]) {
        player_time[start_pos.row][start_pos.col] = 0;
        q_player.push(start_pos);
    }

    while (!q_player.empty()) {
        Cell u = q_player.front();
        q_player.pop();

        if (u.row == 0 || u.row == rows - 1 || u.col == 0 || u.col == cols - 1) {
            exit_pos = u;
            break; // Found the shortest path to a border cell.
        }

        for (int i = 0; i < 4; ++i) {
            int nr = u.row + dr[i];
            int nc = u.col + dc[i];
            int next_player_time = player_time[u.row][u.col] + 1;

            if (is_valid(nr, nc) && player_time[nr][nc] == INF_TIME && next_player_time < lava_time[nr][nc]) {
                player_time[nr][nc] = next_player_time;
                predecessor[nr][nc] = u;
                q_player.push({nr, nc});
            }
        }
    }

    // --- Step 3: Reconstruct the path from exit to start ---
    if (exit_pos.row == -1) {
        return {false, ""}; // No path to an exit was found.
    }

    std::string path_str = "";
    Cell current = exit_pos;
    while (current.row != start_pos.row || current.col != start_pos.col) {
        Cell pred = predecessor[current.row][current.col];
        if (pred.row == current.row + 1) path_str += 'U';
        else if (pred.row == current.row - 1) path_str += 'D';
        else if (pred.col == current.col + 1) path_str += 'L';
        else if (pred.col == current.col - 1) path_str += 'R';
        current = pred;
    }
    std::reverse(path_str.begin(), path_str.end());

    return {true, path_str};
}
