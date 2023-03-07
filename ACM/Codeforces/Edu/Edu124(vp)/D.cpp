#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

struct Node {
	int x, y;
	int tot;
}p[maxn];
int t, n;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
map <int, int> in[maxn], vis[maxn];
map <pii, int> pos2id;
pii res[maxn];

void init () {
	
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].tot = i;
		pos2id[{p[i].x, p[i].y}] = i;
		++vis[p[i].x][p[i].y];
		for (int j = 0; j < 4; ++j) {
			++in[p[i].x + dx[j]][p[i].y + dy[j]];
		}
	}
	queue <Node> q;
	for (int i = 1; i <= n; ++i) {
		if (in[p[i].x][p[i].y] < 4) {
			q.push (p[i]);
			for (int j = 0; j < 4; ++j) {
				if (!vis[p[i].x + dx[j]][p[i].y + dy[j]]) {
					res[p[i].tot] = {p[i].x + dx[j], p[i].y + dy[j]};
					break;
				}
			}
		}
	}
	Node now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 0; i < 4; ++i) {
			if (vis[now.x + dx[i]][now.y + dy[i]] && (in[now.x + dx[i]][now.y + dy[i]]--) >= 4) {
				int id = pos2id[{now.x + dx[i], now.y + dy[i]}];
				res[id] = res[now.tot];
				q.push (p[id]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << res[i].fi << ' ' << res[i].se << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}