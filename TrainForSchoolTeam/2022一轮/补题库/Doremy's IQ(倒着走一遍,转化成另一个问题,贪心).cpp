#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;
ll dif[maxn], res[maxn];

void init () {
	for (int i = 1; i <= n; ++i) res[i] = 0;
}

void charming () {
	init ();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> dif[i];
	}
	int cur_q = 0;
	for (int i = n; i >= 1 && cur_q <= q; --i) {
		if (dif[i] <= cur_q) res[i] = 1;
		else if (cur_q < q) ++cur_q, res[i] = 1;
		else res[i] = 0;
	}
	for (int i = 1; i <= n; ++i) cout << res[i];
	cout << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}