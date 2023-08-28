#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int t, n, cnt;
int siz[maxn], in[maxn];
vector <int> adj[maxn];
set <int> ans[maxn];

void init () {
	for (int i = 0; i < maxn; ++i) {
		in[i] = 0, siz[i] = 1;
		adj[i].clear (), ans[i].clear ();
	}
}

void charming () {
	init ();
	cin >> n;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s, s = '#' + s;
		for (int j = 1; j <= n; ++j)
		if (s[j] == '1') adj[i].emplace_back (j), ++in[j];
	}
	for (int i = 1; i <= n; ++i) ans[i].insert (i);
	queue <int> q;
	for (int i = 1; i <= n; ++i) if (!in[i]) {
		q.push (i);
	}
	int cur;
	while (!q.empty ()) {
		cur = q.front ();
		q.pop ();
		for (auto it : adj[cur]) {
			for (auto i : ans[cur])
			ans[it].insert (i);
			--in[it];
			if (in[it] <= 0) q.push (it);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i].size () << " ";
		for (auto it : ans[i])
		cout << it << " ";
		cout << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}