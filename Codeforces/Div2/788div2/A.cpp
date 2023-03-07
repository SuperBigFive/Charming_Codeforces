#include<iostream>
#include<cmath>
using namespace std;
const int maxn=2e5+15;
int arr[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int key=0;
		scanf("%d",&n);
		int neg=0;
		scanf("%d",&arr[1]);
		if(arr[1]<0) ++neg;
		for(int i=2;i<=n;++i){
			scanf("%d",&arr[i]);
			if(arr[i]<0) ++neg;
		}
		for(int i=2;i<=neg;++i){
			if(abs(arr[i])>abs(arr[i-1])){
				printf("NO\n");
				key=1;
				break;
			}
		}
		if(key) continue;
		for(int i=neg+2;i<=n;++i){
			if(abs(arr[i])<abs(arr[i-1])){
				printf("NO\n");
				key=1;
				break;
			}
		}
		if(key) continue;
		printf("YES\n");
	}	
}
