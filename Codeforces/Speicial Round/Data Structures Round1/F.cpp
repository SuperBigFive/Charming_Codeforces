#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;

int t, n, q;

void get_prim (vector <int> &prim, vector <int> &firstPrim) {
	vector <int> vis (N);
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prim.emplace_back (i), firstPrim[i] = i;
		for (int j = 0; j < prim.size () && i * prim[j] < N; ++j) {
			vis[i * prim[j]] = true;
			firstPrim[i * prim[j]] = prim[j];
			if (i % prim[j] == 0) break;
		}
	}
}

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <vector <int> > tag_add (n + 5), tag_del (n + 5);
	vector <vector <int> > pos (N), nxt (N, vector <int> (20));
	vector <int> prim, firstPrim (N);
	get_prim (prim, firstPrim);
	for (int i = 1, val, siz, p; i <= n; ++i) {
		cin >> val;
		while (val > 1) {
			p = firstPrim[val];
			if (!pos[p].size ()) pos[p].emplace_back (0);
			pos[p].emplace_back (i);
			if (pos[p].size () > 2) {
				siz = pos[p].size ();
				tag_add[pos[p][siz - 3] + 1].emplace_back (i);
				tag_del[pos[p][siz - 2] + 1].emplace_back (i);
			}
			if (val == p) break;
			while (val % p == 0) val /= p;
		}
	}
	multiset <int> s;
	for (int i = 1; i <= n; ++i) {
		for (auto &it : tag_add[i]) s.insert (it);
		for (auto &it : tag_del[i]) {
			auto del = s.find (it);
			s.erase (del);
		}
		if (s.size ()) nxt[i][0] = *s.begin ();
	}
	for (int i = n; i >= 1; --i)
	for (int j = 1; j < 20; ++j)
	nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	for (int i = 1, l, r, res; i <= q; ++i) {
		cin >> l >> r;
		res = 0;
		for (int j = 19; j >= 0; --j) {
			if (!nxt[l][j] || nxt[l][j] > r) continue;
			l = nxt[l][j];
			res += (1 << j);
		}
		cout << ++res << endl;
	}
}

signed main () {
	charming ();
	return 0;
}