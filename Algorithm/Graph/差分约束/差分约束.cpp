#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define int long long
const int N = 2e3 + 5;

int t, n, m, x;
int dis[N], cnt[N], vis[N];
vector <pair <int, int> > G[N];

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

bool SPFA () {
	queue <int> q;
	q.push (0), dis[0] = 0, vis[0] = 1; cnt[0] = 1;
	while (!q.empty ()) {
		int u = q.front ();
		q.pop (), vis[u] = 0;
		for (auto [v, w] : G[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (! vis[v]) {
					q.push (v), vis[v] = 1;
					++ cnt[v];
					if (cnt[v] > n + 1) return false;
				}			
			}
		}
	}
	for (int i = 2; i <= n; ++ i) if (dis[i] - dis[i-1] > 2e9 
  || dis[i] - dis[i-1] <= 0) return false;
	return true;
}

void charming (int c) {
	n = read (), m = read (), x = read ();
	for (int i = 0; i <= n; ++i) {
    cnt[i] = 0, dis[i] = 1e15, G[i].clear (), vis[i] = 0;
  }
	for (int i = 1; i <= n; ++i) {
		G[0].emplace_back (make_pair (i, 0));
		if (i > 1) G[i].emplace_back (make_pair (i - 1, -1));
	}
	for (int i = 1, a, b, c, d; i <= m; ++i) {
		a = read (), b = read (), c = read (), d = read ();
		if (a == b && c == d) {
			G[a].emplace_back (make_pair (c, x));
			G[c].emplace_back (make_pair (a, -x));
		} else {
			G[b].emplace_back (make_pair (c, x - 1));
			G[d].emplace_back (make_pair (a, -x - 1));
		}
	}

	if (!SPFA ()) {
		printf ("Case #%lld: IMPOSSIBLE\n", c);
	} else {
		printf ("Case #%lld: ", c);
		for (int i = 2; i <= n; ++i) {
			printf ("%lld%c", dis[i] - dis[i - 1], i == n ? '\n' : ' ');
		}
	}
}

signed main () {
	t = read ();
	for (int c = 1; c <= t; ++c) charming (c);
	return 0;
}
