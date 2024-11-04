#include <bits/stdc++.h>
const int INF = 1e9;

void charming() {
  int n, m; std::cin >> n >> m;
  std::vector<char> letter = {'n', 'a', 'r', 'e', 'k'};
  std::vector<std::string> s(n);
  std::vector gain(n, std::array<std::pair<int, int>, 5> ());
  // gain[i][j]: 第 i 个串, 从 j 开始匹配时, 得分差(first)以及下一个要匹配的字符(second)

  std::vector<int> cnt(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    for (char ch0 : s[i]) {
      bool chk = false;
      for (char ch1 : letter) if (ch0 == ch1) {
        chk = true; break;
      }
      if (chk) ++cnt[i];
    }
    for (int j = 0, p; j < 5; ++j) {
      p = j;
      gain[i][j].first = -cnt[i];
      for (int k = 0, c = 0; k < m; ++k) {
        if (s[i][k] == letter[p]) {
          ++c;
          p = (p + 1) % 5;
          if (!p) gain[i][j].first += 10, c = 0;
        }
      }
      gain[i][j].second = p;
    }
  }
  
  int ans = 0;
  std::array<int, 5> f = {0, -INF, -INF, -INF, -INF};
  for (int i = 0; i < n; ++i) {
    std::array<int, 5> nf = f;
    for (int j = 0; j < 5; ++j) {
      int new_val = f[j] + gain[i][j].first;
      int new_st = gain[i][j].second;
      ans = std::max(ans, new_val);
      nf[new_st] = std::max(nf[new_st], new_val);
    }
    f = nf;
  }

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