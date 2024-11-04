#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

void charming() {
  ll x; std::cin >> x;
  bool flag = 0, chk = true;
  while (x) {
    int d = x % 10; x /= 10;
    if (!flag) flag = 1;
    else d = (d + 9) % 10;
    if (d == 9) {chk = false; break;}
    if (x == 0 && d > 0) {chk = false; break;}
  }
  if (chk) std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}