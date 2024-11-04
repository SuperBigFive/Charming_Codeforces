#include <bits/stdc++.h>
using ll = long long;
const int N = 1e7 + 5;

std::vector<int> prime, sg;

void Prep() {
  std::vector<int> vis(N);
  vis[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) prime.emplace_back(i), vis[i] = i;
    for (int p : prime) {
      if (i * p < N) {
        vis[i * p] = p;
        if ((i % p) == 0) break;
      } else break;
    }
  }

  sg = std::vector<int> (N);
  sg[1] = 1;
  for (int i = 1, siz = prime.size(); i < siz; ++i) {
    sg[prime[i]] = i + 1;
  }
  for (int i = 1; i < N; i += 2) sg[i] = sg[vis[i]];
}

void charming() {
  int n; std::cin >> n;
  int sum = 0;
  for (int i = 0, ai; i < n; ++i) {
    std::cin >> ai;
    sum ^= sg[ai];
  }
  if (sum) std::cout << "Alice\n";
  else std::cout << "Bob\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  Prep();
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
