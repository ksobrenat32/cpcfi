/**
 * @brief Builds a Cartesian Tree from an array.
 *
 * A Cartesian tree is a binary tree derived from a sequence of numbers.
 * It has two key properties:
 * 1. Min-Heap Property: The value of a node is less than or equal to the
 *    values of its children.
 * 2. In-order Traversal: An in-order traversal of the tree yields the
 *    original sequence.
 *
 * This implementation uses a stack-based approach to construct the tree in
 * a single pass, which is highly efficient. The resulting tree is represented
 * by a `parent` array, where `parent[i]` is the parent of node `i`. The root's
 * parent is -1.
 *
 * @param A The input array of values.
 * @return A vector representing the parent of each node in the Cartesian tree.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
vector<int> build_cartesian_tree(const vector<int>& A) {
    int n = A.size();
    vector<int> parent(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (!s.empty() && A[s.top()] >= A[i]) {
            last = s.top();
            s.pop();
        }
        if (!s.empty())
            parent[i] = s.top();
        if (last >= 0)
            parent[last] = i;
        s.push(i);
    }
    return parent;
}
