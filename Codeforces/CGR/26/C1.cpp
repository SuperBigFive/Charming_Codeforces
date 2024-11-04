#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int now = 0; ll c = 0, mn = LLONG_MAX, mx = 0;
  for (int i = 0; i < n; ++i) {
    c += a[i];
    mn = std::min(mn, c);
    mx = std::max(mx, c);
  }
  std::cout << c - std::min(0ll, 2 * mn) << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}