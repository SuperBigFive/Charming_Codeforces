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

/*
#include<iostream>
#include<cstring>
const int maxn=1e6+5;

struct edge{
	int to;
	int next;
}e[maxn<<1];
int fa[maxn][25],head[maxn],depth[maxn];
int n,m,tot;

void add_edge(int u,int v);
void dfs(int pos,int father,int dep);
int lca(int node1,int node2);
int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof head);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0,0);
	for(int i=0;i<m;++i){
		int node1,node2;
		scanf("%d%d",&node1,&node2);
		printf("%d\n",depth[node1]+depth[node2]-2*depth[lca(node1,node2)]);
	}
	return 0;
}

void add_edge(int u,int v){
	e[tot].to=v;
	e[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int pos,int father,int dep){
	fa[pos][0]=father;
	depth[pos]=dep;
	for(int i=1;(1<<i)<depth[pos];++i){
		fa[pos][i]=fa[fa[pos][i-1]][i-1];
	}
	for(int i=head[pos];i!=-1;i=e[i].next){
		if(e[i].to!=father)
			dfs(e[i].to,pos,dep+1);
	}
}
int lca(int node1,int node2){
	if(depth[node1]<depth[node2]){
		int temp=node1;
		node1=node2;
		node2=temp;
	}
	int i=-1,j;
	for(;(1<<(i+1))<=depth[node1];)
		++i;
	for(j=i;j>=0;--j){
		if(depth[node1]-(1<<j)>=depth[node2])
			node1=fa[node1][j];
	}
	if(node1==node2)
		return node1;
	for(;i>=0;--i){
		if(fa[node1][i]!=fa[node2][i]){
			node1=fa[node1][i];
			node2=fa[node2][i];
		}
	}
	return fa[node1][0];
}
*/
