#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> pre (n + 5), nxt (n + 5);
	string s;
	cin >> s, s = '#' + s;
	pre[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') pre[i] = i;
		else if (s[i - 1] == '1') pre[i] = pre[i - 1];
		else pre[i] = i - 1;
	}
	nxt[n + 1] = n + 1;
	for (int i = n; i >= 1; --i) {
		if (s[i] == '1') nxt[i] = i;
		else if (s[i + 1] == '0') nxt[i] = nxt[i + 1];
		else nxt[i] = i + 1;
	}
	int ok = 0;
	vector <pair <int, int> > b;
	for (int i = 1, l, r; i <= m; ++i) {
		cin >> l >> r;
		if (nxt[l] <= pre[r]) b.emplace_back (make_pair (nxt[l], pre[r]));
		else ok = 1;
	}
	sort (b.begin (), b.end ());
	cout << (unique (b.begin (), b.end ()) - b.begin ()) + ok<< endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}