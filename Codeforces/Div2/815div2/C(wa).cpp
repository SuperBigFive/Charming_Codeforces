#include <bits/stdc++.h>
#define ll long long
#define rg register int
using namespace std;
const int maxn = 3e5 + 5;

int n, m, tot;
int val[maxn];
ll sum[maxn];
int tl[maxn], tr[maxn], lazy_add[maxn];
vector <int> tmp;

void init () {
	
}

void update (int cnt) {sum[cnt] = sum[tl[cnt]] + sum[tr[cnt]];}

void build (int cnt, int l, int r) {
	if (l == r) return;
	rg mid = l + r >> 1;
	build (tl[cnt] = ++tot, l, mid);
	build (tr[cnt] = ++tot, mid + 1, r);
}

void push_down (int cnt, int l, int r) {
	rg mid = l + r >> 1;
	sum[tl[cnt]] += 1ll * (mid - l + 1) * lazy_add[cnt];
	sum[tr[cnt]] += 1ll * (r - mid) * lazy_add[cnt];
	
	lazy_add[tl[cnt]] += lazy_add[cnt];
	lazy_add[tr[cnt]] += lazy_add[cnt];
	
	lazy_add[cnt] = 0;
}

void add (int cnt, int l, int r, int ql, int qr, int val) {
	if (l >= ql && r <= qr) {
		sum[cnt] += (r - l + 1) * val;
		lazy_add[cnt] += val;
		return;
	}
	push_down (cnt, l, r);
	rg mid = l + r >> 1;
	if (ql <= mid) add (tl[cnt], l, mid, ql, qr, val);
	if (qr > mid) add (tr[cnt], mid + 1, r, ql, qr, val);
	update (cnt);
}

void charming () {
	cin >> n >> m;
	int su = 0;
	tmp.resize (n + 1);
	for (rg i = 1; i <= n; ++i) {
		cin >> val[i];
		tmp[i] = tmp[i - 1];
		if (val[i] != val[i - 1]) ++tmp[i];
		su += tmp[i];
	}
	tmp.clear ();
	build (0, 1, n);
	int var = 1;
	for (rg i = 1; i <= n; ++i) {
		add (0, 1, n, i, i, su);
		su -= 1;
		if (tmp[i + 1] > var) su -= n - i, ++var;
	}
	for (rg i = 1, pos, x; i <= m; ++i) {
		cin >> pos >> x;
		if (val[pos] == x) continue;
		if (val[pos - 1] == val[pos]  && val[pos] == val[pos + 1]) {
			add (0, 1, n, 1, pos - 1, 2 * (n - pos + 1) - 1);
			add (0, 1, n, pos, pos, n - pos);
		}
		else if (val[pos - 1] == val[pos]) {
			if (x != val[pos + 1]) {
				add (0, 1, n, 1, pos - 1, n - pos + 1);
			}
			else {
				add (0, 1, n, 1, pos - 1, 1);
				add (0, 1, n, pos, pos, -(n - pos));
			}
		}
		else if (val[pos + 1] == val[pos]) {
			if (x != val[pos - 1]) {
				add (0, 1, n, 1, pos - 1, n - pos + 1);
				add (0, 1, n, pos, pos, n - pos);
			}
			else {
				add (0, 1, n, 1, pos - 1, -1);
			}
		}
		else if (val[pos + 1] == val[pos - 1]) {
			if (x = val[pos + 1]) {
				add (0, 1, n, 1, pos - 1, - 2 * (n - pos + 1) + 1);
				add (0, 1, n, pos, pos, pos - n);
			}
		}
		else {
			if (x != val[pos - 1]) {
				add (0, 1, n, 1, pos - 1, -(n - pos + 1));
				add (0, 1, n, pos, pos, -(n - pos));
			}
			else if (x != val[pos + 1]) {
				add (0, 1, n, 1, pos - 1, -(n - pos + 1));
			}
		}
		cout << sum[0] << endl;
		val[pos] = x;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}