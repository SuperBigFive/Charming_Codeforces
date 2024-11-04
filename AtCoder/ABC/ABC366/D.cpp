#include <bits/stdc++.h>
using ll = long long;
const int N = 1e6 + 5;

void charming() {
  int n; std::cin >> n;
  std::vector<std::vector<std::vector<int> > > a(n + 1, 
  std::vector<std::vector<int> > (n + 1, std::vector<int> (n + 1)));
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
    for (int k = 1, x; k <= n; ++k) {
      std::cin >> x;
      a[i][j][k] = a[i - 1][j][k] + a[i][j - 1][k] + a[i][j][k - 1] 
      - a[i - 1][j - 1][k] - a[i - 1][j][k - 1] - a[i][j - 1][k - 1] 
      + a[i - 1][j - 1][k - 1] + x;
    }
  }
  int q; std::cin >> q;
  for (int i = 1, l1, r1, l2, r2, l3, r3; i <= q; ++i) {
    std::cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
    ll ans = a[r1][r2][r3] - a[l1 - 1][r2][r3] - a[r1][l2 - 1][r3] - a[r1][r2][l3 - 1]
    + a[l1 - 1][l2 - 1][r3] + a[l1 - 1][r2][l3 - 1] + a[r1][l2 - 1][l3 - 1]
    - a[l1 - 1][l2 - 1][l3 - 1];
    std::cout << ans << '\n';
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}