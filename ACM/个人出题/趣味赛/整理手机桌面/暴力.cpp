#include<bits/stdc++.h> 
#define ll long long
#define int ll
using namespace std;
const int maxn=1e3,INF=1e9;

int W[maxn][maxn],n, m, k, tot;
int Lx[maxn],Ly[maxn];//顶标 
int Left[maxn];//右边第i个点对应的左边的点的编号 
bool S[maxn],T[maxn];//是否在增广路 
char mp[maxn][maxn];
vector <array <int, 3> > p1, p2;
 
bool match(int i){
	S[i]=true;
	for(int j=1;j<=n;j++)if(Lx[i]+Ly[j]==W[i][j] && !T[j]){//i到j可行 且 j未被访问 
		T[j]=true;
		if(!Left[j] || match(Left[j])){ //j未标记 或者 通过j可以找打增广路 
			Left[j]=i;return true;
		}
	}
	return false;
}
void update(){//更新顶标 
	int a=INF;
	for(int i=1;i<=n;i++)if(S[i]){
		for(int j=1;j<=n;j++)
		if(!T[j])
		a=min(a,Lx[i]+Ly[j]-W[i][j]);//i在增广路 且 j不在增广路中 
	}
	for(int i=1;i<=n;i++){
		if(S[i])Lx[i]-=a;
		if(T[i])Ly[i]+=a;
	}
}
void KM(){
	for(int i=1;i<=n;i++){
		Left[i]=Lx[i]=Ly[i]=0;
		for(int j=1;j<=n;j++)Lx[i]=max(Lx[i],W[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(;;){
			for(int j=1;j<=n;j++)
			S[j]=T[j]=0;
			if(match(i))
			break;
			else update();
		}
	}
}
 
signed main(){
	cin >> n >> m >> k;
	char ch;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	cin >> ch, mp[i][j] = ch;
	array <int, 3> d;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((j - 1) * m + i > k) continue;
			d[0] = ++tot, d[1] = j, d[2] = i;
			if (mp[j][i] == '0') p1.emplace_back (d);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((j - 1) * m + i <= k) continue;
			d[0] = ++tot, d[1] = j, d[2] = i;
			if (mp[j][i] == '1') p2.emplace_back (d);
		}
	}
	n = tot;
	
	//针对最小权匹配 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	W[i][j]=-1e9;
	
	int u, v, w;
	for (auto [id1, x1, y1] : p2) {
		for (auto [id2, x2, y2] : p1) {
			u = id1, v = id2;
			w = abs (x1 - x2) + abs (y1 - y2);
			if(W[u][v]==-1e9)
			W[u][v]=-w;
			else W[u][v]=max(W[u][v],-w);
		}
	}
  KM();
  int sum=0;
  for(int i=1;i<=n;i++)sum+=W[Left[i]][i];
	cout << (-sum) % 100000000 << endl;
	
	return 0;
}
