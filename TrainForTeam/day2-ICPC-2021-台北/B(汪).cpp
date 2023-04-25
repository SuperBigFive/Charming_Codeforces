#include<bits/stdc++.h>
#define N 1500
using namespace std;
typedef long long ll;
char ch1[N],ch2[N];
int equal_cnt[N];//前缀和
int cross_cnt[N][N];
int cal(int l,int r)
{
    if(l>r)
        return 0;
    return equal_cnt[r]-equal_cnt[l-1];
}
bool cmp(pair <int, int> &x, pair <int, int> &y)
{
    if( (x.second-x.first) == (y.second-y.first) )
        return x.first<y.first;
    return ( (x.second-x.first) < (y.second-y.first) );
}
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&ch1[i]);
    for(int i=1;i<=n;i++)
        scanf(" %c",&ch2[i]);
    /*
    for(int i=1;i<=n;i++)
        printf("%c",ch1[i]);
    puts("");
    for(int i=1;i<=n;i++)
        printf("%c",ch2[i]);
    puts("");
    */
    //printf("%c\n",ch1[10]);
    //printf("%c\n",ch2[10]);
    //if(ch1[10]==ch2[10])
    //    puts("66666");
    for(int i=1;i<=n;i++)
        if(ch1[i]==ch2[i])
            equal_cnt[i]=equal_cnt[i-1]+1;
        else
            equal_cnt[i]=equal_cnt[i-1];
    int l,r;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        if(ch1[i]==ch2[i])
            cnt++;
        cross_cnt[i][i]=cnt;
        for(int j=1;j<=n;j++)
        {
            l=i-j,r=i+j;
            if(l<=0 || r>=n+1)
                break;
            if(ch1[l]==ch2[r])
                cnt++;
            if(ch1[r]==ch2[l])
                cnt++;
            cross_cnt[l][r]=cnt;
        }
    }
    for(int i=1;i<=n-1;i++)//枚举中间偏左
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            l=i-j+1,r=i+j;
            if(l<=0 || r>=n+1)
                break;
            if(ch1[l]==ch2[r])
                cnt++;
            if(ch1[r]==ch2[l])
                cnt++;
            cross_cnt[l][r]=cnt;
        }
    }
    int max_val=-1,cur_cnt=0;
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            cur_cnt=cal(1,i-1)+cal(j+1,n)+cross_cnt[i][j];
            if(cur_cnt>max_val)
            {
                max_val=cur_cnt;
                v.clear();
                v.push_back({i,j});
            }
            else if(cur_cnt==max_val)
                v.push_back({i,j});
        }
    int ans1=equal_cnt[n];
    int ans2=max_val;
    sort(v.begin(),v.end(),cmp);
    int ans3=v[0].first;
    int ans4=v[0].second;
    printf("%d %d %d %d\n",ans1,ans2,ans3,ans4);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
