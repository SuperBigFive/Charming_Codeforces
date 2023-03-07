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
int a[maxn], b[maxn], c[maxn];
int lowbit (int x) {return x & -x;}

void addb (int pos, int val) {
	int x = pos;
	while (x && x <= n) {
		b[x] += val;
		x += lowbit (x);
	}
}

int get_val (int pos) {
	int res = 0;
	int x = pos;
	while (x) {
		res += b[x];
		x -= lowbit (x);
	}
	return res;
}

void addc (int pos, int val) {
	int x = pos;
	while (x <= n) {
		c[x] += val;
		x += lowbit (x);
	}
}

int get_sumc (int pos) {
	int res = 0;
	while (pos) {
		res += c[pos];
		pos -= lowbit (pos);
	}
	return res;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		addb (i, a[i] - a[i - 1]);
		addc (i, a[i]);
	}
	int opt, l, r, pos, k;
	for (int i = 1; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> l >> r >> k;
			addb (l, k);
			addb (r + 1, -k);
		}
		else {
			cin >> pos;
			cout << get_val (pos) << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}