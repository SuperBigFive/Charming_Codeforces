#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
const int maxm=2e3+5;
struct edge{
	int child1;
	int child2;
}edge[maxm];
int value[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&value[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&edge[i].child1,&edge[i].child2);
	}
	ll ans=0;
	for(int i=1;i<=m;++i){
		ans+=(value[edge[i].child1]>value[edge[i].child2]?value[edge[i].child2]:value[edge[i].child1]);
	}
	printf("%lld\n",ans);
	return 0;
}
