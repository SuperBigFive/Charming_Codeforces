#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int cnt[10];
char s[maxn];
vector <int> pos[10];

void init () {
	for (int i = 0; i < 10; ++i) pos[i].clear ();
	memset (cnt, 0, sizeof cnt);
}

void charming () {
	init ();
	cin >> s + 1;
	n = strlen (s + 1);
	for (int i = 1, num; i <= n; ++i) {
		num = s[i] - '0';
		++cnt[num];
		pos[num].emplace_back (i);
	}
	int id = 0, last;
	while (!cnt[id]) ++id;
	last = pos[id].back ();
	for (int i = id + 1; i < 10; ++i) {
		id = lower_bound (pos[i].begin (), pos[i].end (), last) - pos[i].begin ();
		cnt[i] -= id;
		cnt[min (i + 1, 1ll * 9)] += id;
		if (id < pos[i].size ()) last = pos[i].back ();
	}
	for (int i = 0; i < 10; ++i) {
		while (cnt[i]-- > 0) cout << i;
	}
	cout << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}