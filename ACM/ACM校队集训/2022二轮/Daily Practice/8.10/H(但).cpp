#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxn=1010,maxd=10;
int a[maxn][maxn],cnt[maxn];
int main()
{
	a[0][1]=1;
	cnt[0]=1;
	for(int i=1;i<=maxn-10;i++){
		for(int j=1;j<=cnt[i-1];j++)
		a[i][j]=a[i-1][j]*2;
		cnt[i]=cnt[i-1];
		for(int j=1;j<=cnt[i];j++)
		if(a[i][j]>=maxd)a[i][j+1]+=a[i][j]/maxd,a[i][j]%=maxd;
		if(a[i][cnt[i]+1])cnt[i]++;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=cnt[n];i;i--)
		printf("%d",a[n][i]);
		printf("\n");
	}
	return 0;
}