#include <bits/stdc++.h>
using ll = long long;

void charming() {
  std::string s; std::cin >> s;
  if (s[0] == 'R' || s[1] == 'R' && s[2] == 'M') std::cout << "Yes\n";
  else std::cout << "No\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}