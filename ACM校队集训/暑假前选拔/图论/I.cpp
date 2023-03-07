#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;
const int maxn=1e5+5;

struct Edge{
    int to,next;
}edge[maxn<<1];
int head[maxn<<1],cnt;
int n,m,time_cnt,num_scc;
int dfn[maxn<<1],low[maxn<<1],scc[maxn<<1];
bool vis[maxn<<1];
stack<int> st;

inline void add(int from,int to){
	edge[++cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt;
};
void Tarjan(int x) {
    vis[x]=true;
    dfn[x]=low[x]=++time_cnt;
    st.push(x);
    for(int i=head[x]; i!=-1; i=edge[i].next) { 
        int y=edge[i].to;
        if(!dfn[y]) {
            Tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y])
            low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x]) { 
        num_scc++;
        while(1) { 
            int temp=st.top();
            st.pop();
            vis[temp]=false;
            scc[temp]=num_scc;
            if(temp==x)
                break;
        }
    }
}

int main() {
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i) {
        int x,y,xVal,yVal;
        scanf("%d%d%d%d",&x,&xVal,&y,&yVal);
 		int tag1=1-xVal,tag2=1-yVal;
 		add(x+tag1*n,y+yVal*n);
 		add(y+tag2*n,x+xVal*n);
    }
    for(int i=1;i<=2*n;i++)
        if(!dfn[i])
            Tarjan(i);
    for(int i=1;i<=n;i++){
        if(scc[i]==scc[i+n]){
        	printf("NO\n");
        	return 0;
		}
	}
	printf("YES\n");
    return 0;
}
