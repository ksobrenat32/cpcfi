typedef long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const int MAX=1e6+3;
const ll A=911382323;
const ll B=972663749;
ll str[MAX];
ll pk[MAX];
bool prefix[MAX]={false};



ll subs(int i,int j)
{
    if(i)
        return ((str[j]-pk[j-i+1]*str[i-1])%B+B)%B;
    else
        return str[j];
}

//ascii https://elcodigoascii.com.ar/

inline void solve()
{
    string s; cin>>s;
    memset(prefix,true,sizeof(prefix));
    str[0]=s[0];
    pk[0]=1;
    int n=s.size();
    for(int i=1;i<n;i++)
    {
        str[i]=A*str[i-1]+s[i];
        pk[i]=pk[i-1]*A;
        pk[i]%=B;
        str[i]%=B;
    }
    ll aux;
    bool ver;
    for(int i=1;i<=n;i++)
    {
        aux=subs(0,i-1);
        for(int j=0;j+i<=n;j+=i)
        {
            if(aux!=subs(j,j+i-1))
            {
                //cout<<aux<<" "<<subs(j,j+i-1)<<" "<<i<<" "<<j<<endl;
                prefix[i]=false;
                break;
            }
        }
        if(!prefix[i]) continue;
        if(n%i && (subs(n-n%i,n-1)!=subs(0,n%i-1)))
        {
            continue;
        }
        cout<<i<<" ";
    }
}
