#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const int maxn = 3e3+10;
typedef long long ll;
int b[maxn],c,len;
ll cnt[maxn];
ll comp[maxn][maxn];
ll qpow(ll x,ll y)
{
	ll ret = 1;
	for(;y;y>>=1)
	{
		if(y&1)ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod;
	}
	return ret;
}
void modify(int pos,int base)
{
	int slen = len - pos - 1;
	for(int i=0;i<=slen;++i)
	{
		cnt[base + i] = (cnt[base + i] + comp[slen][i]) % mod; 
	}
}
int main()
{
	string str;
	cin>>str>>c;
	len = str.length();
	for(int i=0;i<=len;++i)comp[i][0]=1;
	for(int i=1;i<=len;++i)
	{
		for(int j=1;j<=i;++j)comp[i][j]=(comp[i-1][j-1]+comp[i-1][j])%mod;
	}
	int base = 0;
	for(int i=0;i<len;++i)
	{
		if(str[i] == '1')
		{
			modify(i, base);
			++base;
		}
	}
	++cnt[base];
	ll ans = 0;
	for(int i=0;i<=len;++i)
	{
		ans = (ans + 1ll * cnt[i] * qpow(c, i) % mod) % mod;
	}
	cout<<ans<<endl;
	return 0;
}

