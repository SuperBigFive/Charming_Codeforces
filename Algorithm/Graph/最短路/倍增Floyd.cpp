#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 300 + 5;
const int M = 100 + 5;
const int K = 30;

int n, m, q;
int a[N], d[N], val[N], nval[N];
int dp[K][N][N];
vector <int> adj[N];

void init () {
	for (int i = 0; i < K; ++i)
	for (int j = 0; j < N; ++j)
	for (int p = 0; p < N; ++p) dp[i][j][p] = -INT_MAX;
	for (int i = 0; i < N; ++i) val[i] = nval[i] = -INT_MAX;
}


void Floyed (int k) {
	for (int i = 0; i < n + M; ++i)
	for (int j = 0; j < n + M; ++j)
	for (int p = 0; p < n + M; ++p) if (dp[k - 1][i][p] > -INT_MAX
	&& dp[k - 1][p][j] > -INT_MAX) {
		dp[k][i][j] = max (dp[k][i][j], dp[k - 1][i][p] + dp[k - 1][p][j]);
	}
}

void charming () {
	init ();
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> d[i];
	
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
	}
	for (int i = 0; i <= n; ++i) {
		adj[i].emplace_back (n + 1);
		adj[n + d[i] - 1].emplace_back (i);
	}
	for (int i = n + 1; i < n + M - 1; ++i) {
		adj[i].emplace_back (i + 1);
	}
	for (int i = 0; i < n + M; ++i) {
		sort (adj[i].begin (), adj[i].end ());
		adj[i].resize (unique (adj[i].begin (), adj[i].end ()) - adj[i].begin ());
		for (auto j : adj[i]) dp[0][i][j] = a[j];
	}
	
	for (int i = 1; i < K; ++i) Floyed (i);	
	
	int ans = 0;
	bool flag = true;
	for (int i = K - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) nval[j] = -INT_MAX;
		if (flag) {
			bool ok = false;
			for (int p = 0; p < N; ++p) {
				nval[p] = dp[i][0][p];
				if (nval[p] >= q) ok = true;
			}
			if (!ok) {
				for (int p = 0; p < N; ++p) val[p] = nval[p];
				flag = false, ans += (1 << i);
			}
			continue;
		}
		bool ok = false;
		for (int j = 0; j < N; ++j)
		for (int p = 0; p < N; ++p) {
			if (dp[i][j][p] > -INT_MAX && val[j] > -INT_MAX) {
				nval[p] = max (nval[p], val[j] + dp[i][j][p]);
				if (nval[p] >= q) ok = true;
			}
		}
		if (!ok) {
			for (int p = 0; p < N; ++p) val[p] = nval[p];
			ans += (1 << i);
		}
	}
	cout << ans + 1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}