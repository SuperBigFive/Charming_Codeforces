#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    if(!y)
        return x;
    return gcd(y,x%y);
}
void solve()
{
    int a,b;
    scanf("%d%d",&a,&b);
    ll gcdd=gcd(1LL*180*b,a);
    //printf("T:%d\n",gcdd);
    ll k=1LL*180*b/gcdd;
    printf("%lld\n",k-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
}
