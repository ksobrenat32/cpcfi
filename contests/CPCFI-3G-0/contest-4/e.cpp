#include <bits/stdc++.h>

using namespace std;

int main(){
    // Number of elements
    int n;
    cin>>n;

    // Array saving
    vector<long long> a(n);

    // Read integers
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    long long os=1;

    // From left to right check for continuos
    vector<long long> dpLR(n,1);
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i]){
            dpLR[i] = dpLR[i-1]+1;
        }
        os = max(os, dpLR[i]);
    }

    // From right to left check for continuos
    vector<long long> dpRL(n,1);
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            dpRL[i] = dpRL[i+1]+1;
        }
    }
    
    for(int i=0;i<n;i++){
        // Check if a previous and a next exist
        if(i-1>=0 && i+1<n){
            // Check if a integer is deleted
            if(a[i-1]<a[i+1]){
                os = max(os, dpLR[i-1] +dpRL[i+1] );
            }
        }
    }

    cout<<os<<endl;


    return 0;
}
