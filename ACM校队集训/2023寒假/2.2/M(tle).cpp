#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e6 + 5;
int read () {
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

int rt;
ll n, tot, mn1, mx1, mn2, mx2;
ll node[N << 4], lazy1[N << 4];
int num[N << 4], lazy2[N << 4];
int ls[N << 4], rs[N << 4];

void init () {}

void pushdown (int cnt, int l, int r) {
	if (l == r) return;
	if (lazy1[cnt]) {
		if (!ls[cnt]) ls[cnt] = ++tot;
		if (!rs[cnt]) rs[cnt] = ++tot;
		node[ls[cnt]] += lazy1[cnt];
		node[rs[cnt]] += lazy1[cnt];
		lazy1[ls[cnt]] += lazy1[cnt];
		lazy1[rs[cnt]] += lazy1[cnt];
		lazy1[cnt] = 0;
	}
	if (lazy2[cnt]) {
		if (!ls[cnt]) ls[cnt] = ++tot;
		if (!rs[cnt]) rs[cnt] = ++tot;
		num[ls[cnt]] += lazy2[cnt];
		num[rs[cnt]] += lazy2[cnt];
		lazy2[ls[cnt]] += lazy2[cnt];
		lazy2[rs[cnt]] += lazy2[cnt];
		lazy2[cnt] = 0;
	}
}

void modify (int &cnt, int l, int r, int ql, int qr, int k1, int k2) {
	if (!cnt) cnt = ++tot;
	if (l >= ql && r <= qr) {
		node[cnt] += k1, num[cnt] += k2;
		lazy1[cnt] += k1, lazy2[cnt] += k2;
		return;
	}
	pushdown (cnt, l, r);
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k1, k2);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k1, k2);
}
	
pair <ll, ll> query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return make_pair (node[cnt], num[cnt]);
	pushdown (cnt, l, r);
	int mid = l + r >> 1;
	if (ql <= mid && ls[cnt]) return query (ls[cnt], l, mid, ql, qr);
	if (qr > mid && rs[cnt]) return query (rs[cnt], mid + 1, r, ql, qr);
	return make_pair (0, 0);
}

ll solve (vector <array <int, 2> > &p, vector <array <int, 2> > &q, int ok) {
	rt = ++tot;
	ll res = 0;
	for (int i = n - 1; i >= 1; --i) {
		modify (rt, mn1, mx1, p[i + 1][0] - q[i + 1][0], mx1, p[i + 1][0], 1);
		auto [sum, cnt] = query (rt, mn1, mx1, p[i][0] - q[i][0] - ok, p[i][0] - q[i][0] - ok);
		res += sum - cnt * p[i][0];
	}
	
	rt = ++tot;
	for (int i = n - 1; i >= 1; --i) {
		modify (rt, mn2, mx2, p[i + 1][0] + q[i + 1][0], mx2, p[i + 1][0], 1);
		auto [sum, cnt] = query (rt, mn2, mx2, p[i][0] + q[i][0] - ok, p[i][0] + q[i][0] - ok);
		res += sum - cnt * p[i][0];
	}
	
	return res;
}

void charming () {
	init ();
	n = read ();
	vector <array <int, 2> > p (n + 5), q (n + 5), a (n + 5), b;
	for (int i = 1; i <= n; ++i) p[i][0] = read (), p[i][1] = i;
	for (int i = 1; i <= n; ++i) q[i][0] = read (), q[i][1] = i;
	b = p, a = q;
	sort (p.begin () + 1, p.begin () + 1 + n, [] (array <int, 2> &x,
	array <int, 2> &y) {return x[0] < y[0];});
	for (int i = 1; i <= n; ++i) q[i] = a[p[i][1]];
	ll res = 0;
	mn1 = -N, mn2 = 1, mx1 = N, mx2 = N << 1;
	res += solve (p, q, 0);
	sort (q.begin () + 1, q.begin () + 1 + n, [] (array <int, 2> &x,
	array <int, 2> &y) {return x[0] < y[0];});
	for (int i = 1; i <= n; ++i) p[i] = b[q[i][1]];
	res += solve (q, p, 1);
	cout << res * 2 << endl;
}

signed main () {
	charming ();
	return 0;
}