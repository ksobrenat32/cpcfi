// Time limit exceeded

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long n; cin >> n;
    vector<string> good(n);

    FO(i,n){
        cin >> good[i];
    }

    long g; cin >> g;

    FO(i,g){
        string tmp;
        cin >> tmp;
        int cnt=0;
        size_t qm = tmp.find('?');

        // coffee
        if(qm != string::npos){
            // One coffee mark
            if(tmp.substr(qm+1).find('?') == string::npos){
                size_t pos = qm;
                string tr1 = tmp.substr(0,pos);
                string tr2 = tmp.substr(pos+1);
 
                FO(j,n){
                    if( tr1 == good[j].substr(0,pos)){
                        if( tr2 == good[j].substr(pos+1)){
                            cnt++;
                        }
                    }
                }               
            } else {
                size_t pos1=qm,pos2;
                // Before first mark
                string tr1 = tmp.substr(0,pos1);
                string trtmp = tmp.substr(pos1+1);
                pos2 = trtmp.find('?');
                // Middle
                string tr2 = trtmp.substr(0,pos2);
                // Back
                string tr3 = trtmp.substr(pos2+1);

                FO(j,n){
                    if( tr1 == good[j].substr(0,pos1)){
                        if( tr2 == good[j].substr(pos1+1,pos2)){
                            if( tr3 == good[j].substr(pos1+pos2+2)){
                            cnt++;
                            }
                        }
                    }
                }
 
            }

        } else {
        // juice
            size_t pos = tmp.find('*');
            string tr1 = tmp.substr(0,pos);
            string tr2 = tmp.substr(pos+1);
            int tr2Size = tr2.size();
            size_t sz = good[0].size();

            FO(j,n){
                if( tr1 == good[j].substr(0,pos) && tr2 == good[j].substr(sz-tr2Size)){
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
