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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/Laberinto-Numerico

inline void solve(){
    int N,M; cin >> N >> M;
    int X,Y; cin >> X >> Y;
    int steps;
    vector<vi> v(N,vi(M));

    FO(i,N){
        FO(j,M){
            cin >> v[i][j];
        }
    }

    // Solve it with a bfs
    vector<vi> visited(N,vi(M,0));
    queue<pii> q;
    queue<int> cnt;

    q.push(mp(X-1,Y-1));
    cnt.push(0);

    while(!q.empty()){
        X = q.front().first;
        Y = q.front().second;
        q.pop();
        steps = cnt.front();
        cnt.pop();
        visited[X][Y] = 1;


        // --- Identify if it is a wall, to exit
        // Open wall to the left
        if(Y == 0 && (v[X][Y] & 1) == 0){
            cout << steps << endl;
            return;
        }
        // Open wall to the up
        if(X == 0 && (v[X][Y] & 2) == 0){
            cout << steps << endl;
            return;
        }
        // Open wall to the right
        if(Y == M-1 && (v[X][Y] & 4) == 0){
            cout << steps << endl;
            return;
        }
        // Open wall to the down
        if(X == N-1 && (v[X][Y] & 8) == 0){
            cout << steps << endl;
            return;
        }

        // --- Try to move to the next cell
        // For the left
        if(Y > 0 && (v[X][Y] & 1) == 0 && visited[X][Y-1] == 0){
            q.push(mp(X,Y-1));
            cnt.push(steps+1);
        }
        // For the up
        if(X > 0 && (v[X][Y] & 2) == 0 && visited[X-1][Y] == 0){
            q.push(mp(X-1,Y));
            cnt.push(steps+1);
        }
        // For the right
        if(Y < M-1 && (v[X][Y] & 4) == 0 && visited[X][Y+1] == 0){
            q.push(mp(X,Y+1));
            cnt.push(steps+1);
        }
        // For the down
        if(X < N-1 && (v[X][Y] & 8) == 0 && visited[X+1][Y] == 0){
            q.push(mp(X+1,Y));
            cnt.push(steps+1);
        }

    }
    cout << -1 << endl;
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