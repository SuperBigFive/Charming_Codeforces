#include<iostream>
using namespace std;
const int maxn=2e5+5;

int arr[maxn];
bool used[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
		if(arr[n]-arr[1]<=n+1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
