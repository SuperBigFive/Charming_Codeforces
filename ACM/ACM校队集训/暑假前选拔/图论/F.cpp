/*#include<iostream>
using namespace std;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
struct node{
	int u,v,val;
	node(int _u=0,int _v=0,int _val=0){
		u=_u;v=_v;val=_val;
	}
}edge[MAXN];
int dis[MAXN];
int n,m;
 
int bellman_ford(){
	memset(dis,INF,sizeof(dis));dis[1]=0;
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			if(dis[edge[j].v]>dis[edge[j].u]+edge[j].val){
				dis[edge[j].v]=dis[edge[j].u]+edge[j].val;
			}
		}
	}int f=1;
	for(int j=1;j<=m;++j){
		if(dis[edge[j].v]>dis[edge[j].u]+edge[j].val){
			f=0;break;
		}
	}return f;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>edge[i].u>>edge[i].v>>edge[i].val;
	}
	if(!bellman_ford())	cout<<"存在负环"<<endl;
	else				cout<<"不存在负环"<<endl;
}*/
#include<iostream>
#include<cstring>
using namespace std;
typedef struct edge{
	int u;
	int v;
	int w;
}edge;
const int inf=9999999;
const int maxn=1e4+5; 
edge e[maxn];
int dist[maxn];
int cnt=0;
int n,m;
void add(int u,int v,int w){
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt++].w=w;
}
int main(){
	int u,v,w;
	scanf("%d%d",&n,&m);
	memset(dist,inf,n);
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&w);
		add(v,u,w); 
	}
	dist[e[0].u]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(dist[e[j].v]>dist[e[j].u]+e[j].w)
			dist[e[j].v]=dist[e[j].u]+e[j].w;
		}
	}
	int key=1;
	for(int i=0;i<m;++i){
		if(dist[e[i].v]>dist[e[i].u]+e[i].w){
			key=0;
			break;
		}
	}
	if(!key)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}

/*
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e4+5;
const int inf=9999999;

struct edge{
	int u,v,w;
}e[maxn];
int dist[maxn];
int n,m,tot;

void add_edge(int a,int b,int c);

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	memset(dist,inf,sizeof dist);
	dist[1]=0;
	for(int i=1;i<n;++i){
		for(int j=0;j<m;++j){
		int uu=e[j].u,vv=e[j].v,ww=e[j].w;
		if(dist[vv]>dist[uu]+ww)
			dist[vv]=dist[uu]+ww;
		}
	}
	for(int i=0;i<m;++i){
		if(dist[e[i].v]>dist[e[i].u]+e[i].w){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}

void add_edge(int a,int b,int c){
	e[tot].u=a;
	e[tot].v=b;
	e[tot++].w=c;
}
*/
