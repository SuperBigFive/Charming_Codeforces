#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e3 + 5;

int t, n;
int a[maxn], b[maxn], now[maxn], aim[maxn];
vector <pair <int, int> > ans;

void init () {ans.clear ();}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		now[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		aim[b[i]] = i;
	}
	for (int i = n; i >= 1; --i) {
		while (now[i] > aim[i]) {
			int nxt = now[i] - 1;
			while (nxt >= 1 && (a[nxt] < i || aim[a[nxt]] < now[i])) --nxt;
			if (nxt < 1) break;
			ans.emplace_back (nxt, now[i]);
			a[now[i]] = a[nxt];
			now[a[nxt]] = now[i];
			now[i] = nxt;
			a[nxt] = i;
		}
		if (now[i] > aim[i]) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 1; i <= n; ++i) if (a[i] != b[i]) {
		cout << -1 << endl;
		return;
	}
	cout << ans.size () << endl;
	for (auto [x, y] : ans) cout << x << " " << y << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}