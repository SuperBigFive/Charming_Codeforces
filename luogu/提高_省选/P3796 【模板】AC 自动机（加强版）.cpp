#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
const int maxm = 1e6 + 5;

int n, tot, cnt, len, now, nex, num;
int mmax;
int i, j, k;
int trie[maxn][26], fail[maxn], seq[maxn], ans[maxn];
bool vis[maxn];
char str[maxm];
char tmp[maxn][100];
queue <int> q;

void init () {
	for (i = 0; i <= tot; ++i) {
		fail[i] = seq[i] = ans[i] = 0;
		for (j = 0; j < 26; ++j) {
			trie[i][j] = 0;
		}
	}
	tot = cnt = mmax = 0;
} 

void ins () {
	now = 0, len = strlen (tmp[i]);
	for (j = 0; j < len; ++j) {
		num = tmp[i][j] - 'a';
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	seq[now] = ++cnt;
}

void get_fail () {
	now = 0;
	for (i = 0; i < 26; ++i) {
		nex = trie[now][i];
		if (nex) {
			q.push (nex);
			fail[nex] = 0; 
		}
	}
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (i = 0; i < 26; ++i) {
			nex = trie[now][i];
			if (nex) {
				fail[nex] = trie[fail[now]][i];
				q.push (nex);
			}
			else {
				trie[now][i] = trie[fail[now]][i];
			}
		}
	}
}

void find () {
	now = 0;
	len = strlen (str);
	for (i = 0; i < len; ++i) {
		num = str[i] - 'a';
		now = trie[now][num];
		for (j = now; j ; j = fail[j]) {
			if (seq[j]) ++ans[seq[j]];
		}
	}
}

void solve  () {
	init ();
	for (i = 1; i <= n; ++i) {
		cin >> tmp[i];
		ins ();
	}
	cin >> str;
	get_fail ();
	find ();
	for (i = 1; i <= cnt; ++i) {
		if (ans[i] > mmax) {
			mmax = ans[i];
		}
	}
	cout << mmax << endl;
	for (i = 1; i <= cnt; ++i) {
		if (ans[i] == mmax) {
			cout << tmp[i] << endl;
		}
	}
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	while (true) {
		cin >> n;
		if (n) solve ();
		else break;
	} 
}
