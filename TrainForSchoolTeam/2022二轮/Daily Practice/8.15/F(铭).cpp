#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define int ll
#define vi vector <int> 
#define pb push_back
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;

void init () {

}

void charming () {
	init ();
	cin >> n >> m;
	if (m < n - 1) {
		ll res = (n - m - 1) *  (n - 1) * n + m * 2 + m * (m - 1) * 2 + (m + 1) * n * (n - m - 1);
		cout << res << endl;
	}
	else {
		m = min (m, n * (n - 1) / 2);
		ll res = (n - 1) * 2 + ((n - 1) * 2 * (n - 2) - (m - n + 1) * 2);
		cout << res << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
