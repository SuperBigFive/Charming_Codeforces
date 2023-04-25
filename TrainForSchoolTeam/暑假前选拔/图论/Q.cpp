#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const ll INF=1e15+5; 
struct Edge{
	int u;
	int v;
	ll weight;
}edge[maxn];
int n,tot,num;
int pre[maxn];
ll ans,cost_coe;
ll popu[maxn],minw[maxn],point_weight[maxn];

void add(int u,int v,ll w);
int find(int x);
void build_edge(int left,int right);
bool cmp(Edge a,Edge b);
void kruskal();

int main(){
	scanf("%d%lld",&n,&cost_coe);
	ll p;
	for(int i=0;i<n;){
		scanf("%lld",&p);
		popu[++i]=p;
	}
	build_edge(1,n);
	kruskal();
	printf("%lld",ans);
	return 0;
}

void add(int u,int v,ll w){
	edge[++tot].u=u;
	edge[tot].v=v;
	edge[tot].weight=w;
}
int find(int x){
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
bool cmp(Edge a,Edge b){
	return a.weight<b.weight;
}
void build_edge(int left,int right){
	if(left>=right) return;
	int t=(right-left)/2;
	ll min=INF;
	int min_point;
	for(int i=left;i<=left+t;++i){
		point_weight[i]=popu[i]-i*cost_coe;
		if(point_weight[i]<min){
			min=point_weight[i];
			min_point=i;
		}
	}
	ll max=INF;
	int max_point;
	for(int i=left+t+1;i<=right;++i){
		point_weight[i]=popu[i]+i*cost_coe;
		if(point_weight[i]<max){
			max=point_weight[i];
			max_point=i;
		}
		add(min_point,i,point_weight[min_point]+point_weight[i]);
	}
	for(int i=left;i<=left+t;++i){
		if(i!=min_point);
			add(max_point,i,point_weight[max_point]+point_weight[i]);
	}
	build_edge(left,left+t);
	build_edge(left+t+1,right);
}
void kruskal(){
	for(int i=1;i<=n;++i) pre[i]=i;
	sort(edge+1,edge+tot,cmp);
	int cnt=0;
	for(int i=1;cnt<n-1;++i){
		int preu=find(edge[i].u);
		int prev=find(edge[i].v);
		if(preu!=prev){
			ans+=edge[i].weight;
			cnt++;
			pre[preu]=prev;
		}
	}
}
