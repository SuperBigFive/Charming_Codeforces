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
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]&1)
            cnt++;
    }
    if(abs(cnt-(n-cnt))<=1)
        puts("Good");
    else
        puts("Not Good");
}
int main()
{
    solve();
    return 0;
}
