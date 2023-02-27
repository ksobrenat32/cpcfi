// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/429433/problem/0

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
	int n;
	cin >> n;

	string s1,s2;
	cin >> s1;
	cin >> s2;

	FO(i,n){
		if ( s1[i] != s2[i]){
			if ( s1[i] == 'G' && s2[i] == 'B' ){
				s1[i] = 'B';
				s2[i] = 'B';
			}
			if ( s1[i] == 'B' && s2[i] == 'G' ){
				s1[i] = 'B';
				s2[i] = 'B';
			}
		}
	}


	if ( s1 == s2){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(){
    int T=0;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
