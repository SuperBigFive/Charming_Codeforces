#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 3e5 + 5;
const int M = 10;

int t, n, m;
int first[M], last[M], seq[M];
int pre[N][M], nxt[N][M];

void init () {
	for (int i = 0; i < M; ++i) first[i] = last[i] = -1;
	for (int i = 0; i < M; ++i) {
		memcpy (pre[i], first, sizeof first);
		memcpy (nxt[i], last, sizeof last);
	}
}

void charming () {
	init ();
	string s, l, r;
	cin >> s >> m >> l >> r;
	n = s.size ();
	for (int i = n - 2; i >= 0; --i) {
		memcpy (nxt[i], nxt[i + 1], sizeof nxt[i + 1]);
		nxt[i][s[i + 1] - '0'] = i + 1;
	}
	first[s[0] - '0'] = 0, last[s[0] - '0'] = 0;
	for (int i = 1; i < n; ++i) {
		if (first[s[i] -'0'] <= -1) first[s[i] - '0'] = i;
		last[s[i] - '0'] = i;
		memcpy (pre[i], pre[i - 1], sizeof pre[i - 1]);
		pre[i][s[i - 1] - '0'] = i - 1;
	}
	if (m == 1) {
		vector <int> vis (M);
		for (char i : s) vis[i - '0'] = 1;
		bool ok = false;
		for (int i = (l[0] - '0'); i <= (r[0] - '0'); ++i) {
			if (!vis[i]) ok = true;
		}
		printf (ok ? "YES\n" : "NO\n");
	}
	else {
		int right = -1, left = n + 1;
		bool ok = false;
		
		auto DFS1 = [&] (auto && me, int cur, int lim) -> void {
			if (ok) return;
			if (cur >= lim) {
				cur = first[seq[0]];
				if (cur == -1) {
					printf ("YES\n");
					ok = true;
					return;
				}
				for (int j = 1; j < m / 2; ++j) {
					cur = nxt[cur][seq[j]];
					if (cur == -1) {
						printf ("YES\n");
						ok = true;
						return;
					}
				}
				right = max (right, cur);
				return;
			}
			for (int i = (l[cur] - '0'); i <= (r[cur] - '0'); ++i) {
				seq[cur] = i;
				me (me, cur + 1, lim);
				if (ok) return;
			}
		};
		
		auto DFS2 = [&] (auto && me, int cur, int lim) -> void {
			if (ok) return;
			if (cur >= lim) {
				cur = last[seq[lim - 1]];
				if (cur == -1) {
					printf ("YES\n");
					ok = true;
					return;
				}
				for (int j = lim - 2; j >= 0; --j) {
					cur = pre[cur][seq[j]];
					if (cur == -1) {
						printf ("YES\n");
						ok = true;
						return;
					}
				}
				left = min (left, cur);
				return;
			}
			for (int i = (l[cur] - '0'); i <= (r[cur] - '0'); ++i) {
				seq[cur] = i;
				me (me, cur + 1, lim);
				if (ok) return;
			}
		};
		
		DFS1 (DFS1, 0, m / 2);
		l = l.substr (m / 2, m - m / 2);
		r = r.substr (m / 2, m - m / 2);
		DFS2 (DFS2, 0, m - m / 2);
		
		if (ok) return;
		else if (left <= right) printf ("YES\n");
		else printf ("NO\n");
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}