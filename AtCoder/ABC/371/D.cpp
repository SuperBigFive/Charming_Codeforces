#include <bits/stdc++.h>

void charming() {
  int n, q; std::cin >> n;
  std::vector<int> x(n), p(n);
  std::vector<long long> pre(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    if (i) pre[i] = pre[i - 1];
    pre[i] += p[i];
  }
  std::cin >> q;
  for (int i = 0, l, r; i < q; ++i) {
    std::cin >> l >> r;
    int idx0 = lower_bound(x.begin(), x.end(), l) - x.begin() - 1;
    int idx1 = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
    if (idx1 < 0) std::cout << 0 << '\n';
    else if (idx0 >= 0) std::cout << pre[idx1] - pre[idx0] << '\n';
    else std::cout << pre[idx1] << '\n';
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}