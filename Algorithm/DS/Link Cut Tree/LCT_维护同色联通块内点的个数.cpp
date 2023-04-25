#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, q;

struct LinkCutTree {
	int fa[N], ch[N][2], siz[N], siz_f[N], rev[N];
	
	void Clear (int x) {siz[x] = siz_f[x] = rev[x] = fa[x] = ch[x][0] = ch[x][1] = 0;}
	bool isRoot (int x) {return x != ch[fa[x]][0] && x != ch[fa[x]][1];}
	bool Getch (int x) {return x == ch[fa[x]][1];}
	void PushUp (int x) {siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1 + siz_f[x];}
	void PushRev (int x) {rev[x] ^= 1; swap (ch[x][0], ch[x][1]);}
	void PushDown (int x) {
		if (rev[x]) {
			PushRev (ch[x][0]);
			PushRev (ch[x][1]);
			rev[x] = 0;
		}
	}
	void Update (int x) {
		if (!isRoot (x)) Update (fa[x]);
		PushDown (x);
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
		Update (x);
		for (int f = fa[x]; f = fa[x], !isRoot (x); Rotate (x)) {
			if (!isRoot (f)) Rotate (Getch (f) == Getch (x) ? f : x);
		}
	}
	
	int Access (int x) {
		int last = 0;
		for (; x; last = x, x = fa[x]) {
			Splay (x), siz_f[x] += siz[ch[x][1]] - siz[last], ch[x][1] = last, PushUp (x);
		}
		return last;
	}
	
	void MakeRoot (int x) {
		Access (x);
		Splay (x);
		//PushRev (x);
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
		siz_f[y] += siz[x];
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
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	
	auto dfs = [&] (auto && me, int f, int u) -> void {
		fa[u] = f;
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, u, v);
		}
		LCT[col[u]].Link (u, fa[u]);
	};
	
	dfs (dfs, n + 1, 1), col[n + 1] = col[1] ^ 1;
	cin >> q;
	for (int i = 1, opt, u, rt; i <= q; ++i) {
		cin >> opt >> u;
		if (opt == 0) {
			rt = LCT[col[u]].FindRoot (u);
			cout << LCT[col[u]].siz[LCT[col[u]].ch[rt][1]] << endl;
		}
		else {
			LCT[col[u]].Cut (u, fa[u]);
			LCT[col[u] ^= 1].Link (u, fa[u]);
		}
	}
}

signed main () {
	charming ();
	return 0;
}