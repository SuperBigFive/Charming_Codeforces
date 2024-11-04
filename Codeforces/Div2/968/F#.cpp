#include <bits/stdc++.h>
using ll = long long;
std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 32;
const int M = 3e3 + 5;
const int T = 300;

struct FinwickTree {
  int n;
  std::vector<int> mx;

  void Init(int _n) {n = _n; mx = std::vector<int> (n + 1);}
  int lowbit(int x) {return x & -x;}
  void upd(int x, int val) {while (x <= n) mx[x] = std::max(mx[x], val), x += lowbit(x);}
  int ask(int x) {int ans = 0; while (x) ans = std::max(ans, mx[x]), x -= lowbit(x); return ans;}
} bit[N];

void charming() {
  int n, m; std::cin >> n >> m;
  std::vector<int> a(n), b(n), c(n), f(M);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  
  int ans = 0;
  for (int _ = 0; _ < T; ++_) {
    for (int i = 1; i < (1 << m); ++i) bit[i].Init(n);
    for (int i = 0; i < M; ++i) f[i] = rnd() % m;
    for (int i = 0; i < n; ++i) {
      int col = f[b[i]]; bit[1 << col].upd(a[i], c[i]);
      for (int st = 1; st < (1 << m); ++st) if (!(st >> col & 1)) {
        int nst = st | (1 << col), mx = bit[st].ask(a[i]);
        if (mx) bit[nst].upd(a[i], mx + c[i]);
      }
      ans = std::max(ans, bit[(1 << m) - 1].ask(n));
    }
  }
  
  if (!ans) ans = -1;
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}
