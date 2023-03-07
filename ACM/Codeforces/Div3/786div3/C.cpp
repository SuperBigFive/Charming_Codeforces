#include<stdio.h>
char str1[51];
char str2[51];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str1);
		scanf("%s",str2);
		int cnt=0,num2=0;
		for(;str2[num2]!='\0';++num2){
			if(str2[num2]=='a') ++cnt; 
		}
		if(cnt>0&&num2>1) {
			printf("-1\n");
			continue;
		}
		if(cnt==1&&num2==1){
			printf("1\n");
			continue;
		}
		int num=0;
		while(str1[num]!='\0') ++num;
		long long ans=1;
		while(num--) ans*=2;
		printf("%lld\n",ans);
	}
}
