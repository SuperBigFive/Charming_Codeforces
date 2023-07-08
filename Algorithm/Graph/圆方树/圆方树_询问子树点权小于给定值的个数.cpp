#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;

struct RoundSquareTree {
	int n, tot, bcc_cnt;
	vector <int> dfn, low;
	vector <vector <int> > G, nG, reG;
	
	RoundSquareTree (int n, vector <vector <int> > &G) {
		this -> n = n, tot = bcc_cnt = 0;
		dfn = low = vector <int> (n << 2);
		this -> G = G, nG = reG = vector <vector <int> > (n << 2);
	}
	
	void Tarjan (int f, int u, vector <int> &stk) {
		dfn[u] = low[u] = ++tot;
		stk.emplace_back (u);
		for (auto &v : G[u]) {
			if (v == f) continue;
			else if (!dfn[v]) {
				Tarjan (u, v, stk);
				low[u] = min (low[u], low[v]);
				if (low[v] >= dfn[u]) {
					++bcc_cnt;
					int nv;
					do {
						nv = stk.back ();
						nG[n + bcc_cnt].emplace_back (nv);
						nG[nv].emplace_back (n + bcc_cnt);
						stk.pop_back ();
					} while (nv != v);
					nG[n + bcc_cnt].emplace_back (u);
					nG[u].emplace_back (n + bcc_cnt);
				}
			} else low[u] = min (low[u], dfn[v]);
		}
	}
	
	void Build ()	{vector <int> stk; Tarjan (0, 1, stk);}
	
	void reBuild (int f, int u) {
		for (auto &v : nG[u]) {
			if (v == f) continue;
			reG[u].emplace_back (v);
			reBuild (u, v);
		}
	}
	
};

struct CaptainMo {
	int n, len, blo, q;
	vector <int> a, rev, be, en, bel, occur;
	array <vector <int>, 2> cnt, blo_cnt;
	vector <array <int, 5> > query;
	
	CaptainMo (int n, int q, vector <int> &a, vector <int> &rev, 
	vector <array <int, 5> > &query) {
		this -> n = n, len = 500, blo = (N + len - 1) / len, this -> q = q;
		this -> a = a, this -> rev = rev, be = en = vector <int> (blo + 5);
		bel = occur = vector <int> (N);
		cnt[0] = cnt[1] = vector <int> (N);
		blo_cnt[0] = blo_cnt[1] = vector <int> (N);
		this -> query = query;
		for (int i = 1; i < N; ++i) bel[i] = (i + len - 1) / len;
		for (int i = 1; i <= blo; ++i) {
			be[i] = (i - 1) * len + 1;
			en[i] = min (N, i * len);
		}
		sort (this -> query.begin (), this -> query.end (), [&] (array <int, 5> &x,
		array <int, 5> &y) {
			if (bel[x[1]] != bel[y[1]]) return bel[x[1]] < bel[y[1]];
			else if (bel[x[1]] & 1) return x[2] < y[2];
			else return x[2] > y[2];
		});
	}
	
	inline void Change (int x, int k) {
		if (rev[x] > n) return;
		int c = a[rev[x]], type = occur[c] & 1;
		if (occur[c]) {
			--cnt[type][c];
			--blo_cnt[type][bel[c]];
		}
		occur[c] += k;
		if (occur[c]) {
			++cnt[type ^ 1][c];
			++blo_cnt[type ^ 1][bel[c]];
		}
	}
	
	vector <int> Solve () {
		vector <int> ans (q + 5);
		int l = 1, r = 0;
		for (auto [opt, ql, qr, lim, id] : query) {
			while (r < qr) Change (++r, 1);
			while (l > ql) Change (--l, 1);
			while (l < ql) Change (l++, -1);
			while (r > qr) Change (r--, -1);
			for (int i = 1; i <= blo; ++i) {
				if (en[i] <= lim) ans[id] += blo_cnt[opt][i];
				else {
					for (int j = be[i]; j <= lim; ++j) {
						ans[id] += cnt[opt][j];
					} break;
				}
			}
		}
		return ans;
	}
};

int n, m, q, tot;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n + 5), b;
	vector <vector <int> > G (n + 5);
	set <pair <int, int> > edge;
	for (int i = 1; i <= n; ++i) cin >> a[i], b.emplace_back (a[i]);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		if (u > v) swap (u, v);
		if (edge.count (make_pair (u, v))) continue;
		else edge.insert (make_pair (u, v));
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	
	cin >> q;
	vector <array <int, 5> > query;
	for (int i = 0, opt, x, y; i < q; ++i) {
		cin >> opt >> x >> y;
		query.emplace_back ((array <int, 5>) {opt, x, x, y, i});
		b.emplace_back (y);
	}
	sort (b.begin (), b.end ());
	b.resize (unique (b.begin (), b.end ()) - b.begin ());
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound (b.begin (), b.end (), a[i]) - b.begin () + 1;
	}
	for (int i = 0; i < q; ++i) {
		query[i][3] = lower_bound (b.begin (), b.end (), query[i][3]) - b.begin () + 1;
	}
	
	RoundSquareTree RST (n, G);
	RST.Build ();
	vector <int> dfn (n << 2), bot (n << 2), rev (n << 2);
	
	auto DFS = [&] (auto && me, int f, int u, vector <vector <int> > &G) -> void {
		dfn[u] = ++tot, rev[tot] = u;
		for (auto &v : G[u]) {
			if (v == f) continue;
			me (me, u, v, G);
		}
		bot[u] = tot;
	};
	
	RST.reBuild (0, 1);
	DFS (DFS, 0, 1, RST.reG);
	for (int i = 0; i < q; ++i) {
		query[i][1] = dfn[query[i][1]];
		query[i][2] = bot[query[i][2]];
	}
	
	vector <int> ans = CaptainMo (n, q, a, rev, query).Solve ();
	for (int i = 0; i < q; ++i) cout << ans[i] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}