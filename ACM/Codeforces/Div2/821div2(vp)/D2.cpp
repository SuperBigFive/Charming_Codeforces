#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e3 + 5;

int t, n, x, y;
int dp[maxn][maxn];
string a, b;
vector <int> pos;

void init () {
	pos.clear ();
	for (int i = 0; i < n + 5; ++i) {
		fill (dp[i], dp[i] + n + 5, 0);
	}
}

void charming () {
	init ();	
	cin >> n >> x >> y;
	cin >> a >> b;
	a = '#' + a, b = '#' + b;
	for (int i = 1; i <= n; ++i) 
	if (a[i] != b[i]) {
		pos.emplace_back (i);
	}
	if (pos.size () & 1) {
		cout << -1 << endl;
		return;
	}
	if (x >= y) {
		if (pos.size () == 2 && pos[0] + 1 == pos[1]) 
		cout << min (x, y * 2) << endl;
		else cout << (pos.size () / 2) * y << endl;
	}
	else {
		if (!pos.size ()) {
			cout << 0 << endl;
			return;
		}
		for (int len = 2; len <= pos.size (); len += 2) {
			for (int i = 0; i + len - 1 < pos.size (); ++i) {
				if (len == 2) {
					dp[i][i + len - 1] = min ((pos[i + len - 1] - pos[i]) * x, y);
					continue;
				}
				dp[i][i + len - 1] = min ({
				  min ((pos[i + len - 1] - pos[i + len - 2]) * x, y) + dp[i][i + len - 3],
	 			  min ((pos[i + 1] - pos[i]) * x, y) + dp[i + 2][i + len - 1],
				  min ((pos[i + len - 1] - pos[i]) * x, y) + dp[i + 1][i + len - 2]});
			}
		}
		cout << dp[0][pos.size () - 1] << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}