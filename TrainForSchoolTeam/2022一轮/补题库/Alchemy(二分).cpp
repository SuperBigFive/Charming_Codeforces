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
const int maxn = 1e5 + 5;

ll n;
ll c[maxn], sum[maxn];
map <ll, ll> cnt;

bool check (ll num) {
	//if (cnt[num]) return true;
	ll zeros = cnt[0] + cnt[num];
	if (num < n) zeros += sum[n - 1] - sum[num];
	ll need = 1;
	for (ll i = num - 1; i > 0; --i) {
		if (cnt[i] < need) need += need - cnt[i];
		else zeros += cnt[i] - need;
		if (need > 1e16) return false;
	}
	return zeros >= need;
}

void charming () {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> cnt[i], sum[i] = sum[i - 1] + cnt[i];
	if (sum[n - 1] == 1) {
		for (int i = 0; i < n; ++i) {
			if (cnt[i]) {
				if (i) cout << i << endl;
				else cout << 1 << endl;
				return;
			}
		}
	}
	ll l = 1, r = 1e16;
	while (l < r - 1) {
		ll mid = (l + r) / 2;
		if (check (mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}