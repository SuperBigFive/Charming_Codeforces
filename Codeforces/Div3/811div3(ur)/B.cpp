#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int val[maxn], cnt[maxn], last[maxn];

void init () {
	for (int i = 1; i <= n; ++i) cnt[i] = 0, last[i] = 0;
}
void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		++cnt[val[i]];
		if (cnt[val[i]] > 1) ans = max (ans, last[val[i]]);
		last[val[i]] = i;
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}