#include <iostream>
#include <queue>  	        
#include <vector>            
using namespace std;

const int maxn = 1e6+5;
const long long INF = 1000000000000000;
bool vis[maxn];
long long dis[maxn];

struct node
{
    int u;			
    long long w;			
    bool operator <(const node &r)const
    {
        return w > r.w;
    }
}temp;
vector <node> e[maxn];
void dijkstra(int st)
{
    fill(vis,vis+maxn,false);
    fill(dis,dis+maxn,INF);
    priority_queue <node> pque;
    dis[st] = 0;
    temp.u=st,temp.w=0;
    pque.push(temp);
    while(!pque.empty())
    {
        node t = pque.top();
        pque.pop();
        int u = t.u;
        if(vis[u])
            continue;
        vis[u] = true;
        for(int i = 0 ; i < e[u].size() ; i++)
        {
            int v = e[u][i].u;
            long long w = e[u][i].w;
            if(!vis[v] && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                temp.u=v,temp.w=dis[v];
                pque.push(temp);
            }
        }
    }
}

int main()
{
    int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
    for(int i = 1 ; i <= m ; i++)
    {
        int u,v;
		long long w;
        scanf("%d%d%d",&u,&v,&w);
        temp.u=v,temp.w=w;
        e[u].push_back(temp);
    }
    dijkstra(s);			
    for(int i = 1; i<=n ;i++){
	if (dis[i] == INF)		
        printf("-1\n");
    else
    	printf("%lld\n",dis[i]);
    }
    return 0;
}
