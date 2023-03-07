#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e2 + 5;
const int mod = 1e9 + 7;

int q, n, m;
int nxt[maxn];
int mov[maxn], dp[maxn];
vector <int> pos;
string s, t;

void init () {
	fill (mov, mov + maxn, INT_MAX);
	fill (dp, dp + maxn, 0);
	pos.clear ();
}

void get_nxt () {
	for (int i = 2, j = 0; i <= m; ++i) {
		while (j && t[i] != t[j + 1]) j = nxt[j];
		if (t[i] == t[j + 1]) ++j;
		nxt[i] = j;
	}
}

void kmp () {
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j && s[i] != t[j + 1]) j = nxt[j];
		if (s[i] == t[j + 1]) ++j;
		if (j == m) {
			pos.emplace_back (i - m + 1);
			j = nxt[j];
		}
	}
}

void charming () {
	init ();
	cin >> s, n = s.size (), s = '#' + s;
	cin >> t, m = t.size (), t = '#' + t;
	get_nxt (), kmp ();
	if (!pos.size ()) {
		cout << 0 << " " << 1 << endl;
		return;
	}
	mov[0] = dp[0] = 1;
	for (int i = 1; i < pos.size (); ++i) {
		if (pos[i] > pos[0] + m - 1) break;
		else mov[i] = 1, dp[i] = 1;
	}
	for (int i = 0; i < pos.size (); ++i) {
		int j = i + 1;
		while (j < pos.size () && pos[j] <= pos[i] + m - 1) ++j;
		for (int k = j; k < pos.size (); ++k) {
			if (pos[k] > pos[j] + m - 1) break;
			if (mov[k] > mov[i] + 1) {
				mov[k] = mov[i] + 1;
				dp[k] = dp[i];
			}
			else if (mov[k] == mov[i] + 1) dp[k] = (dp[k] + dp[i]) % mod;
		}
	}
	int ans_mov = 0, ans_dp = 0;
	for (int i = pos.size () - 1; i >= 0; --i) {
		if (pos[i] + m - 1 < pos.back ()) break;
		if (mov[i] < ans_mov || !ans_mov) {
			ans_mov = mov[i];
			ans_dp = dp[i];
		}
		else if (mov[i] == ans_mov) ans_dp = (ans_dp + dp[i]) % mod;
	}
	cout << ans_mov << " " << ans_dp << endl;
}

signed main () {
	cin >> q;
	while (q--) charming ();
	return 0;
}