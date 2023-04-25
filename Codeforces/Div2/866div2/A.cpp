#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s, ns;
	cin >> s;
	n = s.size ();
	if (n == 1) {
		if (s[0] == '^') cout << 1 << endl;
		else cout << 2 << endl;
		return;
	}
	int ans = 0;
	if (s[0] == '_') ns += '^', ++ans;
	for (int i = 0, j; i < n; i = j) {
		if (s[i] == '_') ns += '_', j = i + 1;
		else {
			j = i;
			while (j <= n && s[j] == s[i]) ++j;
			ns += '^';
		}
	}
	if (ns.back () == '_') ns += '^', ++ans;
	n = ns.size ();
	for (int i = 0, j; i < n - 1; i = j) {
		j = i + 1;
		while (j < n && ns[j] == '_') ++j;
		ans += (j - i - 2);
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}