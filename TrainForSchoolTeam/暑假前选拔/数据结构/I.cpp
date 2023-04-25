#include<iostream>
#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<15,stdin),frS==frT)?EOF:*frS++)
char frBB[1<<15],*frS=frBB,*frT=frBB;
template<typename T>
inline void read(T &x){
    x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const int maxm=3e6+5;
const ll mod=1e9+7;

int pre[maxn],s[maxn];
bool ans[maxm];
ll two_mod[maxm];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
} 
void joint(int x,int y){
	int prex=find(x),prey=find(y);
	if(prex==prey) return;
	if(s[prex]<=s[prey]){
		pre[prex]=prey;
		++s[prey];
		return;
	}
	pre[prey]=prex;
	++s[prex];
}
void build(int lim){
	two_mod[lim]=1;
	for(int i=lim-1;i>0;--i){
		two_mod[i]=((two_mod[i+1])<<1)%mod;
	}
}

int main(){
	int n,m,cnt=0,cnt2=0;
	read(n);
	read(m);
	int opt,node1,node2;
	for(int i=1;i<=n;++i) pre[i]=i,s[i]=1;
	for(int i=0;i<m;++i){
		read(opt);
		read(node1),read(node2);
		if(opt==1)	joint(node1,node2);
		if(opt==2){
			if(find(node1)==find(node2)) {ans[++cnt]=true;continue;}
			ans[++cnt]=false;
		}
	}
	build(cnt);
	//for(int i=1;i<=n;++i) printf("%d ",pre[i]);
	//printf("\n");
	//for(int i=1;i<=m;++i) printf("%d ",two_mod[i]);
	ll a=0;
	int i=1;
	while(i<=cnt){
		if(ans[i]) a+=two_mod[i];
		++i;
	}
	printf("%lld\n",a%mod);
	return 0;
}
