#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m, inv2;

void init () {}

ll QSM (ll x, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) ans = (ans * x) % MOD;
        p >>= 1, x = x * x % MOD;
    }
    return ans;
}

void charming () {
    init ();
    cin >> n >> m;
    vector <vector <int> > dp (m + 5, vector <int> (m + 5));
    for (int i = 1; i <= m; ++i) dp[i][m + 1] = m + 1 - i;
    ll ans = 0, inv2 = QSM (2, MOD - 2);

    auto DP = [&] (auto && me, int now, int nxt) -> int {
        if (nxt >= m + 1) return m + 1 - now;
        else if (now == nxt) return 0;
        else if (dp[now][nxt]) return dp[now][nxt];
        else return dp[now][nxt] = (me (me, now + 1, nxt) + 1 + me (me, now, nxt + 1)) * inv2 % MOD;
    };

    
    for (int i = 0, last = -1, now; i < n; ++i) {
        cin >> now;
        if (last != -1) ans = (ans + DP (DP, last, now)) % MOD;
        if (i == n - 1) ans = (ans + DP (DP, now, m + 1)) % MOD;
        last = now;
    }
    cout << ans << endl;
}

signed main () {
    charming ();
    return 0;
}
