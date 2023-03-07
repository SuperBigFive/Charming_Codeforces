#include <iostream>
using namespace std;
const int maxn=5e5+5;

int n,m;
int a[maxn],c[maxn];

int lowbit(int x){
	return x&(-x);
}
void updata(int pos,int val){
	a[pos]+=val;
	while(pos<=n){
		c[pos]+=val;
		pos+=lowbit(pos);
	}
}
int get_sum(int l,int r){
	int suml=0,sumr=0;
	while(l>0){
		suml+=c[l];
		l-=lowbit(l);
	}
	while(r>0){
		sumr+=c[r];
		r-=lowbit(r);
	}
	return sumr-suml;
}

int main(){
	scanf("%d%d",&n,&m);
	int opt,x,k;
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		updata(i,k);
	}
	while(m--){
		scanf("%d%d%d",&opt,&x,&k);
		if(opt==1) updata(x,k);
		else printf("%d\n",get_sum(x-1,k));
	}
	return 0;
}
