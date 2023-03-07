#include<iostream>
using namespace std;
const int maxn=1e6+25;

int main(){
	int t;
	scanf("%d",&t);
	int a,b,c,x,y;
	while(t--){
		scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
		if(x>=a){
			int res=c-(x-a);
			if(res<0){
				printf("NO\n");
				continue;
			}
			if(res+b<y){
				printf("NO\n");
				continue;
			}
			else{
				printf("YES\n");
				continue;
			}
		}
		if(y>=b){
			int res=c-(y-b);
			if(res<0){
				printf("NO\n");
				continue;
			}
			if(res+a<x){
				printf("NO\n");
				continue;
			}
			else{
				printf("YES\n");
				continue;
			}
		}
		printf("YES\n");
	}
	return 0;
}
