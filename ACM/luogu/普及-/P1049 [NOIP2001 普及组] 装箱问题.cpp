#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=31;
const int maxv=2e4+15;

int n,vm;
int box[maxn];
int dp[maxn][maxv];

int main(){
	scanf("%d%d",&vm,&n);
	for(int i=1;i<=n;++i) scanf("%d",&box[i]);
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=vm;++j){
			if(box[i]<=j){
				dp[i][j]=max(dp[i-1][j-box[i]]+box[i],dp[i-1][j]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",vm-dp[n][vm]);
	return 0;
} 
