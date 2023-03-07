#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
struct Node
{
    int x,y,z;
    string s;
}a[N];
bool cmp(Node p,Node q)
{
    if(p.x==q.x && p.y==q.y)
        return p.z>q.z;
    else if(p.x==q.x)
        return p.y>q.y;
    return p.x>q.x;
}
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p,q,r;
        string s;
        scanf("%d%d%d",&p,&q,&r);
        getchar();
        getline(cin,s);
        a[i].x=p;
        a[i].y=q;
        a[i].z=r;
        a[i].s=s;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[1].s<<endl;
}
int main()
{
    solve();
    return 0;
}
