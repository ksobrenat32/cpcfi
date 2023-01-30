#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int p,n;
    cin>>p>>n;

    unordered_map<int, long long> ht;
    vector<int> e;

    for(int i=0;i<n;i++){
        long long x;
        cin>>x;

        if(ht.find(x%p) != ht.end()){
            cout<<i+1<<endl;
            return 0;
        } else {
            ht[x%p] = x;
        }

    }

    cout<<-1<<endl;

    return 0;
}
