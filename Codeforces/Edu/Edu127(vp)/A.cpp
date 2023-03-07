#include<iostream>
using namespace std;
const int maxn=51;
char str[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int key=1;
		scanf("%s",str+1);
		int tmp=1;
		if(str[2]=='\0'){
			printf("NO\n");
			continue;
		}
		for(int i=2;str[i]!='\0';++i){
			if(str[i]!=str[i-1]&&(tmp==1||str[i+1]=='\0')){
				printf("NO\n");
				key=0;
				break;
			}
			if(str[i]==str[i-1]) ++tmp;
			if(str[i]!=str[i-1]) tmp=1;
		}
		if(key)
			printf("YES\n");
	}
	return 0;
}
