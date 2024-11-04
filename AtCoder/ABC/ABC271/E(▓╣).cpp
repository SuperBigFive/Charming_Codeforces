#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

struct Edge {
	int to;
	int nxt;
	int w;
}edge[maxn];
int n, m, k, tot, tail, res;
int stk[maxn], head[maxn], seq[maxn];
bool vis[maxn];
vector <int> id[maxn];

void init () {}

void add_edge (int u, int v, int w) {
	edge[++tot].to = v;
	edge[tot].nxt = head[u];
	edge[tot].w = w;
	head[u] = tot;
}

void dfs (int cur, int sum) {
	if (sum > res && res != -1) return;
	if (cur == n) {
		if (res == -1 || sum < res) res = sum;
		return;
	}
	for (int i = head[cur], tmp; i; i = edge[i].nxt) {
		if (vis[i] || !id[i].size ()) continue;
		tmp = lower_bound (id[i].begin (), id[i].end (), stk[tail]) - id[i].begin ();
		if (tmp >= id[i].size ()) continue;
		tmp = id[i][tmp];
		stk[++tail] = tmp;
		vis[i] = true;
		dfs (edge[i].to, sum + edge[i].w);
		vis[i] = false;
		--tail;
	}
}

void charming () {
	cin >> n >> m >> k;	
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		add_edge (u, v, w);
	}
	for (int i = 1; i <= k; ++i) {
		cin >> seq[i];
		id[seq[i]].emplace_back (i);
	}
	res = -1, dfs (1, 0);
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}