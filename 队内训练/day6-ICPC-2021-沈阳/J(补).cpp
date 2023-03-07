#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int n = 10;

int t, tot;
string a, b;
map <array <int, 4>, int> ans;
map <array <int, 4>, bool> vis;

void init () {}

void bfs () {
	queue <array <int, 4> > q;
	array <int, 4> s;
	s[0] = s[1] = s[2] = s[3] = 0;
	q.push (s);
	ans[s] = 0;
	array <int, 4> cur, nxt;
	while (!q.empty ()) {
		cur = nxt = q.front ();
		++tot;
		q.pop ();
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 2; ++j) {
				nxt[i] = (cur[i] + (j ? 1 : -1) + n) % n;
				if (!vis[nxt]) {
					vis[nxt] = true;
					ans[nxt] = ans[cur] + 1;
					q.push (nxt);
				}
				nxt[i] = cur[i];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				for (int k = 0; k < 2; ++k) {
					nxt[i] = (cur[i] + (k ? 1 : -1) + n) % n;
					nxt[j] = (cur[j] + (k ? 1 : -1) + n) % n;
					if (!vis[nxt]) {
						vis[nxt] = true;
						ans[nxt] = ans[cur] + 1;
						q.push (nxt);
					}
					nxt[i] = cur[i];
					nxt[j] = cur[j];
				}
				break;
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				for (int k = j + 1; k < 4; ++k) {
					for (int p = 0; p < 2; ++p) {
						nxt[i] = (cur[i] + (p ? 1 : -1) + n) % n;
						nxt[j] = (cur[j] + (p ? 1 : -1) + n) % n;
						nxt[k] = (cur[k] + (p ? 1 : -1) + n) % n;
						if (!vis[nxt]) {
							vis[nxt] = true;
							ans[nxt] = ans[cur] + 1;
							q.push (nxt);
						}
						nxt[i] = cur[i];
						nxt[j] = cur[j];
						nxt[k] = cur[k];
					}
					break;
				}
				break;
			}
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				nxt[j] = (cur[j] + (i ? 1 : -1) + n) % n;
			}
			if (!vis[nxt]) {
				vis[nxt] = true;
				ans[nxt] = ans[cur] + 1;
				q.push (nxt);
			}
			nxt = cur;
		}
	}
}

void debug (int i, int j, int p, int q) {
	array <int, 4> st;
	st[0] = i, st[1] = j, st[2] = p, st[3] = q;
	cout << ans[st] << endl;
}

void charming () {
	init ();
	bfs ();
	int i, j, p, q;
	/*while (true) {
		cin >> i >> j >> p >> q;
		if (i + j + p + q == 0) break;
		debug (i, j, p, q);
	}*/
	cin >> t;
	array <int, 4> st;
	while (t--) {
		cin >> a >> b;
		for (int i = 0; i < 4; ++i) {
			st[i] = (b[i] - a[i] + n) % n;
		}
		bfs ();
		cout << ans[st] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}