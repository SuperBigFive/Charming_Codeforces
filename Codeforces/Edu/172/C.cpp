#include <bits/stdc++.h>

void charming() {
  int n, k; std::cin >> n >> k;
  std::string s; std::cin >> s;
  int suf = 0;
  std::vector<int> a;
  for (int i = n - 1; i > 0; --i) {
    if (s[i] == '0') --suf;
    else ++suf;
    a.emplace_back(suf);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  bool ok = false;
  int ans = 1;
  for (int x : a) {
    if (x <= 0) break;
    else {
      ++ans;
      k -= x;
      if (k <= 0) {ok = true; break;}
    }
  }
  if (ok) std::cout << ans << '\n';
  else std::cout << -1 << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
