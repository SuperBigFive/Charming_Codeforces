#include<iostream>
#include<cstring>
typedef long long ll;
const int maxn=5e3+15;

int pc[maxn][maxn];
int pb[maxn][maxn];
int arr[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		//memset(pb,0,sizeof pb);
		for(int i=0;i<=n+1;++i){
			for(int j=0;j<=n+1;++j){
				pb[i][j]=pc[i][j]=0;
			}
		}
		//memset(pc,0,sizeof pc);
		for(int i=1;i<=n;++i){
			scanf("%d",&arr[i]);
		}
		for(int i=1;i<=n;++i){
			pc[i][1]=0;
			for(int j=2;j<=i;++j){
				pc[i][j]=pc[i][j-1];
				if(arr[j-1]<arr[i]) ++pc[i][j];
			}
		}
		
		/*for(int i=1;i<=n;++i){
			for(int j=i;j>1;--j){
				printf("%d在第%d个数前面一共有%d个数比他小\n",arr[i],j,pc[i][j]);
			}
		}*/
		
		for(int i=1;i<=n;++i){
			arr[n+1]=-1;
			for(int j=n-1;j>=i;--j){
				pb[i][j]=pb[i][j+1];
				if(arr[j+1]<arr[i]) ++pb[i][j];
			}
		}
		/*printf("\n");
		for(int i=1;i<n-1;++i){
			for(int j=i;j<n;++j){
				printf("%d在第%d个数后面一共有%d个数比他小\n",arr[i],j,pb[i][j]);
			}
		}*/
		
		ll ans=0;
		for(int i=2;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				ans+=pb[i][j]*pc[j][i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
