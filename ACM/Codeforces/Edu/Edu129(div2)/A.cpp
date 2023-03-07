#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
int i, j, k;
int alice[maxn], bob[maxn];

void init () {}

bool check () {}

void solve () {
	cin >> n;
	init ();
	for (i = 1; i <= n; ++i) cin >> alice[i];
	cin >> m;
	for (j = 1; j <= m; ++j) 
		cin >> bob[j];
	sort (alice + 1, alice + 1 + n);
	sort (bob + 1, bob + 1 + m);
	int p1 = 1, p2 = 0;
	if (alice[n] >= bob [m]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	if (bob[m] >= alice[n]) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	/*while (p1 <= n && p2 <= m) {
		while (alice[p1] <= bob[p2] && p1 <= n) ++p1;
		if (p1 > n) {
			cout << "Bob" << endl;
			break;
		}
		while (bob[p2] <= alice[p1] && p2 <= m) ++p2;
		if (p2 > m) {
			cout << "Alice" << endl;
			break;
		}
	}
	p1 = 1, p2 = 0;
	while (p1 <= m && p2 <= n) {
		while (bob[p1] <= alice[p2] && p1 <= m) ++p1;
		if (p1 > m) {
			cout << "Alice" << endl;
			break;
		}
		while (alice[p2] <= bob[p1] && p2 <= n) ++p2;
		if (p2 > n) {
			cout << "Bob" << endl;
			break;
		}
	}*/
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
