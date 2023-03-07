#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], pos[maxn];
map <int, int> cop[maxn];

void init () {
	for (int i = 1; i <= 1000; ++i) pos[i] = -1;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	int res = -1;
	for (int i = 1; i <= 1000; ++i) {
		if (pos[i] == -1) continue;
		for (auto it : cop[i]) {
			if (pos[i] != -1 && pos[it.first] != -1) {
				res = max (res, pos[i] + pos[it.first]);
			}
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (__gcd (i, j) == 1) cop[i][j] = 1;
		}
	}
	cin >> t;
	while (t--) charming ();
	return 0;
}