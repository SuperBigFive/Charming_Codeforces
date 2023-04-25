#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
ll n,m;
int a[N];
//ax+by=d
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ll gcd1=__gcd(n,n*(n+1)/2);
    ll gcd2=__gcd(gcd1,m);
    ll ans=sum%gcd2;
    ll k=sum/gcd2;
    k=-k;
    ll x,y;
    exgcd(gcd1,m,x,y);
    k=(k%m+m)%m;
    x*=k,y*=k;
    x=(x%m+m)%m;
    ll s,d;
    exgcd(n,n*(n+1)/2,s,d);
    //x=(x%m+m)%m;
    s*=x,d*=x;
    s=(s%m+m)%m;
    d=(d%m+m)%m;
    printf("%lld\n",ans);
    printf("%lld %lld\n",s,d);
}
int main()
{
    solve();
    return 0;
}
