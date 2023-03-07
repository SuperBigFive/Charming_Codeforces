#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, q, rt, tot;
int node[N  << 2], lazy[N << 2];
int ls[N << 2], rs[N << 2];

void init () {rt = tot = 1;}

void build (int cnt, int l, int r) {
	node[cnt] = lazy[cnt] = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

void pushdown (int cnt, int l, int r) {
	if (l == r || !lazy[cnt]) return;
	node[ls[cnt]] += lazy[cnt];
	node[rs[cnt]] += lazy[cnt];
	lazy[ls[cnt]] += lazy[cnt];
	lazy[rs[cnt]] += lazy[cnt];
	lazy[cnt] = 0;
}

void modify (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {
		++node[cnt], ++lazy[cnt];
		return;
	}
	pushdown (cnt, l, r);
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr);
}

int query (int cnt, int l, int r, int p) {
	if (l == r) return node[cnt];
	pushdown (cnt, l, r);
	int mid = l + r >> 1;
	if (p <= mid) return query (ls[cnt], l, mid, p);
	return query (rs[cnt], mid + 1, r, p);
}

int update (int num) {
	int sum = 0;
	while (num) sum += num % 10, num /= 10;
	return sum;	
}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build (rt, 1, n);
	for (int i = 1, opt, l, r, x; i <= q; ++i) {
		cin >> opt;
		if (opt == 1) cin >> l >> r, modify (rt, 1, n, l, r);
		else {
			cin >> x;
			int times = query (rt, 1, n, x), b = a[x];
			while (times--) {
				if (b < 10) break;
				b = update (b);
			}
			cout << b << endl;
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}