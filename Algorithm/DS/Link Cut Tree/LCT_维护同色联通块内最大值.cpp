#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;

int n, q;

struct LinkCutTree {
	int fa[N], ch[N][2], rev[N], val[N], mn[N];
	multiset <int> s[N];
	
	void Clear (int x) {val[x] = mn[x] = rev[x] = fa[x] = ch[x][0] = ch[x][1] = 0, s[x].clear ();}
	bool isRoot (int x) {return x != ch[fa[x]][0] && x != ch[fa[x]][1];}
	bool Getch (int x) {return x == ch[fa[x]][1];}
	void PushUp (int x) {
		mn[x] = min ({mn[ch[x][0]], mn[ch[x][1]], val[x]});
		if ((int) s[x].size () > 0) mn[x] = min (mn[x], *(s[x].begin ()));
	}
	
	void Rotate (int x) {
		int y = fa[x], z = fa[y], chk = Getch (x);
		if (!isRoot (y)) ch[z][Getch (y)] = x;
		if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
		ch[y][chk] = ch[x][chk ^ 1];
		ch[x][chk ^ 1] = y;
		fa[y] = x, fa[x] = z;
		PushUp (y), PushUp (x);
	}
	
	void Splay (int x) {
		for (int f = fa[x]; f = fa[x], !isRoot (x); Rotate (x)) {
			if (!isRoot (f)) Rotate (Getch (f) == Getch (x) ? f : x);
		}
	}
	
	int Access (int x) {
		int last = 0;
		for (; x; last = x, x = fa[x]) {
			Splay (x);
			if (ch[x][1]) s[x].insert (mn[ch[x][1]]);
			if (last) s[x].erase (s[x].find (mn[last]));
			ch[x][1] = last, PushUp (x);
		}
		return last;
	}
	
	void MakeRoot (int x) {
		Access (x);
		Splay (x);
	}
	
	int FindRoot (int x) {
		MakeRoot (x);
		while (ch[x][0]) x = ch[x][0];
		Splay (x);
		return x;
	}
	
	void Link (int x, int y) {
		MakeRoot (x);
		fa[x] = y;
		MakeRoot (y);
		s[y].insert (mn[x]);
	}
	
	void Cut (int x, int y) {
		MakeRoot (x);
		Splay (y);
		ch[y][1] = fa[x] = 0;
		PushUp (x), PushUp (y);
	}
}LCT[2];

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> col (n + 5, 1), fa (n + 5);
	vector <vector <int> > adj (n + 5);
	for (int i = 1; i <= n; ++i) cin >> col[i];
	LCT[0].mn[0] = LCT[1].mn[0] = LCT[0].mn[n + 1] = LCT[1].mn[n + 1] = 
	LCT[0].val[0] = LCT[1].val[0] = LCT[0].val[n + 1] = LCT[1].val[n + 1] = LLONG_MAX;
	for (int i = 1, val; i <= n; ++i) {
		cin >> val;
		LCT[0].val[i] = LCT[1].val[i] = val;
		LCT[0].mn[i] = LCT[1].mn[i] = LLONG_MAX;
	}
	for (int i = 2, f; i <= n; ++i) {
		cin >> f;
		adj[f].emplace_back (i);
	}
	
	auto dfs = [&] (auto && me, int f, int u) -> void {
		fa[u] = f;
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, u, v);
		}
		LCT[col[u]].Link (u, fa[u]);
	};
	
	dfs (dfs, n + 1, 1);
	cin >> q;
	for (int i = 1, opt, u, w, rt; i <= q; ++i) {
		cin >> opt >> u;
		if (opt == 1) {
			LCT[col[u]].Cut (u, fa[u]);
			LCT[col[u] ^= 1].Link (u, fa[u]);
		}
		else if (opt == 2) {
			cin >> w;
			LCT[col[u]].MakeRoot (u);
			LCT[col[u]].val[u] = w;
			LCT[col[u]].PushUp (u);
			LCT[col[u] ^ 1].MakeRoot (u);
			LCT[col[u] ^ 1].val[u] = w;
			LCT[col[u] ^ 1].PushUp (u); 
		}
		else {
			rt = LCT[col[u]].FindRoot (u);
			cout << LCT[col[u]].mn[LCT[col[u]].ch[rt][1]] << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}

/*
2
1 1
2 3
1
3
1 1
2 2 100
3 2
*/