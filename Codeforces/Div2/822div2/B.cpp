#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	cout << 1 << endl;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (j == 1 || j == i) cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)	charming ();
	return 0;
}