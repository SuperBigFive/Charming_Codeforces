#include<bits/stdc++.h>
#define N 4000100
#define M 4000100
#define D 1000000
using namespace std;
typedef long long ll;
struct Edge
{
    int from,to;
    int next;
}e[M<<1];
struct Input
{
    int x,y;
}input[N];
int n,t,idx,num;
int head[N],dfn[N],low[N];
bool vis[N],mk[N],fix[N],mkk[N];
void add(int u,int v)
{
    e[idx].from=u,e[idx].to=v;
    e[idx].next=head[u];
    head[u]=idx++;
}
bool flag;
void tarjan(int x,int fa)
{
    dfn[x]=low[x]=++num;
    if(mk[x])
        flag=true;
    for(int i=head[x];~i;i=e[i].next)
    {
        int v1=e[i].to;
        if(!vis[v1])
            continue;
        if(!dfn[v1])
        {
            tarjan(v1,x);
            low[x]=min(low[x],low[v1]);
            if(low[v1]<=dfn[x])
            {
                flag=true;
                //printf("Test:%d-%d\n",v1,x);
            }
        }
        else if(v1!=fa)
        {
            low[x]=min(low[x],dfn[v1]);
        }

    }
}
bool check(int x)
{
    for(int i=1;i<=x;i++)
    {
        vis[i]=1;
        dfn[i]=low[i]=mk[i]=0;
    }
    for(int i=x+1;i<=t;i++)
    {
        vis[i]=0;
        dfn[i]=low[i]=mk[i]=0;
    }
    for(int i=1;i<=t;i++)
        mk[i]=fix[i];
    for(int i=1;i<=t;i++)
    {
        if(mkk[i]==0)
            continue;
        int u=input[i].x,v=input[i].y;
        if(!vis[u] && vis[v])
            mk[v]=1;
        else if(vis[u] && !vis[v])
            mk[u]=1;
    }
    for(int i=1;i<=x;i++)
        if(!dfn[i])
        {
            flag=false;
            tarjan(i,-1);
            if(flag==false)
                return false;
        }
    return true;
}
void init()
{
    scanf("%d%d",&n,&t);
    idx=0;
    for(int i=1;i<=D+10;i++)
        head[i]=-1;
    unordered_set<ll>S;
    for(int i=1;i<=t;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        input[i].x=u,input[i].y=v;
        int c1=max(u,v),c2=min(u,v);
        if(c2>t)
            continue;
        if(c1>t)
        {
            fix[c2]=1;
            continue;
        }
        mkk[i]=1;
        if(u==v)
        {
            fix[u]=1;
            continue;
        }
        if(u>v)
            swap(u,v);
        ll hash_val=1LL*10000000*u+v;
        if(S.count(hash_val)>=1)
        {
            fix[u]=fix[v]=1;
            continue;
        }
        S.insert(hash_val);
        add(u,v);
        add(v,u);
    }
}
void solve()
{
    int l=0,r=min(n,t)+1;
    //[1,l]ok,[r,t+1]not ok
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d\n",r);
    /*
    for(int i=1;i<=t;i++)
        if(check(i))
            puts("YES");
        else
            puts("NO");
    */
    /*
    if(check(5))
        puts("YES");
    else
        puts("NO");
    for(int i=1;i<=t;i++)
        printf("%d:%d\n",i,dfn[i]);
    for(int i=1;i<=t;i++)
        printf("%d:%d\n",i,low[i]);
    for(int i=1;i<=t;i++)
        printf("%d:%d\n",i,mk[i]);
    */
}
int main()
{
    init();
    solve();
}

