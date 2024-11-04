#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;
  int mn = INT_MAX, mx = 0, mxa = 0;
  std::vector<int> tag(k << 2);
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a, mxa = std::max(mxa, a);
    a %= (k << 1);
    tag[a] += 1, tag[a + k] -= 1;
    if (a + k * 2 < (k << 2)) tag[a + k * 2] += 1;
    if (a + k * 3 < (k << 2)) tag[a + k * 3] -= 1;
  }
  int sum = 0;
  std::vector<int> idx;
  for (int i = 0; i < (k << 2); ++i) {
    sum += tag[i];
    if (sum == n) idx.emplace_back(i);
  }
  if (idx.empty()) std::cout << -1 << '\n';
  else {
    int ans = INT_MAX;
    for (int i : idx) {
      ll nans = i + 1ll * (mxa + 2 * k - 1) / (2 * k) * 2 * k;
      while (nans - 2 * k >= mxa) nans -= 2 * k;
      while (nans + 2 * k <= mxa) nans += 2 * k;
      ans = std::min((ll)ans, nans);
    }
    std::cout << ans << '\n';
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