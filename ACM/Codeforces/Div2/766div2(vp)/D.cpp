#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n;

void init () {}


void charming () {
	init ();
	cin >> n;
	vector <int> vis (N);
	for (int i = 1, a; i <= n; ++i) {
		cin >> a, vis[a] = true;
	}
	int res = 0;
	for (int i = N - 1; i >= 1; --i) {
		if (vis[i]) continue;
		vector <int> prim;
		for (int j = i; j < N; j += i) {
			if (vis[j]) prim.emplace_back (j / i);
		}
		if (prim.size () < 2) continue;
		int p = prim[0];
		for (int j = 1; j < prim.size () && p != 1; ++j)
		p = __gcd (p, prim[j]);
		if (p > 1) continue;
		vis[i] = true;
		++res;
	}
	cout << res << endl;
}

signed main () {
	ios_base :: sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}