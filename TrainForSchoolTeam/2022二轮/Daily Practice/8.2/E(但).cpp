#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],dp[maxn];
int find(int x,int l,int r,int t[]){
	while(l<r){
		int mid=((l+r)>>1)+1;
		if(t[mid]>x)r=mid-1;
		else l=mid;
	}
	if(t[l]>x)return l-1;
	return l;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t=find(a[i]-k,1,i,a);
		dp[i]=max(dp[t]+1,dp[i-1]);
	}
	printf("%d",dp[n]);
	return 0;
}
