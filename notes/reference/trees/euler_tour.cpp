const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int in_time[MAXN], out_time[MAXN];
int timer = 0;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void euler_tour(int root) {
    stack<tuple<int, int, bool>> st;
    st.push({root, -1, false});

    while (!st.empty()) {
        auto [u, parent, visited] = st.top();
        st.pop();

        if (!visited) {
            in_time[u] = ++timer;
            st.push({u, parent, true});

            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                if (*it != parent) {
                    st.push({*it, u, false});
                }
            }
        } else {
            out_time[u] = ++timer;
        }
    }
}
