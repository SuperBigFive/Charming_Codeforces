#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int maxx=505;
const int maxy=505;
const int inf = 1e4+5;
int map[maxx][maxy];//地图 ，假设\为0，/为1 
typedef struct node{
	int x;
	int y;
	node(){};
	node(int a,int b):x(a),y(b){};
	node(const node& n){
		x=n.x,y=n.y;
	}
}node;
node now;
int energy[maxx][maxy];//到达每点所需要消耗的能量 
int dir[4][4]={1,1,1,1,1,-1,1,0,-1,1,0,1,-1,-1,0,0};//在每个点时可以走的方向 
int ideal_c[4]={0,1,1,0};//如果地图上对应的是值与该数组对应的值相同，则不需要消耗能量便能进入 
int bfs(int x,int y,int end_x,int end_y);
int n,m; 

int main(){
	scanf("%d%d",&n,&m);
	if((n+m)%2)	
		printf("NO SOLUTION\n");
	else{
		int c;
		for(int i=1;i<=n;++i){
			for (int j=1;j<=m;++j){
				scanf(" %c",&c);
				if(c=='/')
					map[i][j]=1;//数据预处理 
			}
		}
		memset(energy,0x3f,sizeof energy);
		int min_energy=bfs(0,0,n,m);
		printf("%d",min_energy);
	}
	return 0;
}

int bfs(int x,int y,int end_x,int end_y){
	now.x=x;
	now.y=y;
	energy[x][y]=0;
	deque <node> q;
	q.push_back(now);
	while(!q.empty()){
		now=q.front();
		if(now.x==end_x&&now.y==end_y)
			return energy[end_x][end_y];
		q.pop_front();
		for(int i=0;i<4;++i){
			int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
			int nnx=now.x+dir[i][2],nny=now.y+dir[i][3];
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m){
				int cost=(map[nnx][nny]==ideal_c[i]?0:1);
				if(energy[nx][ny]>energy[now.x][now.y]+cost){
					energy[nx][ny]=energy[now.x][now.y]+cost;
					if(!cost)
						q.push_front(node(nx,ny));
					else
						q.push_back(node(nx,ny));
				}
			}
		} 
	}
}
/*
#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
const int maxn=505;
const int inf=1e4+5;

struct pos{
	int x,y;
	pos(int a,int b):x(a),y(b){};
};
int map[maxn][maxn],energy[maxn][maxn],vis[maxn][maxn];
int dir[4][4]={1,1,1,1,1,-1,1,0,-1,1,0,1,-1,-1,0,0};
int ideal_c[4]={0,1,1,0};
int n,m;
void  bfs();

int main(){
	scanf("%d%d",&n,&m);
	if((n+m)%2){
		printf("NO SOLUTION\n");
		return 0; 
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c;
			scanf(" %c",&c);
			if(c=='/')
			 map[i][j]=1;
		}
	}
	bfs();
	printf("%d\n",energy[n][m]);
	return 0;
}

void  bfs(){
	deque <pos> q;
	memset(energy,inf,sizeof energy);
	pos now(0,0);
	energy[now.x][now.y]=0;
	q.push_front(now);
	while(!q.empty()){
		now=q.front();
		if(now.x==n&&now.y==m)
			return;
		q.pop_front();
		vis[now.x][now.y]=true;
		for(int i=0;i<4;++i){
			int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
			int nnx=now.x+dir[i][2],nny=now.y+dir[i][3];
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&!vis[nx][ny]){
				int cost=(map[nnx][nny]==ideal_c[i]?0:1);
				if(energy[nx][ny]>energy[now.x][now.y]+cost){
					energy[nx][ny]=energy[now.x][now.y]+cost;
					if(!cost)
						q.push_front(pos(nx,ny));
					else
						q.push_back(pos(nx,ny));
				}
			}
		}
	}
}
*/
