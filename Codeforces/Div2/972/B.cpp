#include <bits/stdc++.h>

void charming() {
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<int> b(m), ans(q);
  std::vector<std::pair<int, int> > qry(q);
  for (int i = 0; i < m; ++i) std::cin >> b[i];
  for (int i = 0; i < q; ++i) {
    std::cin >> qry[i].first;
    qry[i].second = i;
  }
  sort(b.begin(), b.end());
  sort(qry.begin(), qry.end());

  std::function<int(int, int)> Solve = [&](int pre, int nxt) {
    if (pre > nxt) std::swap(pre, nxt);
    int d = nxt - pre, ans = 0;
    if (d & 1) ans = (d + 1) / 2 + pre;
    else ans = d / 2 + pre + 1;
    return ans;
  };

  for (int i = 0, p = 0, x, q_idx; i < q; ++i) {
    x = qry[i].first, q_idx = qry[i].second;
    while (p < m && b[p] < x) ++p;
    if (p == 0) ans[q_idx] = b[0] - 1;
    else if (p >= m) ans[q_idx] = n - b[m - 1];
    else ans[q_idx] = Solve(b[p] - x - 1, x - b[p - 1] - 1);
  }

  for (int i = 0; i < q; ++i) std::cout << ans[i] << "\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}