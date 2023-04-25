#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n, m, k;
int rev[maxn];

void init () {

}

void charming () {
	init ();
	cin >> n >> m >> k;
	for (int i = 1, b; i <= k; ++i) {
		cin >> b;
		rev[b] = i;
	}
	for (int i = k, remain = n * m - 2, mx = 0; i >= 1; --i) {
		if (rev[i] > mx) {
			remain -= rev[i] - mx;
			mx = rev[i];
		}
		if (remain <= 0) {
			cout << "TIDAK" << endl;
			return;
		}
		++remain;
	}
	cout << "YA" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}