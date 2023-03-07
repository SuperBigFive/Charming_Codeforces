#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e3 + 5;
const int max_val = 1e6;

ll k;
int val[maxn];

void charming () {
	cin >> k;
	val[1] = -1;
	val[2] = 1;
	int tot = 2;
	while (k + tot > max_val) {
		val[++tot] = max_val;
		k -= max_val;
	}
	++tot;
	val[tot] = k + tot - 1;
	cout << tot << endl;
	for (int i = 1; i <= tot; ++i) cout << val[i] << ' ';
}

signed main () {
	charming ();
	return 0;
}