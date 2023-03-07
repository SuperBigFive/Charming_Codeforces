#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	char str[3];
	while(t--){
		scanf("%s",str);
		int sum=0;
		sum+=25*(str[0]-'a');
		sum+=str[1]-'a'+1;
		if(str[1]>str[0]) --sum;
		printf("%d\n",sum);
	}
	return 0;
}
