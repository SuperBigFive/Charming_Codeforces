#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
string s1,s2;
int pow10[10];
void pre()
{
    pow10[0]=1;
    for(int i=1;i<=7;i++)
        pow10[i]=pow10[i-1]*10;
}
void solve()
{
    int num1=0,num2=0;
    cin>>s1>>s2;
    int siz1=s1.length();
    int siz2=s2.length();
    bool flag=true;
    for(int i=0;i<siz1;i++)
    {
        if(s1[i]<'0' || s1[i]>'9')
        {
            flag=false;
            num1=0;
        }
        else
            num1=num1+(s1[i]-'0')*pow10[siz1-i-1];
    }
    for(int i=0;i<siz2;i++)
    {
        if(s2[i]<'0' || s2[i]>'9')
        {
            flag=false;
            num2=0;
        }
        else
            num2=num2+(s2[i]-'0')*pow10[siz2-i-1];
    }
    if(!flag)
    {
        puts("NaN");
        return;
    }
    printf("%d\n",num1-num2);
}
int main()
{
    pre();
    solve();
    return 0;
}
