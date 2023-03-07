#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int idx[maxn],f[maxn],minx[maxn],chos[maxn],p[maxn];
ll a[maxn];
int fd_f(int x){
	if(x==f[x])return x;
	return f[x]=fd_f(f[x]);
}
bool cmp(int x,int y){
	if(chos[x]!=chos[y])return chos[x]<chos[y];
	return a[x]<a[y];
}
int main()
{
	int n,m,cnt;
	ll cost=0;
	scanf("%d%d",&n,&m);
	if(2*(n-1-m)>n){printf("Impossible");return 0;}
	cnt=2*(n-1-m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		f[i]=i;idx[i]=i;
		minx[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(fd_f(x)!=fd_f(y))minx[fd_f(y)]=a[minx[fd_f(x)]]<a[minx[fd_f(y)]]?minx[fd_f(x)]:minx[fd_f(y)],f[fd_f(x)]=fd_f(y);
	}
	for(int i=0;i<n&&cnt>0;i++)
	if(!p[fd_f(i)])cost+=a[minx[fd_f(i)]],p[fd_f(i)]=1,chos[minx[fd_f(i)]]=1,cnt--;
	sort(idx,idx+n,cmp);
	for(int i=0;i<cnt;i++)
	cost+=a[idx[i]];
	printf("%lld",cost);
	return 0;
}