#include<iostream>
using namespace std;
const int maxn=2e5+15;

char map[6][6];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int row,colomn;
		scanf("%d%d",&row,&colomn);
		for(int i=1;i<=row;++i){
			for(int j=1;j<=colomn;++j)
				scanf(" %c",&map[i][j]);
		}
		if(map[1][1]=='R'){
			printf("YES\n");
			continue;
		}
		int up_max=0,left_max=0;
		for(int i=1;i<=row;++i){
			int key=1;
			for(int j=1;j<=colomn;++j)
				if(map[i][j]=='R') key=0;
			if(!key) break;
			++up_max;
		}
		for(int i=1;i<=colomn;++i){
			int key=1;
			for(int j=1;j<=row;++j)
				if(map[j][i]=='R') key=0;
			if(!key) break;
			++left_max;
		}
		bool ans=false;
		for(int i=1;i<=up_max+1;++i){
			for(int j=1;j<=left_max+1;++j){
				if(map[i][j]=='R') ans=true;
			}
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
