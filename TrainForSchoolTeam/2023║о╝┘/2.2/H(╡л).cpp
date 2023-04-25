#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int n;
int a[N],pmax[N];
vector<int>pos;
void solve()
{
    int t=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t=max(t,a[i]);
        pmax[i]=t;
        if(t>pmax[i-1])
        {
            //printf("T:%d\n",i);
            pos.push_back(i);
        }
    }
    int siz=pos.size();
    ll ans=1;
    if(siz==1)
    {
        puts("1");
        return;
    }
    for(int i=1;i<siz;i++)
        ans=ans*(pos[i]-pos[i-1]+1)%mod;
    printf("%lld\n",ans);
}
int main()
{
    solve();
    return 0;
}
