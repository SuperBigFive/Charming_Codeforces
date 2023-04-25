#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+25;
int zheng1[maxn],zheng2[maxn],fan1[maxn],fan2[maxn];
int n,m;
int arr[maxn];

void build_zheng();
void build_fan();
int find(int l,int r);

int main(){
	scanf("%d%d",&n,&m);
	arr[1]=n;
	arr[n+2]=n+1;
	for(int i=2;i<=n+1;++i){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n+2;++i){
		zheng1[i]=maxn;
		zheng2[i]=maxn;
		fan1[i]=maxn;
		fan2[i]=maxn;
	}
	zheng2[1]=arr[1];
	fan2[1]=arr[n+1];
	build_zheng();
	build_fan();
	/*
	for(int i=1;i<=n+2;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(int i=1;i<=n+2;++i){
		printf("%d ",zheng1[i]);
	}
	printf("\n");
	for(int i=1;i<=n+2;++i){
		printf("%d ",zheng2[i]);
	}
	printf("\n");
	for(int i=1;i<=n+2;++i){
		printf("%d ",fan1[i]);
	}
	printf("\n");
	for(int i=1;i<=n+2;++i){
		printf("%d ",fan2[i]);
	}
	printf("\n");*/
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",find(l,r));
	}
}

void build_zheng(){
	zheng1[0]=maxn;
	for(int i=1;i<=n+2;++i){
		zheng1[i]=zheng1[i-1];
		zheng2[i]=zheng2[i-1];
		if(zheng1[i]>arr[i]) zheng2[i]=zheng1[i],zheng1[i]=arr[i];
		else if(zheng2[i]>arr[i]) zheng2[i]=arr[i];
	}
	zheng2[1]=arr[1];
}
void build_fan(){
	fan1[n+3]=maxn;
	for(int i=n+2;i>=1;--i){
		fan1[i]=fan1[i+1];
		fan2[i]=fan2[i+1];
		if(fan1[i]>arr[i]) fan2[i]=fan1[i],fan1[i]=arr[i];
		else if(fan2[i]>arr[i]) fan2[i]=arr[i];
	}
	fan2[n+2]=arr[n+2];
}
int find(int l,int r){
	int val[5];
	val[0]=zheng1[l];
	if(l==1) val[1]=maxn;
	else val[1]=zheng2[l];
	val[2]=fan1[r+2];
	if(r+2==n+2) val[3]=maxn;
	else val[3]=fan2[r+2];
	sort(val,val+4);
	return val[1];
}
