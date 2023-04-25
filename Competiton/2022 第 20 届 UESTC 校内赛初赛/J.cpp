#include<iostream>
using namespace std;
const int maxn=300;
char str[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int length=0;
		while(str[length]!='\0') ++length;
		bool juds=false,duankou=false;
		if(str[4]=='s') juds=true;
		int maohao=0;
		for(int i=0;i<length;++i){
			if(i==4&&juds) continue;
			if(str[i]==':') ++maohao;
			if(str[i]==':'&&maohao>1){
				str[i]='-';
				duankou=true;
			}
		}
		int xiegang=0,charu=-1;
		for(int i=0;i<length;++i){
			if(i==4&&juds) continue;
			if(str[i]=='/') ++xiegang;
			if(str[i]=='.') str[i]='-';
			if(xiegang==3){
				charu=i;
				break;
			}
		}
		if(charu==-1) charu=length;
		for(int i=0;i<=length;++i){
			if(i==4&&juds) continue;
			if(i==charu){
				if(duankou) printf("-p");
				if(juds) printf("-s");
				printf(".vpn.uestc.edu.cn:8118");
			}
			if(i==length) break;
			printf("%c",str[i]);
		}
		//if(xiegang<3) printf(".vpn.uestc.edu.cn:8118");
		printf("\n");
	}
}
