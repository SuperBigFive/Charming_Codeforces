#include <bits/stdc++.h>
const int N = 2e5 + 5;
const int M = 1e9;

struct SegmentTree {
  int root, tot;
  std::vector<int> ls, rs, mn;

  SegmentTree() {
    root = tot = 1;
    ls = rs = std::vector<int> (N << 6);
    mn = std::vector<int> (N << 6, INT_MAX);
  }

  void Clear() {
    for (int i = 0; i <= tot; ++i) ls[i] = rs[i] = 0,  mn[i] = INT_MAX;
    root = tot = 1;
  }

  void PushUp(int rt) {
    mn[rt] = std::min(mn[ls[rt]], mn[rs[rt]]);
  }

  void Modify(int &rt, int l, int r, int p) {
    if (!rt) rt = ++tot;
    if (l == r) {mn[rt] = l; return;}
    int mid = l + r >> 1;
    if (p <= mid) Modify(ls[rt], l, mid, p);
    else Modify(rs[rt], mid + 1, r, p);
    PushUp(rt);
  }

  int Query(int rt, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[rt];
    int mid = l + r >> 1, ans = INT_MAX;
    if (ql <= mid) ans = std::min(ans, Query(ls[rt], l, mid, ql, qr));
    if (qr > mid) ans = std::min(ans, Query(rs[rt], mid + 1, r, ql, qr));
    return ans; 
  }
} tree;

void charming() {
  int n; std::cin >> n; tree.Clear();
  std::vector<std::pair<std::pair<int, int>, int> > like(n);
  for (int i = 0, l, r; i < n; ++i) {
    std::cin >> l >> r;
    like[i] = std::make_pair(std::make_pair(l, r), i);
  }
  std::vector<int> ans(n);
  for (int _ : {0, 1}) {
    sort(like.begin(), like.end(), [](std::pair<std::pair<int, int>, int> a,
    std::pair<std::pair<int, int>, int> b) {
      if (a.first.first != b.first.first) return a.first.first < b.first.first;
      else return a.first.second > b.first.second;
    });
    for (int i = 0; i < n; ++i) {
      int l = like[i].first.first, r = like[i].first.second;
      int id = like[i].second;

      if (i && like[i].first == like[i - 1].first) {
        ans[id] = ans[like[i - 1].second] = 0;
      }

      else {
        int mn_r = tree.Query(tree.root, 1, M, r, M);
        if (mn_r < INT_MAX) ans[id] += mn_r - r;
      }
      
      tree.Modify(tree.root, 1, M, r);
    }
    tree.Clear();
    for (int i = 0; i < n; ++i) {
      int l = like[i].first.first, r = like[i].first.second;
      int id = like[i].second;
      int nr = M - l + 1, nl = M - r + 1;
      l = nl, r = nr;
      like[i] = std::make_pair(std::make_pair(l, r), id);
    }
  }

  for (int i = 0; i < n; ++i) std::cout << ans[i] << "\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
