#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int n,t;
priority_queue<>
bool check(int x)

int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=t;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int c1=min(u,v),c2=max(u,v),choice=-1;
        if(c1>t)
            continue;
        if(c2>t)
            c2=1e6+5;
        if(vis[c1]==0)
            choice=c1;
        else if(vis[c1]==1 && vis[c2]==0)
            choice=c2;
        else if(vis[c1]==1 && vis[c2]==1)
            continue;
        if(choice!=-1 && choice<=t)
            vis[choice]=1;
    }
    for(int i=1;i<=t;i++)
        if(vis[i]==0)
        {
            printf("%d\n",i);
            return 0;
        }
    printf("%d\n",min(n,t)+1);
}
