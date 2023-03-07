#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
map <int, int> mp;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, val; i <= (n << 1); ++i) {
		cin >> val;
		++mp[val % m];
	}
	if (m & 1) {
		for (auto it : mp) {
			if (it.second & 1) {
				cout << "Alice" << endl;
				return;
			}
		}
		cout << "Bob" << endl;
		return;
	}
	bool ok1 = true, ok2 = false;
	for (auto it : mp) {
		int x = it.first, y = (x + m / 2) % m;
		int a = it.second, b = mp[y];
		if (abs (a - b) & 1) ok1 = false;
		ok2 ^= (min (a, b) & 1);
		mp[x] = mp[y] = 0;
	}
	if (ok1 && !ok2) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}