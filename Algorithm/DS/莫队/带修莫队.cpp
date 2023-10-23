#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, len, blo, qcnt, ccnt;
int a[N], b[N], bel[N], ans[N], pre[N], nxt[N];
int cntx[N], cntc[N];

struct Query {
  int l, r, k, t, qid;
  Query () {}
  Query (int l, int r, int k, int t, int qid) : 
  l (l), r (r), k (k), t (t), qid (qid) {}
  array <int, 5> Get () {return (array <int, 5>) {l, r, t, k, qid};}
} qry[N];

struct Change {
  int p, old, x, t;
  Change () {}
  Change (int p, int old, int x, int t) : p (p), old (old), x (x), t (t) {}
} cge[N];

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

void ListInsert (int x) {
  pre[x] = pre[n + 1];
  nxt[x] = n + 1;
  nxt[pre[x]] = pre[n + 1] = x;
}

void ListErase (int x) {
  nxt[pre[x]] = nxt[x], pre[nxt[x]] = pre[x];
}

void Add (int x) {
  --cntc[cntx[x]];
  if (cntc[cntx[x]] == 0) ListErase (cntx[x]);
  ++cntx[x];
  ++cntc[cntx[x]];
  if (cntc[cntx[x]] == 1) ListInsert (cntx[x]);
}

void Del (int x) {
  --cntc[cntx[x]];
  if (cntc[cntx[x]] == 0) ListErase (cntx[x]);
  --cntx[x];
  ++cntc[cntx[x]];
  if (cntc[cntx[x]] == 1) ListInsert (cntx[x]);
}

void Update (int t, int sign, int l, int r) {
  int p = cge[t].p, old = cge[t].old, x = cge[t].x;
  bool inSeq = (p >= l && p <= r);
  if (sign == 1) {
    if (inSeq) Del (old), Add (x);
    a[p] = x;
  }
  else {
    if (inSeq) Del (x), Add (old);
    a[p] = old;
  }
}

int getAns (int k) {
  vector <int> vec;
  int sum = 0;
  for (int i = nxt[0]; i != n + 1; i = nxt[i]) {
    vec.emplace_back (i), sum += cntc[i];
  }
  if (sum < k) return -1;
  sort (vec.begin (), vec.end ());
  sum = cntc[vec[0]];
  int ans = INT_MAX;
  for (int i = 0, j = 0, siz = vec.size (); i < siz; ++i) {
    while (j + 1 < siz && sum < k) ++j, sum += cntc[vec[j]];
    if (sum < k) break;
    else ans = min (ans, vec[j] - vec[i]);
    sum -= cntc[vec[i]];
  }
  return ans;
}

void init () {cntc[0] = N;}

void charming () {
  init ();
  n = read (), m = read ();
  len = pow (n, 0.6667), blo = (n + len - 1) / len;
  for (int i = 1; i <= n; ++i) bel[i] = (i + len - 1) / len;
  for (int i = 1; i <= n; ++i) b[i] = a[i] = read ();
  for (int i = 1, opt, l, r, k, p, x; i <= m; ++i) {
    opt = read ();
    if (opt == 1) {
      ++qcnt;
      l = read (), r = read (), k = read ();
      qry[qcnt] = Query (l, r, k, ccnt, qcnt);
    } else {
      ++ccnt;
      p = read (), x = read ();
      cge[ccnt] = Change (p, b[p], x, ccnt);
      b[p] = x;
    }
  }
  sort (qry + 1, qry + 1 + qcnt, [&] (Query &x,
  Query &y) {
    if (bel[x.l] != bel[y.l]) return bel[x.l] < bel[y.l];
    else if (bel[x.r] != bel[y.r]) return bel[x.r] < bel[y.r];
    else return x.t < y.t;
  });

  nxt[0] = n + 1, pre[n + 1] = 0;
  for (int i = 1, l = 1, r = 0, t = 0; i <= qcnt; ++i) {
    auto [ql, qr, qt, qk, qid] = qry[i].Get ();
    while (l > ql) Add (a[--l]);
    while (r < qr) Add (a[++r]);
    while (l < ql) Del (a[l++]);
    while (r > qr) Del (a[r--]);
    while (t < qt) Update (++t, 1, l, r);
    while (t > qt) Update (t--, -1, l, r);
    ans[qid] = getAns (qk);
  }
  for (int i = 1; i <= qcnt; ++i) printf ("%d\n", ans[i]);
}

signed main () {
  charming ();
  return 0;
}
