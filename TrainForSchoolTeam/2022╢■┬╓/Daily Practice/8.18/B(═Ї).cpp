#include<iostream>
#include<unordered_map>
#include<vector>
#define INF 2147483647
#define N 10000010
#define D 10000000
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int n,q;
int primes[N],cnt;
bool st[N];
int mobius[N];
//vector<int>v;
//int stk[N],top=-1;//模拟vector,下标从零开始
//unordered_map<int,bool>vis;
int log_[N];
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
void pre()
{
    for(int i=0;i<=20;i++)
        log_[1<<i]=i;
}
inline int gcd(int x,int y)
{
    if(!y)
        return x;
    return gcd(y,x%y);
}
void find_factors(int x,vector<int>&v,unordered_map<int,bool>&vis)
{
    for(int i=0;i<cnt && primes[i]<=x/primes[i];i++)
    {
        int temp=primes[i];
        if(x%temp==0)
        {
            if(!vis[temp])
            {
                //stk[++top]=temp;
                v.emplace_back(temp);
                vis[temp]=true;
            }
            while(x%temp==0)
                x/=temp;
        }
    }
    if(x>1)
    {
        if(!vis[x])
        {
            //stk[++top]=x;
            v.emplace_back(x);
            vis[x]=true;
        }
    }
}
void find_mobius(int n)
{
    //mobius[1] = 1;
    for (register int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            //mobius[i] = -1;
        }
        for (register int j=0;j<cnt && primes[j]<=n/i;j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                //mobius[primes[j] * i] = 0;
                break;
            }
            //mobius[primes[j] * i] = mobius[i] * (-1);
        }
    }
}
int lowbit(int x)
{
    return x&(-x);
}
int huzhi_cnt(int n,vector<int>&v,unordered_map<int,bool>&vis)//[1,n]中与v中所有素数互质的数的个数
{
    int res=0;
    int len=v.size();
    //int len=top+1;
    int tot=(1<<len)-1;//len位二进制数，0到len-1，每位取0/1
    for(int i=1;i<=tot;i++)
    {
        int neg=1;
        ll temp=1;
        //for(register int j=0;j<=len-1;j++)
        int t=i;
        while(t)
        {
            neg^=1;
            int lb=lowbit(t);
            t^=lb;
            temp*=v[log_[lb]];
            //temp*=stk[log_[lb]];
            if(temp>n)
                break;
        }
            //res+=(n/temp)*mobius[temp];
            if(neg)
                res-=(n/temp);
            else
                res+=(n/temp);
    }
    return n-res;
}
/*inline void clear_all()
{
    vis.clear();
    v.clear();
}*/
void solve()
{
    n=read(),q=read();
    //scanf("%d%d",&n,&q);
    for(int i=1,x,y;i<=q;i++)
    {
        x=read(),y=read();
        //scanf("%d%d",&x,&y);
        int com_factors=gcd(x,y);
        if(com_factors==1)
        {
            printf("1 1\n");
            continue;
        }
        vector<int>v;
        unordered_map<int, bool>vis;
        find_factors(com_factors,v,vis);
        find_factors(x/com_factors,v,vis);
        find_factors(y/com_factors,v,vis);
        int res=huzhi_cnt(n,v,vis);
        if(com_factors==2)
            res++;
        printf("2 %d\n",res);
        //clear_all();
    }
}
int main()
{
    pre();
    //cout<<log_[32]<<endl;
    find_mobius(D);
    solve();
    return 0;
}
