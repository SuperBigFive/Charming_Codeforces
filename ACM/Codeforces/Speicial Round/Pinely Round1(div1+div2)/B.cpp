#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n), vis (n + 1);
	int cnt = 0;
	for (auto &it : a) {
		cin >> it;
		if (!vis[it]) ++cnt;
		vis[it] = true;
	}
	if (cnt >= 3) cout << n << endl;
	else cout << (n / 2) + 1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}