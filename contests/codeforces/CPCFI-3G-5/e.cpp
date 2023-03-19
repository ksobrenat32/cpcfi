// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/433780/problem/E

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;

    vector<int> a(n);
    vector<int> t(n);

    // Zero count
    long long zerocnt=0;
    long long solu[3];

    // Original
    FO(i,n){
        cin >> a[i];
        if(a[i] == 0){
            zerocnt++;
        }
    }

    long long lzrcnt;
    long long cnt;

    // Point counts

    // Check normal
    t = a;
    lzrcnt=0;
    cnt=0;
    FO(i,n){
        if(t[i] == 0){
            lzrcnt++;
        }
        if(t[i] == 1){
            cnt += zerocnt-lzrcnt;
        }
    }
    solu[0] = cnt;

    // Zero fliped
    t = a;
    FO(i,n){
        if(t[i] == 0){
            t[i] = 1;
            break;
        }
    }
    lzrcnt=0;
    cnt=0;
    FO(i,n){
        if(t[i] == 0){
            lzrcnt++;
        }
        if(t[i] == 1){
            cnt += (zerocnt-1) -lzrcnt;
        }
    }
    solu[1] = cnt;

    // one flip
    t = a;
    for(int i = n-1; i >=0; i--){
        if(t[i] == 1){
            t[i] = 0;
            break;
        }
    }
    lzrcnt=0;
    cnt=0;
    FO(i,n){
        if(t[i] == 0){
            lzrcnt++;
        }
        if(t[i] == 1){
            cnt += (zerocnt+1)-lzrcnt;
        }
    }
    solu[2] = cnt;

    cout << max(max(solu[0],solu[1]),solu[2]) << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}