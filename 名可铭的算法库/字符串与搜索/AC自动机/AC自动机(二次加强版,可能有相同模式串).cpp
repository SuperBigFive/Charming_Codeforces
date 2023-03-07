#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, len_s, len_t, tot;
int in[maxn * 30];
int fail[maxn * 30], ans[maxn * 30];
int trie[maxn][30];
string s;
vector <int> en[maxn * 30];
vector <string> t;

void init () {}

void ins (int cnt) {
	int now = 0, num;
	for (int i = 0; i < len_t; ++i) {
		num = t[cnt][i] - 'a' + 1;
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	en[now].emplace_back (cnt);
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
	init ();
	cin >> n;
	string tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		t.emplace_back (tmp);
		len_t = tmp.size ();
		ins (i);
	}
	get_fail ();
	cin >> s;
	len_s = s.size ();
	for (int i = 0, now = 0, num; i < len_s; ++i) {
		num = s[i] - 'a' + 1;
		now = trie[now][num];
		++ans[now];
	}
	tupo ();
	vector <int> res (n);
	for (int i = 1; i <= tot; ++i) if (en[i].size ()) {
		for (auto it : en[i]) res[it] = ans[i];
	}
	for (int i = 0; i < n; ++i) cout << res[i] << endl;
}


signed main () {
	charming ();
	return 0;
}