#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, m;
  std::string s, t; std::cin >> s >> t;
  n = s.size(), m = s.size();
  for (int len = 1; len < n; ++len) {
    for (int i = 0; i < len; ++i) {
      std::string nt;
      for (int j = i; j < n; j += len) {
        nt += s[j];
      }
      if (nt == t) {
        puts("Yes");
        return;
      }
    }
  }
  puts("No");
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}