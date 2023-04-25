#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <vector <int> > mp (n + 5, vector <int> (n + 5));
	int cost = 0;
	for (int i = 1; i <= n; ++i) 
	for (int j = 1; j <= n; ++j)
	cin >> mp[i][j];
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j) {
		if ((i - 1) * n + j > n * n / 2) break;
		if (mp[i][j] != mp[n - i + 1][n - j + 1]) ++cost;
	}
	cout << (cost <= k && ((k - cost) % 2 == 0 || (n & 1)) ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}