#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Event {
	int a, b, c;
	int cnt, id;
};

int n, k;
int node[N], ans[N], rev[N];

void init () {}

int lowbit (int x) {return x & -x;}

void add (int x, int k) {
	while (x < N) {
		node[x] += k;
		x += lowbit (x);
	}
}

int query (int x) {
	int ans = 0;
	while (x) ans += node[x], x -= lowbit (x);
	return ans;
}

void cdq (int l, int r, vector <Event> e) {
	if ((int) e.size () == 0) return;
	if (l == r) {
		sort (e.begin (), e.end (), [] (Event &x,
		Event &y) {return x.b < y.b;});
		for (int i = 0, j; i < e.size (); i = j + 1) {
			j = i;
			add (e[j].c, e[j].cnt);
			while (j + 1 < e.size () && e[j + 1].b == e[j].b) {
				++j, add (e[j].c, e[j].cnt);
			}
			for (int k = i; k <= j; ++k)
			ans[e[k].id] += query (e[k].c) - e[k].cnt;
		}
		for (int i = 0; i < e.size (); ++i)
		add (e[i].c, -e[i].cnt);
		return;	
	}
	int mid = l + r >> 1;
	vector <Event> gol, gor;
	for (int i = 0; i < e.size (); ++i) {
		if (e[i].a <= mid) gol.emplace_back (e[i]);
		else gor.emplace_back (e[i]);
	}
	vector <pair <int, int> > stk;
	sort (gol.begin (), gol.end (), [] (Event &x,
	Event &y) {return x.b < y.b;});
	sort (gor.begin (), gor.end (), [] (Event &x,
	Event &y) {return x.b < y.b;});
	for (int i = 0, p = 0; i < gor.size (); ++i) {
		while (p < gol.size () && gol[p].b <= gor[i].b) {
			add (gol[p].c, gol[p].cnt);
			stk.emplace_back (gol[p].c, -gol[p].cnt);
			++p;
		}
		ans[gor[i].id] += query (gor[i].c);
	}
	while ((int) stk.size () > 0) {
		auto [pos, val] = stk.back ();
		add (pos, val);
		stk.pop_back ();
	}
	cdq (l, mid, gol);
	cdq (mid + 1, r, gor);
}

void charming () {
	init ();
	cin >> n >> k;	
	int old_n = n;
	map <array <int, 3>, int> ID;
	vector <Event> event;
	for (int i = 1, a, b, c, nid; i <= n; ++i) {
		cin >> a >> b >> c;
		array <int, 3> e = {a, b, c};
		if (ID.count (e)) event[ID[e]].cnt += 1;
		else {
			nid = ID.size (), ID[e] = nid;
			event.emplace_back ((Event) {a, b, c, 1, nid});
		}
	}
	n = ID.size ();
	cdq (1, N, event);
	for (int i = 0; i < n; ++i) {
		ans[event[i].id] += event[i].cnt - 1;
		rev[ans[event[i].id]] += event[i].cnt;
	}
	for (int i = 0; i < old_n; ++i) cout << rev[i] << endl;
}

signed main () {
	charming ();
	return 0;
}