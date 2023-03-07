#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 4e5 + 5;

int n;
vector <int> node[maxn];
queue <int> q; 
int dep[maxn];
int cnt[maxn];
int inp[maxn];
int f[maxn];
int ideal[maxn]; 
bool vis[maxn];

void dfs (int fa, int u, int depth) {
	dep[u] = depth;
	f[u] = fa;
	for (int i = 0; i < node[u].size (); ++i) {
		int v = node[u][i];
		if (v == fa) continue;
		dfs (u, v, depth + 1);
	}
}

void charming () {
	cin >> n;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		node[u].push_back (v);
		node[v].push_back (u);
	}
	dfs (0, 1, 1);
	for (int i = 1; i <= n; ++i) {
		++cnt[dep[i]];
	}
	int cur = 1, last = 1, j = 1;
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		cin >> inp[i];
		if (i - last >= cnt[j]) {
			last = i;
			++j;
			++cur;
		}
		if (dep[inp[i]] != cur) {
			ok = false;
		}
	}
	if (!ok) {
		cout << "NO" << endl;
		return;
	}
	q.push (1);
	vis[1] = true;
	int now, cntt = 2;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = (now == 1 ? 0 : 1); i < node[now].size (); ++i) {
			q.push (inp[cntt]);
			if (f[inp[cntt]] != now) {
				ok = false;
				break;
			}
			else ++cntt;
		}
	}
	if (!ok) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
