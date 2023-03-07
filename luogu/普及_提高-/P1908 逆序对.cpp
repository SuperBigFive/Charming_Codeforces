#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;

struct node{
	ll value;
	int order;
}a[maxn];
int n;
ll ans;
ll aa[maxn],c[maxn],order[maxn];

bool cmp(node x,node y);
int lowbit(int x);
void update(int pos,ll val);
int get_sum(int l,int r);

int main(){
	scanf("%d",&n);
	ll value;
	for(int i=1;i<=n;++i){
		scanf("%lld",&value);
		a[i].value=value;
		a[i].order=i;
	}
	stable_sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i) aa[a[i].order]=i;
	for(int i=1;i<=n;++i){
		update(aa[i],1);
		ans+=i-get_sum(0,aa[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
bool cmp(node x,node y){
	return x.value<y.value;
}
int lowbit(int x){
	return x&(-x);
}
void update(int pos,ll val){
	int x=pos;
	while(x<=n){
		c[x]+=val;
		x+=lowbit(x);
	}
}
int get_sum(int l,int r){
	int suml=0;
	while(l>0){
		suml+=c[l];
		l-=lowbit(l);
	}
	int sumr=0;
	while(r>0){
		sumr+=c[r];
		r-=lowbit(r);
	}
	return sumr-suml;
}
