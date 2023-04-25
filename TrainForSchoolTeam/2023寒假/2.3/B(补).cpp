#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, m, a, c, x0, l1, r1, l2, r2, be, len;

void init () {}

void charming (int tot) {
	init ();
	cin >> m >> a >> c >> x0 >> l1 >> r1 >> l2 >> r2;
	if (m == 1) {
		cout << "Case #" << tot << ": " << 0 << endl;
		return;
	}
	vector <int> seqx (1, x0), vis (m);
	vis[x0] = 0;
	for (int i = 1, nx, last = x0; i <= m; ++i) {
		nx = (a * last + c) % m;
		if (vis[nx] || nx == x0) {be = vis[nx]; len = i - be; break;}
		vis[nx] = i;
		last = nx, seqx.emplace_back (nx);
	}
	vector <int> cnt1 (m), cnt2 (m);
	int lim1 = min (r1, be + (r1 - (be - 1)) / len - 1);
	int lim2 = min (r2, be + (r2 - (be - 1)) / len - 1);
	auto get_cnt = [&] (vector <int> &cnt, int l, int r) -> void {
		if (l < be) {
			for (int i = l; i < min (be, r + 1); ++i)
			++cnt[seqx[i]];
			if (r < be) return;
			l = be;
		}
		if (r - l + 1 <= m * 2 + 5) {
			for (int i = l; i <= r; ++i)
			++cnt[seqx[be + (i - ((be - 1)) % len + len - 1) % len]];
			return;
		}
		int id1 = be - 1 + ((l - (be - 1) - 1) / len + 1) * len;
		int id2 = be - 1 + ((r - (be - 1)) / len) * len + 1;
		for (int i = l; i <= id1; ++i)
		++cnt[seqx[be + (i - ((be - 1)) % len + len - 1) % len]];
		for (int i = id2; i <= r; ++i)
		++cnt[seqx[be + (i - ((be - 1)) % len + len - 1) % len]];
		for (int i = be; i < be + len; ++i)
		cnt[seqx[i]] += (id2 - id1 - 1) / len;
	};
	get_cnt (cnt1, l1, r1), get_cnt (cnt2, l2, r2);
	vector <int> pre (m);
	ll res = 0;
	for (int i = 0; i < m; ++i) {
		if (i) pre[i] = pre[i - 1];
		pre[i] += cnt1[i];
		res += i * cnt1[i] * (r2 - l2 + 1);
	}
	for (int i = 0; i < m; ++i) {
		if (!cnt2[i]) continue;
		for (int j = 0, coef; (i + 1) * j - 1 < m; ++j) {
			coef = pre[min (m - 1, (i + 1) * (j + 1) - 1)] 
			- ((i + 1) * j - 1 >= 0 ? pre[min (m - 1, (i + 1) * j - 1)] : 0);
			res -= (i + 1) * j * coef * cnt2[i];
		}
	}
	cout << "Case #" << tot << ": " << res << endl;
}

signed main () {
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}