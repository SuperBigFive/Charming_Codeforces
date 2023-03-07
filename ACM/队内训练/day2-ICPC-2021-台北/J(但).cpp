#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
		for(int i=1,s;i<=m;i++)
		scanf("%d",&s);
		printf("%lld\n",((ll)(n+p-m-2)*(n-1)+(ll)(n-p)*p)*2);
	}
	return 0;
}