#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct SegmentTree {
	int n;
	vector <int> sum, mn, lazy;
	
	SegmentTree (int n, int type) {
		this -> n = n;
		if (type == 0) this -> sum = this -> lazy = vector <int> (n << 2 | 1);
		else this -> mn = vector <int> (n << 2 | 1);
	}
	
	void PushDown (int rt, int l, int mid, int r) {
		if (!lazy[rt]) return;
		sum[rt << 1] += (mid - l + 1) * lazy[rt];
		sum[rt << 1 | 1] += (r - mid) * lazy[rt];
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
	
	void Modify_add (int rt, int l, int r, int ql, int qr, int k) {
		if (l >= ql && r <= qr) {
			sum[rt] += k;
			lazy[rt] += k;
			return;
		}
		int mid = l + r >> 1;
		PushDown (rt, l, mid, r);
		if (ql <= mid) Modify_add (rt << 1, l, mid, ql, qr, k);
		if (qr > mid) Modify_add (rt << 1 | 1, mid + 1, r, ql, qr, k);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
	
	void Modify_set (int rt, int l, int r, int p, int k) {
		if (l == r) {mn[rt] = k; return;}
		int mid = l + r >> 1;
		if (p <= mid) Modify_set (rt << 1, l, mid, p, k);
		else Modify_set (rt << 1 | 1, mid + 1, r, p, k);
		mn[rt] = min (mn[rt << 1], mn[rt << 1 | 1]);
	}
	
	int Query_sum (int rt, int l, int r, int p) {
		if (l == r) return sum[rt];
		int mid = l + r >> 1;
		PushDown (rt, l, mid, r);
		if (p <= mid) return Query_sum (rt << 1, l, mid, p);
		else return Query_sum (rt << 1 | 1, mid + 1, r, p);
	}
	
	int Query_mn (int rt, int l, int r, int ql, int qr) {
		if (l >= ql && r <= qr) return mn[rt];
		int mid = l + r >> 1, ans = LLONG_MAX;
		if (ql <= mid) ans = min (ans, Query_mn (rt << 1, l, mid, ql, qr));
		if (qr > mid) ans = min (ans, Query_mn (rt << 1 | 1, mid + 1, r, ql, qr));
		return ans;
	}
};

int n, q;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), ans (n + 5);
	SegmentTree Tree (n, 0), Asc (n, 1), Desc (n, 1), Low1 (n, 1), Low2 (n, 1);
	for (int i = 1; i <= n; ++i) cin >> a[i], Tree.Modify_add (1, 1, n, i, i, a[i]);
	set <int> good;
	ll sum = 0;
	
	auto Update = [&] (int id) -> int {
		if (id >= n) return 0;
		int now = Tree.Query_sum (1, 1, n, id);
		int left = Tree.Query_sum (1, 1, n, id - 1);
		int right = Tree.Query_sum (1, 1, n, id + 1);
		if (id == 1) left = now;
		int old_ans = ans[id], delta = abs (right - now) - ans[id];
		ans[id] = old_ans + delta;
		if (now >= left && now >= right) {
			Asc.Modify_set (1, 1, n, id, LLONG_MAX);
			Desc.Modify_set (1, 1, n, id, LLONG_MAX);
			Low1.Modify_set (1, 1, n, id, LLONG_MAX);
			Low2.Modify_set (1, 1, n, id, LLONG_MAX); 
			good.insert (id);
		}
		else if (now >= left) {
			Asc.Modify_set (1, 1, n, id, right - now);
			Desc.Modify_set (1, 1, n, id, LLONG_MAX);
			Low1.Modify_set (1, 1, n, id, LLONG_MAX);
			Low2.Modify_set (1, 1, n, id, LLONG_MAX); 
			if (good.count (id)) good.erase (id);  
		}
		else if (now >= right) {
			Asc.Modify_set (1, 1, n, id, LLONG_MAX);
			Desc.Modify_set (1, 1, n, id, left - now);
			Low1.Modify_set (1, 1, n, id, LLONG_MAX);
			Low2.Modify_set (1, 1, n, id, LLONG_MAX); 
			if (good.count (id)) good.erase (id);
		}
		else {
			Asc.Modify_set (1, 1, n, id, LLONG_MAX);
			Desc.Modify_set (1, 1, n, id, LLONG_MAX);
			Low1.Modify_set (1, 1, n, id, left + right - 2 * now);
			Low2.Modify_set (1, 1, n, id, min (left - now, right - now)); 
			if (good.count (id)) good.erase (id);
		}
		return delta;
	};
	
	cin >> q;
	for (int i = 1; i < n; ++i) sum += Update (i);
	for (int i = 1, opt, l, r, x, mn1, mn2, mn3; i <= q; ++i) {
		cin >> opt >> l >> r >> x;
		if (opt == 1) {
			auto id = good.lower_bound (l);
			if (id != good.end () && *id <= r) cout << sum + x * 2 << endl;
			else {
				mn1 = min (Asc.Query_mn (1, 1, n, l, r), Desc.Query_mn (1, 1, n, l, r));
				mn2 = Low1.Query_mn (1, 1, n, l, r); 
				mn3 = Low2.Query_mn (1, 1, n, l, r); 
				if (mn1 < LLONG_MAX) cout << sum + max (0ll, 2 * max (x - mn1, max (x - mn2, -mn3))) << endl;
				else cout << sum + 2 * max ({-x, x - mn2, -mn3}) << endl;
			}
		}
		else {
			Tree.Modify_add (1, 1, n, l, r, x);
			sum += Update (l - 1), sum += Update (l);
			sum += Update (r), sum += Update (r + 1); 
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