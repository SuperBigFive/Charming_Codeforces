#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int n, m, tim;
int a[maxn], b[maxn];
int mx[maxn], mn[maxn];
bool st[maxn];
bool vis[maxn][10005];

void init () {}

void dfs (int cur, int lim, int sum) {
	if (cur > lim) {
		if (sum == m) {
			cout << "Yes" << endl;
			for (int i = 1; i <= n; ++i)
			cout << (st[i] ? "H" : "T");
			exit (0);
		}
		return;
	}
	if (vis[cur][sum]) return;
	if (sum + mx[cur] < m) {
		vis[cur][sum] = true;
		return;
	}
	if (sum + mn[cur] > m) {
		vis[cur][sum] = true;
		return;
	}
	st[cur] = true;
	dfs (cur + 1, lim, sum + a[cur]);
	st[cur] = false;
	dfs (cur + 1, lim, sum + b[cur]);
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = n; i >= 1; --i) {
		mn[i] = mn[i + 1] + min (a[i], b[i]);
		mx[i] = mx[i + 1] + max (a[i], b[i]);
	}
	dfs (1, n, 0);
	cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}