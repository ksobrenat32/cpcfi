#include<bits/stdc++.h>
using namespace std;

// By israel5468

int FactoresPrimos(int n)
{

    while (n % 2 == 0)
    {
        n = n / 2;
    }
    int result2 = 0;
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n%i == 0)
        {
            result2++;
            n = n / i;
        }
    }
   if (n > 2)
        result2++;
   return result2;
}


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin>>n;
        if(n==1){
            cout<<"FastestFinger" << endl;
            continue;
        }
        if(n%2==1){
            cout<<"Ashishgup"<< endl;
            continue;
        }
        if(n==2){
            cout<<"Ashishgup"<< endl;
            continue;
        }
        int pares = 0,num=0;
        int impares = FactoresPrimos(n);
        while(n%2==0){
            n/=2;
            num++;
        }
        if(impares==0)
        {
            cout<<"FastestFinger"<< endl;
        }
        else if(num>1)
        {
        cout<<"Ashishgup"<< endl;
        }
        else if(impares==1)
        {
         cout<<"FastestFinger"<< endl;
        }
        else 
        {
        cout<<"Ashishgup"<< endl;
        }
    }
}