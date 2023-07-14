#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1000;
const int len = 2000;

int n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5), b, tmp;
	for (int i = 1; i <= n; ++i) cin >> a[i], b.emplace_back (a[i]);
	vector <array <int, 4> > query;
	vector <array <int, 4> > change;
	change.emplace_back ((array <int, 4>) {0, 0, 0, 0});
	tmp = a;
	for (int i = 0, type, l, r, p, x, time = 0, cnt = 0; i < q; ++i) {
		cin >> type;
		if (type == 1) {
			cin >> l >> r;
			query.emplace_back ((array <int, 4>) {l, r, time, cnt++});
		} else {
			cin >> p >> x;
			change.emplace_back ((array <int, 4>) {p, tmp[p], x, ++time});
			b.emplace_back (x);
			tmp[p] = x;
		}
	}
	
	sort (b.begin (), b.end ());
	b.resize (unique (b.begin (), b.end ()) - b.begin ());
	for (int i = 1; i <= n; ++i) a[i] = lower_bound (b.begin (), b.end (), a[i]) - b.begin () + 1;
	for (auto &[p, oldx, nx, time] : change) {
		oldx = lower_bound (b.begin (), b.end (), oldx) - b.begin () + 1;
		nx = lower_bound (b.begin (), b.end (), nx) - b.begin () + 1;
	}

	vector <int> ans ((int) query.size ());
	sort (query.begin (), query.end (), [] (array <int, 4> &x,
	array <int, 4> &y) {
		if (x[0] / len != y[0] / len) return x[0] / len < y[0] / len;
		else if (x[1] / len != y[1] / len) return x[1] / len < y[1] / len;
		else return x[2] < y[2];
	});
	vector <int> c (n << 2), cnt (n << 2);
	cnt[0] = N;
	
	auto Move = [&] (int p, int sign) -> void {
		--cnt[c[a[p]]];
		c[a[p]] += sign;
		++cnt[c[a[p]]];
	};
	
	auto Modify = [&] (int tid, int sign, int l, int r) -> void {
		auto [p, oldx, nx, t] = change[tid];
		if (sign == -1) swap (oldx, nx);
		a[p] = nx;
		if (p < l || p > r) return;
		--cnt[c[oldx]];
		--c[oldx];
		++cnt[c[oldx]];
		
		--cnt[c[nx]];
		++c[nx];
		++cnt[c[nx]];
		a[p] = nx;
	};
	
	q = query.size ();
	change.emplace_back ((array <int, 4>) {N, N, N, N});
	for (int i = 0, l = 1, r = 0, tid = 1; i < q; ++i) {
		auto [ql, qr, qt, qid] = query[i];
		while (r < qr) Move (++r, 1);
		while (l > ql) Move (--l, 1);
		while (l < ql) Move (l++, -1);
		while (r > qr) Move (r--, -1);
		while (change[tid][3] <= qt) Modify (tid++, 1, l, r);
		while (change[tid - 1][3] > qt) Modify (--tid, -1, l, r);
		for (int i = 1; i <= M; ++i) {
			if (cnt[i] == 0) {ans[qid] = i; break;}
		}
		if (ans[qid] == 0) ans[qid] = n + 1;
	}
	for (int i : ans) cout << i << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}