#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=998244853;
using namespace std;
typedef long long ll;
int n,m,k;
map<pair<int,int>,vector<int>>mp;
int a[N],pow10[N];
ll inv[N];
inline ll qmi(ll base,ll k,ll p)
{
    ll res=1;
    while(k)
    {
        if(k&1)
            res=res*base%p;
        base=base*base%p;
        k>>=1;
    }
    return res;
}
void init()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v)
            swap(u,v);
        mp[{u,v}].push_back(w);
    }
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    int mx=3e5;
    pow10[0]=1;
    for(int i=1;i<=mx;i++)
        pow10[i]=1LL*pow10[i-1]*10%mod;
    inv[1]=1;
    for(int i=2;i<=mx;i++)
        inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;//开long long!
}
void solve()
{
    ll ans=0;
    for(int i=1;i<=k-1;i++)
    {
        int u=a[i],v=a[i+1];
        if(u>v)
            swap(u,v);
        int siz=mp[{u,v}].size();
        if(siz==0)
        {
            puts("Stupid Msacywy!");
            return;
        }
        for(int j=0;j<siz;j++)
        {
            int d=mp[{u,v}][j];
            int temp=1LL*d*pow10[k-1-i]%mod*inv[siz]%mod;
            ans=(ans+temp)%mod;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    init();
    solve();
    return 0;
}
