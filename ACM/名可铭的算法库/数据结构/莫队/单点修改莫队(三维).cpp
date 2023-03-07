#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pip pair <int, pii> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 1e6 + 5;

int n, m, cnt_q, cnt_c;
int val[maxn], tmp_val[maxn], bel[maxn], res[maxn], cnt[maxn];
struct Query {
	int tot, t;
	int l, r;
	bool operator < (const Query &a) const{
		if (bel[l] != bel[a.l]) return bel[l] < bel[a.l];
		if (bel[r] != bel[a.r]) return bel[r] < bel[a.r];
		return t < a.t;
	}
}q[maxn];
struct Change {
	int pos, last_val, new_val;
}c[maxn];

void init () {}

void add_q () {
	++cnt_q;
	cin >> q[cnt_q].l, cin >> q[cnt_q].r;
	q[cnt_q].tot = cnt_q;
	q[cnt_q].t = cnt_c;
}

void add_c () {
	++cnt_c;
	cin >> c[cnt_c].pos, cin >> c[cnt_c].new_val;
	c[cnt_c].last_val = tmp_val[c[cnt_c].pos];
	tmp_val[c[cnt_c].pos] = c[cnt_c].new_val;
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		tmp_val[i] = val[i];
	}
	int block = pow (n, (double) 2 / 3);
	for (int i = 1; i <= n; ++i) {
		bel[i] = (i - 1) / block + 1;
	}
	char ch;
	for (int i = 1; i <= m; ++i) {
		cin >> ch;
		if (ch == 'Q') add_q ();
		else add_c ();
	}
	sort (q + 1, q + 1 + cnt_q);
	int pl = 1, pr = 0, pt = 0, ans = 0;
	for (int i = 1; i <= cnt_q; ++i) {
		while (pr < q[i].r) {
			++pr;
			++cnt[val[pr]];
			if (cnt[val[pr]] == 1) ++ans;
		}
		while (pr > q[i].r) {
			--cnt[val[pr]];
			if (!cnt[val[pr]]) --ans;
			--pr;
		}
		while (pl < q[i].l) {
			--cnt[val[pl]];
			if (!cnt[val[pl]]) --ans;
			++pl;
		}
		while (pl > q[i].l) {
			--pl;
			++cnt[val[pl]];
			if (cnt[val[pl]] == 1) ++ans;
		}
		while (pt < q[i].t) {
			++pt;
			if (c[pt].pos >= q[i].l && c[pt].pos <= q[i].r) {
				--cnt[c[pt].last_val];
				if (!cnt[c[pt].last_val]) --ans;
				++cnt[c[pt].new_val];
				if (cnt[c[pt].new_val] == 1) ++ans;
			}
			val[c[pt].pos] = c[pt].new_val;
		}
		while (pt > q[i].t) {
			if (c[pt].pos >= q[i].l && c[pt].pos <= q[i].r) {
				--cnt[c[pt].new_val];
				if (!cnt[c[pt].new_val]) --ans;
				++cnt[c[pt].last_val];
				if (cnt[c[pt].last_val] == 1) ++ans;
			}
			val[c[pt].pos] = c[pt].last_val;
			--pt;
		}
		res[q[i].tot] = ans; 
	}
	for (int i = 1; i <= cnt_q; ++i) {
		cout << res[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}