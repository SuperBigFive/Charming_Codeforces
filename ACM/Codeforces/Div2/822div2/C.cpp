#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int q, n;
int cost[maxn], nxt[maxn];
char t[maxn];
vector <int> pre[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		cost[i] = i, nxt[i] = i;
		pre[i].clear (), pre[i].emplace_back (i);
	}
}

void charming () {
	cin >> n;
	init ();
	cin >> t + 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (t[i] != '0') continue;
		res += cost[i];
		for (auto it : pre[i]) {
			nxt[it] += it;
			pre[nxt[it]].emplace_back (it);
			cost[nxt[it]] = min (cost[nxt[it]], it);
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> q;
	while (q--)	charming ();
	return 0;
}