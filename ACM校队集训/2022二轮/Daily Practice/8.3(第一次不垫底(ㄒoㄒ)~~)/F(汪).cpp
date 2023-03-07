#include<iostream>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int a[N];
void solve()
{
    int n,limit;
    ll ans=0;
    scanf("%d%d",&n,&limit);
    if(limit==0)
    {
        ans=1LL*n*n;
        printf("%lld\n",ans);
        return;
    }
    for(int j=limit+1;j<=n;j++)
    {
        ll res=0;
        int t=(n-(j-1))/j;
        //printf("%d:t:%d\n",j,t);
        int lasti=n-(t+1)*j;
        //printf("%d:lasti:%d\n",j,lasti);
        if(lasti<limit)
            res=(j-1-limit+1)*(t+1);
        else
            res=(lasti-limit+1)*(t+2)+(j-1-lasti)*(t+1);
        //printf("%d:res:%lld\n",j,res);
        ans+=res;
    } 
    printf("%lld\n",ans);
}
int main()
{
    solve();
    return 0;
}
