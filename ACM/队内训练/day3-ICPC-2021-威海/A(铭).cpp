#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n;
int in[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	bool ok = true;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		++in[u], ++in[v];
		if (in[u] > 3 || in[v] > 3) ok = false;
	}
	if (!ok) {
		cout << 0 << endl;
		return;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (in[i] < 3) ++res;
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;	
}