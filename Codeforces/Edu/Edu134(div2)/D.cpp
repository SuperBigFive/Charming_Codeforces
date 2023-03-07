#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 4e6 + 5;

int t, n, tot;
int a[maxn], b[maxn];
set <int> set_a[maxm], set_b[maxm];

void init () {
	for (int i = 1; i <= tot; ++i) {
		set_a[i].clear (), set_b[i].clear ();
	}
	tot = 1;
}

bool check (int d) {
	--d;
	for (int i = 1; i <= tot; ++i) {
		int cnt_a = 0, cnt_b = 0;
		for (auto it : set_a[i]) {
			if ((a[it] >> d) % 2) ++cnt_a;
		}
		for (auto it : set_b[i]) {
			if ((b[it] >> d) % 2) ++cnt_b;
		}
		if (cnt_a + cnt_b != set_a[i].size ()) return false;
	}
	return true;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		set_a[1].insert (i);
	}
	for (int i = 1, tmp, tot; i <= n; ++i) {
		cin >> b[i];
		set_b[1].insert (i);
	}
	int res = 0;
	for (int i = 30; i >= 1; --i) {
		if (!check (i)) continue;
		res += (1 << (i - 1));
		int old_tot = tot;
		for (int j = 1; j <= old_tot; ++j) {
			if (set_a[j].size () == 1) continue;
			int cnt = 0;
			for (auto it : set_a[j]) if ((a[it] >> (i - 1)) % 2) ++cnt;
			if (cnt == 0 || cnt == set_a[j].size ()) continue;
			++tot;
			for (auto it : set_a[j]) if ((a[it] >> (i - 1)) % 2) {
				 set_a[tot].insert (it);
			}
			for (auto it : set_a[tot]) {
				set_a[j].erase (it);
			}
			for (auto it : set_b[j]) if (!((b[it] >> (i - 1)) % 2)) {
				set_b[tot].insert (it);
			}
			for (auto it : set_b[tot]) {
				set_b[j].erase (it);
			}
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}