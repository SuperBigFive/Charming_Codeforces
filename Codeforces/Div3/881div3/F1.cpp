#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> mx_seg (n + 5), mn_seg (n + 5);
	vector <int> mx_suf (n + 5), mn_suf (n + 5);
	mx_seg[1] = 1, mx_suf[1] = 1;
	char op;
	for (int i = 0, u, v, x, k, cnt = 1; i < n; ++i) {
		cin >> op;
		if (op == '+') {
			cin >> v >> x;
			++cnt;
			mx_suf[cnt] = max ({0ll, x, x + mx_suf[v]});
			mn_suf[cnt] = min ({0ll, x, x + mn_suf[v]});
			mx_seg[cnt] = max (mx_seg[v], mx_suf[cnt]);
			mn_seg[cnt] = min (mn_seg[v], mn_suf[cnt]);
		}
		else {
			cin >> u >> v >> k;
			if (k >= mn_seg[v] && k <= mx_seg[v]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}