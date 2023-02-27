// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/429433/problem/C

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin >> n;

    int sa=0,sb=0,sc=0;

    unordered_map<string, int> m;

    string s;

    // First player
    FO(i,n){
        cin >> s;
        // Mark the word as used once
        m[s]=1;
        // Plus three points
        sa+=3;
    }

    // Second player
    FO(i,n){
        cin >> s;
        // If the word was already used
        if(m[s]==1){
            // Minus two point to player a
            sa-=2;
            // Plus one point player b
            sb+=1;
            // Mark as 3 so both player a and b have the word
            m[s]=3;
        } else {
            // Mark the word as used by player b
            m[s]=2;
            // Plus three points to player b
            sb+=3;
        }
    }

    // Third player
    FO(i,n){
        cin >> s;
        // If the word was already used my player a
        if(m[s]==1){
            // Minus two point to player a
            sa-=2;
            // Plus one point player c
            sc+=1;
        // If the word was already used my player b
        } else if(m[s]==2){
            // Minus two point to player b
            sb-=2;
            // Plus one point player c
            sc+=1;
        // If the word was already used my players a and b
        } else if(m[s]==3){
            // Minus one point to player a
            sa-=1;
            // Minus one point to player b
            sb-=1;
        } else {
            // Plus three points to player c
            sc+=3;
        }
    }

    // Print scores
    cout << sa << " " << sb << " " << sc << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}