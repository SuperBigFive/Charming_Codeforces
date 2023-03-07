#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int a[N];
void solve()
{
    int n,m;
    string s,t;
    cin>>s>>t;
    n=s.length();
    m=t.length();
    int flag=0;
    int len=min(n,m);
    for(int i=0;i<=len-1;i++)
    {
        if(s[i]==t[i])
            continue;
        if(s[i]>t[i])
        {
            flag=1;
            break;
        }
        if(s[i]<t[i])
        {
            flag=2;
            break;
        }
    }
    if(flag==1)
        cout<<s<<">"<<t<<endl;
    else if(flag==2)
        cout<<s<<"<"<<t<<endl;
    else if(flag==0)
    {
        if(n>m)
            cout<<s<<">"<<t<<endl;
        else if(n<m)
            cout<<s<<"<"<<t<<endl;
        else if(n==m)
            cout<<s<<"="<<t<<endl;
    }

}
int main()
{
    solve();
    return 0;
}
