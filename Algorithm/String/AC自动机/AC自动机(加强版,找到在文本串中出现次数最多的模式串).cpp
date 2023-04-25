#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n, len_s, len_t, tot;
int in[maxn * 30], en[maxn * 30];
int fail[maxn * 30], ans[maxn * 30];
int trie[maxn][30];
char s[200][100], t[maxn];

void init () {
	for (int i = 0; i <= tot; ++i) {
		in[i] = fail[i] = ans[i] = en[i] = 0;
		fill_n (trie[i], 30, 0);
	}
	tot = 0;
}

void ins (int cnt) {
	int now = 0, num;
	for (int i = 1; i <= len_s; ++i) {
		num = s[cnt][i] - 'a' + 1;
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	en[now] = cnt;
}

void get_fail () {
	queue <int> q;
	for (int i = 1; i <= 26; ++i) if (trie[0][i]) {
		q.push (trie[0][i]);
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 1; i <= 26; ++i) {
			if (trie[now][i]) {
				fail[trie[now][i]] = trie[fail[now]][i];
				++in[trie[fail[now]][i]];
				q.push (trie[now][i]);
			}
			else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void tupo () {
	queue <int> q;
	for (int i = 1; i <= tot; ++i) if (!in[i]) {
		q.push (i);
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		ans[fail[now]] += ans[now];
		--in[fail[now]];
		if (!in[fail[now]] && fail[now]) q.push (fail[now]);
	}
}

void charming () {
	cin >> n;
	if (!n) exit (0);
	init ();
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] + 1;
		len_s = strlen (s[i] + 1);
		ins (i);
	}
	get_fail ();
	cin >> t + 1;
	len_t = strlen (t + 1);
	for (int i = 1, now = 0, num; i <= len_t; ++i) {
		num = t[i] - 'a' + 1;
		now = trie[now][num];
		++ans[now];
	}
	tupo ();
	int res = 0;
	vector <int> id;
	for (int i = 1; i <= tot; ++i) {
		if (!en[i]) continue;
		if (ans[i] == res) id.emplace_back (en[i]);
		if (ans[i] > res) {
			id.clear ();
			id.emplace_back (en[i]);
			res = ans[i];
		}
	}
	cout << res << endl;
	for (auto it : id) {
		cout << s[it] + 1 << endl;
	}
}


signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	while (true) 
	charming ();
	return 0;
}