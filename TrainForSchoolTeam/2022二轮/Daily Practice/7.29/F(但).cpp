#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=150;
ll siz[maxn];
int num[maxn][2],cnt_tree;
int construct(ll t){
	for(int i=0;i<=cnt_tree;i++)
	if(siz[i]==t)return i;
	int u,v;
	if(t%2)u=construct(t/2),v=construct(t/2+1);
	else u=v=construct(t/2);
	siz[++cnt_tree]=t;
	num[cnt_tree][0]=v;
	num[cnt_tree][1]=u;
	return cnt_tree;
}
int main()
{
	int t;
	scanf("%d",&t);
	num[0][0]=num[0][1]=-1;
	siz[0]=1;
	while(t--){
		ll n;
		scanf("%lld",&n);
		cnt_tree=0;
		int ans=construct(n);
		printf("%d\n",cnt_tree+1);
		for(int i=0;i<=cnt_tree;i++)
		printf("%d %d\n",num[i][0],num[i][1]);
		printf("%d\n",ans);
	}
	return 0;
}
