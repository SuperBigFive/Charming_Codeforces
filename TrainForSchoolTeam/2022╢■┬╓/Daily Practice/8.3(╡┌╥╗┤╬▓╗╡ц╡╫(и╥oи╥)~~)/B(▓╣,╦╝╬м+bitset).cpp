#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 4e2 + 5;
const int maxm = 3e5 + 5;

int n, m;
int x[maxm], y[maxm];
bool ok[maxn];
bitset <maxn> kil[maxn];

void init () {
	memset (ok, true, sizeof ok);
	for (int i = 1; i <= 400; ++i) {
		kil[i][i] = 1;
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			if (kil[i][x[j]] && kil[i][y[j]]) {
				ok[i] = false;
				break;
			}
			else if (kil[i][x[j]]) kil[i][y[j]] = true;
			else if (kil[i][y[j]]) kil[i][x[j]] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!ok[i]) continue;
		for (int j = i + 1; j <= n; ++j) {
			if (ok[j] && ((kil[i] & kil[j]).none ())) ++ans;
		}
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}