#include <bits/stdc++.h>

using namespace std;

int main(){

    int i,n,c=0,x;
    cin>>n;
    priority_queue<int> q;
    map<int,int> ind;
    vector<long long> v(n);
    string s;

    for(i=0; i<n; i++){
        cin>>v[i];
        ind[v[i]]=i+1;
    }

    sort(v.begin(),v.end());
    cin>>s;
    for(i=0; i<2*n; i++){
        if(s[i]=='0'){
            cout<<ind[v[c]]<<endl;
            q.push(v[c]);
            c++;
        }else if(s[i]=='1'){
            x=q.top(); 
            cout<<ind[x]<<endl;
            q.pop();
        }
    }

    return 0;
}
