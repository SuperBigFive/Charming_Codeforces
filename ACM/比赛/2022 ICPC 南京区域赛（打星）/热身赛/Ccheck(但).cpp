#include <bits/stdc++.h>
using namespace std;
string s = "UDLR" ;
char mov[50010],tar[50010];
int mp[25][25],vis[25][25],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},n,m;
struct p{
	p(int x_,int y_):x(x_),y(y_){}
	int x,y;
};
queue<p>q;
bool canreach(int x,int y){
	if(x>n||x<1)return false;
	if(y>m||y<1)return false;
	return true;
}
int main()
{
  srand(time(NULL));
  for (int i = 1; i <= 50000; i++) mov[i]=rand() % 4;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
  	char ch=getchar();
  	while(ch!='0'&&ch!='1')ch=getchar();
  	mp[i][j]=ch-'0';
  }
  q.push(p(n,m));
  vis[n][m]=1;
  int tot=0;
  while(!q.empty()){
  	p t=q.front();q.pop();
  	for(int i=0;i<4;i++)
  	if(canreach(t.x+dx[i],t.y+dy[i])&&!vis[t.x+dx[i]][t.y+dy[i]])
  			q.push(p(t.x+dx[i],t.y+dy[i])),vis[t.x+dx[i]][t.y+dy[i]]=1,tar[++tot]=i;
  }
  int f=0;
  for(int i=1,j=1;i<=tot;i++,j++){
  	while(mov[j]!=tar[i]&&j<=50000){
  		j++;
  		if(mov[j-1]==tar[i]^1){
  			i--;break;
  		}
  	}
  	if(j>50000)break;
  	if(i==tot)f=j;
  }
  if(f){
		printf("yes\n");
		printf("%d %d",f,tot);
	}
  else printf("no");
  return 0;
}