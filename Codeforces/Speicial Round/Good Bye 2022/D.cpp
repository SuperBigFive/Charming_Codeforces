#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1), b (n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	vector <set <pair <int, int> > > cnt (n + 1);
	for (int i = 1; i <= n; ++i) {
		cnt[a[i]].insert (make_pair (i, 0));
		cnt[b[i]].insert (make_pair (i, 1));
	}
	queue <int> q;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i].size () == 1) {
			q.push (i);
		}
		if (cnt[i].size () <= 0) {
			cout << 0 << endl;
			return;
		}
	}
	vector <int> stay (n + 1, 1);
	while (!q.empty ()) {
		int val = q.front ();
		q.pop ();
		auto [id, st] = *cnt[val].begin ();
		if ((st == 0 && cnt[b[id]].size () <= 1)
		|| (st == 1 && cnt[a[id]].size () <= 1)) {
			cout << 0 << endl;
			return;
		}
		cnt[val].erase (*cnt[val].find (make_pair (id, st)));
		if (st == 0) {
			cnt[b[id]].erase (*cnt[b[id]].find (make_pair (id, st ^ 1)));
			if (cnt[b[id]].size () <= 1) q.push (b[id]);
		}
		else {
			cnt[a[id]].erase (*cnt[a[id]].find (make_pair (id, st ^ 1)));
			if (cnt[a[id]].size () <= 1) q.push (a[id]);
		}
		stay[id] = 0;
	}
	int coef = 1, res = 1;
	vector <int> vis (n + 1), ok (n + 1);
	map <int, int> ncnt;
	for (int i = 1; i <= n; ++i) {
		if (!stay[i]) continue;
		else if (a[i] == b[i] && !vis[a[i]]) {
			coef = (coef * n) % mod;
			vis[a[i]] = true;
			stay[i] = 0;
		}
		else if (a[i] == b[i] && vis[a[i]]) {
			cout << 0 << endl;
			return;
		}
		else ok[a[i]] = true, ok[b[i]] = true;
		++ncnt[a[i]], ++ncnt[b[i]];
	}
	for (int i = 1; i <= n; ++i) {
		if (ncnt[i] != 0 && ncnt[i] != 2) {
			cout << 0 << endl;
			return;
		}
	}
	vector <int> pre (n + 1);
	auto find = [&] (auto && me, int x) -> int {
		if (x == pre[x]) return x;
		return pre[x] = me (me, pre[x]);
	};
	for (int i = 1; i <= n; ++i) pre[i] = i;
	for (int i = 1; i <= n; ++i) {
		if (!stay[i]) continue;
		int fu = find (find, a[i]);
		int fv = find (find, b[i]);
		if (fu == fv) continue;
		pre[fu] =  fv;
	}
	for (int i = 1; i <= n; ++i) {
		if (ok[i] && i == pre[i])
		res = (res * 2) % mod;
	}
	res = (res * coef) % mod;
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}