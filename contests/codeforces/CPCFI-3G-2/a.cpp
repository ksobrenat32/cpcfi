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

	string s;
	cin >> s;

	if(n!=5){
		cout << "NO" << endl;
		return;
	}

	sort(s.begin(), s.end());

	if ( s == "Timru"){
		cout << "YES" << endl;
	} else{
		cout << "NO" << endl;
	}

	
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
