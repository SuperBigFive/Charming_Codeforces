#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],st[maxn],cnt[maxn],cnt2[maxn],ans[maxn],sqr;
struct Q{
	int l,r,idx;
	bool operator<(const Q a)const
	{
		if(l/sqr!=a.l/sqr)return l/sqr<a.l/sqr;
		return r<a.r;
	}
}que[maxn];
int main()
{
	int n,m,nans=0;
	scanf("%d%d",&n,&m);
	sqr=sqrt(n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]),st[i]=a[i];
	sort(st,st+n);
	int nw=unique(st,st+n)-st;
	for(int i=0;i<n;i++)
	a[i]=lower_bound(st,st+nw,a[i])-st;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&que[i].l,&que[i].r);
		que[i].l--;que[i].r--;
		que[i].idx=i;
	}
	sort(que+1,que+m+1);
	for(int i=1,l=(que[1].l/sqr+1)*sqr,r=l-1;i<=m;i++){
		if(que[i].l/sqr!=que[i-1].l/sqr){
			for(int j=l;j<=r;j++)
			cnt[a[j]]=0;
			l=min(n,(que[i].l/sqr+1)*sqr),r=l-1;
			nans=0;
		}
		while(r<que[i].r){
			cnt[a[++r]]++;
			if(cnt[a[r]]==st[a[r]])nans++;
			else if(cnt[a[r]]==st[a[r]]+1)nans--;
		}
		int t=0;
		for(int j=min(l-1,que[i].r);j>=que[i].l;j--){
			cnt2[a[j]]++;
			if(cnt[a[j]]+cnt2[a[j]]==st[a[j]])t++;
			else if(cnt[a[j]]+cnt2[a[j]]==st[a[j]]+1)t--;
		}
		ans[que[i].idx]=nans+t;
		for(int j=min(l-1,que[i].r);j>=que[i].l;j--)
		cnt2[a[j]]--;
	}
	for(int i=1;i<=m;i++)
	printf("%d\n",ans[i]);
	return 0;
}