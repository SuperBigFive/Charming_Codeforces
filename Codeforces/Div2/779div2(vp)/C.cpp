#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int c[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	bool ok = true;
	int cnt1 = c[1] == 1 ? 1 : 0, en = n - c[1] + 2;
	for (int i = 2; i <= n; ++i) {
		if (c[i] - c[i - 1] == 1) continue;
		if (c[i] - c[i - 1] > 1) {
			ok = false;
			break;
		}
		if (c[i] == 1) {
			++cnt1;
			if (i > en) {
				ok = false;
				break;
			}
		}
		en = min (en, (n - c[i]) + i + 1);
	}
	if (cnt1 > 1 || !cnt1 || c[1] - c[n] > 1) ok = false;
	cout << (ok ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}