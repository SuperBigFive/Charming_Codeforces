#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  if (s[0] == s.back()) std::cout << "No\n";
  else std::cout << "Yes\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}