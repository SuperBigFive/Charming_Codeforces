#include<iostream>
using namespace std;
const int maxn=31;
int arr[maxn];

int main(){
	int t;
	scanf("%d",&t);
	int opt;
	while(t--){
		int n;
		opt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&arr[i]);
		}
		for(int i=n-1;i>=1;--i){
			if(!arr[i+1]){
				opt=-1;
				break;
			}
			while(arr[i]>=arr[i+1]){
					arr[i]/=2;
					++opt;
			}
		}
		printf("%d\n",opt);
	}
	return 0;
}
