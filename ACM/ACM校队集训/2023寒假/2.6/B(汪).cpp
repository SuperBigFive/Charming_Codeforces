#include<bits/stdc++.h>
#define INF 2147483647
#define N 500
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int n,k;
int a[N][N];
void solve()
{
    scanf("%d%d",&n,&k);
    if(n==2)
    {
        if(k==1)
        {
            puts("YES");
            puts("#.");
            puts("..");
        }
        else if(k==0)
        {
            puts("YES");
            puts("..");
            puts("..");
        }
        else
            puts("NO");
        return;
    }
    if(k>n*n-n)
    {
        puts("NO");
        return;
    }
    puts("YES");
    for(int i=2;i<=n-1;i++)
        a[i][i]=1;
    a[1][n]=a[n][1]=1;
    int t=n*n-n-k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0)
            {
                if(t==0)
                    break;
                a[i][j]=1;
                t--;
                if(t==0)
                    break;
            }
        }
        if(t==0)
            break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
                printf(".");
            else if(a[i][j]==0)
                printf("#");
        }
        printf("\n");
    }
}
int main()
{
    solve();
    return 0;
}
