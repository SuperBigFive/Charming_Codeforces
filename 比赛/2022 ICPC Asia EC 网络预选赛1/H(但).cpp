#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll mod=20220911;
ll a[maxn];
char s[100];
int main()
{
	int nw=0;
	scanf("%s",s);
	while(s[0]!='f'||s[1]!='i'){
		if(s[0]=='l')a[nw]=(a[nw]+1)%mod;
		else if(s[0]=='r')nw++;
		else if(s[0]=='f'&&s[1]=='o'){
			ll t;
			scanf("%lld",&t);
			a[nw-1]=(a[nw-1]+a[nw]*t%mod)%mod;
			a[nw]=0;
			nw--;
		}
		scanf("%s",s);
	}
	printf("%lld",a[0]);
	return 0;
}