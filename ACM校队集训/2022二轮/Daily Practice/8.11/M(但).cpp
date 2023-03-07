#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,cnt=0,minx=1e9+10,maxx=-1e9-10;
		ll sum=0;
		scanf("%d",&n);
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			if(x<=0)cnt++,sum-=x;
			else sum+=x;
			minx=min(minx,x);
			maxx=max(maxx,x);
		}
		if(n==1)printf("%lld\n",cnt?-sum:sum);
		else if(!cnt)printf("%lld\n",sum-minx*2);
		else if(cnt==n)printf("%lld\n",sum+maxx*2);
		else printf("%lld\n",sum);
	}
	return 0;
}
