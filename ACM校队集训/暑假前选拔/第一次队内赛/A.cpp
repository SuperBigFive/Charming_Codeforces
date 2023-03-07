#include<iostream>
using namespace std;
const int maxn=5e3+5;

struct Edge{
	int to;
	int next;
}edge[maxn];
int n,tot;
int head[maxn];

void add(int u,int v){
	edge[++tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int vv;
		scanf("%d",&vv);
		add(i,vv);
		add(vv,i);
	}
	for(int i=1;i<=n;++i){
		for(int j=head[i];j;j=edge[j].next){
			int v1=edge[j].to;
			for(int k=head[v1];k;k=edge[k].next){
				int v2=edge[k].to;
				for(int m=head[v2];m;m=edge[m].next){
					if(edge[m].to==i){
						printf("YES\n");
						return 0;
					}
					else continue;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}
