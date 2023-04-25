#include<iostream>
#define INF 2147483647
#define N 20000100
#define D 20000000
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int primes[N],cnt,phi[N];
ll ans[N];
bool vis[N];
void get_Eulers(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            vis[primes[j]*i]=true;
            if(i%primes[j]==0)
            {
                phi[primes[j]*i]=phi[i]*primes[j];
                break;
            }
            phi[primes[j]*i]=phi[i]*(primes[j]-1);
        }
    }
}
void get_psum(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(i%2==1)
            ans[i]=ans[i-1]+phi[i]/2;
        else
            ans[i]=ans[i-1]+phi[i];
    }
}
void solve()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",ans[n]);
}
int main()
{
    int T;
    scanf("%d",&T);
    get_Eulers(D);
    get_psum(D);
    while(T--)
    {
        solve();
    }
    return 0;
}
