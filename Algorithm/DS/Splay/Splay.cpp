#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, rt, tot;
int cnt[maxn], val[maxn], siz[maxn], fa[maxn];
int ch[maxn][2];

namespace Splay {
	void Maintain (int x) {siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x];}
	bool Get (int x) {return x == ch[fa[x]][1];}
	void Clear (int x) {cnt[x] = val[x] = siz[x] = fa[x] = ch[x][0] = ch[x][1] = 0;}
	
	void Rotate (int x) {
		int y = fa[x], z = fa[y], chk = Get (x);
		ch[y][chk] = ch[x][chk ^ 1];
		if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
		ch[x][chk ^ 1] = y;
		fa[y] = x, fa[x] = z;
		if (z) ch[z][y == ch[z][1]] = x;
		Maintain (y);
		Maintain (x);
	}
	
	void Splay (int x) {
		for (int f = fa[x]; f = fa[x], f; Rotate (x)) {
			if (fa[f]) Rotate (Get (f) == Get (x) ? f : x);
		}
		rt = x;
	}
	
	void Insert (int x) {
		if (!rt) {
			cnt[++tot] = 1;
			val[tot] = x;
			fa[tot] = 0;
			rt = tot;
			Maintain (tot);
			return;
		}
		int cur = rt, f = 0;
		while (cur) {
			if (val[cur] == x) {
				++cnt[cur];
				Maintain (cur);
				Maintain (f);
				Splay (cur);
				return;
			}
			f = cur, cur = ch[cur][val[cur] < x];
		}
		cnt[++tot] = 1;
		val[tot] = x;
		fa[tot] = f;
		ch[f][val[f] < x] = tot;
		Maintain (tot);
		Maintain (f);
		Splay (tot);
	}
	
	int Get_Rank (int x) {
		int cur = rt, f = 0, res = 0;
		while (cur) {
			if (val[cur] == x) {
				res += siz[ch[cur][0]];
				Splay (cur);
				return res + 1;
			}
			else if (val[cur] > x) {
				f = cur;
				cur = ch[cur][0];
			}
			else {
				res += siz[ch[cur][0]] + cnt[cur];
				f = cur;
				cur = ch[cur][1];
			}
		}
		Splay (f);
		return res + 1;
	}
	
	int Get_Kth (int k) {
		int cur = rt, f = 0;
		while (cur) {
			if (k <= siz[ch[cur][0]]) {
				f = cur;
				cur = ch[cur][0];
			}
			else {
				k -= siz[ch[cur][0]] + cnt[cur];
				if (k <= 0) {
					Splay (cur);
					return val[cur];
				}
				f = cur;
				cur = ch[cur][1];
			}
		}
		return val[f];
	}
	
	int Get_Pre () {
		int cur = ch[rt][0];
		if (!cur) return cur;
		while (ch[cur][1]) cur = ch[cur][1];
		Splay (cur);
		return cur;
	}
	
	int Get_Nxt () {
		int cur = ch[rt][1];
		if (!cur) return cur;
		while (ch[cur][0]) cur = ch[cur][0];
		Splay (cur);
		return cur;
	}
	
	void Delete (int x) {
		Get_Rank (x);
		int cur = rt;
		if (cnt[rt] > 1) {
			--cnt[rt];
			Maintain (rt);
			return;
		}
		else if (!ch[rt][0] && !ch[rt][1]) {
			Clear (rt);
			rt = 0;
			return;
		}
		else if (!ch[rt][0]) {
			rt = ch[cur][1];
			fa[rt] = 0;
			Clear (cur);
			return;
		}
		else if (!ch[rt][1]) {
			rt = ch[cur][0];
			fa[rt] = 0;
			Clear (cur);
			return;
		}
		x = Get_Pre ();
		ch[rt][1] = ch[cur][1];
		fa[ch[cur][1]] = x;
		Maintain (rt);
		Clear (cur);
		return;
	}
}

void init () {};

void charming () {
	init ();	
	cin >> n;
	for (int i = 1, opt, x; i <= n; ++i) {
		cin >> opt >> x;
		if (opt == 1) Splay :: Insert (x);
		else if (opt == 2) Splay :: Delete (x);
		else if (opt == 3) cout << Splay :: Get_Rank (x) << endl;
		else if (opt == 4) cout << Splay :: Get_Kth (x) << endl;
		else if (opt == 5) {
			Splay :: Insert (x);
			cout << val[Splay :: Get_Pre ()] << endl;
			Splay :: Delete (x);
		}
		else {
			Splay :: Insert (x);
			cout << val[Splay :: Get_Nxt ()] << endl;
			Splay :: Delete (x);
		}
	}		
}

signed main () {
	charming ();
	return 0;
}
		