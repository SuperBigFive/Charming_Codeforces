#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll base,val;
ll b10[114];
void solve()
{
    scanf("%lld%lld",&base,&val);
    vector<ll> g(114);
    g[0] = 1;
    for(int i=1;g[i] <= 1ll*val*base*base; ++i)g[i] = g[i-1] * base;
    int cur = 0;
    for(int i=1;true;++i)
    {
        //cout<<val<<" "<<g[i]<<endl;
        if(val<=g[i])
        {
            --val;
            for(int j=1;j<=i;++j)
            {
                ll r = 10 - base + val % g[i-j+1] / g[i-j];
                printf("%lld",r); 
            }
            printf("\n");
            return;
        }
        val -= g[i];
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}