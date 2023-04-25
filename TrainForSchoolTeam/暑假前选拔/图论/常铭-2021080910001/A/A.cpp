#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
const int maxn=300+5;
const int inf=9999999;

int n,m,min_cut=inf;
int map[maxn][maxn],dist[maxn];//邻接矩阵，存储各个顶点之间的边数;dist储存集合A以外点到集合A的最小割 
bool vis[maxn],combine[maxn];//vis用于判断每次循环判断是否已经访问过;combine用于判断该点是否已经用于合并

void SW(); //最外层循环每循环一次去掉一个点，一共n个点，所以要循环n-1次 
		   //次外层循环：嵌套三个最内层循环，分别求最重边最大的边、合并成一个子集（注意相应的点和边的变化）、真正地将两个点（或点集）合在一起 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++map[u][v];
		++map[v][u];
	}
	SW();
	printf("%d",min_cut%10000);
	return 0;
}

void SW(){
	int s,t,max,max_v;
	for(int i=1;i<n;++i){
		memset(vis,false,sizeof vis);
		memset(dist,0,sizeof dist);
		s=t=0;
		for(int j=1;j<=n-i+1;++j){
			s=t;
			t=0;
			max=0;
			max_v=0;
			for(int k=1;k<=n;++k){
				if(!vis[k]&&!combine[k]){
					if(dist[k]>max||!max_v){
						max=dist[k];
						max_v=k;
					}
				}
			}
			t=max_v;
			vis[t]=true;
			for(int k=1;k<=n;++k){
				if(!combine[k]&&!vis[k])
					dist[k]+=map[t][k];
			}
		}
		if(min_cut>dist[t]) 
			min_cut=dist[t];
		combine[s]=1;
		for(int j=1;j<=n;++j){
				map[t][j]+=map[s][j];
				map[j][t]+=map[j][s];
		}
	}
}
