#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

struct SegmentTree {
  int mx[N << 2];
  
  void init(int n) {
    for (int i = 1; i <= (n << 2); ++i) mx[i] = 0;
  }
  
  void Modify(int rt, int l, int r, int p, int k) {
    mx[rt] = std::max(mx[rt], k);
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid) Modify(rt << 1, l, mid, p, k);
    else Modify(rt << 1 | 1, mid + 1, r, p, k);
  }

  int Query(int rt, int l, int r, int ql, int qr) {
    if (ql > qr) return 0;
    if (l >= ql && r <= qr) return mx[rt];
    int mid = l + r >> 1, ans = 0;
    if (ql <= mid) ans = std::max(ans, Query(rt << 1, l, mid, ql, qr));
    if (qr > mid) ans = std::max(ans, Query(rt << 1 | 1, mid + 1, r, ql, qr));
    return ans;
  }

} tree;

void charming() {
  int n; std::cin >> n;
  tree.init(n);
  std::vector<int> a(n), b;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    b.emplace_back(a[i]);
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  std::vector<std::pair<int, int>> seg(n, std::make_pair(-1, -1));
  std::vector<std::vector<int>> pos(n+1);
  int mx = 0;
  for (int i = 0, f; i < n; ++i) {
    a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    f = tree.Query(1, 0, n, 0, a[i] - 1);
    if (f) {
      int l = 0, r = (int) pos[f].size () - 1, k = r;
      while (l <= r) {
        int mid = l + r >> 1;
        if (a[pos[f][mid]] < a[i]) r = mid - 1, k = mid;
        else l = mid + 1;
      }
      seg[i] = std::make_pair(k, (int) pos[f].size() - 1);
    }
    mx = std::max(mx, f + 1);
    pos[f + 1].emplace_back(i);
    tree.Modify(1, 0, n, a[i], f + 1);
  }

  std::vector<int> ans, stk;
  for (int x : pos[mx]) {
    stk.emplace_back(x);
    ans.emplace_back(x + 1);
  }
  for (int i = mx - 1; i >= 1; --i) {
    std::vector<std::pair<int, int>> seg1, seg2;
    for (int x: stk) {
      auto [sl, sr] = seg[x];
      seg1.emplace_back(std::make_pair(sl, sr));
    }
    sort(seg1.begin(), seg1.end(), [](std::pair<int, int> &x,
    std::pair<int, int> &y) {return x.first < y.first;});
    for (auto [l, r] : seg1) {
      if ((int) seg2.size() > 0 && seg2.back().second >= l) {
        seg2.back().second = std::max(seg2.back().second, r);
      }
      else seg2.emplace_back(std::make_pair(l, r));
    }
    stk.clear();
    for (auto [l, r] : seg2) {
      for (int j = l; j <= r; ++j) {
        ans.emplace_back(pos[i][j] + 1);
        stk.emplace_back(pos[i][j]);
      }
    }
  }

  int m = ans.size();
  sort(ans.begin(), ans.end());
  std::cout << m << "\n";
  for (int i = 0; i < m; ++i) std::cout << ans[i] << " \n"[i == m - 1];
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}
