#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+25;

int n,mod;
int dp[maxn][maxn];

int main(){
	scanf("%d%d",&n,&mod);
	dp[2][2]=1;
	for(int i=3;i<=n;++i){
		for(int j=2;j<=n;++j){
			dp[i][j]=(dp[i][j-1]+dp[i-1][(i-1+1)-(j-1)])%mod;
		}
	}
	ll ans=0;
	for(int i=2;i<=n;++i) ans=(ans+dp[n][i])%mod;
	ans=(ans*2)%mod;
	printf("%d\n",ans);
	return 0;
}
