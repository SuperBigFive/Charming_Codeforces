#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

int n, tot;

void init () {}

void charming () {
  init ();
  cin >> n, tot = n;
  vector <int> ans (n << 1), pre (n << 1), siz (n << 1, 1), het (n << 1);
  vector <array <int, 2> > ch (n << 1);
  iota (pre.begin (), pre.end (), 0);

  auto Find = [&] (auto && me, int x) -> int {
    if (x == pre[x]) return x;
    else return pre[x] = me (me, pre[x]);
  };

  auto QSM = [&] (int x, int p) -> int {
    int ans = 1;
    while (p) {
      if (p & 1) ans = (1ll * ans * x) % MOD;
      p >>= 1, x = (1ll * x * x) % MOD;
    }
    return ans;
  };

  for (int i = 1, p, q, fp, fq, inv; i < n; ++i) {
    cin >> p >> q;
    fp = Find (Find, p), fq = Find (Find, q);
    if (het[fp] < het[fq]) swap (fp, fq);
    ++tot;
    ch[tot][0] = fp, ch[tot][1] = fq;
    inv = QSM (siz[fp] + siz[fq], MOD - 2);
    ans[fp] = 1ll * siz[fp] * inv % MOD;
    ans[fq] = 1ll * siz[fq] * inv % MOD;
    // cout << fp << " " << ans[fp] << " | " << fq << " " << ans[fq] << endl;
    siz[tot] = siz[fp] + siz[fq];
    het[tot] = het[fp] + (het[fp] == het[fq]);
    pre[fp] = pre[fq] = tot;
  }

  auto DFS = [&] (auto && me, int u, int sum) -> void {
    ans[u] = (ans[u] + sum) % MOD;
    if (u <= n) return;
    me (me, ch[u][0], ans[u]);
    me (me, ch[u][1], ans[u]);
  };

  DFS (DFS, tot, 0);
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
  charming ();
  return 0;
}