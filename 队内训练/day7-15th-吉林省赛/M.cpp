#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int a[N];
void solve()
{
    int n;
    scanf("%d",&n);
    int maxv=-1,minv=INF;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxv=max(maxv,a[i]);
        minv=min(minv,a[i]);
    }
    ll ans=1LL*(maxv-minv)*n;
    printf("%lld\n",ans);
}
int main()
{
    solve();
    return 0;
}
