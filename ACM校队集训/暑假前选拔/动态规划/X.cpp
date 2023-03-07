#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=5e5+15;

struct Edge{
    int to;
    int next;
    ll wet;
}edge[maxn<<1];
int n,root,tot=0;
ll use_time=0;
ll time_cost[maxn];
ll dp[maxn];
int du[maxn];
int head[maxn];

void add(int u,int v,ll w){
    edge[++tot].to=v;
    edge[tot].next=head[u];
    edge[tot].wet=w;
    head[u]=tot;
}

void dfs1(int fa,int u);
void dfs2(int fa,int u);
void init(){
	memset(time_cost,0,sizeof time_cost);
	memset(dp,0,sizeof dp);
	memset(du,0,sizeof du);
	memset(head,0,sizeof head);
}

int main(){
	init();
    scanf("%d%d",&n,&root);
    int uu,vv;
    ll ww;
    for(int i=1;i<n;++i){
        scanf("%d%d%lld",&uu,&vv,&ww);
        add(uu,vv,ww);
        add(vv,uu,ww);
        ++du[uu],++du[vv];
    }
    dfs1(root,root);
    ll mmax=-1;
    for(int i=1;i<=n;++i){
        if(du[i]<2&&i!=root){
            dp[i]=time_cost[i];
            mmax=mmax>dp[i]?mmax:dp[i];
        }
    }
    for(int i=1;i<=n;++i){
        if(du[i]<2&&i!=root){
            dp[i]=mmax-dp[i];
        }
    }
    dfs2(root,root);
    for(int i=1;i<=n;++i) if(i!=root) use_time+=dp[i];
    //for(int i=1;i<=n;++i) printf("dp[%d]=%d\n",i,dp[i]);
    //for(int i=1;i<=n;++i) printf("time_cost[%d]=%d\n",i,time_cost[i]);
    //for(int i=1;i<=n;++i) printf("%d's du is %d\n",i,du[i]);
    printf("%lld\n",use_time);
    return 0;
}

void dfs1(int fa,int u){
    int e=head[u];
    while(e){
        if(edge[e].to==fa){
            e=edge[e].next;
            continue;
        }
        int v=edge[e].to;
        time_cost[v]=time_cost[u]+edge[e].wet;
        dfs1(u,v);
        e=edge[e].next;
    }
}
void dfs2(int fa,int u){
    if(du[u]<2&&u!=root) return;
    int e=head[u];
    ll mmin=99999999999999999;
    while(e){
        if(edge[e].to==fa){
            e=edge[e].next;
            continue;
        }
        int v=edge[e].to;
        dfs2(u,v);
        mmin=mmin<dp[v]?mmin:dp[v];//min((int)mmin,(int)dp[v]);
        e=edge[e].next;
    }
    if(u==root) return;
    e=head[u];
    while(e){
        if(edge[e].to==fa){
            e=edge[e].next;
            continue;
        }
        int vv=edge[e].to;
        dp[vv]-=mmin;
        e=edge[e].next;
    }
    dp[u]=mmin;
}

