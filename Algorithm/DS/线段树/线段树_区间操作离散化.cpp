#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;

struct SegmentTree {
	int n, tot;
	vector <int> sum, L, R, lazy;
	vector <pair <int, int> > seq;
	
	SegmentTree (int n, vector <pair <int, int> > &seq) {
		this -> n = n, this -> tot = 1;
		this -> sum = this -> L = this -> R = vector <int> (n << 2 | 1);
		this -> lazy = vector <int> (n << 2 | 1, -1);
		this -> seq = seq;
	}
	
	void Build (int rt, int l, int r) {
		if (l == r) {
			L[rt] = seq[l].first;
			R[rt] = seq[l].second;
			return;
		}
		int mid = l + r >> 1;
		Build (rt << 1, l, mid);
		Build (rt << 1 | 1, mid + 1, r);
		L[rt] = L[rt << 1], R[rt] = R[rt << 1 | 1];
	}
	
	void PushUp (int rt) {
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
	
	void PushDown (int rt) {
		if (lazy[rt] == -1) return;
		else {
			sum[rt << 1] = (R[rt << 1] - L[rt << 1] + 1) * lazy[rt];
			sum[rt << 1 | 1] = (R[rt << 1 | 1] - L[rt << 1 | 1] + 1) * lazy[rt];
			lazy[rt << 1] = lazy[rt];
			lazy[rt << 1 | 1] = lazy[rt];
			lazy[rt] = -1;
		}
	}
	
	void Modify (int rt, int l, int r, int ql, int qr, int st) {
		if (L[rt] >= ql && R[rt] <= qr) {
			sum[rt] = (R[rt] - L[rt] + 1) * st;
			lazy[rt] = st;
			return;
		}
		int mid = R[rt << 1];
		PushDown (rt);
		if (ql <= mid) Modify (rt << 1, l, mid, ql, qr, st);
		if (qr > mid) Modify (rt << 1 | 1, mid + 1, r, ql, qr, st);
		PushUp (rt);
	}
};

inline int read () {
  int x = 0, f = 1; char ch = getchar ();
  while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar ();}
  while (ch >= '0' && ch <= '9') {x = x * 10 + ch -'0'; ch = getchar ();}
  return x * f;
}

inline void write (int x) {
	if (x < 0) {putchar ('-'); x = -x;}
  if (x > 9) write (x / 10);
  putchar (x % 10 + '0');
}

int n, q;

void init () {}

void charming () {
	init ();
	n = read (), q = read ();
	vector <int> sa;
	vector <array <int, 3> > ask;
	for (int i = 1, l, r, k; i <= q; ++i) {
		l = read (), r = read (), k = read ();
		ask.emplace_back ((array <int, 3>) {l, r, k});
		sa.emplace_back (l);
		sa.emplace_back (r);
	}
	sa.emplace_back (1), sa.emplace_back (n);
	sort (sa.begin (), sa.end ());
	sa.resize (unique (sa.begin (), sa.end ()) - sa.begin ());
	vector <pair <int, int> > seq;
	seq.emplace_back (make_pair (0, 0));
	for (int i = 0, siz = sa.size (); i < siz; ++i) {
		if (i > 0 && sa[i] - sa[i - 1] > 1) {
			seq.emplace_back (make_pair (sa[i - 1] + 1, sa[i] - 1));
		}
		seq.emplace_back (make_pair (sa[i], sa[i]));
	}
	int old_n = n;
	n = (int) seq.size () - 1;
	SegmentTree Tree (n, seq);
	Tree.Build (1, 1, n);
	Tree.Modify (1, 1, n, 1, old_n, 1);
	for (auto &[l, r, k] : ask) {
		if (k == 1) {
			Tree.Modify (1, 1, n, l, r, 0); 
		}
		else {
			Tree.Modify (1, 1, n, l, r, 1); 
		}
		write (Tree.sum[1]);
		puts ("");
	}
}

signed main () {
	charming ();
	return 0;
}