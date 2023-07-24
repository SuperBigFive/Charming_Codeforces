#include <bits/stdc++.h>
#define ll long long
#define int ll
#define double long double
using namespace std;
const int N = 1e5 + 5;
const int M = 5e4 + 5;
double eps = 1e-10;

struct Seg {
	double k, b;
	Seg (double k = -100, double b = -1e5) : k (k), b (b) {}
	double Calc (int x) {return k * (x - 1) + b;}
}seg[N];

struct LiChao_SegmentTree {
	int n;
	vector <int> node;
	
	LiChao_SegmentTree (int n) {
		this -> n = n;
		this -> node = vector <int> (n << 2 | 1);
	}
	
	void Insert (int rt, int l, int r, int id) {
		int mid = l + r >> 1;
		if (seg[node[rt]].Calc (mid) < seg[id].Calc (mid)) swap (node[rt], id);
		int chk_l = (seg[id].Calc (l) > seg[node[rt]].Calc (l));
		int chk_r = (seg[id].Calc (r) > seg[node[rt]].Calc (r));
		if (chk_l) Insert (rt << 1, l, mid, id);
		if (chk_r) Insert (rt << 1 | 1, mid + 1, r, id);  
	}
	
	double Query (int rt, int l, int r, int p) {
		double ans = seg[node[rt]].Calc (p), nans;
		if (l == r) return ans;
		int mid = l + r >> 1;
		if (p <= mid) nans = Query (rt << 1, l, mid, p);
		else nans = Query (rt << 1 | 1, mid + 1, r, p);
		ans = max (ans, nans);
		return ans;
	}	
};

int n;

void init () {}

void charming () {
	init ();
	cin >> n;	
	string opt;
	LiChao_SegmentTree LiChao (M);
	double S, P;
	for (int i = 1, T, cnt = 0; i <= n; ++i) {
		cin >> opt;
		if (opt[0] == 'Q') {
			cin >> T;
			if (cnt == 0) cout << 0 << endl;
			else cout << max (0ll, (int) (LiChao.Query (1, 1, M, T) + eps) / 100) << endl;
		}
		else {
			cin >> S >> P;
			seg[++cnt] = {P, S};
			LiChao.Insert (1, 1, M, cnt); 
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
