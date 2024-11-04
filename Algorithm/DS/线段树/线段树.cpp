namespace SegmentTree {
  // 区间加操作, 维护最小值以及最小值的个数

  #define lson rt << 1
  #define rson rt << 1 | 1

  int n;
  std::vector<int> mn, cnt, lazy;

  void Init(int _n) {
    n = _n;
    mn = cnt = lazy = std::vector<int> (n << 2);
  }

  void Build(int rt = 1, int l = 0, int r = n - 1) {
    mn[rt] = 0, cnt[rt] = r - l + 1, lazy[rt] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
  }

  void PushDown(int rt) {
    if (!lazy[rt]) return;
    mn[lson] += lazy[rt];
    mn[rson] += lazy[rt];
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];
    
    lazy[rt] = 0;
  }

  void PushUp(int rt) {
    mn[rt] = std::min(mn[lson], mn[rson]);
    if (mn[lson] == mn[rson]) cnt[rt] = cnt[lson] + cnt[rson];
    else if (mn[lson] < mn[rson]) cnt[rt] = cnt[lson];
    else cnt[rt] = cnt[rson];
  }

  void Modify(int ql, int qr, int val, int rt = 1, int l = 0, int r = n - 1) {
    if (l >= ql && r <= qr) {
      mn[rt] += val;
      lazy[rt] += val;
      return;
    }
    PushDown(rt);
    int mid = l + r >> 1;
    if (ql <= mid) Modify(ql, qr, val, lson, l, mid);
    if (qr > mid) Modify(ql, qr, val, rson, mid + 1, r);
    PushUp(rt);
  }

  int Query() {
    if (mn[1] == 0) return cnt[1];
    else return INT_MAX;
  }

  #undef lson
  #undef rson
}

namespace SegmentTree {
  // 线段树上二分
  // 维护数组 a, 满足 a[i] = 0 or 1
  // 询问给定 l, 求最小的 r 使得 a[l], a[l + 1] , ... , a[r] 的和为 k

  #define lson rt << 1
  #define rson rt << 1 | 1

  int n;
  std::vector<int> sum;

  void Init(int _n) {
    n = _n;
    sum = std::vector<int> (n << 2);
  }

  void Modify(int p, int val, int rt = 1, int l = 0, int r = n - 1) {
    sum[rt] += val;
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid) Modify(p, val, lson, l, mid);
    else Modify(p, val, rson, mid + 1, r);
  }

  int _Query0(int ql, int qr, int rt = 1, int l = 0, int r = n - 1) {
    if (ql > qr) return 0;
    if (l >= ql && r <= qr) return sum[rt];
    int mid = l + r >> 1, ans = 0;
    if (ql <= mid) ans += _Query0(ql, qr, lson, l, mid);
    if (qr > mid) ans += _Query0(ql, qr, rson, mid + 1, r);
    return ans;
  }

  int _Query1(int k, int rt = 1, int l = 0, int r = n - 1) {
    if (l == r) return l;
    int mid = l + r >> 1;
    if (sum[lson] < k) {k -= sum[lson]; return _Query1(k, rson, mid + 1, r);}
    else return _Query1(k, lson, l, mid);
  }

  int Query(int l, int k) {
    k += _Query0(0, l - 1);
    if (sum[1] < k) return n;
    else return _Query1(k);
  }

  #undef lson
  #undef rson
}


namespace SegmentTree {
  // 线段树维护区间最大值以及个数, 区间加操作
  #define lson rt << 1
  #define rson rt << 1 | 1

  int N = 5e4, tot = 0;
  std::vector<int> mx, cnt, lazy;

  void Build(int rt = 1, int l = -N, int r = N) {
    if (l == r) {cnt[rt] = 1; return;}
    int mid = l + r >> 1;
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
    cnt[rt] = cnt[lson] + cnt[rson];
  }

  void Init() {mx = cnt = lazy = std::vector<int> (N << 4);}

  void PushUp(int rt) {
    mx[rt] = std::max(mx[lson], mx[rson]);
    if (mx[lson] > mx[rson]) cnt[rt] = cnt[lson];
    else if (mx[lson] < mx[rson]) cnt[rt] = cnt[rson];
    else cnt[rt] = cnt[lson] + cnt[rson];
  }

  void PushDown(int rt) {
    if (!lazy[rt]) return;
    
    mx[lson] += lazy[rt];
    mx[rson] += lazy[rt];
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];

    lazy[rt] = 0;
  }

  void Modify(int ql, int qr, int val, int rt = 1, int l = -N, int r = N) {
    if (l >= ql && r <= qr) {
      mx[rt] += val, lazy[rt] += val;
      return;
    }
    PushDown(rt);
    int mid = l + r >> 1;
    if (ql <= mid) Modify(ql, qr, val, lson, l, mid);
    if (qr > mid) Modify(ql, qr, val, rson, mid + 1, r);
    PushUp(rt);
  }

  int Query(int n) {
    if (mx[1] == n) return cnt[1];
    else return 0;
  }

  #undef lson
  #undef rson
}