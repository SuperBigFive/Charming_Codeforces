#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

struct SegmentTree {
  int n, tot;
  vector <int> a, node, ls, rs, root, fiPrime;

  ll fpow (ll x, ll p) {
    ll ans = 1;
    while (p) {
      if (p & 1) ans = (ans * x) % MOD;
      p >>= 1, x = (x * x) % MOD;
    }
    return ans;
  }

  ll GCD (ll x, ll y) {
    ll gcd = __gcd (x, y);
    return fpow (gcd, MOD - 2);
  }

  void Update (int rt) {
    node[rt] = (node[rt << 1] * node[rt << 1 | 1]) % MOD  * 
      GCD (node[rt << 1], node[rt << 1 | 1]);
    node[rt] = ((node[rt] % MOD) + MOD) % MOD;
  }

  void Modify (int &rt, int l, int r, int ql, int qr) {
    if (!rt) rt = ++tot;
    if (l == r) {node[rt] = (node[rt] *  l) % MOD; return;}
    int mid = l + r >> 1;
    if (ql <= mid) Modify (ls[rt], l, mid, ql, qr);
    else Modify (rt[rt], mid + 1, r, ql, qr);
    node[rt] = node[ls[rt]] * node[rs[rt]] % MOD;
  }

  void Merge (int rt1, int rt2, int l, int r) {
    if (!rt1 || !rt2) return rt1 | rt2;
    int cur = ++tot;

  }

  void Build (int rt, int l, int r) {
    if (l == r) {
      int p = fiPrime[a[l]];
      while (a[l]) {
        modify (root[rt], 1, n, p);
        a[l] /= p, p = fiPrime[a[l]];
      }
      return;
    }
    int mid = l + r >> 1;
    Build (rt << 1, l, mid);
    Build (rt << 1 | 1, mid + 1, r);
    root[rt] = Merge (root[rt << 1], root[rt << 1 | 1]);
  }

  SegmentTree (int n, vector <int> &a, vector <int> &fiPrime) {
    this -> n = n;
    node = vector <int> (n * 40, 1);
    ls = rs = vector <int> (n * 40);
    root = vector <int> (n << 2);
    this -> a = a, this -> fiPrime = fiPrime;
    Build (1, 1, n);
  }

  int Query (int rt, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return node[rt];
    int mid = l + r >> 1, ans = 1, nans;
    if (ql <= mid) {
      nans = Query (rt << 1, l, mid, ql, qr);
      ans = (ans * nans % MOD) * GCD (ans, nans);
      ans = ((ans % MOD) + MOD) % MOD;
    }
    if (qr > mid) {
      nans = Query (rt << 1 | 1, mid + 1, r, ql, qr);
      ans = (ans * nans % MOD) * GCD (ans, nans);
      ans = ((ans % MOD) + MOD) % MOD;
    }
    return ans;
  }
};

int n, q;

void Get_Prime (vector <int> &fiPrime) {
  vector <int> vis (N), Prime;
  for (int i = 2, siz = 0; i < N; ++i) {
    if (!vis[i]) Prime.emplace_back (i), fiPrime[i] = i, ++siz;
    for (int j = 0; j < siz && i * Prim[j] < N; ++j) {
      fiPrime[i * Prime[j]] = Prime[j];
      vis[i * Prime[j]] = true;
      if (i % Prime[j] == 0) break;
    }
  }
}

void init () {}

void charming () {
  init ();
  cin >> n;
  vector <int> a (n + 5), fiPrime (N);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  SegmentTree ST (n, a, Get_Prime (fiPrime));
  cin >> q;
  for (int i = 1, l, r, lastans = 0; i <= q; ++i) {
    cin >> l >> r;
    l = (l + lastans) % n + 1;
    r = (r + lastans) % n + 1;
    if (l > r) swap (l, r);
    lastans = ST.Query (1, 1, n, l, r);
    cout << lastans << endl;
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  /*mt19937 rnd (random_device {} ());
  int t = 100;
  while (t--) {
  n = 6;
  vector <int> a (n + 5);
  int b = 1, c = 1, lcm = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = rnd () % 16 + 1,  b *= a[i], c *= __gcd (a[i - 1], a[i]);
    lcm = lcm * a[i] / __gcd (lcm, a[i]);
  }
  cout << lcm << " " << b << " " << c << " " << b / c << endl;
  }*/
  return 0;
}
