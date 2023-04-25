#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
const int maxn=2e5+5;

ll arr[maxn];
char str[maxn];
bool change[maxn];
int st[maxn];

int main(){
	int n,q;
	ll sum=0;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%lld",&arr[i]);
		sum+=arr[i];
	}
	int opt;
	int x1,x2;
	ll x3;
	ll num;
	bool key=false;
	int tot=0;
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x1,&x2);
			bool exist=false;
			for(int i=1;i<=tot;++i) if(st[i]==x1) exist=true;
			if(exist||!key){
				sum+=x2-arr[x1];
				arr[x1]=x2;
				printf("%lld\n",sum);
			}
			else{
				sum+=x2-num;
				arr[x1]=x2;
				st[++tot]=x1;
				printf("%lld\n",sum);
			}
		}
		else{
			scanf("%lld",&x3);
			sum=n*x3;
			num=x3;
			while(tot>=0){
				st[tot--]=-1;
			}
			tot=0;
			key=true;
			printf("%lld\n",sum);
		}
	}
	//printf("%lld\n",sum);
	return 0;
}
