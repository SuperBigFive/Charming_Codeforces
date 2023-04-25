#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int a[N];
void solve()
{
    double n;
    scanf("%lf",&n);
    double ans=n/2/(n-1);
    printf("%lf\n",ans);
}
int main()
{
    solve();
    return 0;
}