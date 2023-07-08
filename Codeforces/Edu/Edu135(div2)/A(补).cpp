#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int cnt[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	int mx = 0, id;
	for (int i = 1; i <= n; ++i) {
		cin >> cnt[i];
		if (cnt[i] > mx) {
			mx = max (mx, cnt[i]);
			id = i;
		}
	}
	cout << id << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}