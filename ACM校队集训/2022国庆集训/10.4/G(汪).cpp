#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int B,R,D,S;
int a[N];
void solve()
{
    scanf("%d%d%d%d",&B,&R,&D,&S);
    int t;
    t=S/(60.0/R)+1;
    if(R==0)
    {
        if(D!=0)
            puts("gua!");
        else
            puts("ok");
    }
    else
    {
        if(1LL*B*t<1LL*D)
            puts("gua!");
        else
            puts("ok");
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
