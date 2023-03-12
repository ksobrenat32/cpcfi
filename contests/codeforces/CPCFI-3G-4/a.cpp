// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/431889/problem/A 

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin >> n;

    int put=0;
    int del=0;

    vector<int> b(n);

    FO(i,n){
        cin >> b[i];
        if(b[i] > 0){
            put++;
        } else {
            del++;
        }
 
    }

    // imprimir max
    int cntMax=0;

    for(int i = 0; i < put ; i++){
        cntMax++;
        cout << cntMax << " ";
    }

    for(int i = 0; i < del ; i++){
        cntMax--;
        cout << cntMax << " ";
    }
    cout << endl;

    // imprimir min
    int cnt = 0,diff = abs(put-del);

    for(int i = 0 ; i < min(put,del) ; i++){
        cout << 1 << " " << 0 << " ";
    }
    FO(i,diff){
        cnt++;
        cout << cnt << " ";
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
