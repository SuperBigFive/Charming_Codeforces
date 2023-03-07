#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 3e5 + 5;

int n, k, rt, tot;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	int f2 = 31;
	while (!((k >> f2) & 1) && f2) --f2;
	vector <int> a (n + 5);
	map <int, int> rev;
	map <int, vector <int> > s;
	for (int i = 1, b; i <= n; ++i) {
		cin >> a[i], b = a[i];
		for (int j = 0; j <= f2; ++j)
		if ((b >> j) & 1) b -= (1 << j);
		s[b].emplace_back (a[i]);
		rev[a[i]] = i;
	}
	if (k == 0) {
		cout << n << endl;
		for (int i = 1; i <= n; ++i)
		cout << i << " \n"[i == n];
		return;
	}
	vector <int> ans, key (n << 5);
	vector <array <int, 2> > nxt (n << 5);
	for (auto it : s) {
		rt = ++tot;
		for (auto val : it.second) {
			int cur = rt;
			key[cur] = val;
			for (int i = f2, chk; i >= 0; --i) {
				chk = (val >> i) & 1;
				if (!nxt[cur][chk]) nxt[cur][chk] = ++tot;
				cur = nxt[cur][chk];
				key[cur] = val;
			}
		}
		bool ok = false;
		for (auto val : it.second) {
			int cur = rt;
			for (int i = f2, chk1, chk2; i >= 0; --i) {
				chk1 = (val >> i) & 1, chk2 = (k >> i) & 1;
				if (i == 0 && (key[cur] ^ val) >= k) {
					ok = true;
					ans.emplace_back (val);
					ans.emplace_back (key[cur]);
					break;
				}
				else if (nxt[cur][chk1 ^ 1] && !chk2) {
					ok = true;
					ans.emplace_back (val);
					ans.emplace_back (key[nxt[cur][chk1 ^ 1]]);
					break;
				}
				else if (!nxt[cur][chk1 ^ 1] && chk2) break;
				else if (chk2) cur = nxt[cur][chk1 ^ 1];
				else cur = nxt[cur][chk1];
			}
			if (ok) break;
		}
		if (!ok) ans.emplace_back (it.second[0]);
	}
	if (ans.size () < 2) return void (cout << -1 << endl);
	cout << ans.size () << endl;
	for (int i = 0; i < ans.size (); ++i)
	cout << rev[ans[i]] << " \n"[i == ans.size () - 1];
}

signed main () {
	charming ();
	return 0;
}