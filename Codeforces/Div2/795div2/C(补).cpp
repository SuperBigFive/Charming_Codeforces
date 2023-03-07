#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e5 + 5;

int t, n, k;
ll ans, l, r, cnt;
char arr[maxn];

void init () {l = -1, r = 0, cnt = 0;}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		init ();
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			if (arr[i] == '1') {
				if (!cnt) l = i;
				++cnt;
				r = i;
			}
		}
		if (!cnt) {
			cout << 0 << endl;
			continue;
		}
		ans = cnt*11;
		if (cnt == 1) {
			if (n - r <= k) ans -= 10;
			else if (l - 1 <= k) ans -= 1;
			cout << ans << endl;
			continue;
		}	
		if (n - r <= k) {
			ans -= 10;
			k -= n - r;
		}
		if (l - 1 <= k) --ans;
		cout << ans << endl;
	}
}
