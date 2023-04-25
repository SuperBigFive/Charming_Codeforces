#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7,ni=41666667;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,ans;
		scanf("%lld",&n);
		ans=(n*n%mod*n%mod*n%mod+6*n%mod*n%mod*n%mod+11*n%mod*n%mod+6*n)%mod;
		ans=ans*ni%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
