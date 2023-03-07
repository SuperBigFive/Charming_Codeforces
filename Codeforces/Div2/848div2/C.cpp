#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k, res, siz;
string a, b;
vector <bool> used (26), ok (26), cho (10);

void init () {
	res = 0;
	for (int i = 0; i < 26; ++i) used[i] = ok[i] = false;
	for (int i = 0; i < 10; ++i) cho[i] = false;
}

void dfs (int u, int cnt) {
	if (cnt >= k) {
		for (int i = 0, cnt = 0; i < 26; ++i) {
			if (!used[i]) continue;
			if (cho[cnt++]) ok[i] = true;
		}
		string na = a;
		for (int i = 1; i <= n; ++i) {
			if (na[i] == b[i]) continue;
			else if (ok[na[i] - 'a']) na[i] = b[i];
		}
		int nres = 0;
		for (int i = 1, j; i <= n; i = j) {
			while (i <= n && na[i] != b[i]) ++i;
			if (i > n) break;
			j = i;
			while (j <= n && na[j] == b[j]) ++j;
			nres += (j - i) * (j - i + 1) / 2;
		}
		res = max (res, nres);
		for (int i = 0; i < 26; ++i) ok[i] = false;
		return;
	}
	for (int i = u; i < siz; ++i) {
		if (cho[i]) continue;
		cho[i] = true;
		dfs (u + 1, cnt + 1);
		cho[i] = false;
	}
}

void charming () {
	init ();
	cin >> n >> k >> a >> b;
	a = '#' + a, b = '#' + b;
	set <int> s;
	for (int i = 1; i <= n; ++i) {
		if (s.count (a[i])) continue;
		else s.insert (a[i]);
		used[a[i] - 'a'] = true;
	}
	siz = s.size ();
	k = min (k, (int) s.size ());
	dfs (0, 0);
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