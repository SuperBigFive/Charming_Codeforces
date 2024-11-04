#include <bits/stdc++.h>

void charming() {
  char a, b, c; std::cin >> a >> b >> c;
  if ((a == '<' && b == '>') || (a == '>' && b == '<')) std::cout << "A\n";
  else if ((a == '<' && c == '<') || (a == '>' && c == '>')) std::cout << "B\n";
  else std::cout << "C\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}