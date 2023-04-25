#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],apr[maxn],firs[maxn],cnt[maxn],n;
long long ans[maxn];
void add(int pos,int val){
	for(int i=pos;i<=n;i+=i&(-i))
	cnt[i]+=val;
}
int get(int pos){
	int cntn=0;
	for(int i=pos;i;i-=i&(-i))
	cntn+=cnt[i];
	return cntn;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		ans[1]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		add(a[1],1),apr[a[1]]=1;
		for(int i=2;i<=n;i++){
			ans[i]=ans[i-1];
			if(!apr[a[i]])add(a[i],1),apr[a[i]]=1;
			else apr[a[i]]++;
			if(apr[a[i]]==2)firs[a[i]]=i;
			if(a[i]>a[1])swap(a[i],a[1]),ans[i]+=apr[a[i]]>1?i-firs[a[i]]+1:1;
			ans[i]+=get(n)-get(a[i]);
		}
		for(int i=1;i<n;i++)
		printf("%lld ",ans[i]);
		printf("%lld\n",ans[n]);
		for(int i=1;i<=n;i++)
		apr[i]=cnt[i]=0;
	}
	return 0;
}
