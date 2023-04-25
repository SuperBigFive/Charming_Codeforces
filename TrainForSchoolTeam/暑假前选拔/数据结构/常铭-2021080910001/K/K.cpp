#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=5e2+5;

struct Node{
	int mmax;
	int mmin;
}node[maxn<<2][maxn<<2];
int n,mn,mx;
int arr[maxn][maxn];

void build2(int out,int cnt,int out_l,int out_r,int l,int r);
void build1(int cnt,int l,int r);
void update2(int out,int cnt,int x,int y,int l,int r,int val);
void update1(int cnt,int x,int y,int l,int r,int val);
int find2(int out,int cnt,int l,int r,int x1,int y1,int x2,int y2);
int find1(int cnt,int l,int r,int x1,int y1,int x2,int y2);

void myprint(int cnt,int l,int r){
	printf("%d~%d,max:%d;min:%d\n",l,r,node[cnt][6].mmax,node[cnt][6].mmin);
	if(l==r) return;
	myprint(cnt<<1,l,(l+r)/2);
	myprint((cnt<<1)+1,(l+r)/2+1,r);
}


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&arr[i][j]);
		}
	}
	build1(1,1,n);
	
	//myprint(1,1,n);
	
	int m;
	scanf("%d",&m);
	int opt,x1,y1,x2,y2,x,y,k;
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&x,&y,&k);
			update1(1,x,y,1,n,k);
			//myprint(1,1,n);
		}
		else{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			mn=1<<30,mx=-1;
			find1(1,1,n,x1,y1,x2,y2);
			printf("%d %d\n",mx,mn);
		}
	}
	return 0;
}

void build2(int out,int cnt,int out_l,int out_r,int l,int r){
	if(l!=r){
		int mid=(l+r)/2;
		build2(out,cnt<<1,out_l,out_r,l,mid);
		build2(out,(cnt<<1)+1,out_l,out_r,mid+1,r);
		node[out][cnt].mmax=max(node[out][cnt<<1].mmax,node[out][(cnt<<1)+1].mmax);
		node[out][cnt].mmin=min(node[out][cnt<<1].mmin,node[out][(cnt<<1)+1].mmin);
	}
	else{
		if(out_l==out_r) {
			node[out][cnt].mmax=arr[out_l][l];
			node[out][cnt].mmin=arr[out_r][r];
		}
		else{
			node[out][cnt].mmax=max(node[out<<1][cnt].mmax,node[(out<<1)+1][cnt].mmax);
			node[out][cnt].mmin=min(node[out<<1][cnt].mmin,node[(out<<1)+1][cnt].mmin);	
		}
	}
}
void build1(int cnt,int l,int r){
	int mid=(l+r)/2;
	if(l!=r){
		build1(cnt<<1,l,mid);
		build1((cnt<<1)+1,mid+1,r);
	}
	build2(cnt,1,l,r,1,n);
}
void update2(int out,int cnt,int x,int y,int l,int r,int val){
	if(l==r) {
		if(val==-114514){
			node[out][cnt].mmax=max(node[out<<1][cnt].mmax,node[(out<<1)+1][cnt].mmax);
			node[out][cnt].mmin=min(node[out<<1][cnt].mmin,node[(out<<1)+1][cnt].mmin);
		}
		else node[out][cnt].mmax=val,node[out][cnt].mmin=val;
	}
	else{
		int mid=(l+r)/2;
		if(y<=mid) update2(out,cnt<<1,x,y,l,mid,val);
		else update2(out,(cnt<<1)+1,x,y,mid+1,r,val);
		node[out][cnt].mmax=max(node[out][cnt<<1].mmax,node[out][(cnt<<1)+1].mmax);
		node[out][cnt].mmin=min(node[out][cnt<<1].mmin,node[out][(cnt<<1)+1].mmin);
	}
}
void update1(int cnt,int x,int y,int l,int r,int val){
	if(l!=r){
		int mid=(l+r)/2;
		if(x<=mid) update1(cnt<<1,x,y,l,mid,val);
		else update1((cnt<<1)+1,x,y,mid+1,r,val);
		update2(cnt,1,x,y,1,n,-114514);
	}
	else update2(cnt,1,x,y,1,n,val);
}
int find2(int out,int cnt,int l,int r,int x1,int y1,int x2,int y2){
	if(l>=y1&&r<=y2){
		mn=min(mn,node[out][cnt].mmin);
		mx=max(mx,node[out][cnt].mmax);
	}
	else{
		int mid=(l+r)/2;
		if(y1<=mid) find2(out,cnt<<1,l,mid,x1,y1,x2,y2);
		if(y2>mid) find2(out,(cnt<<1)+1,mid+1,r,x1,y1,x2,y2);
	}
}
int find1(int cnt,int l,int r,int x1,int y1,int x2,int y2){
	if(l>=x1&&r<=x2){
		find2(cnt,1,1,n,x1,y1,x2,y2);
	}
	else{
		int mid=(l+r)/2;
		if(x1<=mid) find1(cnt<<1,l,mid,x1,y1,x2,y2);
		if(x2>mid) find1((cnt<<1)+1,mid+1,r,x1,y1,x2,y2);
	}
}
