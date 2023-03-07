#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
ll arr[maxn];

void charming () {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum -= arr[n];
	bool ok = false;
	ll cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (arr[i]) ok = true;
		if (!arr[i] && ok) {
			++cnt;
		}
	}
	ll ans = sum + cnt;
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