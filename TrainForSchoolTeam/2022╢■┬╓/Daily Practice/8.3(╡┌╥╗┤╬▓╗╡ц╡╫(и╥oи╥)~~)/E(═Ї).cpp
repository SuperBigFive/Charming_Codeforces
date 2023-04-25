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
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m)
        swap(n,m);
    if(n==1 && m==1)
    {
        puts("1");
        return;
    }   
    if(n==1)
    {
        printf("%d\n",m-2);
        return;
    }
    if(n==2)
    {
        puts("0");
        return;
    }
    ll ans=1LL*(n-2)*(m-2);
    printf("%lld\n",ans);
}
int main()
{
    solve();
    return 0;
}
