#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		int n,r,b;
		scanf("%d%d%d",&n,&r,&b);
		int cnt=1;
		while(r>=(b+1)*cnt) cnt++;
		int times=r-(b+1)*(--cnt);
		while(b--){
			for(int i=0;i<cnt;++i)
				printf("R");
			if(times-->0)
				printf("R");
			printf("B");
			if(!b){
				for(int i=0;i<cnt;++i){
					printf("R");
					if(times-->0)
						printf("R");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
