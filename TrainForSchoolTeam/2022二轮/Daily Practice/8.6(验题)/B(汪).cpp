#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int n,idx;
int head[N],w[N];
struct Edge
{
    int to;
    int w;
    int next;
}e[M];
struct Node
{
    int u,v;
}node[N];
void add(int u,int v)
{
    e[idx].to=v;
    e[idx].next=head[u];
    head[u]=idx++;
}
void init()
{
    idx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    add(1,2);add(1,3);add(2,3);
    add(2,1);add(3,1);add(3,2);
    for(int i=4;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        node[i].u=u,node[i].v=v;
        add(i,u),add(u,i);
        add(i,v),add(v,i);
    }
}
ll solve(int which)
{
    map<int,bool>vis;
    vis.clear();
    ll res=0;
    res+=w[which];
    unsigned int node1=which;
    unsigned int node2=which%3+1;
    unsigned int node3;
    if(which==1)
        node3=3;
    else
        node3=(which%3+2)%3;
    vis[node1]=1;
    vis[node2]=0;
    vis[node3]=0;
    for(int i=4;i<=n;i++)
    {
        int u1=node[i].u;
        int v1=node[i].v;
        if(vis[u1]||vis[v1])
            vis[i]=0;
        else
        {
            vis[i]=1;
            res+=w[i];
        }
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    memset(head,-1,sizeof(head));
    while(T--)
    {
        init();
        ll res1=solve(1);
        ll res2=solve(2);
        ll res3=solve(3);
        //printf("Test:%lld %lld %lld\n",res1,res2,res3);
        ll ans=max(res1,max(res2,res3));
        printf("%lld\n",ans);
    }
    return 0;
}
