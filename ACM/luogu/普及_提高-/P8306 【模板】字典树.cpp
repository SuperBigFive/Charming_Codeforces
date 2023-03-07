//来实现一波字典树~~~
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+15;
const int maxm=3e6+15;

int tot=1,old=0;
char temp[maxm];
int size[maxm];
int dic_tree[maxm][62];
 
int s2n(char s);
void ins(char (&str)[maxm]);
int find(char (&str)[maxm]);

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=old-1;i<=tot;++i) size[i]=0;
		old=tot;
		for(int i=0;i<=61;++i) dic_tree[0][i]=0;
		for(int i=1;i<=n;++i){
			scanf("%s",temp);
			ins(temp);
		}
		for(int i=1;i<=q;++i){
			scanf("%s",temp);
			printf("%d\n",find(temp));
		}
	}	
}
int s2n(char s){
	if(s>='0'&&s<='9') return s-'0';
	if(s>='a'&&s<='z') return s-'a'+10;
	if(s>='A'&&s<='Z') return s-'A'+36; 
}
void ins(char (&str)[maxm]){
	int len=0,node=0;
	++size[0];
	while(str[len]!='\0') ++len;
	for(int i=0;i<len;++i){
		int num=s2n(str[i]);
		if(!dic_tree[node][num]){
			dic_tree[node][num]=tot;
			node=tot;
			++tot;
		}
		else{
			node=dic_tree[node][num];
		}
		++size[node];
	}
}
int find(char (&str)[maxm]){
	int len=0,node=0;
	while(str[len]!='\0') ++len;
	for(int i=0;i<len;++i){
		int num=s2n(str[i]);
		if(!dic_tree[node][num]){
			return 0;
		}
		node=dic_tree[node][num];
	}
	return size[node];
}
