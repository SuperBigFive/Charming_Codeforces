#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n;
pii val[maxn];
int cnt_small[maxn], cnt_big[maxn], cnt[maxn];
int pos_big[maxn], pos_small[maxn], st[maxn << 1];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i].fi;
		val[i].se = i;
	}
	sort (val + 1, val + 1 + n, [] (pii a, pii b) {
		return a.fi < b.fi;
	});
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > n / 2) st[val[i].se] = 1, res += val[i].fi;
		else st[val[i].se] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cnt_small[i] = cnt_small[i - 1];
		cnt_big[i] = cnt_big[i - 1];
		if (st[i]) ++cnt_big[i];
		else ++cnt_small[i];
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i] = cnt_big[i] - cnt_small[i];
	}
	int idx = 0, tmp = -100;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] > tmp) {
			idx = i;
			tmp = cnt[i];
		}
	}
	cout << idx - 1 << ' ' << res << endl;
}

signed main () {
	//freopen ("input.in","r", stdin);
	charming ();
	return 0;
}