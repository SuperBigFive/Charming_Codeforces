#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct pos{
	int x;
	int y;
	int step=0;
	pos(){}
	pos(int a,int b,int c):x(a),y(b),step(c){};
}p;
queue <p> q;
bool vis[21][21];
p horse[2];
int dir[12][2]={-2,-1,-2,-2,-2,1,-2,2,-1,-2,-1,2,1,-2,1,2,2,-1,2,-2,2,1,2,2};

void min_step(pos &h);

int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	horse[0].x=x1,horse[0].y=y1;
	horse[1].x=x2,horse[1].y=y2;
	min_step(horse[0]);
	min_step(horse[1]);
	return 0;
}

void min_step(pos &h){
	while(!q.empty())
		q.pop();
	memset(vis,false,sizeof vis);
	q.push(h);
	vis[h.x][h.y]=true;
	while(!q.empty()){
		pos now=q.front();
		q.pop();
		for(int i=0;i<=11;++i){
			int ux=now.x+dir[i][0],uy=now.y+dir[i][1];
			if(ux>0&&ux<=20&&uy>0&&uy<=20&&!vis[ux][uy]){
				if(ux==1&&uy==1){
					printf("%d\n",now.step+1);
					return;
				}
				else {
					q.push(pos(ux,uy,now.step+1));
					vis[ux][uy]=true;
				}
			}
		}
	}
}
