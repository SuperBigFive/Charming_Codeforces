#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int a[N],b[N];
vector<int>pos;
void solve(int case_number)
{
    pos.clear();
    int n;
    scanf("%d",&n);
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=0;
        sum1+=a[i];
    }
    if(n==1)
    {
        if(a[1]%2==1)
            printf("Case %d: Alice\n",case_number);
        else
            printf("Case %d: Bob\n",case_number);
        return;
    }
    if(a[1]<a[2])
    {
        pos.push_back(1);
        b[1]=0;
    }
    for(int i=2;i<=n-1;i++)
    {
        if(a[i]<a[i+1] && a[i]<a[i-1])
        {
            pos.push_back(i);
            b[i]=0;
        }
    }
    if(a[n-1]>a[n])
    {
        pos.push_back(n);
        b[n]=0;
    }
    int siz=pos.size();
    /*
    for(int i=0;i<siz;i++)
        printf("%d ",pos[i]);
    printf("\n");
    */
    for(int i=1;i<siz;i++)
    {
        int p1=pos[i-1],p2=pos[i];
        for(int j=p1+1;j<p2;j++)
            if(a[j-1]<a[j])
                b[j]=max(b[j],b[j-1]+1);
        for(int j=p2-1;j>p1;j--)
            if(a[j]>a[j+1])
                b[j]=max(b[j],b[j+1]+1);
    }
    int p_first=pos[0],p_last=pos[siz-1];
    for(int j=p_first-1;j>=1;j--)
        if(a[j]>a[j+1])
            b[j]=max(b[j],b[j+1]+1);
    for(int j=p_last+1;j<=n;j++)
        if(a[j-1]<a[j])
            b[j]=max(b[j],b[j-1]+1);
    for(int i=1;i<=n;i++)
        sum2+=b[i];
    /*
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    printf("\n");
    */
    if( (sum1-sum2)%2==1 )
        printf("Case %d: Alice\n",case_number);
    else
        printf("Case %d: Bob\n",case_number);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        solve(i);
    }
    return 0;
}
