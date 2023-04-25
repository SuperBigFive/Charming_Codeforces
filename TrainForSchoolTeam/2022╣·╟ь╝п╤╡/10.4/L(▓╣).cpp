#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 998244353;

int n, m, cnt;
int val[maxn], ans[maxn];
int fail[maxn], len[maxn], id[maxn];
int trie[maxn][30];
char s[maxn], t[maxn];

void init () {}

void ins (int tot) {
	int now = 0, num, siz = strlen (t + 1);
	for (int i = 1; i <= siz; ++i) {
		num = t[i] - 'a';
		if (!trie[now][num]) trie[now][num] = ++cnt;
		now = trie[now][num];
	}
	id[now] = tot;
	len[now] = siz;		
}

void bfs () {
	queue <int> q;
	for (int i = 0; i < 30; ++i) if (trie[0][i]) {
		q.push (trie[0][i]);
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 0; i < 30; ++i) {
			if (trie[now][i]) {
				int son = trie[now][i];
				fail[son] = trie[fail[now]][i];
				if (!len[son]) {
					len[son] = len[fail[son]];
					id[son] = id[fail[son]]; 
				}
				q.push (son);
			}
			else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void charming () {
	cin >> s + 1;
	n = strlen (s + 1);
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> t + 1 >> val[i];
		ins (i);
	}
	bfs ();
	val[0] = ans[0] = 1;
	for (int i = 1, now = 0, num; i <= n; ++i) {
		num = s[i] - 'a';
		now = trie[now][num];
		ans[i] = ans[i - 1] % mod;
		for (int j = now, last = -1; j; last = j, j = fail[j]) {
			if (id[j] == id[last] || !len[j]) {
				fail[last] = fail[j];
				continue;
			}
			ans[i] = (ans[i] + 
			ans[i - len[j]] * val[id[j]]) % mod;
		}
		cout << ans[i] % mod << " \n"[i == n];
	}
}

signed main () {
	charming ();
	return 0;	
}