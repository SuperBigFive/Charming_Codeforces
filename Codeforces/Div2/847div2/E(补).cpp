#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k, x;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> x;
	vector <int> vis (n + 5);
	int Xorsum = 0;
	for (int i = 1; i <= n; ++i) Xorsum ^= i;
	if (Xorsum != (k & 1) * x) return void (cout << "NO" << endl);
	vector <vector <int> > ans;
	if (k == 1) {
		cout << "YES" << endl;
		cout << n << " ";
		for (int i = 1; i <= n; ++i) cout << i << " ";
		cout << endl;
		return;
	}
	if (x <= n) {
		ans.emplace_back (vector <int> (1, x));
		vis[x] = true;
	}
	for (int i = 1; i <= n && ans.size () < k - 1; ++i) {
		if (vis[i] || (x ^ i) > n) continue;
		vector <int> nxt (2);
		nxt[0] = i, nxt[1] = x ^ i;
		vis[i] = vis[x ^ i] = true;
		ans.emplace_back (nxt);
	}
	if (ans.size () == k - 1) {
		vector <int> nxt;
		for (int i = 1; i <= n; ++i) if (!vis[i]) nxt.emplace_back (i);
		if (!nxt.size () || ans.size () < k - 1) return void (cout << "NO" << endl);
		ans.emplace_back (nxt);
	}
	if (ans.size () != k) return void (cout << "NO" << endl);
	cout << "YES" << endl;
	for (int i = 0 ; i < ans.size (); ++i) {
		cout << ans[i].size () << " ";
		for (auto &it : ans[i]) cout << it << " ";
		cout << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}