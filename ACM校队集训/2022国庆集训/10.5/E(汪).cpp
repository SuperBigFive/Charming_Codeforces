#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int a[N];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll sum=a[1]+a[2];
    int cnt=2;
    for(int i=3;i<=n;i++)
    {
        if(1LL*a[i]>sum)
        {
            sum+=a[i];
            cnt++;
        }
    }
    printf("%d\n",cnt);
}
int main()
{
    solve();
    return 0;
}