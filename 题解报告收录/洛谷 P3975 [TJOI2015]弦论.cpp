#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n, t, k, last, tot;
int link[maxn], len[maxn];
int in[maxn], cnt[maxn], sum[maxn];
int sa[maxn], bowl[maxn];
int nxt[maxn][30];
bool vis[maxn];
char s[maxn];


void init () {link[0] = -1;}

void sam_ins (int num) {
	int cur = ++tot;
	len[cur] = len[last] + 1;
	int p = last;
	while (p != -1 && !nxt[p][num]) {
		nxt[p][num] = cur;
		p = link[p];
	}
	if (p == -1) link[cur] = 0;
	else {
		int q = nxt[p][num];
		if (len[p] + 1 == len[q]) link[cur] = q, ++in[q];
		else {
			int clone = ++tot;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			memcpy (nxt[clone], nxt[q], sizeof nxt[q]);
			while (p != -1 && nxt[p][num] == q) {
				nxt[p][num] = clone;
				p = link[p];
			}
			link[cur] = link[q] = clone, in[clone] += 2;
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

/*void dfs (int now) {
	sum[now] = cnt[now];
	for (int i = 0; i < 26; ++i) {
		if (nxt[now][i]) {
			int v = nxt[now][i];
			if (!vis[v]) dfs (v);
			vis[v] = true;
			sum[now] += sum[v];
		}
	}
}*/

string get_ans () {
	string ans;
	int now = 0;
	bool ok = true;
	while (ok) {
		ok = false;
		k -= cnt[now];
		if (k <= 0) break;
		for (int i = 0; i < 26; ++i) {
			if (nxt[now][i]) {
				if (k > sum[nxt[now][i]])
				k -= sum[nxt[now][i]];
				else {
					ans += 'a' + i;;
					now = nxt[now][i];
					ok = true;
					break;
				}
			}
		}
	}
	return ans;
}

void charming () {
	init ();
	cin >> s + 1;
	n = strlen (s + 1);
	for (int i = 1; i <= n; ++i) sam_ins (s[i] - 'a');
	cin >> t >> k;
	if (t) topu ();
	else fill (cnt + 1, cnt + 1 + tot, 1);
	for (int i = 1; i <= tot; ++i) ++bowl[len[i]];
	for (int i = 1; i <= tot; ++i) bowl[i] += bowl[i - 1];
	for (int i = tot; i >= 0; --i) sa[bowl[len[i]]--] = i;
	for (int i = 1; i <= tot; ++i) sum[i] = cnt[i];
	sum[0] = cnt[0] = 0;
	for (int i = tot; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) if (nxt[sa[i]][j]) {
			sum[sa[i]] += sum[nxt[sa[i]][j]];
		}
	}
	if (sum[0] < k) cout << -1 << endl;
	else cout << get_ans () << endl;
}

signed main () {
	charming ();
	return 0;
}