#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<std::string> s(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    m = std::max(m, (int)s[i].size());
  }
  std::vector<std::vector<char> > ans(m, std::vector<char> (n, '0'));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)s[i].size(); ++j) {
      ans[j][n - i - 1] = s[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ans[i][j] == '0') {
        bool ok = false;
        for (int k = j; k < n; ++k) if (ans[i][k] != '0') {
          ok = true; break;
        }
        if (ok) ans[i][j] = '*';
      }
    }
  }
  
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ans[i][j] != '0') std::cout << ans[i][j];
    }
    std::cout << '\n';
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}