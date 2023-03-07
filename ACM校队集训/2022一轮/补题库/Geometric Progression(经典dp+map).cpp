#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
#define int long long 
using namespace std;
const int maxn = 2e6 + 5;

ll n, k, tot;
ll arr[maxn];
map <ll, ll> mmap[3];
map <ll, bool> vis;

void charming () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	ll res = 0;
	if (k == 1) {
		sort (arr + 1, arr + 1 + n);
		for (int i = 1; i <= n; ++i) {
			ll j = i;
			while (arr[j] == arr[i] && j <= n) ++j;
			ll tmp = j - i;
			i = j - 1;
			if (tmp >= 3) res += tmp * (tmp - 1) * (tmp - 2) / 6;
		}
		cout << res << endl;
		return;
	}
	ll zeros = 0;
	for (int i = 1; i <= n; ++i) {
		if (arr[i]) ++mmap[0][arr[i]];
		else ++zeros;
		if (!(arr[i] % k) && arr[i]) {
			mmap[1][arr[i]] += mmap[0][arr[i] / k];
		}
		if (!(arr[i] % (k * k)) && arr[i]) {
			mmap[2][arr[i]] += mmap[1][arr[i] / k];
		}
	}
	if (zeros >= 3) res += zeros * (zeros - 1) * (zeros - 2) / 6;
	for (int i = 1; i <= n; ++i) {
		if (!vis[arr[i]] && arr[i]) res += mmap[2][arr[i]], vis[arr[i]] = true;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}