#include <bits/stdc++.h>

void charming() {
  int l, n, m; std::cin >> l >> n >> m;
  std::vector<int> a(l + 5);
  for (int i = 0; i < l; ++i) std::cin >> a[i];
  std::vector b(n + 5, std::vector<int> (m + 5));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) std::cin >> b[i][j];
  
  std::vector f(n + 5, std::vector<int> (m + 5));
  for (int i = l - 1; i >= 0; --i) {
    std::vector nf(n + 5, std::vector<int> (m + 5));
    int tar = a[i];
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (!f[j + 1][k + 1] && b[j][k] == tar) {
          nf[j][k] = 1;
        }
        else nf[j][k] = 0;
      }
    }
    for (int j = n - 1; j >= 0; --j) {
      for (int k = m - 1; k >= 0; --k) {
        nf[j][k] |= nf[j + 1][k];
        nf[j][k] |= nf[j][k + 1];
      }
    }
    f = nf;
  }
  if (f[0][0]) std::cout << "T\n";
  else std::cout << "N\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}