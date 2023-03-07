#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e5 + 5;

int n, root;
int c[maxn];
bool ok, flag, flag2;
vector <int> adj[maxn];
priority_queue <int, vector <int>, greater <int> > q;

void init () {

}

bool dfs (int fa, int u) {
	int v;
	flag = true;
	for (int i = 0; i < adj[u].size (); ++i) {
		v = adj[u][i];
		flag = flag & (dfs (u, v));
	}
	if (flag && c[u]) q.push (u);
	return c[u];
}

void charming () {
	init ();
	cin >> n;
	int fa, c_;
	for (int i = 1; i <= n; ++i) {
		cin >> fa >> c_;
		c[i] = c_;
		if (fa + 1) adj[fa].pb (i);
		else root = i;
	}
	dfs (-1, root);
	int now;
	vector <int> res;
	while (!q.empty ()) {
		now = q.top ();
		q.pop ();
		res.pb (now);
	}
	if (res.size ()) {
		for (int i = 0; i < res.size (); ++i) {
			cout << res[i] << ' ';
		}
	}
	else {
		cout << -1 << endl;
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}