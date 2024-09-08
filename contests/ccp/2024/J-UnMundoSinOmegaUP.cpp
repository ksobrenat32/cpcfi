#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& v : (arr))
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end()
#define sz(x)                       (int) x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/Un-mundo-sin-omegaUp-2

inline void solve(){
    int n;
    cin >> n;

    string name;
    char problem_id;
    int p;

    map<string, map<char,int>> points;

    FO(i,n){
        string s;
        cin >> s >> problem_id >> p;
        points[s][problem_id] = p;
    }

    // Get the names of each participant with the points
    map<int,vector<string>> participants;
    for( auto p : points){
        int total = 0;
        for(auto q : p.second){
            total += q.second;
        }
        participants[total].push_back(p.first);
        //cout << p.first << " " << total << endl;
    }

    deque<string> ordered_winners;

    // Get the first 4 participants
    int i = 0;
    for(auto point : participants){
        vector<string> winners;
        for(auto name : point.second){
            winners.push_back(name);
            i++;
            if(i == 4) break;
        }
        sort(all(winners));
        reverse(all(winners));

        FO(j,sz(winners)){
            ordered_winners.push_front(winners[j]);
        }
    }

    // Print the winners
    for(auto name : ordered_winners){
        cout << name << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
