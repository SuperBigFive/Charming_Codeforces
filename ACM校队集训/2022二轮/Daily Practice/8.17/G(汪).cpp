#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int a[N],b[N],t[N],t1[N],t2[N],da,db,dt,dt1,dt2;
int MUL_X(int A[],int deg_A)
{
    for(int i=deg_A;i>=0;i--)
        A[i+1]=A[i];
    A[0]=0;
    return deg_A+1;
}
int ADD(int A[],int deg_A,int B[],int deg_B)
{
    for(int i=0;i<=max(deg_A,deg_B);i++)
        A[i]+=B[i];
    return max(deg_A,deg_B);
}
int SUB(int A[],int deg_A,int B[],int deg_B)
{
    for(int i=0;i<=max(deg_A,deg_B);i++)
        A[i]-=B[i];
    return max(deg_A,deg_B);
}
int give_val(int A[],int deg_A,int B[],int deg_B)
{
    for(int i=0;i<=deg_B;i++)
        A[i]=B[i];
    for(int i=deg_B+1;i<=deg_A;i++)
        A[i]=0;
    return deg_B;
}
bool jg(int A[],int deg_A)
{
    for(int i=0;i<=deg_A;i++)
        if(abs(A[i])>1)
            return false;
    return true;
}
void out_put()
{
    printf("%d\n",da);
    for(int i=0;i<=da;i++)
        printf("%d ",a[i]);
    printf("\n");

    printf("%d\n",db);
    for(int i=0;i<=db;i++)
        printf("%d ",b[i]);
    printf("\n");
}
void solve()
{
    int n;
    scanf("%d",&n);
    a[0]=1;
    da=db=0;
    for(int i=1;i<=n;i++)
    {
        dt=give_val(t,dt,a,da);
        da=MUL_X(a,da);
        dt1=give_val(t1,dt1,a,da);
        dt2=give_val(t2,dt2,a,da);
        dt1=ADD(t1,dt1,b,db);
        dt2=SUB(t2,dt2,b,db);
        if(jg(t1,dt1))
            da=give_val(a,da,t1,dt1);
        else if(jg(t2,dt2))
            da=give_val(a,da,t2,dt2);
        db=give_val(b,db,t,dt);
    }
}
int main()
{
    solve();
    out_put();
    return 0;
}
