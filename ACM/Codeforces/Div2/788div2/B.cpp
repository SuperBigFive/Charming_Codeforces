#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2e5+5;

char str[maxn];
char special[27];
bool map[27];
bool map2[maxn];
int ub[maxn];
int pos[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",str);
		int num;
		scanf("%d",&num);
		memset(map,false,sizeof map);
		for(int i=0;i<num;++i){
			scanf("%s",&special[i]);
			map[special[i]-'a']=true;
		}
		int cnt=0,last=-1,ans=0;
		for(int i=0;i<n;++i){
			if(map[str[i]-'a']){
				++cnt;
				if(last==-1){
					last=i;
					ans=i;
					continue;
				}
				ans=max(ans,i-last);
				last=i;
			}
		}
		if(!cnt){
			printf("0\n");
			continue;
		}
		if(cnt==1){
			printf("%d\n",last);
			continue;
		}
		//printf("\n");
		printf("%d\n",ans);
		//printf("\n");
	}
}
