#include<bits/stdc++.h>
#define ll long long

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  ll lcm = 1;
  for (int i = 0; i < n; ++i) {
    lcm = 1ll * lcm * a[i] / std::__gcd(lcm, 1ll * a[i]);
  }
  ll son = 0;
  for (int i = 0; i < n; ++i) {
    son += lcm / a[i];
  }
  if (son >= lcm) {
    std::cout << -1 << '\n';
  }
  else {
    for (int i = 0; i < n; ++i) {
      std::cout << lcm / a[i] << " \n"[i == n - 1];
    }
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}