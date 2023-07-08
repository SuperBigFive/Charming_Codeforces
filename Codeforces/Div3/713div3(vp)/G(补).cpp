#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e7 + 5;

int t, n;
int ans[N], inv[N];

void get () {
	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			ans[j] += i;
		}
		if (ans[i] < N && !inv[ans[i]]) inv[ans[i]] = i;
	}
}

void init () {}

void charming () {
	init ();
	cin >> n;
	if (inv[n]) cout << inv[n] << endl;
	else cout << -1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	get ();
  cin >> t;
	while (t--) charming ();
  return 0;
}