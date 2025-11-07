#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

ull binpow(ull a, ull b, ull mod){
    ull arns = 1;
    while(b>0){
        if(b&1) arns = arns * a % mod;
        a = a*a % mod;
        b>>=1;
    }
    return arns%mod;
}

ull modInv(ull a, ull mod){
    return binpow(a,mod-2,mod);
}


inline void solve(){
    // curve is y^2 = x^3 + ax + b (mod p)
    ull a,b,p,x1,x2,y1,y2; cin>>a>>b>>p>>x1>>y1>>x2>>y2;
    
    if (x1 == x2 and (y1+y2)%p == 0) {
        cout << "POINT_AT_INFINITY"<<endl;
        return;
    }
    if(x1 == x2 and y1 == y2){
        ull s = (((3*(x1*x1%p)%p)%p + a)%p * modInv((2*y1)%p,p))%p;  
        // x3 = s^2 - 2 x1
        ull x3 = ((s*s)%p - (2*x1)%p + p)%p;
        // s(x1 - x3) - y1
        ull y3 = (s*(x1 - x3+p)%p - y1+p)%p;
        x3 = (x3 % p + p) % p;
        y3 = (y3 % p + p) % p;
        cout<<x3%p<<" "<<y3%p<<endl;
    }else{
         // s = (y1-y2)/(x1-x2)
        ull s = ((y1 - y2+p)%p * modInv((x1-x2+p)%p,p))%p;
        // x3 = s^2 -x1 -x2
        ull x3 = (((s*s)%p - x1 + p)%p - x2 + p)%p;
        // y3 = s(x1 - x3) - y1
        ull y3 = (s*(x1 - x3 + p)%p)%p - y1;
        x3 = (x3 % p + p) % p;
        y3 = (y3 % p + p) % p;
        cout<<x3%p<<" "<<y3%p<<endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}