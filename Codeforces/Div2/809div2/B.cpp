#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int color[maxn], last[maxn], cnt[maxn], res[maxn];

void init () {
	for (int i = 1; i <= n; ++i) cnt[i] = last[i] = res[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> color[i];
	int now = 1;
	for (int i = 1; i <= n; ++i) {
		if (!last[color[i]]) {
			last[color[i]] = i;
			res[color[i]] = 1;
			cnt[color[i]] = 1;
			continue;
		}
		if ((i - last[color[i]]) & 1) ++cnt[color[i]], last[color[i]] = i;
		else {
			res[color[i]] = max (res[color[i]], cnt[color[i]]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		res[i] = max (res[i], cnt[i]);
		cout << res[i] << ' ';
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}