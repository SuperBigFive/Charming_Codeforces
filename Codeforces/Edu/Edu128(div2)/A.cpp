#include<iostream>
using namespace std;
const int maxn=2e5+15;

int arr[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==l2){
			printf("%d\n",l1);
			continue;
		}
		if(l1<l2){
			if(r1>=l2){
				printf("%d\n",l2);
				continue;
			}
			else{
				printf("%d\n",l1+l2);
				continue;
			}
		}
		if(l1>l2){
			if(r2>=l1){
				printf("%d\n",l1);
				continue;
			}
			else{
				printf("%d\n",l1+l2);
				continue;
			}
		}
	}
	return 0;
}
