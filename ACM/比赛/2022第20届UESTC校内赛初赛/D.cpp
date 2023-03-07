#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=2e5+15;

struct Node{
	ll l;
	ll r;
	int val;
}node[maxn];

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		node[i].l=node[i-1].r+1;
		int temp;
		ll cnt=1;
		scanf("%d",&temp);
		while(!(temp%3)) temp/=3,cnt*=3;
		node[i].r=node[i].l+cnt-1;
		node[i].val=temp;
	}
	int pos=1;
	for(int i=1;i<=m;++i){
		ll q;
		scanf("%lld",&q);
		while(q>node[pos].r) ++pos;
		printf("%d ",node[pos].val);
	}
	return 0;
}
