#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int n,k;
int a[N];
priority_queue<int,vector<int>,greater<int>>q;
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        q.push(a[i]);
        if((int)q.size()>k)
            q.pop();
    }
    ll sum=0;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        sum+=t;
    }
    printf("%lld\n",sum);
}
int main()
{
    solve();
    return 0;
}
