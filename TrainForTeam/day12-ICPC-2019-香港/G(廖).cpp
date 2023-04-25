#include<bits/stdc++.h>
using namespace std;
const int maxn = 114514;
int n,k,cnt;
int fa[maxn],dfn[maxn],val[maxn],sz[maxn],ls[maxn],rs[maxn],dcnt;
int build1(int f)
{
    int cur = ++cnt;
    fa[cur] = f;
    return cur;
}
int build2(int f)
{
    int cur = ++cnt;
    rs[cur] = build1(cur);
    fa[cur] = f;
    return cur;
}
int build(int val,int f)
{
    int cur = ++cnt;
    if(val == 1) return cur;
    if(val % 2 == 0)
    {
        rs[cur] = build1(cur);
        ls[cur] = build(val-1,cur);
    }
    else
    {
        rs[cur] = build2(cur);
        ls[cur] = build((val-1)>>1,cur);
    }
    return cur;
}
void dfs(int cur,int f)
{
    dfn[cur] = ++dcnt;
    fa[dfn[cur]] = dfn[f];
    if(ls[cur] == 0 && rs[cur] == 0)
        val[dfn[cur]] = 1;
    else
    {
        if(ls[cur])
        {
            dfs(ls[cur], cur);
            val[dfn[cur]] += val[dfn[ls[cur]]];
        }
        if(rs[cur])
        {
            dfs(rs[cur], cur);
            val[dfn[cur]] += val[dfn[rs[cur]]];
        }
    }
}
int main()
{
    cin>>k;
    build(k,0);
    dfs(1,0);
    if(k==1)
    {
        cout<<2<<endl<<1<<endl<<1<<" "<<114514<<endl;
        return 0;
    }
    cout<<dcnt<<endl;
    for(int i=2;i<=dcnt;++i)printf("%d ",fa[i]);
    cout<<endl;
    for(int i=1;i<=dcnt;++i)printf("%d ",val[i]);
    return 0;
}