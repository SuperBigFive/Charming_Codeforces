#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int k[maxn];
int fa[maxn], rev[maxn], siz[maxn];
int ch[maxn][2];

namespace LCT {
	bool Get (int x) {return x == ch[fa[x]][1];}
	bool isRoot (int x) {return x != ch[fa[x]][0] && x != ch[fa[x]][1];}
	void PushUp (int x) {siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;}
	void PushRev (int x) {
		swap (ch[x][0], ch[x][1]);
		rev[x] ^= 1;
	}
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
		int y = fa[x], z = fa[y], chk = Get (x);
		if (!isRoot (y)) ch[z][Get (y)] = x;
		if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
		ch[y][chk] = ch[x][chk ^ 1];
		ch[x][chk ^ 1] = y;
		fa[y] = x, fa[x] = z;
		PushUp (y), PushUp (x);
	}
	
	void Splay (int x) {
		Update (x);
		for (int f = fa[x]; f = fa[x], !isRoot (x); Rotate (x)) {
			if (!isRoot (f)) Rotate (Get (f) == Get (x) ? f : x);
		}
	}

	int Access (int x) {
		int last;
		for (last = 0; x; last = x, x = fa[x]) {
			Splay (x), ch[x][1] = last, PushUp (x);
		}
		return last;
	}
	
	void makeRoot (int x) {
		x = Access (x);
		PushRev (x);
	}
	
	void Split (int x, int y) {
		makeRoot (x);
		Access (y);
		Splay (y);
	}
	
	int findRoot (int x) {
		x = Access (x);
		PushDown (x);
		while (ch[x][0]) x = ch[x][0], PushDown (x);
		Splay (x);
		return x;
	}
	
	void Link (int x, int y) {
		if (findRoot (x) == findRoot (y)) return;
		makeRoot (x);
		fa[x] = y;
	}
	
	void Cut (int x, int y) {
		Split (x, y);
		if (ch[y][0] != x || ch[x][1]) return;
		fa[x] = ch[y][0] = 0;
		PushUp (y);
	}
}

void init () {}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		if (i + k[i] <= n) LCT :: Link (i, i + k[i]);
		else LCT :: Link (i, n + 1);
	}
	cin >> m;
	int opt, x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> opt >> x;
		++x;
		if (opt == 1) {
			LCT :: Split (x, n + 1);
			cout << siz[n + 1] - 1 << endl;
		}
		else {
			cin >> y;
			LCT :: Cut (x, min (n + 1, x + k[x]));
			LCT :: Link (x, min (n + 1, x + y));
			k[x] = y;
		}
	}
}

signed main () {
	charming ();
	return 0;
}