#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int ans[maxn];

void init () {}

void charming () {
	for (int i = 1; i < maxn; ++i) {
		for (int j = 2 * i; j < maxn; j += i)
		ans[j] += i;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		if (ans[n] > n) cout << "abundant" << endl;
		else if (ans[n] < n) cout << "deficient" << endl;
		else cout << "perfect" << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}