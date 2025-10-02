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

void solve() {
    int n;
    cin >> n;
    
    // Use a map to count cards by their remainder
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int card;
        cin >> card;
        counts[card % 5]++;
    }

    long long total_groups = 0;

    // --- Step 1: Handle remainder 0 cards ---
    total_groups += counts[0];

    // --- Step 2: Handle simple pairs (1,4) and (2,3) ---
    // This is the section with the main bug fix
    int pairs_1_4 = min(counts[1], counts[4]);
    total_groups += pairs_1_4;
    counts[1] -= pairs_1_4;
    counts[4] -= pairs_1_4;

    int pairs_2_3 = min(counts[2], counts[3]);
    total_groups += pairs_2_3;
    counts[2] -= pairs_2_3;
    counts[3] -= pairs_2_3;
    
    // --- Step 3: Handle leftovers with a direct greedy approach ---
    
    // Groups of 3 cards
    int k = min(counts[1] / 2, counts[3]); // (1,1,3)
    total_groups += k; counts[1] -= k * 2; counts[3] -= k;

    k = min(counts[1], counts[2] / 2); // (1,2,2)
    total_groups += k; counts[1] -= k; counts[2] -= k * 2;

    k = min(counts[2], counts[4] / 2); // (2,4,4)
    total_groups += k; counts[2] -= k; counts[4] -= k * 2;
    
    k = min(counts[3] / 2, counts[4]); // (3,3,4)
    total_groups += k; counts[3] -= k * 2; counts[4] -= k;

    // Groups of 4 cards
    k = min({counts[1] / 3, counts[2]}); // (1,1,1,2)
    total_groups += k; counts[1] -= k * 3; counts[2] -= k;

    k = min({counts[1], counts[3] / 3}); // (1,3,3,3)
    total_groups += k; counts[1] -= k; counts[3] -= k * 3;

    k = min({counts[2] / 3, counts[4]}); // (2,2,2,4)
    total_groups += k; counts[2] -= k * 3; counts[4] -= k;

    k = min({counts[3], counts[4] / 3}); // (3,4,4,4)
    total_groups += k; counts[3] -= k; counts[4] -= k * 3;

    // Groups of 5 identical cards
    for (int i = 1; i <= 4; ++i) {
        total_groups += counts[i] / 5;
    }

    cout << total_groups << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
