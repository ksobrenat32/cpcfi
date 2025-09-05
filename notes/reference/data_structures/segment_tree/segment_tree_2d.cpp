// Implements a generic, 2D Segment Tree for point updates and range queries.
// It is built as a "tree of trees": an outer segment tree over the rows,
// where each node of the outer tree is a 1D segment tree over the columns.
//
// Time Complexity: O(log R * log C) for updates and queries.
// Space Complexity: O(R * C)

#include <vector>
#include <functional>

template<typename T, class JoinOp = std::plus<T>>
class SegmentTree2D {
private:
    const int rows, cols;
    std::vector<std::vector<T>> tree;
    JoinOp join;
    T identity_element;

    // Recursive query on an inner (column) tree
    T query_y(int vx, int vy, int tly, int try_, int y1, int y2) {
        if (y1 > y2) return identity_element;
        if (tly == y1 && try_ == y2) return tree[vx][vy];
        int tmy = tly + (try_ - tly) / 2;
        T left_res = query_y(vx, 2 * vy, tly, tmy, y1, std::min(y2, tmy));
        T right_res = query_y(vx, 2 * vy + 1, tmy + 1, try_, std::max(y1, tmy + 1), y2);
        return join(left_res, right_res);
    }

    // Recursive query on the outer (row) tree
    T query_x(int vx, int tlx, int trx, int x1, int x2, int y1, int y2) {
        if (x1 > x2) return identity_element;
        if (tlx == x1 && trx == x2) return query_y(vx, 1, 0, cols - 1, y1, y2);
        int tmx = tlx + (trx - tlx) / 2;
        T left_res = query_x(2 * vx, tlx, tmx, x1, std::min(x2, tmx), y1, y2);
        T right_res = query_x(2 * vx + 1, tmx + 1, trx, std::max(x1, tmx + 1), x2, y1, y2);
        return join(left_res, right_res);
    }

    // Recursive update on an inner (column) tree
    void update_y(int vx, int tlx, int trx, int vy, int tly, int try_, int x, int y, T new_val) {
        if (tly == try_) {
            if (tlx == trx) tree[vx][vy] = new_val;
            else tree[vx][vy] = join(tree[2 * vx][vy], tree[2 * vx + 1][vy]);
        } else {
            int tmy = tly + (try_ - tly) / 2;
            if (y <= tmy) update_y(vx, tlx, trx, 2 * vy, tly, tmy, x, y, new_val);
            else update_y(vx, tlx, trx, 2 * vy + 1, tmy + 1, try_, x, y, new_val);
            tree[vx][vy] = join(tree[vx][2 * vy], tree[vx][2 * vy + 1]);
        }
    }

    // Recursive update on the outer (row) tree
    void update_x(int vx, int tlx, int trx, int x, int y, T new_val) {
        if (tlx != trx) {
            int tmx = tlx + (trx - tlx) / 2;
            if (x <= tmx) update_x(2 * vx, tlx, tmx, x, y, new_val);
            else update_x(2 * vx + 1, tmx + 1, trx, x, y, new_val);
        }
        update_y(vx, tlx, trx, 1, 0, cols - 1, x, y, new_val);
    }

    // Recursive build on an inner (column) tree
    void build_y(int vx, int tlx, int trx, int vy, int tly, int try_, const std::vector<std::vector<T>>& arr) {
        if (tly == try_) {
            if (tlx == trx) tree[vx][vy] = arr[tlx][tly];
            else tree[vx][vy] = join(tree[2 * vx][vy], tree[2 * vx + 1][vy]);
        } else {
            int tmy = tly + (try_ - tly) / 2;
            build_y(vx, tlx, trx, 2 * vy, tly, tmy, arr);
            build_y(vx, tlx, trx, 2 * vy + 1, tmy + 1, try_, arr);
            tree[vx][vy] = join(tree[vx][2 * vy], tree[vx][2 * vy + 1]);
        }
    }

    // Recursive build on the outer (row) tree
    void build_x(int vx, int tlx, int trx, const std::vector<std::vector<T>>& arr) {
        if (tlx != trx) {
            int tmx = tlx + (trx - tlx) / 2;
            build_x(2 * vx, tlx, tmx, arr);
            build_x(2 * vx + 1, tmx + 1, trx, arr);
        }
        build_y(vx, tlx, trx, 1, 0, cols - 1, arr);
    }

public:
    SegmentTree2D(int r, int c, JoinOp op = JoinOp(), T ident = T{})
        : rows(r), cols(c), join(op), identity_element(ident) {
        tree.assign(4 * r, std::vector<T>(4 * c, identity_element));
    }

    SegmentTree2D(const std::vector<std::vector<T>>& arr, JoinOp op = JoinOp(), T ident = T{})
        : SegmentTree2D(arr.size(), arr.empty() ? 0 : arr[0].size(), op, ident) {
        if (rows > 0 && cols > 0) build_x(1, 0, rows - 1, arr);
    }

    // Query range from (x1, y1) to (x2, y2), 0-indexed and inclusive.
    T query(int x1, int y1, int x2, int y2) {
        return query_x(1, 0, rows - 1, x1, x2, y1, y2);
    }

    // Update value at (x, y) to new_val, 0-indexed.
    void update(int x, int y, T new_val) {
        update_x(1, 0, rows - 1, x, y, new_val);
    }
};
