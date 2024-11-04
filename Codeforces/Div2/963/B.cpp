#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  int c0 = 0, c1 = 0;
  std::vector<int> a0, a1;
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a;
    if (a & 1) ++c1, a1.emplace_back(a);
    else ++c0, a0.emplace_back(a);
  }
  sort(a0.begin(), a0.end(), [](int x, int y) {return x > y;});
  sort(a1.begin(), a1.end(), [](int x, int y) {return x > y;});
  int ans = 0;
  if (c0 == 0 || c1 == 0) std::cout << 0 << '\n';
  else {
    ll mx = a1[0], flag = false;
    for (int i = c0 - 1; i >= 0; --i) {
      if (mx >= a0[i]) mx += a0[i];
      else {
        flag = true;
        break;
      }
    }
    if (flag) std::cout << c0 + 1 << '\n';
    else std::cout << c0 << '\n';
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