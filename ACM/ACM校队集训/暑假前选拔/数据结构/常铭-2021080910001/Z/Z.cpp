#include <iostream>
#include <cmath>
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
const int maxn=1e4+5;

struct node{
	int next;
	int size;
	ll mission[7000];
}no[maxn];
int n,m,cut;
int cnt,tail;

int find_node(int &pos);
void split(int node);
void ins(int pos,ll val);
ll find_val(int pos);

int main () {
	scanf("%d%d",&n,&m);
	cut=5000;
	ll val;
	int blo,po;
	for(int i=1;i<=n;++i){
		scanf("%lld",&val);
		blo=(i-1)/cut+1;
		po=i%cut;
		if(!po) po=cut; 
		no[blo].mission[po]=val;
		++no[blo].size;
	}
	tail=cnt=(n-1)/cut+1;
	for(int i=1;i<cnt;++i) no[i].next=i+1;
	int opt,pos;
	ll k;
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%lld%d",&k,&pos);
			ins(pos,k);
		}
		else{
			scanf("%d",&pos);
			printf("%lld\n",find_val(pos));
		}
	}
/*	for(int i=1;i!=-1;i=no[i].next){
		printf("no[%d].size=%d\n",i,no[i].size);
		for(int j=1;j<=no[i].size;++j){
			printf("%lld ",no[i].mission[j]);
		}
		printf("\n");
	}
	for(int i=1;i<=100;++i) printf("%d ",no[i].next);*/
	return 0;
} 

int find_node(int &pos){
	int ans=1;
	while(pos>no[ans].size&&ans){
		pos-=no[ans].size;
		ans=no[ans].next;
	}
	return ans;
}
void split(int node){
	no[++cnt].next=no[node].next;
	no[node].next=cnt;
	int rest=no[node].size/2;
	no[cnt].size=no[node].size-rest;
	no[node].size=rest;
	if(no[cnt].next==0) tail=cnt;
	for(int i=rest+1;i<=cut+1;++i){
		no[cnt].mission[i-rest]=no[node].mission[i];
	}
    /*for(int i=1;i!=-1;i=no[i].next){
		printf("no[%d].size=%d\n",i,no[i].size);
		for(int j=1;j<=no[i].size;++j){
			printf("%lld ",no[i].mission[j]);
		}
		printf("\n");
	}*/
}
void ins(int pos,ll val){
	int nnode=find_node(pos);
	if(nnode==0){
		nnode=tail;
		no[tail].mission[++no[tail].size]=val;
	}
	else{
		for(int i=no[nnode].size;i>=pos;--i) 
			no[nnode].mission[i+1]=no[nnode].mission[i];
		no[nnode].mission[pos]=val;
		++no[nnode].size;
	}
	
	/*printf("node:%d ,size:%d\n",nnode,no[nnode].size);
	for(int i=1;i<=no[nnode].size;++i)
		printf("%lld ",no[nnode].mission[i]);
	printf("\n\n");
	*/
	if(no[nnode].size>cut)
		split(nnode); 
}
ll find_val(int pos){
	int nnode=find_node(pos);
	return no[nnode].mission[pos];
}
