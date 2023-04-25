#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int t, n;
ll arr[maxn];
ll pos[maxn];

void charming () {
	cin >> n;
	int pos0, pos1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	if (n <= 2) {
		cout << 1 << endl;
		return;
	}
	ll ans = 1, cnt = 0;
	int l = min (pos[0], pos[1]), r = max (pos[0], pos[1]);
	for (int i = 2; i < n; ++i) {
		if (pos[i] < l) {
			l = pos[i];
			++cnt;
			continue;
		}
		else if (pos[i] > r) {
			r = pos[i];
			++cnt;
			continue;
		}
		ans = ans * (r - l - 1 - cnt) % mod;
		++cnt;
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
