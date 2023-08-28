#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e5 + 5;

int n, last, tot;
int fail[maxn], len[maxn];
int in[maxn], ans[maxn];
int trie[maxn][30];
char s[maxn];

void init () {tot = -1;}

int add_node (int l) {
	len[++tot] = l;
	fail[tot] = 0;
	return tot;
}

int get_fail (int id1, int id2) {
	while (s[id1] != s[id1 - len[id2] - 1]) id2 = fail[id2];
	return id2;
}

void ins (int id) {
	int num = s[id] - 'a';
	int now = get_fail (id, last);
	int son = trie[now][num];
	if (!son) {
		son = add_node (len[now] + 2);
		fail[son] = trie[get_fail (id, fail[now])][num];
		++in[fail[son]];
		trie[now][num] = son;
	}
	++ans[son];
	last = son;
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
		ans[fail[now]] += ans[now];
		--in[fail[now]];
		if (!in[fail[now]]) q.push (fail[now]);
	}
}

void charming () {
	init ();
	cin >> s + 1;
	n = strlen (s + 1);
	add_node (0), add_node (-1);
	fail[0] = fail[1] = 1;
	for (int i = 1; i <= n; ++i) ins (i);
	topu ();
	int res = 0;
	for (int i = 1; i <= tot; ++i) {
		res = max (res, len[i] * ans[i]);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}