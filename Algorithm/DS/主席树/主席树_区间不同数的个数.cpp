#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e6 + 5;
inline int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar ();
	}
	int k = ch - '0';
	while (ch = getchar (), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch - '0');
	}
	if (flag) return k;
	return -k;
}
inline void write (int x) {
	if (!x) putchar ('0');
	char F[200];
	int tmp = x > 0 ? x : -x;
	if (x < 0) putchar ('-');
	int cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
		tmp /= 10;
  }
	while (cnt > 0) putchar (F[--cnt]);
	puts ("");
}

int n, q, tot;
int a[N], last[N];
int root[N], node[N << 5], ls[N << 5], rs[N << 5];

void init () {}

int modify (int pre, int l, int r, int p, int k) {
	int cur = ++tot;
	ls[cur] = ls[pre], rs[cur] = rs[pre], node[cur] = node[pre] + k;
	if (l == r) return cur;
	int mid = l + r >> 1;
	if (p <= mid) ls[cur] = modify (ls[pre], l, mid, p, k);
	else rs[cur] = modify (rs[pre], mid + 1, r, p, k);
	return cur;
}

int query (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt];
	int mid = l + r >> 1, res = 0;
	if (ql <= mid) res += query (ls[rt], l, mid, ql, qr);
	if (qr > mid) res += query (rs[rt], mid + 1, r, ql, qr);
	return res;
}

void charming () {
	init ();
	n = read ();
	for (int i = 1; i <= n; ++i) {
		a[i] = read ();
		if (last[a[i]]) {
			 root[i] = modify (root[i - 1], 1, n, last[a[i]], -1);
			 root[i] = modify (root[i], 1, n, i, 1);
		} else root[i] = modify (root[i - 1], 1, n, i, 1);
		last[a[i]] = i;
	}
	q = read ();
	for (int i = 1, l, r; i <= q; ++i) {
		l = read (), r = read ();
		write (query (root[r], 1, n, l, r));
	}
}

signed main () {
	charming ();
	return 0;
}