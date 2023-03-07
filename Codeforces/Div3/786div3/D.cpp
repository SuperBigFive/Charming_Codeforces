#include<stdio.h>
const int maxn=2e5+5;
int flag;
int a[maxn],b[maxn],c[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
				if(n==1){
			printf("YES\n");
			continue;
		}
		flag=0;
		for(int i=n;i>=1;){
			int mmin=a[i]<a[i-1]?a[i]:a[i-1];
			i=i-2;
			if(i==1){
				if(a[i]>mmin){
					printf("NO\n");
					flag=1;
				}
				break;
			}
			int mmax=a[i]>a[i-1]?a[i]:a[i-1];
			if(mmin<mmax){
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if(flag) continue;
		printf("YES\n");
	}
}
