#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int n,k;
int b[N];
int a[N];
void init()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    b[1]=a[n-1];
    b[2]=a[n];
}
void solve()
{
    bool flag=true;
    int ans=INF;
    for(int i=3;i;i++)
    {
        b[i]=max(2*b[i-1]-b[i-2],0);
        if(b[i]>=b[i-1])
        {
            flag=false;
            break;
        }
        if(b[i]<k)
        {
            flag=true;
            ans=i+n-2;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]<k)
        {
            flag=true;
            ans=min(ans,i);
            break;
        }
    }
    if(!flag)
        puts("Python will never be faster than C++");
    else
        printf("Python 3.%d will be faster than C++\n",ans);
}
int main()
{
    init();        
    solve();
    return 0;
}
