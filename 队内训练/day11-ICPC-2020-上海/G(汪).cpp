#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
ll n;
ll cal1(ll n)//i为3的倍数时,对(n-i)求和
{
    return n/3*n-(1+n/3)*(n/3)/2*3;
}
ll cal2(ll n)//[i/3]从1到n求和
{
    if(n%3==0)
        return (1+n/3)*(n/3)/2 + ((1+n/3)*(n/3)/2-n/3)*2;
    else if(n%3==1)
        return cal2(n-1)+n/3;
    else
        return cal2(n-2)+(n-1)/3+n/3;
}
void solve()
{
    scanf("%lld",&n);
    ll res1=cal1(n);
    ll res2 = ( n/3*n - cal2(n) ) - ( (n/3)*(n/3) - (1+n/3)*(n/3)/2 );
    ll ans=res1+res2;
    printf("%lld\n",ans);
}
int main()
{
    solve();
    return 0;
}
