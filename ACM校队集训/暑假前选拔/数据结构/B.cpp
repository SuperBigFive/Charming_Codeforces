#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=998244353;

struct Node{
	int r,l;
	ll sum;
	ll lazy_add;
	ll lazy_mul;
	Node(){
		sum=0,lazy_add=0,lazy_mul=1;
	}
}node[maxn<<2];
int n,m,tot;
ll ans;
ll arr[maxn];

void build(int l,int r,int tot){
	node[tot].r=r;
	node[tot].l=l;
	node[tot].lazy_mul=1;
	if(r==l) {
		node[tot].sum=arr[r]%mod;
		return;
	}
	int m=(r+l)/2;
	build(l,m,tot<<1);
	build(m+1,r,(tot<<1)+1);
	node[tot].sum=(node[tot<<1].sum+node[(tot<<1)+1].sum)%mod;
}

void pushdown(int cnt){
	if(node[cnt].l==node[cnt].r) return;
	node[cnt<<1].sum=(ll)(node[cnt].lazy_mul*node[cnt<<1].sum+node[cnt].lazy_add*(node[cnt<<1].r-node[cnt<<1].l+1))%mod;
	node[cnt<<1].lazy_add=(ll)(node[cnt<<1].lazy_add*node[cnt].lazy_mul+node[cnt].lazy_add)%mod;
	node[cnt<<1].lazy_mul=(ll)(node[cnt<<1].lazy_mul*node[cnt].lazy_mul)%mod;
	node[(cnt<<1)+1].sum=(ll)(node[cnt].lazy_mul*node[(cnt<<1)+1].sum+node[cnt].lazy_add*(node[(cnt<<1)+1].r-node[(cnt<<1)+1].l+1))%mod;
	node[(cnt<<1)+1].lazy_add=(ll)(node[(cnt<<1)+1].lazy_add*node[cnt].lazy_mul+node[cnt].lazy_add)%mod;
	node[(cnt<<1)+1].lazy_mul=(ll)(node[cnt].lazy_mul*node[(cnt<<1)+1].lazy_mul)%mod;
	node[cnt].lazy_mul=1;
	node[cnt].lazy_add=0;
}

void addk(int cnt,int l,int r,int k){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		node[cnt].sum=(node[cnt].sum+(node[cnt].r-node[cnt].l+1)*k)%mod;
		node[cnt].lazy_add=(node[cnt].lazy_add+k)%mod;
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].r+node[cnt].l)/2;
	if(l<=mid) addk(cnt<<1,l,r,k);
	if(r>mid) addk((cnt<<1)+1,l,r,k);
	node[cnt].sum=(node[cnt<<1].sum+node[(cnt<<1)+1].sum)%mod;
}

void mulk(int cnt,int l,int r,int k){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		node[cnt].sum=(node[cnt].sum*k)%mod;
		node[cnt].lazy_mul=(node[cnt].lazy_mul*k)%mod;
		node[cnt].lazy_add=(node[cnt].lazy_add*k)%mod;
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].l+node[cnt].r)/2;
	if(l<=mid) mulk(cnt<<1,l,r,k);
	if(r>mid) mulk((cnt<<1)+1,l,r,k);
	node[cnt].sum=(node[cnt<<1].sum+node[(cnt<<1)+1].sum)%mod;
}
void find_sum(int cnt,int l,int r){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		ans=(ans+node[cnt].sum)%mod;
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].l+node[cnt].r)/2;
	if(l<=mid) find_sum(cnt<<1,l,r);
	if(r>mid) find_sum((cnt<<1)+1,l,r); 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		ll num;
		scanf("%lld",&num);
		arr[i]=num;
	}
	build(1,n,1);
	//for(int i=1;i<=9;++i)
	//	printf("%d ",node[i].sum);
	//printf("\n");
	for(int i=0;i<m;++i){
		int opt,x,y;
		ll k;
		scanf("%d",&opt);
		if(opt!=3){
			scanf("%d%d%lld",&x,&y,&k);
			if(opt==1) mulk(1,x,y,k);
			else addk(1,x,y,k);
		//	for(int i=1;i<=9;++i) printf("%d ",node[i].sum);
		//	printf("\n");
		}
		else{
			scanf("%d%d",&x,&y);
			ans=0;
			find_sum(1,x,y);
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
}
