#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int t, n, s, tot;
int a[maxn], b[maxn];
int candi[maxn];
int cnt[maxn];
bool vis[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		candi[i] = cnt[i] = 0;
		vis[i] = false;
	}
	tot = 0;
}

void charming () {
	init ();
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int mins = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		if (b[i] > 0) vis[b[i]] = true, mins = max (mins, a[i] - b[i]);
	}
	if (mins > s) {
		cout << 0 << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) candi[++tot] = i;
	}
	int lb = 0, tott = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] == -1) {
			tott = 1;
			lb = a[i] - s;
			tott = lower_bound (candi + 1, candi + 1 + tot, lb) - candi;
			++cnt[tott];
			if (tott > tot) {
				cout << 0 << endl;
				return;
			}
		}
	}
	ll ans = 1;
	for (int i = 1; i <= tot; ++i) {
		cnt[i] += cnt[i-1];
		ans = ans * (cnt[i] - i + 1) % mod;
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
