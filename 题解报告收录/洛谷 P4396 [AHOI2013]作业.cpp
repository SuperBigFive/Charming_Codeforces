#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

struct Query {
	int l, r;
	int a, b;
	int tot;
}q[maxn];
int n, m, blo;
int arr[maxn], cnt[maxn];
int bel[maxn], kind[maxn], sum[maxn];
pair <int, int> ans[maxn];

void init () {}

pair <int, int> force (int a, int b) {
	pair <int, int> tmp;
	tmp.first = tmp.second = 0;
	for (int i = a; i <= b; ++i) {
		if (cnt[i]) ++tmp.second;
		tmp.first += cnt[i];
	}
	return tmp;
}

void get_ans (int id, int a, int b) {
	int bela = bel[a], belb = bel[b];
	if (bela == belb || bela == belb - 1)	{
		ans[id] = force (a, b);
		return;
	}
	pair <int, int> tmp1, tmp2;
	int ena = bela * blo, enb = (belb - 1) * blo + 1;
	tmp1 = force (a, ena);
	tmp2 = force (enb, b);
	ans[id].first = tmp1.first + tmp2.first;
	ans[id].second = tmp1.second + tmp2.second;
	for (int i = bela + 1; i < belb; ++i) {
		ans[id].first += sum[i];
		ans[id].second += kind[i];
	}
}

void del (int id) {
	--cnt[arr[id]];
	if (cnt[arr[id]] == 0) --kind[bel[arr[id]]];
	--sum[bel[arr[id]]];
}

void add (int id) {
	++cnt[arr[id]];
	if (cnt[arr[id]] == 1) ++kind[bel[arr[id]]];
	++sum[bel[arr[id]]];
}
	
void charming () {
	cin >> n >> m;
	blo = sqrt (maxn);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		bel[i] = (i - 1) / blo + 1;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> q[i].l >> q[i].r;
		cin >> q[i].a >> q[i].b;
		q[i].tot = i;
	}
	sort (q + 1, q + 1 + m, [] (Query &x, Query &y) {
		if (bel[x.l] != bel[y.l]) return bel[x.l] < bel[y.l];
		return bel[x.r] < bel[y.r];
	});
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i) {
		int ql = q[i].l, qr = q[i].r;
		while (r < qr) add (++r);
		while (r > qr) del (r--);
		while (l < ql) del (l++);
		while (l > ql) add (--l);
		get_ans (q[i].tot, q[i].a, q[i].b);
	}
	for (int i = 1; i <= m; ++i) 
	cout << ans[i].first << " " << ans[i].second << endl;
}

signed main () {
	charming ();
	return 0;
}