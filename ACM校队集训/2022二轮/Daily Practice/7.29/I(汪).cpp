#include<bits/stdc++.h>
#define INF 2147483647
#define N 5100
#define M 5001000
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int sg[N];
map<int,bool>vis;
void init()
{
    memset(sg,-1,sizeof(sg));
    sg[0]=0;sg[1]=0;sg[2]=1;
}
int mex()
{
    for(int i=0;i<=INF;i++)
        if(!vis[i])
        {
            //cout<<"i:"<<i<<endl;
            return i;
        }
}
int SG(int x)
{
    if(sg[x]!=-1)
        return sg[x];
    vis.clear();
    for(int i=0;i<=(x-2);i++)
    {
        ll a=SG(i);
        ll b=SG(x-i-2);
        ll temp=a^b;
        vis[temp]=1;
    }
    return sg[x]=mex();
}
void solve()
{
    int n;
    scanf("%d",&n);
    int jg=SG(n);
    if(!jg)
        puts("Second");
    else
        puts("First");
}
int main()
{
    init();
    for(int i=3;i<=5000;i++)
        sg[i]=SG(i);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
