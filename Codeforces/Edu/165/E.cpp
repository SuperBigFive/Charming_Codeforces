#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 3e5 + 5;

int t, n;

struct SegmentTree1 {
  int mn[N << 2];

  void Build (int rt, int l, int r) {
    mn[rt] = INT_MAX;
    if (l == r) return;
    int mid = l + r >> 1;
    Build (rt << 1, l, mid);
    Build (rt << 1 | 1, mid + 1, r);
  }

  void Modify (int rt, int l, int r, int p, int val) {
    mn[rt] = min (mn[rt], val);
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid) Modify (rt << 1, l, mid, p, val);
    else Modify (rt << 1 | 1, mid + 1, r, p, val);
  }

  int Query (int rt, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[rt];
    int mid = l + r >> 1, ans = INT_MAX;
    if (ql <= mid) ans = min (ans, Query (rt << 1, l, mid, ql, qr));
    if (qr > mid) ans = min (ans, Query (rt << 1 | 1, mid + 1, r, ql, qr));
    return ans;
  }
} tree1;

struct SegmentTree2 {
  int mn[N << 2], lazy[N << 2];
  
  void Build (int rt, int l, int r) {
    mn[rt] = lazy[rt] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    Build (rt << 1, l, mid);
    Build (rt << 1 | 1, mid + 1, r);
  }

  void PushDown (int rt) {
    if (!lazy[rt]) return;
    mn[rt << 1] += lazy[rt];
    mn[rt << 1 | 1] += lazy[rt];
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }

  void Modify (int rt, int l, int r, int ql, int qr, int val) {
    if (l >= ql && r <= qr) {
      mn[rt] += val;
      lazy[rt] += val;
      return;
    }
    PushDown (rt);
    int mid = l + r >> 1;
    if (ql <= mid) Modify (rt << 1, l, mid, ql, qr, val);
    if (qr > mid) Modify (rt << 1 | 1, mid + 1, r, ql, qr, val);
    mn[rt] = min (mn[rt << 1], mn[rt << 1 | 1]);
    cout << "tree2 " << rt << " " << mn[rt] << endl;
  }

  int findL (int rt, int l, int r, int p) {
    if (mn[rt] > 0) return n + 1;
    if (l == r) return l;
    PushDown (rt);
    int mid = l + r >> 1, ans = INT_MAX;
    if (p > mid && mn[rt << 1 | 1] > 0) ans = findL (rt << 1 | 1, mid + 1, r, p);
    if (ans < n + 1) return ans;
    else return findL (rt << 1, l, mid, p);
  }

} tree2;

vector <int> get_ans_pre (vector <int> &a) {
  tree1.Build (1, 1, n), tree2.Build (1, 1, n);
  vector <int> lst (n + 1), pre (n + 1);
  for (int i = 1; i <= n; ++i) {
    pre[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  cout << endl;
  vector <int> ans_pre (n + 1, INT_MAX);
  for (int i = 1, l, nxt; i <= n; ++i) {
    l = pre[i];
    if (l) tree2.Modify (1, 1, n, pre[l] + 1, l, -1);
    tree2.Modify (1, 1, n, pre[i] + 1, i, 1);
    l = tree2.findL (1, 1, n, i);
    if (l == n + 1) l = 0;
    cout << l << " " << i << endl;
    if (l) tree1.Modify (1, 1, n, i, 1 + tree1.Query (1, 1, n, max (l - 1, 1ll), i - 1));
    else tree1.Modify (1, 1, n, i, 0);
    tree2.Modify (1, 1, n, pre[i] + 1, i, 1);
    ans_pre[i] = tree1.Query (1, 1, n, i, i);
  }

  // cout << tree2.findL (1, 1, n, 3, 4) << endl;
  // for (int i = 1; i <= n; ++i) cout << ans_pre[i] << " ";
  // cout << endl;
  for (int i = 1; i <= n; ++i) cout << tree2.findL (1, 1, n, i) << " \n"[i == n];
  return ans_pre;
}

void charming () {
  cin >> n;
  vector <int> a (n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  
  vector <int> ans_pre = get_ans_pre (a);
  reverse (a.begin () + 1, a.end ());
  vector <int> ans_suf = get_ans_pre (a);
  reverse (ans_suf.begin () + 1, ans_suf.end ());

  bool flag = true;
  for (int i = 1; i <= n; ++i) flag &= (ans_pre[i] == 0 && ans_suf[i] == 0);
  if (flag) cout << 0 << endl;
  else {
    int ans = INT_MAX;
    for (int i = 2; i < n; ++i) ans = min (ans, 1 + ans_pre[i - 1] + ans_suf[i + 1]);
    cout << ans << endl;
  }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}