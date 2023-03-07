#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],dp[maxn][2],las[220];
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int t=2;t<=200;t++){
		for(int i=1;i<=n;i++){
			if(t-a[i]>0&&las[t-a[i]])dp[i][0]=max(dp[i-1][0],dp[las[t-a[i]]][1]+1);
			else dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][0]+1;
			las[a[i]]=i;
		}
		cnt=max(cnt,dp[n][0]);
		for(int i=1;i<=n;i++)
		las[a[i]]=0,dp[i][0]=dp[i][1]=0;
	}
	printf("%d",cnt);
	return 0;
}
