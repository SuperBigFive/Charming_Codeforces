#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
#define inl inline
using namespace std;
const int maxn = 2e6 + 5;

ll t, n, k;
ll arr[maxn];

void init () {
	
}


void charming () {
	init ();
	cin >> n >> k;
	ll tot = 0, tmp;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		tmp = k - tmp % k;
		if (tmp != k) arr[++tot] = tmp;
	}
	sort (arr + 1, arr + 1 + tot);
	ll cnt = 1;
	ll max_times = 1, id = 0;
	for (int i = 2; i <= tot; ++i) {
		if (arr[i] != arr[i - 1]) {
			if (cnt >= max_times) {
				max_times = cnt;
				id = arr[i - 1];
			}
			cnt = 1;
		}
		else ++cnt;
	}
	if (cnt >= max_times && tot) {
		max_times = cnt;
		id = arr[tot];
	}
	if (!tot) {
		cout << 0 << endl;
		return;
	}
	ll ans = (max_times - 1) * k + id + 1;
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