#include <bits/stdc++.h>

void charming() {
  int n; std::cin >> n;
  std::vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
  std::vector<char> ans;
  for (int i = 0; i < n; ++i) ans.emplace_back(ch[i % 5]);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < n; ++i) std::cout << ans[i];
  std::cout << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}