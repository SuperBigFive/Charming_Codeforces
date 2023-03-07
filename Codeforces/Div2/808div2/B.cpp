#include <bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int t, n, l, r;
ll res[maxn];

void charming () {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; ++i) {
		ll k = (l - 1) / i + 1;
		if (k * i > r) {
			cout << "NO" << endl;
			return;
		}
		res[i] = k * i;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}