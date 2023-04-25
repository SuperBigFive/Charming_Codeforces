#include<bits/stdc++.h>
using namespace std;
const int maxn=50,maxt=1e3;
int cnt[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,upr=0;
		scanf("%d",&n);
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			for(int j=0;x;j++){
				if(x%2)cnt[j]++;
				x>>=1;
				upr=max(upr,j);
			}
		}
		for(int i=1,mk=1;i<=maxt&&mk;i++){
			mk=0;
			for(int j=upr;j;j--)
			if(cnt[j]>cnt[j-1]){
				int k=(cnt[j]-cnt[j-1])/3;
				if(k*3+cnt[j-1]<cnt[j])k++;
				cnt[j-1]+=k*2,cnt[j]-=k;
				mk=1;
			}
		}
		printf("%d\n",cnt[0]);
		for(int i=0;i<=upr;i++)
		cnt[i]=0;
	}
	return 0;
}
