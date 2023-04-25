#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], sum[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	int res = 0;
	vector <int> pos;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		if (!a[i]) pos.emplace_back (i);
	}
	pos.emplace_back (n + 1);
	for (int i = 1; i < pos[0]; ++i) if (!sum[i]) ++res;
	for (int i = 0; i < pos.size () - 1; ++i) {
		map <int, int> cnt;
		int mx = 0;
		for (int j = pos[i]; j < pos[i + 1]; ++j) {
			mx = max (mx, ++cnt[sum[j]]);
		}
		res += mx;
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}