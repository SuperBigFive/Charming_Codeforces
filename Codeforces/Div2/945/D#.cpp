#include <bits/stdc++.h>
#define ll long long
const int N = 1e4 + 5;

int ask (int l, int x) {
  std::cout << "? " << l << " " << x << std::endl;
  int rcv; std::cin >> rcv;
  return rcv;
}

int answer (int x) {
  std::cout << "! " << x << std::endl;
  int rcv; std::cin >> rcv;
  return rcv;
}

void charming() {
  int n, k;
  std::cin >> n >> k;
  int mx = 1;
  while (ask(1, mx * n) != n) ++mx;

  int m = -1;
  for (int i = n / k; i >= 1; --i) {
    int p = 1, chk = 0;
    for (int j = 1; j <= k && p <= n; ++j) {
      p = ask(p, i * mx) + 1;
      if (p > n + 1) break;
      if (p >= n + 1 && j == k) chk = 1; 
    }
    if (chk) {m = i * mx; break;}
  }

  answer(m);
}

signed main() {
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}