#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int d[maxn];

void init () {}

void charming () {
	cin >> n;
	bool ok = true;
	vector <int> ans;
	ans.emplace_back (0);
	for (int i = 1, now = 0; i <= n; ++i) {
		cin >> d[i];
		if (!d[i]) ans.emplace_back (now);
		else if (now + d[i] >= 0 && now - d[i] >= 0) ok = false;
		else if (now + d[i] >= 0) now += d[i], ans.emplace_back (now);
		else now -= d[i], ans.emplace_back (now);
	}
	if (!ok) cout << -1 << endl;
	else {
		for (int i = 1; i <= n; ++i)
		cout << ans[i] << " \n"[i == n];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}