#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 6200100
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int n,k,idx;
int a[55][55];
vector<pair<int,int>>vp[2510];
int head[N];
ll dis[N];
bool vis[N];
priority_queue<pair<int,int>>q;
struct Edge
{
    int to;
    int w;
    int next;
}e[M];
int MHT(int x1,int y1,int x2,int y2)
{
    int d=abs(x1-x2)+abs(y1-y2);
    return d;
}
void add(int u,int v,int w)
{
    e[idx].to=v;
    e[idx].w=w;
    e[idx].next=head[u];
    head[u]=idx++;
}
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        vp[i].push_back({-1,-1});
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            a[i][j]=x;
            vp[x].push_back({i,j});
        }
    for(int i=1;i<=k;i++)
    {
        int siz=vp[i].size()-1;
        if(siz==0)
        {
            puts("-1");
            return;
        }
    }
    int S=n*n+1,T=n*n+2;
    for(auto t:vp[1])
    {
        int x1=t.first,y1=t.second;
        int idx1=y1+(x1-1)*n;
        if(x1==-1)
            continue;
        add(S,idx1,0);
        //add(idx1,S,0);
    }
    for(auto t:vp[k])
    {
        int x1=t.first,y1=t.second;
        int idxn=y1+(x1-1)*n;
        if(x1==-1)
            continue;
        //add(T,idxn,0);
        add(idxn,T,0);
    }
    for(int i=1;i<=k-1;i++)
    {
        int siz_cur=vp[i].size()-1;
        int siz_ne=vp[i+1].size()-1;
        for(int j=1;j<=siz_cur;j++)
            for(int k=1;k<=siz_ne;k++)
            {
                int x1=vp[i][j].first,y1=vp[i][j].second;
                int idx_1=y1+(x1-1)*n;
                int x2=vp[i+1][k].first,y2=vp[i+1][k].second;
                int idx_2=y2+(x2-1)*n;
                int d=MHT(x1,y1,x2,y2);
                add(idx_1,idx_2,d);
                //add(idx_2,idx_1,d);
            }
    }
    for(int i=1;i<=n*n+2;i++)
        dis[i]=INF;
    dis[S]=0;
    q.push(make_pair(0,S));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]==true)
            continue;
        vis[u]=true;
        for(int i=head[u];~i;i=e[i].next)
        {
            int v1=e[i].to;
            int w1=e[i].w;
            if(dis[v1]>dis[u]+w1)
            {
                dis[v1]=dis[u]+w1;
                q.push(make_pair(-dis[v1],v1));
            }
        }
    }
    /*
    int sizn=vp[k].size()-1;
    ll minv=INF;
    for(int i=1;i<=sizn;i++)
    {
        int x1=vp[k][i].first,y1=vp[k][i].second;
        int idx_n=y1+(x1-1)*n;
        //printf("%lld\n",dis[idx_n]);
        minv=min(minv,dis[idx_n]);
    }
    //cout<<"Test"<<vis[T]<<endl;
    printf("%lld\n",minv);
    */
    printf("%lld\n",dis[T]);
    /*
    for(int i=1;i<=k;i++)
    {
        int siz=vp[i].size()-1;
        for(int j=1;j<=siz;j++)
        {
            int x1=vp[i][j].first,y1=vp[i][j].second;
            int idx_=y1+(x1-1)*n;
            //printf("%d ",idx_);
            printf("%lld ",dis[idx_]);
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n*n+2;i++)
        printf("%lld ",dis[i]);
    */
}
int main()
{
    memset(head,-1,sizeof(head));
    solve();
    return 0;
}
