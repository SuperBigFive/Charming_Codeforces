#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
typedef long long ll;
const int maxn=2e5+5;

int arr[maxn];
char str[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll num;
		scanf("%lld",&num);
		if(num%2||num==2){
			printf("-1\n");
			continue;
		}
		else{
			ll num_4=num/4;
			ll num_6=num/6;
			if(!(num%6)){
				printf("%lld ",num_6);
			}
			if(num%6){
				printf("%lld ",num_6+1);
			}
			if(!(num%4)){
				printf("%lld\n",num_4);
			}
			if(num%4){
				printf("%lld\n",num_4);
			}
		}
	}
	return 0;
}
