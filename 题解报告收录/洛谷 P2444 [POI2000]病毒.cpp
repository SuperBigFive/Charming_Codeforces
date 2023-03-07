#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, len, tot;
int fail[maxn];
int trie[maxn][2];
char s[maxn];
bool vis[maxn], in[maxn], en[maxn];

void init () {
	tot = 0;
	fill (vis, vis + maxn, false);
	fill (in, in + maxn, false);
	fill (en, en + maxn, false);
}

void ins () {
	int now = 0, num;
	for (int i = 1; i <= len; ++i) {
		num = s[i] - '0';
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	en[now] = true;
}

void get_fail () {
	queue <int> q;
	if (trie[0][0]) q.push (trie[0][0]);
	if (trie[0][1]) q.push (trie[0][1]);
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 0; i <= 1; ++i) {
			if (trie[now][i]) {
				fail[trie[now][i]] = trie[fail[now]][i];
				en[trie[now][i]] |= en[fail[trie[now][i]]];
				q.push (trie[now][i]);
			}
			else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void dfs (int now) {
	if (in[now]) {
		cout << "TAK" << endl;
		exit (0);
	}
	if (vis[now] || en[now]) return;
	vis[now] = in[now] = true;
	dfs (trie[now][0]);
	dfs (trie[now][1]);
	in[now] = false;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s + 1;
		len = strlen (s + 1);
		ins ();
	}
	get_fail ();
	dfs (0);
	cout << "NIE" << endl;
}

signed main () {
	charming ();
	return 0;
}