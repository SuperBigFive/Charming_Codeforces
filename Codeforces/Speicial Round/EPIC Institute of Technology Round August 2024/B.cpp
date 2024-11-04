#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  if (b == a) std::cout << "Bob\n";
  else {
    reverse(b.begin(), b.end());
    if (b == a) std::cout << "Bob\n";
    else std::cout << "Alice\n";
  } 
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}