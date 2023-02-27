#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    int n,m,t,i,j,sum;

    cin>>n;
    unordered_set<int> arrA;
    for(i=0;i<n;i++){
        cin>>t;
        arrA.insert(t);
    }

    cin>>m;
    unordered_set<int> arrB;
    for(i=0;i<m;i++){
        cin>>t;
        arrB.insert(t);
    }

    for (int a : arrA) {
        for (int b : arrB) {
            if (arrA.find(a + b) == arrA.end() && arrB.find(a + b) == arrB.end()) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    return 0;
}
