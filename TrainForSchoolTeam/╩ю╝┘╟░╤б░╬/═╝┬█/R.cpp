#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e2+5;
const int maxm=1e5+5;
const int maxw=1e6+5;

struct Edge{
    int u;
	int v;
	int w;
}edge[maxm];
int n,m,r,ans,tot=1;
int min_weight[maxn],pre[maxn],re[maxn],vis[maxn];

bool zhuliu(){
    while(tot){
    	memset(vis,-1,sizeof vis);
    	memset(re,-1,sizeof re);
    	memset(min_weight,maxw,sizeof min_weight);
        for(int i = 0; i < m; ++ i){
            if(edge[i].u!= edge[i].v){
            	if(edge[i].w < min_weight[edge[i].v]){
		            min_weight[edge[i].v] = edge[i].w;
		            pre[edge[i].v] = edge[i].u;
		        }
            }
        }
        for(int i = 1; i <= n; ++ i){
            if(i != r && min_weight[i] == maxw){
                return false;
            }
        }
        min_weight[r] = 0;
        tot = 0;
        for(int i = 1; i <= n; ++ i){
            ans += min_weight[i];
            int v = i;
            while(vis[v] != i && re[v] == -1 && v != r){
                vis[v] = i;
                v = pre[v];
            }
            if(v != r && re[v] == -1){
                re[v] = ++tot;
                for(int u = pre[v]; u != v; u = pre[u])
					re[u] = tot;
            }
        }
        if(!tot) return true;
        for(int i = 1; i <= n; ++ i){
            if(re[i] == -1){
                re[i] = ++tot;
            }
        }
        for(int i=0;i < m;){
            int vv = edge[i].v;
            edge[i].u = re[edge[i].u], edge[i].v = re[edge[i].v];
            if(edge[i].u != edge[i].v){
                edge[i ++].w -= min_weight[vv];
            }
            else{
                swap(edge[i],edge[-- m]);
            }
        }
        n = tot;
        r = re[r];
    }
}
int main(){	
    scanf("%d%d%d", &n, &m, &r);
    for(int i = 0; i <m; ++i){
    	int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i].u = u,edge[i].v = v,edge[i].w = w;
    }
    if(!zhuliu()) 
		printf("-1\n");
    else 
		printf("%d\n", ans);
    return 0;
}
