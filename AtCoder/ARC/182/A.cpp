#include <bits/stdc++.h>
using ll = long long;
const int N = 5e3 + 5;
const int MOD = 998244353;

void charming() {
  int n, q; std::cin >> n >> q;
  std::vector<std::multiset<int> > mn(N), mx(N);
  for (int i = 1; i < N; ++i) mn[i].insert(INT_MAX), mx[i].insert(0);
  std::vector<std::pair<int, int> > pv;
  for (int i = 0, p, v; i < q; ++i) {
    std::cin >> p >> v;
    pv.emplace_back(std::make_pair(p, v));
    mn[p].insert(v);
  }

  int ans = 1;
  for (int i = 0, p, v; i < q; ++i) {
    p = pv[i].first, v = pv[i].second;
    int ok1 = 1, ok2 = 1;
    for (int j = 1; j <= p; ++j) {
      if ((*mn[j].begin()) < v) {ok1 = 0; break;}
    }
    for (int j = p; j <= n; ++j) {
      if ((*mn[j].begin()) < v) {ok2 = 0; break;}
    }

    for (int j = 1; j <= p && ok1; ++j) {
      if ((*mx[j].rbegin()) > v) {ok1 = 0; break;}
    }
    for (int j = p; j <= n && ok2; ++j) {
      if ((*mx[j].rbegin()) > v) {ok2 = 0; break;}
    }

    ans = 1ll * ans * (ok1 + ok2) % MOD;
    if (!ans) break;

    mn[p].erase(mn[p].find(v));
    mx[p].insert(v);
  }

  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}