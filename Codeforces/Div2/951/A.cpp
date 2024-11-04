#include<bits/stdc++.h>
#define ll long long

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i) ans = std::min(ans, std::max(a[i - 1], a[i]));
  }
  std::cout << ans - 1 << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}