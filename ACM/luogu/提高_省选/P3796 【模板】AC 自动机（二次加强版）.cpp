#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 2e6 + 5;

int n, tot, cnt, len, now, nex, num;
int mmax;
int i, j, k;
int trie[maxn][26], fail[maxn], seq[maxn], ans[maxn], in[maxn], mmap[maxn], mark[maxn];
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
	++cnt;
	if (!seq[now]) seq[now] = cnt;
	mmap[cnt] = seq[now];
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
				++in[trie[fail[now]][i]];
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
		++mark[now]; 
	}
}

void topu () {
	for (i = 0; i <= tot; ++i) {
		if (!in[i]) q.push (i); 
	}
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		nex = fail[now];
		ans[seq[now]] = mark[now];
		--in[nex];
		mark[nex] += mark[now];
		if (!in[nex]) q.push (nex);
	}
}
void solve  () {
	cin >> n;
	init ();
	for (i = 1; i <= n; ++i) {
		cin >> tmp[i];
		ins ();
	}
	cin >> str;
	get_fail ();
	find ();
	topu ();
	for (i = 1; i <= cnt; ++i) 
	cout << ans[mmap[i]] << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	solve ();
}
