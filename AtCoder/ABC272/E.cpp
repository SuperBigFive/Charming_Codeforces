#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int a[maxn];
vector <int> occur[maxn];

void init () {

}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int turns = 1;
		a[i] += i;
		if (a[i] < 0) {
			turns += (-a[i] - 1) / i + 1;
			a[i] += (turns - 1) * i;
		}
		while (a[i] < n && turns <= m) {
			occur[turns].emplace_back (a[i]);
			++turns;
			a[i] += i;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (!occur[i].size ()) {
			cout << 0 << endl;
			continue;
		}
		sort (occur[i].begin (), occur[i].end ());
		int len = unique (occur[i].begin (), occur[i].end ()) - occur[i].begin ();
		int ans = 0;
		for (int j = 0; j < len; ++j) {
			if (occur[i][j] != j) break;
			++ans;
		}
		cout << ans << endl;
	}
}

signed main () {
	charming ();
	return 0;
}