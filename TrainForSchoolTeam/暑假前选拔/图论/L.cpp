#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int mod=10000;
const int maxn=1e2+5;
const int maxm=1e5+5;

struct Edge{
	int u;
	int v;
	int w;
}edge[maxm],l_used[maxn];
int n,m,num_point,cnt,tot,mint;
int pre[maxn],w_used[maxn],p_point[maxn],ma[maxn][maxn];

bool cmp(Edge x,Edge y);
int find(int x);
void con_line(int weight);
void narrow_point();
void build_ma(int weight);
int gauss(int num);
void solve();

int main() 
{ 	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;++i) 
		pre[i]=i;
	for(int i=1;i<=m&&cnt!=n-1;++i)
	{
		int u=edge[i].u,v=edge[i].v;
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu!=fv)
		{
			pre[fu]=fv; l_used[++cnt]=edge[i];
			if(edge[i].w!=w_used[tot]) 
				w_used[++tot]=edge[i].w;
		}
	}
	if(cnt!=n-1){
		printf("0\n");
		return 0;
	}
	mint=1;
	solve();
	printf("%d\n",(mint+mod)%mod);
	return 0;
} 

bool cmp(Edge x,Edge y){ 
	return x.w<y.w;
}
int find(int x){
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void con_line(int weight){
	for(int i=1;i<=n;++i) 
		pre[i]=i;
	for(int i=1;i<n;++i)
	if(l_used[i].w!=weight)
	{
		int preu=find(l_used[i].u),prev=find(l_used[i].v);
		if(preu!=prev) pre[preu]=prev;
	}
}
void narrow_point(){
	num_point=0;
	for(int i=1;i<=n;++i)
	if(find(i)==i) 
		p_point[i]=++num_point;
	for(int i=1;i<=n;++i)
		p_point[i]=p_point[find(i)];
}
void build_ma(int weight){
	memset(ma,0,sizeof ma);
	for(int i=1;i<=m;++i)
	if(edge[i].w==weight){
		int u=p_point[edge[i].u],v=p_point[edge[i].v];
		ma[u][u]++; 
		ma[v][v]++; 
		ma[u][v]--; 
		ma[v][u]--;
	}
}
int gauss(int num)
{
	int res=1;
	for(int i=1;i<num;++i)
	{
		for(int j=i+1;j<num;++j)
		while(ma[j][i])
		{
			int t=ma[i][i]/ma[j][i];
			for(int k=i;k<num;++k)
			ma[i][k]=(ma[i][k]-t*ma[j][k]+mod)%mod;
			swap(ma[j],ma[i]);
			res=-res;
		}
		res=(res*ma[i][i])%mod;
	}
	return (res+mod)%mod;
}
void solve(){
	for(int i=1;i<=tot;++i)
	{
		con_line(w_used[i]); 
		narrow_point(); 
		build_ma(w_used[i]);
		mint=mint*gauss(num_point)%mod;
	}
}
