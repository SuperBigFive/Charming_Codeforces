#include <iostream>
using namespace std;
const int maxn=5e5+5;

int n,m;
int a[maxn],d[maxn],sum_d1[maxn],sum_d2[maxn]; 

int lowbit(int x);
void update(int pos,int val);
void update2(int l,int r,int val);
int get_sum(int l,int r);

int main(){
	scanf("%d%d",&n,&m);
	int opt,x,y,k;
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		a[i]=k;
		update(i,a[i]-a[i-1]);
	}
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&x,&y,&k);
			update2(x,y,k);
		}
		else{
			scanf("%d",&x);
			printf("%d\n",get_sum(x-1,x));
		}
	}
	return 0;
}
int lowbit(int x){
	return x&(-x);
}
void update(int pos,int val){
	int x=pos;
	d[pos]+=val;
	while(x<=n){
		sum_d1[x]+=val;
		sum_d2[x]+=val*(pos-1);
		x+=lowbit(x);
	}
}
void update2(int l,int r,int val){
	update(l,val);
	update(r+1,-val);
}
int get_sum(int l,int r){
	int tmp=l;
	int suml=0;
	while(tmp>0){
		suml+=l*sum_d1[tmp]-sum_d2[tmp];
		tmp-=lowbit(tmp);
	}
	int sumr=0;
	tmp=r;
	while(tmp>0){
		sumr+=r*sum_d1[tmp]-sum_d2[tmp];
		tmp-=lowbit(tmp);
	}
	return sumr-suml;
}
