#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e9 + 5;

char getch () { 
	static char buf[100000], *s1, *s2; 
	return (s1 == s2) && (s2 = (s1 = buf) + 
	fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++; 
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {ch = getch (); if (ch == '-') w = -1;}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

struct SegmentTree {
  int n, root, tot;
  int mx[N << 6], ls[N << 6], rs[N << 6];

  void init () {
    for (int i = 0; i <= tot; ++i) mx[i] = ls[i] = rs[i] = 0;
    tot = root = 0;
  }  

  void Modify (int &rt, int l, int r, int ql, int qr, int k) {
    if (!rt) rt = ++tot;
    if (l >= ql && r <= qr) {mx[rt] = max (mx[rt], k); return;}
    int mid = l + r >> 1;
    if (ql <= mid) Modify (ls[rt], l, mid, ql, qr, k);
    if (qr > mid) Modify (rs[rt], mid + 1, r, ql, qr, k);
  }

  int Query (int rt, int l, int r, int p) {
    int ans = mx[rt];
    if (!rt || l == r) return ans;
    int mid = l + r >> 1;
    if (p <= mid) ans = max (ans, Query (ls[rt], l, mid, p));
    else ans = max (ans, Query (rs[rt], mid + 1, r, p));
    return ans;
  }
} Tree;

int t, n, q;

void init () {Tree.init ();}

void charming () {
  init ();
  n = read ();
  vector <array <int, 4> > seq (n);
  for (int i = 0; i < n; ++i) {
    seq[i][0] = read (), seq[i][3] = read ();
    seq[i][1] = read (), seq[i][2] = read ();
  }
  sort (seq.begin (), seq.end (), [] (array <int, 4> &x,
  array <int, 4> &y) {return x[2] < y[2];});
  vector <int> stk;
  for (int i = 0; i < n; ++i) {
    while ((int) stk.size () && seq[stk.back ()][2] >= seq[i][0]) {
      seq[i][0] = min (seq[i][0], seq[stk.back ()][0]);
      stk.pop_back ();
    }
    stk.emplace_back (i);
  }
  for (int id : stk) {
    Tree.Modify (Tree.root, 1, M, seq[id][0], seq[id][2], seq[id][2]);
    // cout << seq[id][0] << " " << seq[id][2] << endl;
  }
  q = read ();
  for (int i = 0, x; i < q; ++i) {
    x = read ();
    printf ("%d ", max (x, Tree.Query (Tree.root, 1, M, x)));
  }
  printf ("\n");
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}
