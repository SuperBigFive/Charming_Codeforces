#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;

int n, k, m;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> m;
	vector <int> c (n), dis (1 << (n + m), INT_MAX);
	vector <vector <int> > fix (1 << (n + m), vector <int> (n, 0));
	vector <vector <int> > equip (m);
	int rt = 0, en = (1 << n) - 1;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		if (c[i] == 1) rt += (1 << i);
	}
	for (int i = 0, r; i < m; ++i) {
		cin >> r;
		equip[i].resize (r);
		for (int j = 0; j < r; ++j)
		cin >> equip[i][j], --equip[i][j];
	}
	queue <int> q;
	q.push (rt);
	dis[rt] = 0;
	while (!q.empty ()) {
		int cur = q.front (), nxt = cur;
		q.pop ();
		if ((cur & ((1 << n) - 1)) == (1 << n) - 1) {
			int cnt = 0;
			for (int i = n; i < n + m; ++i)
			if ((cur >> i) & 1) ++cnt;
			dis[en] = min (dis[en], dis[cur] + cnt);
		}
		for (int i = 1; i <= k; ++i) {
			nxt = 0;
			for (int j = 0; j < n; ++j) {
				if (fix[cur][j]) nxt += cur & (1 << j);
				else nxt += (c[j] == i) * (1 << j);
			}
			nxt += (cur >> n) << n;
			if (dis[nxt] < INT_MAX) continue;
			dis[nxt] = dis[cur] + 1;
			fix[nxt] = fix[cur];
			q.push (nxt);
		}
		for (int i = 0; i < m; ++i) {
			if ((cur >> (n + i)) & 1) {
				nxt = cur - (1 << (n + i));
				if (dis[nxt] < INT_MAX) continue;
				dis[nxt] = dis[cur] + 1;
				fix[nxt] = fix[cur];
				for (int j = 0; j < equip[i].size (); ++j)
				fix[nxt][equip[i][j]] -= 1;
				q.push (nxt);
			}
			else {
				nxt = cur + (1 << (n + i));
				if (dis[nxt] < INT_MAX) continue;
				dis[nxt] = dis[cur] + 1;
				fix[nxt] = fix[cur];
				for (int j = 0; j < equip[i].size (); ++j)
				fix[nxt][equip[i][j]] += 1;
				q.push (nxt);
			}
		}
	}
	cout << (dis[en] < INT_MAX ? dis[en] : -1) << endl;
}

signed main () {
	charming ();
	return 0;
}