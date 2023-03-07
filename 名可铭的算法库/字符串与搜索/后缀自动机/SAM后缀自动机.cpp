#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, last, tot;
int len[maxn], link[maxn];
int in[maxn], cnt[maxn];
char s[maxn];
map <char, int> nxt[maxn];

void init () {
	tot = last = 0;
	len[0] = 0, link[0] = -1;
}

void sam_ins (char ch) {
	int cur = ++tot, p = last;
	len[cur] = len[last] + 1;
	while (p != -1 && !nxt[p].count (ch)) {
		nxt[p][ch] = cur;
		p = link[p];
	}
	if (p == -1) link[cur] = 0;
	else {
		int q = nxt[p][ch];
		if (len[p] + 1 == len[q]) link[cur] = q, ++in[q];
		else {
			int clone = ++tot;
			len[clone] = len[p] + 1, link[clone] = link[q];
			nxt[clone] = nxt[q];
			link[q] = link[cur] = clone;
			++in[clone], ++in[clone];
			while (p != -1 && nxt[p][ch] == q) {
				nxt[p][ch] = clone;
				p = link[p];
			}
		}
	}
	last = cur;
	++cnt[cur];
}

void topu () {
	queue <int> q;
	for (int i = 1; i <= tot; ++i) if (!in[i]) {
		q.push (i);
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		cnt[link[now]] += cnt[now];
		--in[link[now]];
		if (!in[link[now]]) q.push (link[now]);
	}
}

void charming () {
	init ();
	cin >> s + 1;
	n = strlen (s + 1);
	for (int i = 1; i <= n; ++i) sam_ins (s[i]);
	topu ();
	int res = 0;
	for (int i = 1; i <= tot; ++i) if (cnt[i] > 1) {
		res = max (res, len[i] * cnt[i]);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}