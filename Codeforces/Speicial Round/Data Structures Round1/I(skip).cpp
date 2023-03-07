#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int mp[N][N];
int dfs(int x,int y,int dx,int dy){return (mp[x+dx][y+dy]==0)?1:(1+dfs(x+dx,y+dy,dy,dx));}
signed main(){
	int n,m,q,ans=0;cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)	mp[i][j]=1,ans+=4*min(i,j)-3+(i!=j);
	while(q--){
		int x,y;cin>>x>>y;
		int cnt=dfs(x,y,-1,0)*dfs(x,y,0,1)+dfs(x,y,0,-1)*dfs(x,y,1,0)-1;
		ans+=((mp[x][y]==1)?(-cnt):cnt);
		cout<<ans<<endl,mp[x][y]^=1;
	}
	return 0;
}