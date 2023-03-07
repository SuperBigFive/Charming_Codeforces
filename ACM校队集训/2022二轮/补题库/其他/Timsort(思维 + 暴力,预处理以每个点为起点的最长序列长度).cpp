#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int, int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 2e5 + 5;

int n, q, ql;
int val[maxn];
int inc_[maxn], dec_[maxn], len[maxn];
vector <pii> ans;

void init () {
	
}

void get_len () {
	val[n + 1] = val[n] - 1;
	for (int i = n; i >= 1; --i) {
		if (val[i] <= val[i + 1]) {
			inc_[i] = inc_[i + 1] + 1;
		}
		else inc_[i] = 0;
	}
	val[n + 1] = val[n] + 1;
	for (int i = n; i >= 1; --i) {
		if (val[i] > val[i + 1]) {
			dec_[i] = dec_[i + 1] + 1;
		}
		else dec_[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		len[i] = max (dec_[i], inc_[i]);
	}
}

void get_ans () {
	int j, res1, res2;
	for (int i = 1; i <= n; ++i) {
		j = 1, res1 = res2 = 0;
		while (j <= n) {
			++res1;
			if (len[j] + 1 >= i || j + len[j] + 1 > n) j += len[j] + 1;
			else {
				res2 += min (i - len[j] - 1, n - j - len[j]);
				j += i;
			}
		}
		ans.pb ({res1, res2});
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	get_len ();
	get_ans ();
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> ql;
		if (ql > n) ql = n;
		cout << ans[ql - 1].fi << ' ' << ans[ql - 1].se << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
} 