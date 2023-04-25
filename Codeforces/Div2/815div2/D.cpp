#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;
int ans[maxn], mx[maxn];
bool vis[maxn];
vector <pair <int, int> > match[maxn];

void init () {
	
}

void charming () {
	cin >> n >> q;
	for (int k = 1, i, j, x; k <= q; ++k) {
		cin >> i >> j >> x;
		match[i].emplace_back (make_pair (j, x));
		match[j].emplace_back (make_pair (i, x));
		if (i == j) mx[i] = x, vis[i] = true;
	}
	for (int i = 1; i <= n; ++i) {
		mx[i] = (1 << 30) - 1;
		for (auto it : match[i]) {
			mx[i] &= it.second;
		}	
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		for (int j = 0; j <= 30; ++j) {
			if (mx[i] & (1 << j)) {
				bool ok = true;
				for (auto it : match[i]) {
					if (!(mx[it.first] & (1 << j))) {
						ok = false;
						break;
					}
				}
				if (ok) mx[i] -= (1 << j);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << mx[i] << ' ';
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}