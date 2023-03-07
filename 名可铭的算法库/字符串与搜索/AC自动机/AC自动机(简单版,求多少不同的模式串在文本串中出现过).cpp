#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n, len_s, len_t, tot;
char s[maxn], t[maxn];
int fail[maxn * 30], cnt[maxn * 30]; 
int trie[maxn][30];
bool vis[maxn * 30];

void init () {}

void ins () {
	int now = 0, num;
	for (int i = 1; i <= len_s; ++i) {
		num = s[i] - 'a' + 1;
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	++cnt[now];
}

void get_fail () {
	queue <int> q;
	int now;
	for (int i = 1; i <= 26; ++i) if (trie[0][i]) {
		q.push (trie[0][i]);
	}
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 1; i <= 26; ++i) {
			if (trie[now][i]) {
				fail[trie[now][i]] = trie[fail[now]][i];
				q.push (trie[now][i]);
			}
			else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s + 1;
		len_s = strlen (s + 1);
		ins ();
	}
	get_fail ();
	cin >> t + 1;
	len_t = strlen (t + 1);
	int res = 0, now = 0, num;
	for (int i = 1; i <= len_t; ++i) {
		num = t[i] - 'a' + 1;
		now = trie[now][num];
		for (int j = now; j && !vis[j]; j = fail[j]) {
			res += cnt[j];
			vis[j] = true;
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}