#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int M = 26;

int n, tot;
int nxt[N][M], sum[N], cnt[N];
string s[N];

void Insert (string &t) {
    int now = 0;
    for (char ch : t) {
        int ch2num = ch - 'a';
        if (!nxt[now][ch2num]) {
            nxt[now][ch2num] = ++tot;
        }
        now = nxt[now][ch2num];
    }
    sum[now] += (int) t.size (), ++cnt[now];
}

void DFS (int u) {
    for (int i = 0, v; i < M; ++i) if (nxt[u][i]) {
        v = nxt[u][i];
        DFS (v);
        sum[u] += sum[v];
        cnt[u] += cnt[v];
    }
}

ll Search (string &t) {
    reverse (t.begin (), t.end ());
    // cout << t << endl;
    int m = t.size (), now = 0;
    ll ans = 0;
    int len = 0;
    for (int i = 0, tar, ch2num; i < m; ++i) {
        ch2num = t[i] - 'a';
        tar = nxt[now][ch2num];
        if (tar) {
            ans += 1ll * (cnt[now] - cnt[tar]) * (m - 2 * len) + (sum[now] - sum[tar]);
            now = tar;
            ++len;
        }
        else break;
    }
    ans += cnt[now] * (m - len) + sum[now] - cnt[now] * len;
    // cout << ans << endl;
    return ans;
}

void charming () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        Insert (s[i]);
    }
    DFS (0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += Search (s[i]);
    }
    cout << ans << endl;

    // for (int i = 0; i <= tot; ++i) {
    //     cout << sum[i] << " " << cnt[i] << endl;
    // }
}

signed main () {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    charming ();
    return 0;
}