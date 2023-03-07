#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;

struct node
{
    int to,nex;
}e[maxn<<1];
int n,m,cnt;
int father[maxn][27],head[maxn],depth[maxn];
int dis[maxn];
void add(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nex=head[u];
    head[u]=cnt++;
}
void dfs(int u,int fa,int dep)
{
    father[u][0]=fa;
    for(int i=1;(1<<i)<=depth[u];i++)
        father[u][i]=father[father[u][i-1]][i-1];
    for(int i=head[u];~i;i=e[i].nex)
    {
        int v=e[i].to;
        if(v!=fa)
        {
        	depth[v]=dep;
            dfs(v,u,dep+1);
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]<depth[v])
    {
        swap(u,v);
    }
    int i=-1,j;
    while((1<<(i+1))<=depth[u])
        i++;
    for(j=i;j>=0;j--)
    {
        if(depth[u]-(1<<j)>=depth[v])
        {
            u=father[u][j];
        }
    }
    if(u==v)
        return u;
    for(int j=i;j>=0;j--)
    {
        if(father[u][j]!=father[v][j])
        {
            u=father[u][j];
            v=father[v][j];
        }
    }
    return father[u][0];
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dis[1]=0;
    dfs(1,0,1);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int lc=lca(u,v);
        int ans=depth[u]+depth[v]-2*depth[lc];
        printf("%d\n",ans);
    }
    return 0;
}

