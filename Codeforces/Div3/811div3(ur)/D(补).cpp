#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 1e3 + 5;

int q, n, lent;
int lens[maxn], nxt[maxn], nxt_id[maxn];
char t[maxn], s[20][maxn];
vector <pii> res;

void init () {
	res.clear ();
	memset (lens, 0, sizeof lens);
	memset (nxt, 0, sizeof nxt);
	memset (nxt_id, 0, sizeof nxt_id);
}

void charming () {
	init ();
	cin >> t + 1;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] + 1;
		lens[i] = strlen (s[i] + 1);
	}
	int lent = strlen (t + 1), mr, id;
	for (int i = 1; i <= lent; ++i) {
		mr = -1;
		for (int j = 1; j <= n; ++j) {
			if (i + lens[j] - 1 > lent) continue;
			bool ok = true;
			for (int k = 1; k <= lens[j]; ++k) {
				if (t[i + k - 1] != s[j][k]) {
					ok = false;
					break;
				}
			}
			if (!ok) continue;
			if (mr < lens[j]) {
				mr = lens[j];
				nxt[i] = i + lens[j] - 1;
				nxt_id[i] = j;
			}
		}
	}
	if (!nxt[1]) {
		cout << -1 << endl;
		return;
	}
	int ans = 1;
	res.pb ({nxt_id[1], 1});
	mr = nxt[1];
	for (int i = 1; i <= lent && mr < lent; i = id) {
		mr = nxt[i];
		for (int j = i + 1; j <= nxt[i] + 1; ++j) {
			if (mr < nxt[j]) {
				mr = nxt[j];
				id = j;
			}
		}
		if (mr == nxt[i]) {
			cout << -1 << endl;
			return;
		}
		res.pb ({nxt_id[id], id});
		++ans;
	}
	cout << ans << endl;
	for (auto it : res) {
		cout << it.fi << ' ' << it.se << endl;
	}
}

signed main () {
	cin >> q;
	while (q--) charming ();
	return 0;
}