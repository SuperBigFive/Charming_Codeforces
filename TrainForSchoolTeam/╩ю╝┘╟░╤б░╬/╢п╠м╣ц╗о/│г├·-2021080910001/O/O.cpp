#include<iostream>
#include<cmath> 
using namespace std;
typedef long long ll;
const int maxn=1e6+15;
const int maxw=4e5+15;

ll dp[maxw];
ll val[maxn];
ll weight[maxn];

int main(){
	int n,w;
	scanf("%d%d",&n,&w);

	int tot=0;
	ll v,c,m;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&v,&c,&m);
		int cnt=1;
		while(cnt<m){
			val[++tot]=cnt*v;
			weight[tot]=cnt*c;
			m-=cnt;
			cnt=cnt<<1; 
		}
		val[++tot]=m*v;
		weight[tot]=m*c;
		--cnt;
		/*val[++tot]=(m-pow(2,cnt)+1)*v;
		weight[tot]=(m-pow(2,cnt)+1)*c;
		//if(cnt==1) continue;
		while(true){
			val[++tot]=pow(2,cnt-1)*v;
			weight[tot]=pow(2,cnt-1)*c;
			//--cnt;
			if(--cnt<1) break;
		}*/
	}
	for(int i=1;i<=tot;++i){
		for(int j=w;j>=weight[i];--j){
			dp[j]=max(val[i]+dp[j-weight[i]],dp[j]);
		}
	}
	printf("%lld\n",dp[w]);
	return 0;
}
