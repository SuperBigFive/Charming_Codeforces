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
    unordered_map<int,bool>vis;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            if(vis[a[i]-1])
            {
                puts("Yes");
                return;
            }
        }
    }
    puts("No");
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
