#include <bits/stdc++.h>

void charming() {
  int n, k; std::cin >> n >> k; ++n;
  std::vector<int> a(n);
  for (int i = 1; i < n; ++i) std::cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int sum = 0, ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (sum + a[i] <= k) {sum += a[i]; continue;}
    else {ans = k - sum; break;}
  }
  if (ans >= INT_MAX) ans = k - sum;
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
