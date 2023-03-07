#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n, c;
int arr[maxn];
map <int, int> mp;

void init () {mp.clear ();}

void charming () {
	init ();
	cin >> n >> c;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		++mp[arr[i]];
	}
	int res = 0;
	for (auto it : mp) {
		res += min (it.second, c);
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}