#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
#define inl inline
using namespace std;
const int maxn = 2e6 + 5;

int t, n, k;
ll arr[maxn];

void init () {
	
}


void charming () {
	init ();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] = k - arr[i] % k;
	}
	sort (arr + 1, arr + 1 + n);
	int cnt = 1;
	int max_times = 1, id;
	for (int i = 2; i <= n; ++i) {
		if (arr[i] != arr[i - 1]) {
			if (cnt >= max_times) {
				max_times = cnt;
				id = arr[i - 1];
			}
			cnt = 1;
		}
		else ++cnt;
	}
	if (cnt >= max_times) {
		max_times = cnt;
		id = arr[n];
	}
	cnt = 1;
	ll ans = (max_times - 1) * k + id;
	cout << ans + id << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}