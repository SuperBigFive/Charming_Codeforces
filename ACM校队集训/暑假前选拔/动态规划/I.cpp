#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=8e3+15;

int arr[maxn];
int dp[maxn][maxn];
int XOR[maxn][maxn];
int tmp[maxn][maxn];

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
		dp[i][i]=arr[i];
		tmp[1][i]=arr[i];
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			tmp[i][j]=tmp[i-1][j]^tmp[i-1][j+1];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			XOR[i][j]=tmp[j-i+1][i];
		}
	}
	/*for(int i=1;i<=n;++i){
		for(int j=2;j<=i;++j) printf("  ");
		for(int j=i;j<=n;++j) printf("%d ",XOR[i][j]);
		printf("\n");
	}*/
	for(int len=2;len<=n;++len){
		for(int i=1;i<n;++i){
			int j=i+len-1;
			dp[i][j]=max(XOR[i][j],dp[i+1][j]);
			dp[i][j]=max(dp[i][j],dp[i][j-1]);
		}
	}
	scanf("%d",&m);
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",dp[l][r]);
	}
	return 0;
}
