#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n, c;
int a[maxn], vis[maxn], tag[maxn];

void init () {
	fill (vis, vis + c + 5, 0);
	fill (tag, tag + c + 5, 0);
}

void charming () {
	init ();
	cin >> n >> c;
	for (int i = 1; i <= n; ++i) 
	cin >> a[i], vis[a[i]] = true;
	vector <int> b, d;
	for (int i = 1; i <= c; ++i) {
		if (vis[i]) b.emplace_back (i);
		else d.emplace_back (i);
	}
	for (auto i : b) {
		for (auto j : d) {
			int be = i * j, en = i * (j + 1);
			if (be > c) break;
			++tag[be];
			if (en > c) break;
			--tag[en];
		}
	}
	int remain = 0;
	for (int i = 1; i <= c; ++i) {
		remain += tag[i];
		if (remain > 0 && vis[i]) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}