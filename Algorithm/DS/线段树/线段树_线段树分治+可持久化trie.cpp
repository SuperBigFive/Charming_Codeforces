#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Bring {
	int day, id, val;
}bring[N];
struct Buy {
	int l, r, tl, tr, x;
}buy[N];

int n, m, cnt0, cnt1, tot;
int good[N], ans[N], stk[N];
int rt[N], siz[N * 20], ch[N * 20][2];
vector <int> node[N << 2];

void init () {}

void insert (int &nrt, int pre, int val) {
	nrt = ++tot;
	int cur = nrt;
	for (int i = 20, chk; i >= 0; --i) {
		chk = (val >> i) & 1;
		ch[cur][chk ^ 1] = ch[pre][chk ^ 1];
		cur = ch[cur][chk] = ++tot;
		pre = ch[pre][chk];
		siz[cur] = siz[pre] + 1;
	}
}

int query (int rt_l, int rt_r, int x) {
	int res = 0;
	for (int i = 20, target; i >= 0; --i) {
		target = ((x >> i) & 1) ^ 1;
		if (siz[ch[rt_r][target]] > siz[ch[rt_l][target]]) {
			rt_l = ch[rt_l][target];
			rt_r = ch[rt_r][target];
			res += (1 << i);
		} else {
			rt_l = ch[rt_l][target ^ 1];
			rt_r = ch[rt_r][target ^ 1];
		}
	}
	return res;
}

void modify (int rt_, int l, int r, int tl, int tr, int id) {
	if (l >= tl && r <= tr) {
		node[rt_].emplace_back (id);
		return;
	}
	int mid = l + r >> 1;
	if (tl <= mid) modify (rt_ << 1, l, mid, tl, tr, id);
	if (tr > mid) modify (rt_ << 1 | 1, mid + 1, r, tl, tr, id);
}

void calc (int rt_, int sl, int sr) {
	tot = 0;
	int cnt = 0;
	for (int i = sl; i <= sr; ++i) {
		stk[++cnt] = bring[i].id;
		insert (rt[cnt], rt[cnt - 1], bring[i].val);
	}
	for (auto id : node[rt_]) {
		int l = upper_bound (stk + 1, stk + 1 + cnt, buy[id].l - 1) - stk - 1;
		int r = upper_bound (stk + 1, stk + 1 + cnt, buy[id].r) - stk - 1;
		ans[id] = max (ans[id], query (rt[l], rt[r], buy[id].x));
	}
}

void divide (int rt_, int tl, int tr, int sl, int sr) {
	if (sl > sr) return;
	calc (rt_, sl, sr);
	vector <Bring> left, right;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	for (int i = sl; i <= sr; ++i) {
		if (bring[i].day <= mid) left.emplace_back (bring[i]);
		else right.emplace_back (bring[i]);
	}
	for (int i = 0; i < left.size (); ++i)
	bring[i + sl] = left[i];
	for (int i = 0; i < right.size (); ++i)
	bring[i + sl + left.size ()] = right[i];
	divide (rt_ << 1, tl, mid, sl, sl + left.size () - 1);
	divide (rt_ << 1 | 1, mid + 1, tr, sl + left.size (), sr);
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> good[i];
		insert (rt[i], rt[i - 1], good[i]);
	}
	for (int i = 1, opt, d; i <= m; ++i) {
		cin >> opt;
		if (opt == 0) {
			cin >> bring[++cnt0].id >> bring[cnt0].val;
			bring[cnt0].day = cnt0;
		} else {
			cin >> buy[++cnt1].l >> buy[cnt1].r >> buy[cnt1].x >> d;
			buy[cnt1].tl = max (cnt0 - d + 1, 1ll), buy[cnt1].tr = cnt0;
			ans[cnt1] = query (rt[buy[cnt1].l - 1], rt[buy[cnt1].r], buy[cnt1].x);
		}
	}
	sort (bring + 1, bring + 1 + cnt0, [] (Bring &a,
	Bring &b) {return a.id < b.id;});
	for (int i = 1; i <= cnt1; ++i) if (buy[i].tl <= buy[i].tr)
	modify (1, 1, cnt0, buy[i].tl, buy[i].tr, i);
	divide (1, 1, cnt0, 1, cnt0);
	for (int i = 1; i <= cnt1; ++i) cout << ans[i] << endl;
}

signed main () {
	charming ();
	return 0;
}