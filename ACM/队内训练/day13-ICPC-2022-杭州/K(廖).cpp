#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 5e5 + 10;
long long f[27][27];
vector<array<int, 27>> Trie;
vector<int> Cnt;
int dcnt=1;
int n,q;
void insert(int u, string &str, int len, int cur)
{
    ++Cnt[u];
    if(len <= cur)
    {
        return;
    }
    int x = str[cur] - 'a';
    for(int i = 0; i < 27; ++i)
    {
        if(x == i)
            continue;
        f[x][i] += Cnt[Trie[u][i]];
    }
    if(!Trie[u][x])
    {
        array<int, 27> arr {};
        Trie.push_back(arr);
        Cnt.push_back(0);
        Trie[u][x] = ++dcnt;
    }
    insert(Trie[u][x], str, len, cur+1);
}
void solve()
{
    array<int, 27> arr {};
    Trie.push_back(arr);
    Cnt.push_back(0);
    Trie.push_back(arr);
    Cnt.push_back(0);
    for(int k=1;k<=n;++k)
    {
        string str;
        cin>>str;
        str = str + (char)('z' + 1);
        insert(1, str, str.length(), 0);
    }
    for(int i=1;i<=q;++i)
    {
        string query;
        cin>>query;
        query = (char)('z' + 1) + query;
        long long ans = 0;
        for(int k=0;k<27;++k)
        {
            for(int l=k+1;l<27;++l)
                ans += f[query[k]-'a'][query[l]-'a'];
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    cin>>n>>q;
    solve();
    return 0;
}
