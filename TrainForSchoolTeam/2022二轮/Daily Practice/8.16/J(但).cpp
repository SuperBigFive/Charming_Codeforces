#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=2e5+10;
struct node{
	int son[27];
	int fa,len,trlen,cnt;
}N[maxn<<1];
char s[maxn];
queue<int>q;
int du[maxn<<1],last,cnt;
void add(int c,int trlen){
	int las=last,u=last=++cnt;
	N[u].len=N[las].len+1;
	N[u].cnt=1;
	N[u].trlen=trlen;
	for(;las&&(!N[las].son[c]);las=N[las].fa)
	N[las].son[c]=u;
	if(!las)N[u].fa=1;
	else {
		int t=N[las].son[c];
		if(N[t].len==N[las].len+1)N[u].fa=t;
		else {
			int newt=++cnt;
			N[newt]=N[t];
			N[newt].cnt=0;
			N[newt].len=N[las].len+1;
			N[t].fa=N[u].fa=newt;
			for(;las&&N[las].son[c]==t;las=N[las].fa)
			N[las].son[c]=newt;
		}
	}
}
void count(){
	for(int i=1;i<=cnt;i++)
	du[N[i].fa]++;
	for(int i=1;i<=cnt;i++)
	if(!du[i])q.push(i);
	while(!q.empty()){
		int t=q.front();q.pop();
		N[N[t].fa].cnt+=N[t].cnt;
		du[N[t].fa]--;
		if(!du[N[t].fa])q.push(N[t].fa);
	}
}
int find(){
	int u=1,ans=0;
 	for(int i=0;s[i]!='\0';i++)
	if(!N[u].son[s[i]-'a'])return 0;
	else u=N[u].son[s[i]-'a'];
	ans=min(N[u].trlen,N[u].len)-N[N[u].fa].len;
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		last=cnt=1;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int i=0;s[i]!='\0';i++)
			add(s[i]-'a',i+1);
			add(26,0);
		}
		count();
		printf("Case #%d:\n",k);
		for(int i=1;i<=m;i++){
			scanf("%s",s);
			printf("%d\n",find());
		}
		for(int i=1;i<=cnt;i++)
		memset(N[i].son,0,sizeof(N[i].son));
		N[1].cnt=0;
	}
	return 0;
}