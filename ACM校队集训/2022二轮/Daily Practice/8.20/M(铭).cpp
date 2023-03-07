#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, len_s, len_t;
char s[maxn], t[maxn];
vector <int> pos[30];

void init () {
	
}

void charming () {
	cin >> s + 1;
	len_s = strlen (s + 1);
	for (int i = 1, num; i <= len_s; ++i) {
		num = s[i] - 'a' + 1;
		pos[num].emplace_back (i);
	}
	cin >> n;
	for (int i = 1, id, res; i <= n; ++i) {
		cin >> t + 1;
		len_t = strlen (t + 1);
		res = 0;
		if (!pos[t[1] - 'a' + 1].size ()) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		for (int j = 1, now = 0, num; j <= len_t; ++j) {
			num = t[j] - 'a' + 1;
			id = lower_bound (pos[num].begin (), pos[num].end (), now) - pos[num].begin ();
			if (id >= pos[num].size () || pos[num][id] <= now) break;
			++res;
			now = pos[num][id];
		}
		for (int i = 1; i <= res; ++i) {
			cout << t[i];
		}
		cout << endl;
	}
}

signed main () {
	charming ();
	return 0;
}