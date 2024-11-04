#include <bits/stdc++.h>
using ll = long long;
const int N = 20;

void charming() {
  int n; std::cin >> n;
  std::vector<std::vector<std::pair<ll, int> > > stk(n + 1);
  std::vector<std::array<ll, N> > pre_mx(n);

  auto Update = [&](auto &&self, std::vector<std::pair<ll, int> > &stk_bi, std::pair<ll, int> a) -> void {
    if (stk_bi.empty()) stk_bi.emplace_back(a);
    else {
      int now = a.second - 1, lst = stk_bi.back().second;
      ll mx = -1;
      for (int i = N - 1; i >= 0; --i) {
        if (now - (1 << i) >= lst) {
          mx = std::max(mx, pre_mx[now][i]);
          now -= (1 << i);
        }
      }
      if (mx < a.first && mx < stk_bi.back().first) {
        a.first += stk_bi.back().first - mx;
        stk_bi.pop_back();
        self(self, stk_bi, a);
      }
      else stk_bi.emplace_back(a);
    }
  };

  ll ans = 0;
  for (int i = 0, ai, bi; i < n; ++i) {
    std::cin >> ai >> bi;
    Update(Update, stk[bi], std::make_pair(ai, i));
    ll nans = stk[bi].back().first;
    ans = std::max(ans, nans);
    pre_mx[i][0] = nans;
    for (int j = 1; j < N; ++j) {
      if (i - (1 << (j - 1)) >= 0) {
        pre_mx[i][j] = std::max(pre_mx[i][j - 1], pre_mx[i - (1 << (j - 1))][j - 1]);
      }
      else pre_mx[i][j] = pre_mx[i][j - 1];
    }
    std::cout << ans << " \n"[i == n - 1];
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
