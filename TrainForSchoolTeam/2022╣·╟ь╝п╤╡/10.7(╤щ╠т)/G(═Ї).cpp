#include<bits/stdc++.h>
#define INF 2147483647
#define N 1200100
#define D 1100000
const int mod=1e9+7;
typedef long long ll;
using namespace std;
ll a[N];
int x,q,T;
int cntT=0;
int cntR[N];
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int work_x()
{
    int temp=x;
    while(temp%2==0)
        temp>>=1;
    for(int k=1;k<=20;k++)
    {
        int l=1<<(k-1);
        int r=1<<k;
        if(temp>l && temp<=r)
            return r;
    }
    return -1;
}
void pre()
{
    for(int i=1;i<=T;i++)
    {
        a[i]=gcd( (1LL*i*x)^x , x );
        if(a[i]==1)
            cntT++;
        cntR[i]=cntT;
    }
}
ll pre_sum(ll n)
{
    int r=n%T;
    ll res=1LL*(n/T)*cntT+cntR[r];
    return res;
}
void solve()
{
    ll ans=0;
    scanf("%d%d",&x,&q);
    T=work_x();
    pre();
    //printf("T:%d\n",T);
    for(int i=1;i<=q;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        //printf("l:%lld\n",pre_sum(l));
        //printf("r:%lld\n",pre_sum(r));
        ans=pre_sum(r)-pre_sum(l-1);
        if(x==1)
            ans=r-l+1;
        printf("%lld\n",ans);
    }
}
int main()
{
    solve();
    return 0;
}
