#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
int fa[maxn], h[maxn];

void init () {}

bool check (int mx) {
	int cnt = 0;
	fill (h + 1, h + 1 + n, 0);
	for (int i = n; i >= 2; --i) {
		if (h[i] == mx - 1 && fa[i] != 1) {
			++cnt;
		}
		else {
			h[fa[i]] = max (h[fa[i]], h[i] + 1);
		}
	}
	return cnt <= k;
}

void charming () {
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) cin >> fa[i];
	int l = 1, r = n - 1, res = n - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) r = mid - 1, res = mid;
		else l = mid + 1;
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