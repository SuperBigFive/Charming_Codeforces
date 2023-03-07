#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int val[maxn];
bool vis[maxn];

void init () {
	for (int i = 1; i <= n; ++i) vis[val[i]] = false;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		vis[val[i]] = true;
	}
	sort (val + 1, val + 1 + n);
	vector <pii> res;
	int cnt = 0, up_ = (n >> 1);
	for (int i = 1; i <= n && cnt < up_; ++i) {
		for (int j = i + 1; j <= n && cnt < up_; ++j) {
			if (vis[val[j] % val[i]]) continue;
			++cnt;
			res.pb ({val[j], val[i]});
		}
	}
	for (auto it : res) {
		cout << it.fi << ' ' << it.se << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}