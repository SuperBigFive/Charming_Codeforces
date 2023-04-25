#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int arr[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	int res = LLONG_MAX;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				res = min (res, max ({arr[i], arr[j], arr[k]})
				 - min ({arr[i], arr[j], arr[k]}));
			}
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)	charming ();
	return 0;
}