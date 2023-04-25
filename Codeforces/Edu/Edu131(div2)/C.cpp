#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 1e6 + 5;

int t, n, m;
ll match[maxn];
ll cnt[maxn];

void init () {
	for (int i = 1; i <= n; ++i) cnt[i] = 0;
}

bool ok (ll times) {
	ll all = times * n;
	/*for (int i = 1; i <= n; ++i) {
		tmp_cnt[i] = cnt[i];
	} */
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (times >= cnt[i]) {
			all -= cnt[i];
			if ((times - cnt[i]) & 1) --all;
		}
		else all -= times, res += cnt[i] - times;
	}
	if (all >= res * 2) return true;
	return false;
}

void charming () {
	init (); 
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> match[i];
		++cnt[match[i]];
	}
	//sort (match + 1, match + 1 + m);
	int l = 0, r = m * 2;
	while (l < r) {
		int mid = (l + r) / 2;
		if (ok (mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
