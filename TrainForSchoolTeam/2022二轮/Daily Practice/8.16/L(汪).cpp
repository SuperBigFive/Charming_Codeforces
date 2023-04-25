#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 5001
#define M 500100
#define INF 2147483647
const int mod=1e9+7;
using namespace std;
typedef long long ll;
struct Edge
{
    int to;
    ll w;
    int next;
}e[4*M];
int n,m,L;
int S,T,idx;
int ti[N],pay[N],pro[N],k[N];
int head[N],deep[N];
vector<int>mp[N];
ll ans=0;
void add(int u,int v,int w)
{
    e[idx].to=v;
    e[idx].w=w;
    e[idx].next=head[u];
    head[u]=idx++;
}
bool bfs()
{
    memset(deep,-1,sizeof(deep));
    deep[S]=0;
    queue<int>q;
    q.push(S);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=head[t];~i;i=e[i].next)
        {
            int v1=e[i].to;
            if(deep[v1]==-1 && e[i].w!=0)
            {
                deep[v1]=deep[t]+1;
                q.push(v1);
            }
        }
    }
    return deep[T]!=-1;
}
ll dfs(int u,ll in)
{
	if(u==T)
		return in;
	ll out = 0;
	for(int i=head[u];~i;i=e[i].next)
    {
		int v1=e[i].to;
		if(e[i].w!=0 && deep[v1]==deep[u]+1)
		{
			ll res = dfs(v1, min(e[i].w, in));
			e[i].w -= res;
			e[i^1].w += res;
			in -= res;
			out += res;
            if(!in)
                break;
		}
	}
	if(out == 0)
		deep[u] =-1;
	return out;
}
void rebuild()
{
    idx=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
    {
        add(i,T,pay[i]);
        add(T,i,0);//编号为x的正向边对应的是编号为(x/2+1)的点负权点，便于二分时修改权值
    }
    for(int i=n+1;i<=n+m;i++)
    {
        add(S,i,pro[i]);
        add(i,S,0);
        for(auto x:mp[i])
        {
            add(i,x,INF);
            add(x,i,0);
        }
    }
}
bool check(int limit,ll sum)
{
    for(int i=1;i<=n;i++)
        if(ti[i]>limit)
            e[2*(i-1)].w=1e12;
    ll res=0;
    while(bfs())
        res+=dfs(S,sum);
    //printf("Test:res:%lld\n",res);
    rebuild();
    if(sum-res>=L)
    {
        ans=sum-res;
        return true;
    }
    else
        return false;
}
void solve(int case_idx)
{
    idx=0;
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&L);
    S=3*(n+m)+10;
    T=3*(n+m)+20;
    //printf("T1\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&pay[i],&ti[i]);
        add(i,T,pay[i]);
        add(T,i,0);//编号为x的正向边对应的是编号为(x/2+1)的点负权点，便于二分时修改权值
    }
    for(int i=n+1;i<=n+m;i++)
    {
        mp[i].clear();
        scanf("%d%d",&pro[i],&k[i]);
        add(S,i,pro[i]);
        add(i,S,0);
        for(int j=1,x;j<=k[i];j++)
        {
            scanf("%d",&x);
            mp[i].push_back(x);
            add(i,x,INF);
            add(x,i,0);
        }
    }
    ll sum=0;
    for(int i=head[S];~i;i=e[i].next)
        sum+=e[i].w;
    int l=0,r=1e9+1;
    //printf("T2\n");
    while(l+1<r)//[0,l]不符合，[r,无穷大]符合
    {
        int mid=(r-l)/2+l;
        //printf("T4\n");
        if(check(mid,sum))
            r=mid;
        else
            l=mid;
    }
    //printf("T3\n");
    /*
    if(check(5,3))
        printf("YES\n");
    else
        printf("NO\n");
    if(check(5,3))
        printf("YES\n");
    else
        printf("NO\n");*/

    if(r==1e9+1)
        printf("Case #%d: impossible\n",case_idx);
    else
        printf("Case #%d: %d %lld\n",case_idx,r,ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        solve(i);
    }
    return 0;
}
