#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> cnt(4);
  std::string s; std::cin >> s;
  int c = 0;
  for (char ch : s) {
    if (ch == '?') ++c;
    else ++cnt[ch - 'A'];
  }
  int ans = 4 * n - c;
  for (int i = 0; i < 4; ++i) if (cnt[i] > n) ans -= cnt[i] - n;
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