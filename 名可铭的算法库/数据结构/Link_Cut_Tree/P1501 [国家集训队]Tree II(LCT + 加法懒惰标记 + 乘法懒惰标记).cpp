#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 51061;

int n, q;
int fa[maxn], rev[maxn];
int val[maxn], sum[maxn], siz[maxn];
int lazy_add[maxn], lazy_mul[maxn];
int ch[maxn][2];

namespace LCT {
	bool Get (int x) {return x == ch[fa[x]][1];}
	bool isRoot (int x) {return x != ch[fa[x]][0] && x != ch[fa[x]][1];}
	void PushUp (int x) {
		sum[x] = (sum[ch[x][0]] + sum[ch[x][1]] + val[x]) % mod;
		siz[x] = siz[ch[x][0]]+ siz[ch[x][1]] + 1;
	}
	void PushAdd (int x, int k) {
		sum[x] = (sum[x] + k * siz[x]) % mod;
		val[x] = (val[x] + k) % mod;
		lazy_add[x] = (lazy_add[x] + k) % mod;
	}
	void PushMul (int x, int k) {
		sum[x] = (sum[x] * k) % mod;
		val[x] = (val[x] * k) % mod;
		lazy_mul[x] = (lazy_mul[x] * k) % mod;
		lazy_add[x] = (lazy_add[x] * k) % mod;
	}
	void PushRev (int x) {
		swap (ch[x][0], ch[x][1]);
		rev[x] ^= 1;
	}
	void PushDown (int x) {
		if (lazy_mul[x] != 1) {
			PushMul (ch[x][0], lazy_mul[x]);
			PushMul (ch[x][1], lazy_mul[x]);
			lazy_mul[x] = 1;
		}
		if (lazy_add[x]) {
			PushAdd (ch[x][0], lazy_add[x]);
			PushAdd (ch[x][1], lazy_add[x]);
			lazy_add[x] = 0;
		}
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

void init () {
	fill (val + 1, val + maxn, 1);
	fill (sum + 1, sum + maxn, 1);
	fill (siz + 1, siz + maxn, 1);
	fill (lazy_mul + 1, lazy_mul + maxn, 1);
}

void charming () {
	init ();
	cin >> n >> q;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		LCT :: Link (u, v);
	}
	char opt;
	int u1, v1, c, u2, v2;
	for (int i = 1; i <= q; ++i) {
		cin >> opt >> u1 >> v1;
		if (opt == '+') {
			cin >> c;
			LCT :: Split (u1, v1);
			LCT :: PushAdd (v1, c);
		}
		else if (opt == '-') {
			cin >> u2 >> v2;
			LCT :: Cut (u1, v1);
			LCT :: Link (u2, v2);
		}
		else if (opt == '*') {
			cin >> c;
			LCT :: Split (u1, v1);
			LCT :: PushMul (v1, c);
		}
		else {
			LCT :: Split (u1, v1);
			cout << sum[v1] << endl;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
