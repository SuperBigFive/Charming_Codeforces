#include<iostream>
#define INF 2147483647
#define N 500100
#define D 100000
#define M 500100
const int mod=998244353;
using namespace std;
typedef long long ll;
int a[N];
void init()
{
    a[0]=a[3]=a[4]=1;
    a[1]=a[2]=0;
    for(int i=5;i<=D;i++)
    {
        a[i]=(1LL*a[i-1]*(i-2)%mod+1LL*a[i-2]*(i-1)%mod)%mod;
        if(i%2==0)
            a[i]=(a[i]+mod-1)%mod;
        else
            a[i]=(a[i]+1)%mod;
    }
}
void solve()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
}
int main()
{
    int T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        solve();
    }
    return 0;
}
