#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n, sum;
int brick[105];


void init () {

}

bool check () {
	for (int i = 1; i <= n; ++i) {
		if (brick[i]) return true;
	}
	return false;
}

void get_brick () {
	for (int i = 1; i <= n; ++i) {
		brick[i] = n - i + 1;
	}
}

void charming () {
	init ();
	cin >> n;
	sum = 0;
	get_brick ();
	for (int i = 1; i <= n; ++i) sum += (n - i + 1) * i;
	int l = (ll) sqrt ((double) sum), h, c;
	for (int i = l; i <= sum; ++i) {
		h = sum / i;
		get_brick ();
		if (i * h != sum) continue;
		vector <pii > ans_1, ans_2;
		for (int j = 1; j <= h; ++j) {
			int res = i;
			for (int k = n; k >= 1 && res; --k) {
				if (!brick[k] || k > res) continue;
				while (brick[k] && k <= res) {
					--brick[k];
					ans_1.pb ({i - res, j - 1});
					ans_2.pb ({i - res + k, j});
					res -= k;
				}
			}
		}
		if (!check ()) {
			c = 2 * (i + h);
			cout << c << endl;
			for (int i = 0; i < ans_1.size (); ++i) {
				cout << ans_1[i].fir << ' ' << ans_1[i].se << ' ' << ans_2[i].fir << ' ' << ans_2[i].se << endl;
			}
			break;
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}