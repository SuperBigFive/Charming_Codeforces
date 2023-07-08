#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], b[maxn];
bool ok[maxn];

void init () {}

void charming () {
	cin >> n;
	fill (ok + 1, ok + 1 + n, false);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		if (b[i] < a[i]) {
			cout << "NO" << endl;
			return;
		}
		if (a[i] == b[i]) ok[i] = true;
	}
	b[n + 1] = b[1];
	for (int i = 1; i <= n; ++i) {
		if (!ok[i] && b[i] - b[i + 1] > 1) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}