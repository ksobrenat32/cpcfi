#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX = 1e5+3;

void solve(){
    int n,x; cin>>n>>x;
    vector<int> amplitudes(n);
    for(int &u: amplitudes) cin>>u;
    long double sum = 0;
    // Obtain k
    for(int i=0; i<n; i++){
        sum+=amplitudes[i]*amplitudes[i];
    }
    long double k = sqrt((x*n)/sum);

    long double t1;
    long double answer = 0;

    if(sum == 0 or x == 0){
        for(int i=0; i<n; i++)
            cout<<"0 ";
        cout<<endl;
    } else {
        for(int i=0; i<n; i++){
            t1 = amplitudes[i]*k;
            cout<<setprecision(10)<<amplitudes[i]*k<<" ";
            answer += t1*t1;
        }
        cout<<endl;
    }



    answer /= n;
    if (answer == x){
        cout<<"YES"<<endl;
    }else{
        cout << setprecision(10) << answer - x << endl;
        cout << setprecision(10) << answer << endl;
        cout<<"NO"<<endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		// cout << "Case #" << t << ": ";
		solve();
	}
}