#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;

inline void solve() {
    string s; cin >> s;
    // target = "112012"
    // states: 012345
    
    int n = sz(s);
    int k = n / 6;

    vector<vector<int>> solutions(k);
    
    queue<int> state_queues[6];

    FO(i, k) {
        state_queues[0].push(i);
    }

    // Process the string in O(n)
    FO(i, n) {
        char c = s[i];
        int found_state = -1;

        if (c == '1') {
            if (!state_queues[0].empty()) found_state = 0;
            else if (!state_queues[1].empty()) found_state = 1;
            else if (!state_queues[4].empty()) found_state = 4;
        } else if (c == '2') {
            if (!state_queues[2].empty()) found_state = 2;
            else if (!state_queues[5].empty()) found_state = 5;
        } else { // c == '0'
            if (!state_queues[3].empty()) found_state = 3;
        }
        
        int builder_id = state_queues[found_state].front();
        state_queues[found_state].pop();

        solutions[builder_id].push_back(i + 1);

        int next_state = found_state + 1;
        if (next_state < 6) {
            state_queues[next_state].push(builder_id);
        }
    }

    FO(i, k) {
        FO(j, 6) {
            cout << solutions[i][j] << (j == 5 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    FO(tc, T) {
        solve();
    }
    return 0;
}
