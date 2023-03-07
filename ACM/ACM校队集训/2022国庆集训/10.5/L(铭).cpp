#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m;
char s[maxn], t[maxn];

void init () {}

void charming () { 
	init ();
	cin >> s + 1 >> t + 1;
	n = strlen (s + 1);
	m = strlen (t + 1);
	int p1 = 1, p2 = 1;
	while (s[p1] == s[1] && p1 <= n) ++p1;
	while (t[p2] == s[1] && p2 <= m) ++p2;
	if (p1 < p2 || s[1] != t[1]) {
		cout << "No" << endl;
		return;
	}
	for (p1 = 1, p2 = 1; p2 <= m; ++p2) {
		if (s[p1] == t[p2]) ++p1;
	}
	cout << ((p1 == n + 1) ? "Yes" : "No") << endl;
}

signed main () {
	charming ();
	return 0;	
}