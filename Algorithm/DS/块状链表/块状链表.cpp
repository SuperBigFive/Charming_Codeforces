#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e3 + 5;
const int MN_LEN = 5e2 + 5;
const int MX_LEN = 5e3 + 5;

int n, m, tot, tail;
int a[N], bel[N];
int ele[M][MX_LEN << 1];
struct List {
	int siz, sum, pre, nxt;
	int ele_id;
	void add (int x) {ele[ele_id][++siz] = x, sum += a[x];}
	void erase (int id) {
		int p = 1;
		while (p < siz && ele[ele_id][p] != id) ++p;
		for (int i = p; i < siz; ++i)
		ele[ele_id][i] = ele[ele_id][i + 1];
		--siz, sum -= a[id];
	}
}lis[M];


void init () {
	tot = tail = 1; 
	lis[tail].siz = lis[tail].sum = 0; 
	lis[tail].pre = 0; lis[tail].nxt = -1;
	lis[tail].ele_id = tail;
}

void charming () {
	init ();
	
	cin >> n >> m;
	
	auto CreatList = [] (int id) -> int {
		lis[++tot].pre = id, lis[tot].nxt = lis[id].nxt;
		if (lis[id].nxt != -1) lis[lis[id].nxt].pre = tot;
		lis[id].nxt = tot;
		lis[tot].siz = lis[tot].sum = 0;
		if (lis[tot].nxt == -1) tail = tot;
		lis[tot].ele_id = tot;
		return tot;
	};
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (lis[tail].siz >= MX_LEN - MN_LEN)
		bel[i] = CreatList (tail);
		else bel[i] = tail;
		lis[tail].add (i);
	};
	
	auto get_l_id = [&] (int id) -> int {
		int p = 1;
		while (p != bel[id]) 
		p = lis[p].nxt;
		return p;
	};
	
	auto merge = [&] (int lpre, int l_id) -> void {
		for (int i = 1; i <= lis[l_id].siz; ++i) {
			lis[lpre].add (ele[lis[l_id].ele_id][i]);	
			bel[ele[lis[l_id].ele_id][i]] = lpre;		
		}
		lis[lpre].nxt = lis[l_id].nxt;
		lis[lis[l_id].nxt].pre = lpre;
	};
	
	auto split = [&] (int l_id) -> void {
		int nl_id = CreatList (l_id), nsiz = (lis[l_id].siz + 1) / 2;
		for (int i = nsiz + 1; i <= lis[l_id].siz; ++i) {
			lis[l_id].sum -= a[ele[lis[l_id].ele_id][i]];
			lis[nl_id].add (ele[lis[l_id].ele_id][i]);
			bel[ele[lis[l_id].ele_id][i]] = nl_id;
		}
		lis[l_id].siz = nsiz;
	};
	
	auto move = [&] (int id_x, int id_y) -> void {
		int l_id_x = get_l_id (id_x);
		lis[l_id_x].erase (id_x);
		if (lis[l_id_x].siz < MN_LEN) {
			if (lis[l_id_x].pre) {
				int lpre = lis[l_id_x].pre;
				if (lis[lpre].siz + lis[l_id_x].siz > MX_LEN) {
					split (lpre);
					merge (lis[l_id_x].pre, l_id_x);
				}
				else merge (lis[l_id_x].pre, l_id_x);
			}
			else if (lis[l_id_x].nxt != -1) {
				int lnxt = lis[l_id_x].nxt;
				if (lis[lnxt].siz + lis[l_id_x].siz > MX_LEN) {
					split (lnxt);
					merge (l_id_x, lis[l_id_x].nxt);
				}
				else merge (l_id_x, lnxt);
			}
		}
		int p = 1, l_id_y = get_l_id (id_y);
		while (ele[lis[l_id_y].ele_id][p] != id_y) ++p;
		++lis[l_id_y].siz;
		for (int i = lis[l_id_y].siz; i > p; --i)
		ele[lis[l_id_y].ele_id][i] = ele[lis[l_id_y].ele_id][i - 1];
		ele[lis[l_id_y].ele_id][p] = id_x;
		lis[l_id_y].sum += a[id_x];
		bel[id_x] = l_id_y;
		if (lis[l_id_y].siz > MX_LEN) split (l_id_y);
	};
	
	auto modify = [&] (int id, int val) -> void {
		lis[bel[id]].sum -= a[id] - val;
		a[id] = val;
	};
	
	auto query_pos = [&] (int id) -> int {
		int l_id = get_l_id (id);
		int p = lis[l_id].pre, ans = 0;
		while (p) ans += lis[p].siz, p = lis[p].pre;
		p = 1;
		while (p <= lis[l_id].siz && ele[lis[l_id].ele_id][p] != id) ++ans, ++p;
		return ans;
	};
	
	auto query_id = [&] (int x) -> int {
		int p = 1;
		while (lis[p].siz < x) x -= lis[p].siz, p = lis[p].nxt;
		return ele[lis[p].ele_id][x];
	};
	
	auto query_sum = [&] (int x, int y) -> int {
		int id_x = query_id (x), id_y = query_id (y);
		int l_id_x = get_l_id (id_x);
		int l_id_y = get_l_id (id_y);
		int ans = 0;
		if (l_id_x == l_id_y) {
			int p = 1;
			while (ele[lis[l_id_x].ele_id][p] != id_x) ++p;
			while (ele[lis[l_id_x].ele_id][p] != id_y) ans += a[ele[lis[l_id_x].ele_id][p++]];
			ans += a[id_y];
		}
		else {
			int p = 1;
			while (ele[lis[l_id_x].ele_id][p] != id_x) ans += a[ele[lis[l_id_x].ele_id][p++]];
			ans = lis[l_id_x].sum - ans;
			p = 1;
			while (ele[lis[l_id_y].ele_id][p] != id_y) ans += a[ele[lis[l_id_y].ele_id][p++]];
			ans += a[id_y];
			p = lis[l_id_x].nxt;
			while (p != l_id_y) ans += lis[p].sum, p = lis[p].nxt;
		}
		return ans;
	};
	
	for (int i = 1, opt, x, y; i <= m; ++i) {
		cin >> opt >> x;
		if (opt == 1) {
			cin >> y;
			move (x, y);
		} else if (opt == 2) {
			cin >> y;
			modify (x, y);
		} else if (opt == 3) {
			cout << query_pos (x) << endl;
		} else if (opt == 4) {
			cout << query_id (x) << endl;
		} else {
			cin >> y;
			cout << query_sum (x, y) << endl;
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
