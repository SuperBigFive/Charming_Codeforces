#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct p{
	ll a,c;
	bool operator<(const p a)const
	{
		return c<a.c;
	}
}opt[maxn];
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	ll n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%lld%lld",&opt[i].a,&opt[i].c);
	sort(opt+1,opt+m+1);
	for(int i=1;i<=m&&n>1;i++){
		ll gcdi=gcd(n,opt[i].a);
		if(gcdi==n)continue;
		ans+=(n/gcdi-1)*gcdi*opt[i].c;
		n=gcdi;
	}
	if(n>1)printf("-1");
	else printf("%lld",ans);
	return 0;
}