#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int b[maxn], ans[maxn];
vector <int> revb[maxn];

void init () {
	for (int i = 0; i <= n + 1; ++i) 
	revb[i].clear ();
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		revb[b[i]].emplace_back (i);
	}
	int now = (revb[0].size () ? 0 : n + 1), nxt;
	int cnt = 0, id;
	int down = -1, up = INT_MAX;
	int st = now ? 1 : 0;
	while (cnt < n) {
		id = -1;
		for (int i = 0; i < revb[now].size (); ++i) {
			ans[++cnt] = revb[now][i];
			if (revb[revb[now][i]].size ()) {
				id = cnt;
				nxt = revb[now][i];
			}
			if (st) down = max (down, revb[now][i]);
			else up = min (up, revb[now][i] - 1);
		}
		if (id == -1) break;
		swap (ans[cnt], ans[id]);
		now = nxt;
		st ^= 1;
	}
	if (down != -1) cout << down << endl;
	else if (up != INT_MAX) cout << up << endl;
	else cout << (revb[n + 1].size () ? n : 0) << endl;
	for (int i = 1; i <= n; ++i)
	cout << ans[i] << " \n"[i == n];
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}