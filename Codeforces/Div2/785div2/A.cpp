#include<stdio.h>
const int maxn=2e5+5;
char str[maxn];
int main(){
	int t;
	scanf("%d",&t);
	int sum;
	while(t--){
		sum=0;
		scanf("%s",str);
		int i;
		for(i=0;str[i]!='\0';++i){
			sum+=str[i]-'a'+1;
			
		}
		if((i-1)%2){
			printf("Alice %d\n",sum);
			continue;
		}
		else{
			int bob=(str[0]-'a'+1)<(str[i-1]-'a'+1)?str[0]-'a'+1:str[i-1]-'a'+1;
			int alice=sum-bob;
			if(alice>bob){
				printf("Alice %d\n",alice-bob);
				continue;
			}
			else{
				printf("Bob %d\n",bob-alice);
				continue;
			}
		}
	}
} 
