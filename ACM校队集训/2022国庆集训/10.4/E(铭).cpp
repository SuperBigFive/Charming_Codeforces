#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
char s[maxn], f[maxn];
int nxt[maxn][40];

void init () {}

void charming () {
	init ();
	scanf ("%s", s + 1), n = strlen (s + 1);
	scanf ("%s", f + 1), m = strlen (f + 1);
	if (m == 1) {
		cout << f[1] << endl;
		return;
	}
	for (int i = 0; i < 40; ++i) {
		nxt[n][i] = -1;
	}
	for (int i = n - 1, num; i >= 1; --i) {
		if (s[i + 1] >= 'a') num = s[i + 1] - 'a';
		else num = s[i + 1] - '0' + 26;
		for (int j = 0; j < 40; ++j) nxt[i][j] = nxt[i + 1][j];
		nxt[i][num] = i + 1;
	}
	int len = INT_MAX, l = 1, r = 1;
	for (int i = 1, cur, id, num; i <= n; ++i) {
		if (s[i] != f[1]) continue;
		cur = i, id = 1;
		bool ok = true;
		while (id < m) {
			++id;
			if (f[id] >= 'a') num = f[id] - 'a';
			else num = f[id] - '0' + 26;
			cur = nxt[cur][num];
			if (cur == -1) {
				ok = false;
				break;
			}
		}
		if (ok && cur - i + 1 < len) {
			len = cur - i + 1;
			l = i, r = cur;
		}
	}
	for (int i = l; i <= r; ++i)
	printf ("%c", s[i]);
	printf ("\n");	
}

signed main () {
	scanf ("%d", &t);
	while (t--) charming ();
	return 0;
}