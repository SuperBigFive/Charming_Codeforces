#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, k;
int f[N];

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	--k;
	if (k > 31) return void (cout << 0 << endl);
	int a1 = f[k], a0 = f[k - 1];
	int ans = 0;
	for (int i = 0, remain; (a0 + a1) * i <= n; ++i) {
		remain = n - a0 * i;
		if ((remain % a1 == 0) && (remain / a1 >= i)) ++ans;
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	f[0] = 0, f[1] = 1;
	for (int i = 2; i <= 31; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cin >> t;
	while (t--) charming ();
	return 0;
}