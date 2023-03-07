#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int n,m,idx=0;
int head[N],fa[N],Rank[N];
bool mk[M];
struct Edge
{
    int u,v,id;
}e[M];
void add(int u,int v)
{
    idx++;
    e[idx].u=u;
    e[idx].v=v;
    e[idx].id=idx;
}
int getfa(int x)//查询
{
    if(fa[x]==x)
        return x;
    return fa[x]=getfa(fa[x]);
}
void simple_union(int x,int y)//朴素合并
{
    int fx=getfa(x),fy=getfa(y);
    fa[fx]=fy;
}
bool same(int x,int y)
{
    return getfa(x)==getfa(y);
}
void rank_union(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(Rank[fx]<Rank[fy])
        fa[fx]=fy;
    else
    {
        fa[fy]=fx;
        if(Rank[fx]==Rank[fy])
            Rank[fx]++;
    }
}
void init()
{
    idx=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        Rank[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        mk[i]=0;
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
}
void solve()
{
    int ans=m;
    for(int i=m;i>=1;i--)
    {
        int u1=e[i].u;
        int v1=e[i].v;
        if(!same(u1,v1))
        {
            rank_union(u1,v1);
            mk[i]=1;
            ans--;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=m;i++)
        if(!mk[i])
            printf("%d ",i);
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        solve();
    }
    return 0;
}
