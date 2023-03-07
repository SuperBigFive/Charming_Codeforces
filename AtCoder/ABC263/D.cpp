#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 2e5 + 5;

ll n, l, r;
ll val[maxn];
struct dec {
	int en;
	int diff;
	bool operator < (const dec &a) const {
		return diff < a.diff;
	}
}dec_r[maxn], dec_l[maxn];

void init () {
	
}

void get_dec_l () {
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += val[i];
		dec_l[i].diff = l * i - sum;
		dec_l[i].en = i;
	}
}

void get_dec_r () {
	ll sum = 0;
	for (int i = n; i >= 1; --i) {
		sum += val[i];
		dec_r[i].diff = r * (n - i + 1) - sum;
		dec_r[i].en = i;
	}
}

void charming () {
	init ();
	cin >> n >> l >> r;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		sum += val[i];
	}
	get_dec_l ();
	get_dec_r ();
	int p = 1;
	ll res = sum;
	if (l < r) {
		dec_r[n + 1].diff = 0;
		dec_r[n + 1].en = n + 1;
		sort (dec_r + 1, dec_r + 1 + n + 1);
		for (int i = 0; i <= n; ++i) {
			while (dec_r[p].en <= i && p <= n + 1) ++p;
			if (sum + dec_l[i].diff + dec_r[p].diff < res) {
				res = sum + dec_l[i].diff + dec_r[p].diff;
			}
		}
	}
	else {
		dec_l[n + 1].diff = 0;
		dec_l[n + 1].en = 0;
		sort (dec_l + 1, dec_l + 1 + n + 1);
		for (int i = n + 1; i >= 1; --i) {
			while (dec_l[p].en >= i && p <= n + 1) ++p;
			if (sum + dec_r[i].diff + dec_l[p].diff < res) {
				res = sum + dec_r[i].diff + dec_l[p].diff;
			}
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}