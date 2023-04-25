#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int sum[maxn], pre[maxn];
bool vis[maxn];
char s[maxn];
vector <int> pos[maxn];

void init () {
	for (int i = 0; i <= n; ++i) pos[i].clear ();
}

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void charming () {
	init ();
	cin >> n;
	n <<= 1;
	for (int i = 1; i <= n; ++i) pre[i] = i;
	fill (vis + 1, vis + 1 + n, false);
	cin >> s + 1;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1];
		s[i] == '(' ? ++sum[i] : --sum[i];
		pos[sum[i]].emplace_back (i);
	}
	int fi, fv;
	for (int i = 1, id, tmp; i <= n; ++i) {
		if (vis[i] || s[i] == ')') continue;
		tmp = sum[i - 1];
		id = upper_bound (pos[tmp].begin (), pos[tmp].end (), i) - pos[tmp].begin ();
		for (int j = id, v; j < pos[tmp].size (); ++j) {
			v = pos[tmp][j];
			fi = find (i), fv = find (v);
			if (fi != fv) {
				pre[fv] = fi;
				if (vis[v]) break;
				vis[v] = true;
			}
			if (s[v + 1] == ')') break;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == find (i)) ++res;
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}