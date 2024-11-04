#include<bits/stdc++.h>
#define ll long long

void charming() {
  int x, y; std::cin >> x >> y;
  int ans = 1;
  while ((x % 2) == (y % 2)) {
    ans *= 2;
    x /= 2, y /= 2;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}