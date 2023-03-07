#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int n, m;
int c[maxn];
int lowbit (int x) {return x & -x;}

void add (int val, int pos) {
	int x = pos;
	while (x <= n) {
		c[x] += val;
		x += lowbit (x);
	}
}

int get_sum (int pos) {
	int res = 0;
	while (pos) {
		res += c[pos];
		pos -= lowbit (pos);
	}
	return res;
}

void charming () {
	cin >> n >> m;
	int val;
	for (int i = 1; i <= n; ++i) {
		cin >> val;
		add (val, i);
	}
	int opt, l, r, pos, k;
	for (int i = 1; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> pos >> k;
			add (k, pos);
		}
		else {
			cin >> l >> r;
			cout << get_sum (r) - get_sum (l - 1) << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}