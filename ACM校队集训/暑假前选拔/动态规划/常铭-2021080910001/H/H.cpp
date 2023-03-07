#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=5e5+15;

int n;
int val[maxn];
int mmax_val[maxn];
int dp[maxn];
vector <int> node[maxn];

int dfs1(int fa,int u);
void dfs2(int fa,int u);

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&val[i]);
		if(!val[i]) val[i]=-1; 
	}
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dp[1]=dfs1(1,1);
	dfs2(1,1);
	for(int i=1;i<=n;++i) printf("%d ",dp[i]);
	return 0;
}

int dfs1(int fa,int u){
	int tot=0,tmp=0;
	while(tot<node[u].size()){
		if(node[u][tot]==fa){
			++tot;
			continue;
		}
		int ttmp=dfs1(u,node[u][tot]);
		if(ttmp>0) tmp+=ttmp;
		++tot;
	}
	mmax_val[u]=tmp+val[u];
	return tmp+val[u];
}
void dfs2(int fa,int u){
	int tot=0;
	while(tot<node[u].size()){
		if(node[u][tot]==fa){
			++tot;
			continue;
		}
		int flag=val[u]<0?1:0;
		int v=node[u][tot];
		if(mmax_val[v]<0) dp[v]=max(mmax_val[v],dp[u]+mmax_val[v]);
		//if(val[v]>0) dp[v]=max(mmax_val[v],dp[u]+flag);
		//else dp[v]=max(mmax_val[v],dp[u]-1);
		else dp[v]=max(mmax_val[v],dp[u]);
		dfs2(u,v);
		++tot;
	}
}
