#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;

struct Node{
	int r,l;
	ll sum;
	ll lazy_add;
	ll lazy_mul;
	Node(){
		sum=0,lazy_add=0,lazy_mul=1;
	}
}node[maxn<<2];
int n,m,tot=1;
int lll[maxn<<3],rr[maxn<<3];
ll ans;
ll arr[maxn];

void build(int l,int r,int cnt){
	node[cnt].r=r;
	node[cnt].l=l;
	if(r==l) {
		node[cnt].sum=arr[r];
		return;
	}
	int m=(r+l)/2;
	if(!lll[cnt]) lll[cnt]=++tot;
	build(l,m,tot);
	if(!rr[cnt]) rr[cnt]=++tot;
	build(m+1,r,tot);
	node[cnt].sum=node[lll[cnt]].sum+node[rr[cnt]].sum;
}

void pushdown(int cnt){
	if(node[cnt].l==node[cnt].r) return;
	node[lll[cnt]].sum+=node[cnt].lazy_add*(node[lll[cnt]].r-node[lll[cnt]].l+1);
	node[rr[cnt]].sum+=node[cnt].lazy_add*(node[rr[cnt]].r-node[rr[cnt]].l+1);
	
	node[lll[cnt]].lazy_add+=node[cnt].lazy_add;
	node[rr[cnt]].lazy_add+=node[cnt].lazy_add;
	
	node[cnt].lazy_add=0;
}

void addk(int cnt,int l,int r,int k){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		node[cnt].sum+=k;
		if(node[cnt].sum>1) node[cnt].sum=1;
		if(node[cnt].sum<-1) node[cnt].sum=-1;
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].r+node[cnt].l)/2;
	if(l<=mid) addk(lll[cnt],l,r,k);
	if(r>mid) addk(rr[cnt],l,r,k);
	node[cnt].sum=node[lll[cnt]].sum+node[rr[cnt]].sum;
}

void find_sum(int cnt,int l,int r){
	if(node[cnt].l>=l&&node[cnt].r<=r){
		ans=ans+node[cnt].sum;
		return;
	}
	pushdown(cnt);
	int mid=(node[cnt].l+node[cnt].r)/2;
	if(l<=mid) find_sum(lll[cnt],l,r);
	if(r>mid) find_sum(rr[cnt],l,r); 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		arr[i]=0;
	}
	build(1,n,tot);
	tot++;
	int start=tot;
	build(1,n,tot);
	//for(int i=1;i<=9;++i)
	//	printf("%d ",node[i].sum);
	//printf("\n");
	for(int i=0;i<m;++i){
		int opt,x,y,x1,y1,x2,y2;
		ll k;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%",&x,&y);
			addk(1,x,x,1);
			addk(start,y,y,1);
		//	for(int i=1;i<=9;++i) printf("%d ",node[i].sum);
		//	printf("\n");
		}
		if(opt==2){
			scanf("%d%d",&x,&y);
			addk(1,x,x,-1);
			addk(start,y,y,-1);
		}
		if(opt==3){
			bool flag=false;
			ans=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			find_sum(1,x1,x2);
			find_sum(start,y1,y2);
			if(ans==x2-x1+1+y2-y1+1) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
