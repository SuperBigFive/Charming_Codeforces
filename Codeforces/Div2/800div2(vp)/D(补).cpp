#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 15;

int t, n, ans;
int l[maxn], r[maxn];
vector <int> node[maxn];

void init () {
	ans = 0;
	for (int i = 1; i <= n; ++i) node[i].clear ();
}

ll dfs (int now) {
	if (!now) return 0;
	ll d = 0;
	for (int i = 0; i < node[now].size (); ++i) {
		d += dfs (node[now][i]);
	}
	if (d < l[now]) {
		++ans;
		return r[now];
	}
	if (d < r[now]) return d;
	return r[now];
}

void charming () {
	init ();
	cin >> n;
	int pre;
	for (int i = 2; i <= n; ++i) {
		cin >> pre;
		node[pre].push_back (i);
	}
	for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
	dfs (1);
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
