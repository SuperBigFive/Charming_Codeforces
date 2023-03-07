#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=6e3+15;
const int maxm=2e5+15;

struct Edge{
	int to;
	int next;
	ll wet;
}edge[maxm<<1];
struct Dist{
	struct vandp{
		ll val;
		int pos;	
	}d[maxn];
}dist[maxn];
ll n,m,T,k,tot,cnt;
ll head[maxn],belong[maxn];
ll size_team[maxn],size_p[maxn],teamonpoint[maxn],mmove[maxn];
bool vis[maxn],flag[maxn];

bool cmp(Dist::vandp x,Dist::vandp y){
	return x.val<y.val;
}
void add(int u,int v,int w){
	edge[++tot].to=v;
	edge[tot].next=head[u];
	edge[tot].wet=w;
	head[u]=tot;
}
void dfs(int u){
	vis[u]=true;
	belong[u]=cnt;
	++size_p[cnt];
	size_team[cnt]+=teamonpoint[u];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v])
		dfs(v);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&T,&k);
	ll point,cnt2=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dist[i].d[j].val=99999999;
		}
	}
	for(int i=1;i<=T;++i){
		scanf("%d",&point);
		flag[point]=true; 
		if(!teamonpoint[point]++) ++cnt2; 
	}
	//for(int i=1;i<=n;++i) if(!flag[i]) dist[i][i]=0;
	ll uu,vv;
	ll ww;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dist[i].d[j].pos=j;
		}
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&uu,&vv,&ww);
		if(!flag[vv]){
			dist[uu].d[vv].val=min(dist[uu].d[vv].val,ww);
			//dist[uu].d[vv].pos=vv;		
		}
		if(!flag[uu]){
			dist[vv].d[uu].val=min(dist[vv].d[uu].val,ww);
			//dist[vv].d[uu].pos=uu;
		}
		add(uu,vv,ww);
		add(vv,uu,ww);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			++cnt;
			dfs(i);	
		}
	}
    for(int mi=1; mi<=n; mi++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if((dist[i].d[j].val>dist[i].d[mi].val+dist[mi].d[j].val)&&(!flag[j]))
                    dist[i].d[j].val=dist[i].d[mi].val+dist[mi].d[j].val;       
	for(int i=1;i<=cnt;++i){
		if(size_team[i]>size_p[i]){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;++i) dist[i].d[i].val=999999999;
	//sort(&dist[1][1],&dist[n][n]);
	for(int i=1;i<=n;++i){
		sort(dist[i].d+1,dist[i].d+1+n,cmp);
	}
	/*
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d :%d ",dist[i].d[j].val,dist[i].d[j].pos);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<=n;++i) printf("%d ",teamonpoint[i]);
	printf("\n");
	*/
	
	//sort(teamonpoint+1,teamonpoint+1+n,greater<int>());
	
	ll ans=9999999999;
	while(cnt2<k){
		ll mmin=9999999999;
		ll idx;
		for(int i=1;i<=n;++i){
			while(flag[dist[i].d[mmove[i]+1].pos]&&mmove[i]<n) ++mmove[i];
			if(mmove[i]>=n) continue;
			if(mmin>dist[i].d[mmove[i]+1].val&&teamonpoint[i]>1){
				mmin=dist[i].d[mmove[i]+1].val;
				idx=i;
			}
			//mmin=min(mmin,dist[i][mmove[i]+1]);
		}
		flag[dist[idx].d[mmove[idx]+1].pos]=true;
		++mmove[idx];
		ans=mmin;
		--teamonpoint[idx];
		++cnt2;
		//++size_team[belong[idx]];
	}
	/*for(int i=1;i<=n;++i){
		if(teamonpoint[i]==1) break;
		int a=0;
		while(teamonpoint[i]-a>1){
			ans+=dist[teamonpoint[i]]
		}
	}*/
	printf("%lld\n",ans);
	return 0;
}
