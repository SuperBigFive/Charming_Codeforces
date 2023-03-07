#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e5+15;

int arr[101];
int map[101];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		bool flag=false;
		for(int i=1;i<=100;++i) map[i]=0;
		int tmp=n;
		for(int i=1;i<=n;++i){
			scanf("%d",&arr[i]);
			++map[arr[i]];
			if(map[arr[i]]==2) flag=true;
			if(!arr[i]) flag=true,--tmp;
		}
		if(flag){
			printf("%d\n",tmp);
			continue;
		}
		else{
			printf("%d\n",n+1);
		}
	}
}
