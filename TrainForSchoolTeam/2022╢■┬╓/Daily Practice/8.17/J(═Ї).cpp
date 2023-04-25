#include<bits/stdc++.h>
#define INF 2147483647
#define N 210
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
string s;
int n,m,idx;
int head[N],color[N];
int edge_map[N][N],depth[N];
int res,ans=-1;
queue<int>q;
struct Edge
{
    int from,to;
    int next;
}e[4*M];
void add(int u,int v)
{
    e[idx].from=u,e[idx].to=v;
    e[idx].next=head[u];
    head[u]=idx++;
}
bool find(int x)
{
    res=-1;
    while(!q.empty())
        q.pop();
    memset(depth,0,sizeof(depth));
    memset(color,0,sizeof(color));
    q.push(x);
    depth[x]=1;
    color[x]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=head[t];~i;i=e[i].next)
        {
            int v1=e[i].to;
            if(color[v1]==0)
            {
                color[v1]=-color[t];
                depth[v1]=depth[t]+1;
                res=max(res,depth[v1]);
                q.push(v1);
            }
            else if(color[v1]==color[t])
                return false;
        }
    }
    return true;
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            if(s[j-1]=='1')
            {
                edge_map[i][j]=1;
                add(i,j);
                add(j,i);
            }
        }
    }
    if(!find(1))
        puts("-1");
    else
    {
        for(int i=1;i<=n;i++)
        {
            find(i);
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    //for(int i=1;i<=n;i++)
    //    printf("%d:%d\n",i,depth[i]);
}
int main()
{
    memset(head,-1,sizeof(head));
    solve();
    return 0;
}