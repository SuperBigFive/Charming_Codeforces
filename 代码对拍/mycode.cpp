#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, rt, tot;
int node[N << 3], ls[N << 3], rs[N << 3];

void init () {
	for (int i = 0; i <= tot; ++i) {
		node[i] = 0, ls[i] = rs[i] = 0;
	}
	rt = tot = 1;
}

void modify (int &cnt, int l, int r, int p, int k) {
	if (!cnt) cnt = ++tot;
	if (l == r) {
		node[cnt] = max (node[cnt], k);
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) modify (ls[cnt], l, mid, p, k);
	if (p > mid) modify (rs[cnt], mid + 1, r, p, k);
	node[cnt] = max (node[ls[cnt]], node[rs[cnt]]);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1;
	int mx = -1;
	if (ql <= mid) mx = max (mx, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) mx = max (mx, query (rs[cnt], mid + 1, r, ql, qr));
	return mx;
}


vector <int> get_gain (vector <int> &a) {
	init ();
	vector <int> gain (n + 5);
	for (int i = 1, b, id; i <= n; ++i) {
		b = a[i] - i;
		id = query (rt, -N, N, -N, b);
		if (id <= 0) {
			if (a[i] < i) gain[i] = a[i] * (a[i] + 1) / 2;
			else gain[i] = (a[i] + (a[i] - i + 1)) * i / 2;
		} else gain[i] = (a[i] + (a[i] - (i - id - 1))) * (i - id) / 2 + gain[id];
		modify (rt, -N, N, b, i);
	}
	return gain;
}

void charming () {
	init ();
	cin >> n;
	vector <int> h (n + 5), nh (n + 5);
	ll res = LLONG_MAX, sum = 0;
	for (int i = 1; i <= n; ++i) cin >> h[i], sum += h[i];
	vector <int> gain_left = get_gain (h);
	nh = h, reverse (nh.begin () + 1, nh.begin () + 1 + n);
	vector <int> gain_right = get_gain (nh);
	reverse (gain_right.begin () + 1, gain_right.begin () + 1 + n);
	for (int i = 1; i <= n; ++i) res = min (res, 
	sum + 2 * h[i] - gain_left[i] - gain_right[i]);
	cout << min (sum, res) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}