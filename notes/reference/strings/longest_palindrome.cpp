typedef long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const int MAX=1e6+3;
vector<int> lps(2*MAX);
int n;
string s;

//ascii https://elcodigoascii.com.ar/

void show(int idx)
{
    int start=(idx-lps[idx])/2;
    int end=start+lps[idx];
    for(int i=start;i<end;i++){
        cout<<s[i];
    }

}

inline void solve()
{
    cin>>s;
    n=s.size();
    lps[0]=0;
    lps[1]=1;
    int rightCenter,leftCenter,center,curRightCenter,curLeftCenter;
    center=1;
    rightCenter=center+lps[center];
    leftCenter=center-lps[center];
    int maxLPScenter=1;
    int diff=-1;
    bool exp;
    for(curRightCenter=2;curRightCenter<2*n+1;curRightCenter++)
    {
        //Condicion de cambio de centro
        curLeftCenter=2*center-curRightCenter;
        diff=rightCenter-curRightCenter;
        exp=false;
        if(diff>=0){
            if(lps[curLeftCenter]<diff){
                lps[curRightCenter]=lps[curLeftCenter];
            }
            else if(lps[curLeftCenter]==diff && rightCenter==2*n)
            {
                lps[curRightCenter]=lps[curLeftCenter];
            }
            else if(lps[curLeftCenter]==diff && rightCenter<2*n){
                lps[curRightCenter]=lps[curLeftCenter];
                exp=true;
            }
            else if(lps[curLeftCenter]>diff){
                lps[curRightCenter]=diff;
                exp=true;
            }
        }
        else{
            lps[curRightCenter]=0;
            exp=true;
        }
        if(exp)
        {
            while(((curRightCenter+lps[curRightCenter])<2*n && curRightCenter-lps[curRightCenter]>0)
            && ((curRightCenter+lps[curRightCenter]+1)%2==0 || s[(curRightCenter+lps[curRightCenter]+1)/2]==s[(curRightCenter-lps[curRightCenter]-1)/2])){
                lps[curRightCenter]++;
            }
        }
        if(lps[curRightCenter]>lps[maxLPScenter])
        {
            maxLPScenter=curRightCenter;
        }
        if(curRightCenter+lps[curRightCenter]>rightCenter){
            center=curRightCenter;
            rightCenter=curRightCenter+lps[curRightCenter];
        }
    }
    show(maxLPScenter);

}
