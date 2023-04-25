#pragma GCC optimize ("-Ofast", "-funroll-all-loops")
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e4 + 5;

int t, n, m, q;
bitset <maxn> a, b, bx, ans;

void init () {
	a.reset (), b.reset (), bx.reset (), ans.reset ();
}

void get_ans () {
	for (int i = maxn - 1; i >= 0; --i) {
		ans.set (i, ((a >> i) & bx).count () & 1);
		if (!b.test (i)) continue;
		for (int j = 0; j < maxn; j += i) bx.flip (j);
	}
}

void charming () {
	init ();
	scanf ("%d%d%d", &n, &m, &q);
	int num;
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &num);
		a.set (num);
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%d", &num);
		b.set (num);
	}
	get_ans ();
	for (int i = 1; i <= q; ++i) {
		scanf ("%d", &num);
		if (ans.test (num)) puts ("1");
		else puts ("0");
	}
}

signed main () {
	scanf ("%d", &t);
	while (t--) charming ();
	return 0;
}