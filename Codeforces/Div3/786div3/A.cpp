#include<stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		int z=y/x;
		/*if(x==1&&y!=1){
			printf("0 0\n");
			continue;
		}*/
		/*if(x==1&&y==1){
			printf("1 1\n");
			continue;
		}*/
		if(z*x!=y||x>y){
			printf("0 0\n");
			continue;
		}
		else{
			if(x==y){
				printf("1 1\n");
				continue;
			}
			else{
				printf("1 %d\n",z);
				continue;
			}
			/*for(int i=2;i<=100;++i){
				int temp=i,cnt=1;
				while(temp<z) {
					temp*=temp;
					++cnt;
				}
				if(temp==z){
					printf("%d %d\n",cnt,i);
					break;
				}
			}*/
		}
	}
	return 0;
}
