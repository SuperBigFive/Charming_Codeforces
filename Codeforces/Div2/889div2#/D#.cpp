#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {} ());

int n, ans;
int a[N], pre[N];
bitset <N> bst;

void init () {ans = 0;}

void charming () {
	init ();
	cin >> n;
	bst[1] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
		if (bst.test (i)) ans = max (ans, pre[i] - (i - 1));
		bst |= (bst << a[i]);
		bst.reset (i);
	}
	for (int i = n + 1; i <= 2 * n; ++i) if (bst.test (i)) {
		ans = max (ans, pre[n] - (i - 1));
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}