#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=1e5+15;
const int big=99999999;

struct Edge{
	int to;
	int next;
}edge[maxn];
int head[maxn];
int tot;
bool key;
int vis[maxn],dep[maxn],dis[maxn];
bool flag[maxn];
stack <int> s;

void add(int u,int v){
	edge[++tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot;	
}

void dfs1(int u,int fa,int depth){
	vis[u]=true;
	dep[u]=depth;
	s.push(u);
	for(int i=head[u];i&&!key;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]&&v!=fa){
			vis[v]=true;
			dfs1(v,u,depth+1);
			s.pop();
		}
		else if(v!=fa){
			int diff=dep[u]-dep[v]+1;
			while(diff--){
				int temp=s.top();
				flag[temp]=true;
				s.pop();
			}
			key=1;
			return;
		}
	}
}
void dfs2(int u,int root,int fa,int dist){
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa){
			if(flag[v]){
				dis[root]=min(dist,dis[root]);
				return;
			}
			else{
				dfs2(v,root,u,dist+1);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int uu,vv;
		scanf("%d%d",&uu,&vv);
		add(uu,vv);
		add(vv,uu);
	}
	dfs1(1,1,1);
		
	/*for(int i=1;i<=n;++i){
		if(flag[i])
			printf("%d is true\n",i);
	}
	*/
	memset(dis,9999999,sizeof dis);
	for(int i=1;i<=n;++i){
		if(!flag[i]){
			dfs2(i,i,i,1);
		}
		else dis[i]=0;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",dis[i]);
	}
	return 0;
}
