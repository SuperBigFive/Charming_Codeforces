#include<bits/stdc++.h>
#define INF 2147483647
#define N 1000100
#define M 500100
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int c[N];
int L[N],len[N],siz;
void solve()
{
    int n,m,k;
    siz=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int left;
    c[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=c[i-1])
            left=i;
        L[i]=left;
    }
    c[n+1]=m+1;
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=c[i+1])
            len[++siz]=i-L[i]+1;
    }
    if(c[1]==c[n] && L[n]!=1)
    {
        len[1]=len[1]+len[siz];
        siz--;
    }
    //for(int i=1;i<=siz;i++)
    //    printf("T:%d:%d\n",i,len[i]);
    bool flag=false;
    for(int i=1;i<=siz;i++)
    {
        if(len[i]>=k)
            flag=true;
    }
    if(flag==false)
    {
        puts("-1");
        return;
    }
    ll ans=0;
    for(int i=1;i<=siz;i++)
    {
        int t=0;
        if(len[i]%k==0)
            t=len[i]/k;
        else
            t=len[i]/k+1;
        ans+=t;
    }
    printf("%lld\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
