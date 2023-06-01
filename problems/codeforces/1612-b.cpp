// Problem link:
// https://codeforces.com/problemset/problem/1612/b

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n,a,b;
    cin >> n >> a >> b;

    // Imposible
    if( a <= (n/2) && b <= (n/2) ){
        cout << -1 << endl;
        return;
    }
    if( a > (n/2) && b > (n/2) ){
        cout << -1 << endl;
        return;
    }
    if(a > (n/2)+1 || b < (n/2)){
        cout << -1 << endl;
        return;
    }

    vector<int> left;
    left.push_back(a);
    vector<int> right;
    right.push_back(b);

    size_t maxsize = n/2;

    for(int i = 1; i <= n; i++){
        if(i == a || i == b){
            continue;
        }
        if(i < b && right.size() < maxsize){
            right.push_back(i);
            continue;
        }
        if(i > a && left.size() < maxsize){
            left.push_back(i);
        }
    }

    for(int i = 0; i < n/2; i++){
        cout << left[i] << " ";
    }
    for(int i = 0; i < n/2; i++){
        cout << right[i] << " ";
    }

    cout << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
