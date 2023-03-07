#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 1e9 + 7;

int t, n;
ll arr[maxn];
ll cnt[maxn];
vector <int> start[maxn];
vector <int> endd[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		start[i].clear ();
		endd[i].clear ();
		cnt[i] = 0;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		++cnt[arr[i]];
	}
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (arr[j] == arr[i] && j <= n) ++j;
		start[arr[i]].push_back (i);
		endd[arr[i]].push_back (j - 1);
		i = j - 1;
	}
	ll ans = 0, tmp;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] <= ans || !start[i].size ()) continue;
		int now = 0;
		tmp = cnt[i];
		if (!(start[i][now] & 1)) --tmp;
		for (; now < start[i].size () - 1; ++now) {
			if ((start[i][now + 1] - endd[i][now]) & 1) continue;
			else --tmp;
		}
		if ((n - endd[i][now]) & 1) -- tmp;
		ans = max (ans, tmp);
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
