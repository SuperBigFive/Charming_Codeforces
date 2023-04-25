#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
ll arr[maxn];
vector <ll> val, idx;

void init () {
	val.clear (), idx.clear ();
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] < i) {
			val.pb (arr[i]);
			idx.pb (i);
		}
	}
	ll ans = 0, sum = 0;
	map <ll, ll> cnt;
	for (int i = 0; i < val.size (); ++i) {
		++cnt[val[i]];
		++sum;
	}
	ll last = 0;
	for (int i = 0; i < val.size (); ++i) {
		ans += sum;
		while (last <= idx[i])
		sum -= cnt[last], ans -= cnt[last], ++last;
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