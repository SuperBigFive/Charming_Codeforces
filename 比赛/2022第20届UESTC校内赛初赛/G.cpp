#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=2e5+15;

struct Node{
	int r,l;
	ll num_n;
	ll num_s;
	ll num_e;
	ll num_w;
	ll sum_n;
	ll sum_s;
	ll sum_e;
	ll sum_w;
	ll lazy_n;
	ll lazy_s;
	ll lazy_e;
	ll lazy_w;
}node[maxn<<2];

int n,m,tot;
ll ans_n,ans_e;
char opt[maxn];

void build(int l,int r,int tot){
	node[tot].r=r;
	node[tot].l=l;
	if(r==l) {
		if(opt[l]=='E')
			node[tot].num_e=node[tot].sum_e=1;
			
		if(opt[l]=='W')
			node[tot].num_w=node[tot].sum_w=1;
		if(opt[l]=='N')
			node[tot].num_n=node[tot].sum_n=1;
		if(opt[l]=='S')
			node[tot].num_s=node[tot].sum_s=1;
		return;
	}
	int m=(r+l)/2;
	build(l,m,tot<<1);
	build(m+1,r,(tot<<1)+1);
	node[tot].sum_e=(node[tot<<1].sum_e+node[(tot<<1)+1].sum_e);
	node[tot].sum_w=(node[tot<<1].sum_w+node[(tot<<1)+1].sum_w);
	node[tot].sum_s=(node[tot<<1].sum_s+node[(tot<<1)+1].sum_s);
	node[tot].sum_n=(node[tot<<1].sum_n+node[(tot<<1)+1].sum_n);
	node[tot].num_e=node[tot].sum_e;
	node[tot].num_n=node[tot].sum_n;
	node[tot].num_s=node[tot].sum_s;
	node[tot].num_w=node[tot].sum_w;
}

void pushdown(int cnt){
	if(node[cnt].l==node[cnt].r) return;
	node[cnt<<1].sum_e+=node[cnt].lazy_e*node[cnt<<1].num_e;
	node[cnt<<1].sum_n+=node[cnt].lazy_n*node[cnt<<1].num_n;
	node[cnt<<1].sum_s+=node[cnt].lazy_s*node[cnt<<1].num_s;
	node[cnt<<1].sum_w+=node[cnt].lazy_w*node[cnt<<1].num_w;
	
	node[(cnt<<1)+1].sum_e+=node[cnt].lazy_e*node[(cnt<<1)+1].num_e;
	node[(cnt<<1)+1].sum_n+=node[cnt].lazy_n*node[(cnt<<1)+1].num_n;
	node[(cnt<<1)+1].sum_s+=node[cnt].lazy_s*node[(cnt<<1)+1].num_s;
	node[(cnt<<1)+1].sum_w+=node[cnt].lazy_w*node[(cnt<<1)+1].num_w;
	
	node[cnt<<1].lazy_w+=node[cnt].lazy_w;
	node[cnt<<1].lazy_s+=node[cnt].lazy_s;
	node[cnt<<1].lazy_e+=node[cnt].lazy_e;
	node[cnt<<1].lazy_n+=node[cnt].lazy_n;
	
	node[(cnt<<1)+1].lazy_w+=node[cnt].lazy_w;
	node[(cnt<<1)+1].lazy_s+=node[cnt].lazy_s;
	node[(cnt<<1)+1].lazy_e+=node[cnt].lazy_e;
	node[(cnt<<1)+1].lazy_n+=node[cnt].lazy_n;
	
	node[cnt].lazy_e=0;
	node[cnt].lazy_s=0;
	node[cnt].lazy_n=0;
	node[cnt].lazy_w=0;
}

void addk(int cnt,int l,int r,char opti){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		if(opti=='E') node[cnt].sum_e+=node[cnt].num_e,++node[cnt].lazy_e;
		if(opti=='W') node[cnt].sum_w+=node[cnt].num_w,++node[cnt].lazy_w;
		if(opti=='N') node[cnt].sum_n+=node[cnt].num_n,++node[cnt].lazy_n;
		if(opti=='S') node[cnt].sum_s+=node[cnt].num_s,++node[cnt].lazy_s;
		//pushdown(cnt);
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].r+node[cnt].l)/2;
	if(l<=mid) addk(cnt<<1,l,r,opti);
	if(r>mid) addk((cnt<<1)+1,l,r,opti);
	node[cnt].sum_e=(node[cnt<<1].sum_e+node[(cnt<<1)+1].sum_e);
	node[cnt].sum_w=(node[cnt<<1].sum_w+node[(cnt<<1)+1].sum_w);
	node[cnt].sum_s=(node[cnt<<1].sum_s+node[(cnt<<1)+1].sum_s);
	node[cnt].sum_n=(node[cnt<<1].sum_n+node[(cnt<<1)+1].sum_n);
}

void find_sum(int cnt,int l,int r){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		ans_n+=node[cnt].sum_n-node[cnt].sum_s;
		ans_e+=node[cnt].sum_e-node[cnt].sum_w;
		pushdown(cnt);
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].l+node[cnt].r)/2;
	if(l<=mid) find_sum(cnt<<1,l,r);
	if(r>mid) find_sum((cnt<<1)+1,l,r); 
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",opt+1);
	build(1,n,1);
	for(int i=0;i<m;++i){
		int optt,l,r,t;
		char x;
		scanf("%d",&optt);
		if(optt==1){
			scanf("%d%d %c",&l,&r,&x);
			addk(1,l,r,x);
		}
		else{
			scanf("%d%d%d",&l,&r,&t);
			ans_n=0;
			ans_e=0;
			ll sum_n=0,sum_e=0;
			int times=t/(r-l+1);
			ll Times=t%(r-l+1);
			if(!Times){
				find_sum(1,l,r);
				printf("%lld %lld\n",times*ans_e,times*ans_n);
				continue;
			}
 			if(times>0){
				find_sum(1,l,r);
				sum_n=ans_n*times;
				sum_e=ans_e*times;
			}
			ans_n=0;
			ans_e=0;
			find_sum(1,l,l+Times-1);
			printf("%lld %lld\n",sum_e+ans_e,sum_n+ans_n);
		}
	}
	return 0;
}
