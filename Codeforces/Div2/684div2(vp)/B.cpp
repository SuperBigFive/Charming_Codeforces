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
	vector <int> a (n * k);
	for (auto &it : a) cin >> it;
	int cnt = 0, res = 0;
	sort (a.begin (), a.end (), greater <int> ());
	for (int i = n / 2; i < n * k && cnt < k; i += n / 2 + 1) {
		res += a[i], ++cnt;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}