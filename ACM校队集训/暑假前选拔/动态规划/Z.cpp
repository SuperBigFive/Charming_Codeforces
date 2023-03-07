#include<iostream>
#include<cmath>
using namespace std;
const int maxn=5e2+5;
const int maxm=5e5+15;

int n,m;
int hit[maxn];
int weight[maxn];
int dp[maxn][maxm];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&hit[i]);
	for(int i=1;i<=n;++i) scanf("%d",&weight[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(j>=weight[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+hit[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
