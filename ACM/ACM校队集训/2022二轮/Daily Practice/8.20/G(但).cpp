#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
typedef long long ll;
ll mul(ll x,ll a){
	if(a==0)return 1;
	if(a==1)return x%mod;
	ll t=mul(x,a/2);
	if(a%2)return t*t%mod*x%mod;
	return t*t%mod;
}
int main()
{
	ll n,m,ans=1;
	scanf("%lld%lld",&n,&m);
	for(int i=2;i<=n;i++){
		ans=ans*i%mod;
		if(ans%2==0&&m>0)ans/=2,m--;
	}
	ans=ans*mul(2,m*(mod-2))%mod;
	printf("%lld",ans);
	return 0;
}