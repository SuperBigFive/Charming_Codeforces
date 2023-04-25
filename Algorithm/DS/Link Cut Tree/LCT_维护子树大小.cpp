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
		x = Access (x);
		PushRev (x);
	}
	
	void Link (int x, int y) {
		MakeRoot (x), Splay (x);
		MakeRoot (y), Splay (y);
		fa[x] = y;
		siz_f[y] += siz[x];
	}
	
	void Cut (int x, int y) {
		MakeRoot (x);
		Access (y);
		Splay (y);
		ch[y][0] = fa[x] = 0;
		PushUp (x), PushUp (y);
	}
}LCT;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	char opt;
	for (int i = 1, x, y; i <= q; ++i) {
		cin >> opt >> x >> y;
		if (opt == 'A') LCT.Link (x, y);
		else {
			LCT.Cut (x, y);
			LCT.MakeRoot (x);
			LCT.MakeRoot (y);
			cout << LCT.siz[x] * LCT.siz[y] << endl;
			LCT.Link (x, y); 
		}
	}
}

signed main () {
	charming ();
	return 0;
}