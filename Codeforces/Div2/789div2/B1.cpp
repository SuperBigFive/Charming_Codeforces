#include<iostream>
using namespace std;
const int maxn=2e5+15;

char arr[maxn];
int a[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,tot=0,len=1;
		scanf("%d",&n);
		scanf(" %c",&arr[1]);
		for(int i=2;i<=n;++i){
			scanf(" %c",&arr[i]);
			if(arr[i]-'0'!=arr[i-1]-'0'){
				++tot;
				a[tot]=len;
				len=1;
				continue;
			}
			++len;
		}
		//if(arr[n]-'0'==arr[n-1]-'0'){
			a[++tot]=len;
		//}
		int ans=0;
		int i,j;
		for(i=1;i<=tot;++i){
			if(a[i]%2){
				for(j=i+1;j<=tot;++j){
					if(a[j]%2){
						ans+=j-i;
						break;
					}
				}
				i=j;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
