//尝试下AC自动机
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=2e6+15;
const int letter=26;

int tot=1;
int trie[maxn][letter];
int fail[maxn*letter];
int cnt[maxn*letter];
char tmp[maxn];
bool vis[maxn*letter];

void ins(char (&str)[maxn]);
void get_fail();
int find(char(&str)[maxn]);

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",tmp);
		ins(tmp);
	}
	scanf("%s",tmp);
	get_fail();
	printf("%d\n",find(tmp));
	return 0;
}

void ins(char (&str)[maxn]){
	int len=0,node=0;
	while(str[len]!='\0') ++len;
	for(int i=0;i<len;++i){
		int num=str[i]-'a';
		if(!trie[node][num]){
			trie[node][num]=tot;
			++tot;
		}
		node=trie[node][num];
	}
	++cnt[node];
}
void get_fail(){
	queue <int> q;
	for(int i=0;i<26;++i) {
		if(trie[0][i]){
			fail[trie[0][i]]=0;
			q.push(trie[0][i]);
		}
	}
	int now;
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(int i=0;i<26;++i){
			if(trie[now][i]){
				fail[trie[now][i]]=trie[fail[now]][i];
				q.push(trie[now][i]);
			}
			else{
				trie[now][i]=trie[fail[now]][i];
			}
		} 
	}
}
int find(char(&str)[maxn]){
	int len=0,node=0;
	int ans=0;
	while(str[len]!='\0') ++len;
	for(int i=0;i<len;++i){
		int num=str[i]-'a';
		node=trie[node][num];
		for(int j=node;j&&!vis[j];j=fail[j]){
			ans+=cnt[j];
			vis[j]=true;
		}
	}
	return ans;
}
