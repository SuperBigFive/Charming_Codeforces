#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
const int maxn=1e5+5;

int lemon_pos[maxn][2];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i){
		int lemon;
		scanf("%d",&lemon);
		if(lemon_pos[lemon][0]) lemon_pos[lemon][1]=i;
		else lemon_pos[lemon][0]=i;
	}
	ll ans=0;
	ans+=lemon_pos[1][0]+lemon_pos[1][1];
	int person1=lemon_pos[1][0],person2=lemon_pos[1][1];
	ll cost1,cost2;
	for(int i=2;i<=n;++i){
		cost1=abs(person1-lemon_pos[i][0])+abs(person2-lemon_pos[i][1]);
		cost2=abs(person1-lemon_pos[i][1])+abs(person2-lemon_pos[i][2]);
		if(cost1<cost2){
			person1=lemon_pos[i][0];
			person2=lemon_pos[i][1];
			ans+=cost1;
		}
		else{
			person1=lemon_pos[i][1];
			person2=lemon_pos[i][0];
			ans+=cost2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
