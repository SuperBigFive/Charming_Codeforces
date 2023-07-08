#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n, w, m;
int val[maxn], sum[maxn], sub[maxn];
bool vis[10];
string s;
vector <int> pos[10];

void init () {
	for (int i = 0; i < 10; ++i) pos[i].clear ();
}

void charming () {
	init ();
	cin >> s;
	for (int i = 1; i <= s.length (); ++i) {
		val[i] = s[i - 1] - '0';
		sum[i] = sum[i - 1] + val[i];
	}
	cin >> w >> m;
	for (int i = 1; i <= s.length (); ++i) if (i >= w) {
		sub[i - w + 1] = (sum[i] - sum[i - w]) % 9;
		pos[sub[i - w + 1]].emplace_back (i - w + 1);
	}
	int seq[10];
	for (int i = 0; i < 9; ++i) seq[i] = i;
	sort (seq, seq + 9, [] (int &a, int &b) {
		if (!pos[a].size ()) return false;
		if (!pos[b].size ()) return true;
		return pos[a][0] < pos[b][0];
	});
	int v1, v2, v3;
	bool ok;
	for (int i = 1, l, r, k; i <= m; ++i) {
		cin >> l >> r >> k;
		fill (vis, vis + 10, false);
		v2 = sum[r] - sum[l - 1];
		ok = false;
		for (int j = 0; j < 9 && !ok; ++j) {
			v1 = seq[j];
			if (!pos[v1].size ()) continue;
			v3 = ((k - (v1 * v2)) % 9 + 9) % 9;
			if (pos[v3].size()) {
				ok = true;
				if (v3 != v1) cout << pos[v1][0] << " " << pos[v3][0] << endl;
				else if (pos[v1].size () > 1) cout << pos[v1][0] << " " << pos[v3][1] << endl;
				else ok = false;
			}
		}
		if (!ok) cout << -1 << " " << -1 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}