#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 8e5 + 5;

int n, m, tot;
int digit[maxn][30], siz[maxn];
int to[maxn], nxt[maxn], head[maxn];
bool vis[maxn], color[maxn];
vector <int> scc[maxn];
vector <array <int, 3> > cons;

void init () {
	tot = 0;
	fill (head, head + maxn, -1);
}

void add_edge (int u, int v) {
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot++;	
}

int pre[maxn];

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void dfs (int f, int u, int co, ll &s, ll &c) {
	vis[u] = true;
	color[u] = co;
	s += siz[u];
	if (co) c += siz[u];
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		if(vis[v]) {
			if (color[v] == color[u]) {
				cout << -1 << endl;
				exit (0);
			}
			continue;
		}
		dfs (u, v, co ^ 1, s, c);
	}
}

ll solve (int id) {
	init ();
	for (int i = 1; i <= n; ++i) 
	pre[i] = i, siz[i] = 1, vis[i] = color[i] = 0;
	for (int i = 0; i < m; ++i) {
		auto [u, v, w] = cons[i];
		if (!digit[i][id]) {
			int fu = find (u);
			int fv = find (v);
			if (fu != fv) {
				pre[fu] = fv;
				siz[fv] += siz[fu];
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		auto [u, v, w] = cons[i];
		if (digit[i][id]) {
			int fu = find (u);
			int fv = find (v);
			add_edge (fu, fv);
			add_edge (fv, fu);
		}
	}
	ll res = 0, sum, cnt1;
	for (int i = 1; i <= n; ++i) if (!vis[i] && find (i) == i) {
		sum = 0, cnt1 = 0;
		dfs (0, i, 1, sum, cnt1);
		res += min (cnt1, sum - cnt1);
	}
	return res;
}

void charming () {
	init ();
	cin >> n >> m;
	cons.resize (m);
	for (int i = 0; i < m; ++i) {
		cin >> cons[i][0] >> cons[i][1] >> cons[i][2];
		int tmp = cons[i][2], cnt = 0;
		while (tmp) {
			++cnt;
			digit[i][cnt] = (tmp & 1);
			tmp >>= 1;
		}
	}
	ll res = 0;
	for (int i = 1; i <= 30; ++i) {
		res += (1 << (i - 1)) * solve (i);
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}