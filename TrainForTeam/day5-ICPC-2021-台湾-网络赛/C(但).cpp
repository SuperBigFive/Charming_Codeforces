#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],cnt[maxn];
void add(int pos,int n,int x){
	for(int i=pos;i<=n;i+=i&(-i))
	cnt[i]+=x;
}
int get(int pos){
	int ans=0;
	for(int i=pos;i;i-=i&(-i))
	ans+=cnt[i];
	return ans;
}
int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=n;i;i--){
		ans+=get(a[i]-1);
		add(a[i],n,1);
	}
	printf("%lld",ans);
	return 0;
}
