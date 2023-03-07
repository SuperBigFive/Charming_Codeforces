#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int a[maxn],stk[maxn],st[maxn],ans[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int tp=0,cnt=0,n,k,t=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=n&&cnt<k;i++){
			while(tp&&stk[tp]<a[i]&&cnt<k)st[++cnt]=stk[tp],tp--;
			stk[++tp]=a[i];
		}
		sort(st+1,st+cnt+1);
		for(int i=tp+cnt+1;i<=n;i++)
		stk[++tp]=a[i];
		for(int i=1,j=cnt;i<=tp||j>0;)
		if(i>tp||(j&&st[j]>stk[i]))ans[++t]=st[j],j--;
		else ans[++t]=stk[i],i++;
		for(int i=1;i<t;i++)
		printf("%d ",ans[i]);
		printf("%d\n",ans[t]);
	}
	return 0;
}