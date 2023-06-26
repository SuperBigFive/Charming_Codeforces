#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <pair <int, int> > > cons (n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		cons[u].emplace_back (make_pair (v, w));
		cons[v].emplace_back (make_pair (u, w));
	}
	vector <int> vis (n), val (n, LLONG_MAX);
	queue <int> q;
	q.push (n - 1),	vis[n - 1] = 1;
	int ans = 0;
	vector <int> time;
	vector <vector <int> > game;
	while (!q.empty () && game.size () < n * n) {
		vector <int> ngame;
		for (int i = 0; i < n; ++i) ngame.emplace_back (vis[i] ^ 1);
		while (!q.empty ()) {
			int u = q.front ();
			q.pop ();
			for (auto [v, w] : cons[u]) {
				if (vis[v]) continue;
				val[v] = min (val[v], w);
			}
		}
		int mn = LLONG_MAX, id = -1;
		for (int i = 0; i < n; ++i) if (!vis[i]) {
			if (mn > val[i]) mn = val[i], id = i;
		}
		if (mn >= LLONG_MAX) return void (cout << "inf" << endl);
		else {
			ans += mn;
			for (int i = 0; i < n; ++i) if (val[i] < LLONG_MAX) {
				val[i] -= mn;
				if (!val[i] && i) vis[i] = 1, q.push (i);
			}
			game.emplace_back (ngame);
			time.emplace_back (mn);
		}
	}
	int siz = game.size ();
	cout << ans << " " << siz << endl;
	for (int i = 0; i < siz; ++i) {
		for (int j = 0; j < n; ++j) cout << game[i][j];
		cout << " " << time[i] << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}