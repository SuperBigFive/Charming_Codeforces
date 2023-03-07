#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node{
	int son[27];
	int fa,len;
}N[maxn<<1];
int n,last=1,tot=1;
char s[maxn];
void add(int c){
	int las=last,now=last=++tot;
	N[now].len=N[las].len+1;
	for(;las&&(!N[las].son[c]);las=N[las].fa)
	N[las].son[c]=now;
	if(!las)N[now].fa=1;
	else {
		int t=N[las].son[c];
		if(N[t].len==N[las].len+1)N[now].fa=t;
		else {
			int newt=++tot;
			N[newt]=N[t];
			N[newt].len=N[las].len+1;
			N[t].fa=N[now].fa=newt;
			for(;las&&N[las].son[c]==t;las=N[las].fa)
			N[las].son[c]=newt;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s[i]=getchar();
		while(!isalpha(s[i]))s[i]=getchar();
	}
	for(int i=1;i<=n;i++)
	add(s[i]-'a');
	for(int i=1;i<=n;i++)
	add(s[i]-'a');
	add(26);
	for(int i=n;i;i--)
	add(s[i]-'a');
	for(int i=n;i;i--)
	add(s[i]-'a');
	long long ans=0;
	for(int i=2;i<=tot;i++)
	if(N[N[i].fa].len<n)ans+=min(n,N[i].len)-N[N[i].fa].len;
	for(int i=1;i<n;i++)
	ans-=n-i+1;
	printf("%lld",ans-1);
	return 0;
}