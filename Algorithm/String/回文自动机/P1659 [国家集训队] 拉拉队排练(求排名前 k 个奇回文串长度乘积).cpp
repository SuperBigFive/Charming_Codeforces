#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 19930726;

struct Node {
	int len;
	int fail;
	int cnt;
}node[maxn];
int n, last, tot;
ll k;
int in[maxn];
int trie[maxn][26];
string s;

int add (int l) {
	node[++tot].len = l;
	node[tot].fail = 0;
	node[tot].cnt = 0;
	return tot;
}

ll binpow (ll num, ll pow) {
	ll res = 1;
	while (pow) {
		if (pow & 1) res = (res * num) % mod;
		pow >>= 1;
		num = (num * num) % mod;
	}
	return res;
}

void init () {
	tot = -1;
	add (0), add (-1);
	node[0].fail = node[1].fail = 1;
}

int get_fail (int pos, int id) {
	while (s[pos - node[id].len - 1] != s[pos]) id = node[id].fail;
	return id;
}

void pam_ins (int pos) {
	int now = get_fail (pos, last);
	int num = s[pos] - 'a';
	int son = trie[now][num];
	if (!son) {
		son = add (node[now].len + 2);
		node[son].fail = trie[get_fail (pos, node[now].fail)][num];
		trie[now][num] = son;
		++in[node[son].fail];
	}
	++node[son].cnt;
	last = son;
}

void topu () {
	queue <int> q;
	for (int i = 2; i <= tot; ++i) if (!in[i]) {
		q.push (i);
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		int fa = node[now].fail;
		node[fa].cnt += node[now].cnt;
		--in[fa];
		if (!in[fa]) q.push (fa);
	}
}

void charming () {
	init ();
	cin >> n >> k;
	cin >> s, s = '#' + s;
	for (int i = 1; i <= n; ++i) pam_ins (i);
	topu ();
	sort (node + 1, node + 1 + tot, [] (Node &x, Node &y) {
		return x.len > y.len;
	});
	ll res = 1;
	for (int i = 1; i <= tot && k > 0; ++i) {
		if (node[i].len < 1) {
			cout << -1 << endl;
			return;
		}
		if (!(node[i].len & 1)) continue;
		if (k < node[i].cnt) node[i].cnt = k;
		res = (res * binpow (node[i].len, node[i].cnt) % mod);
		k -= node[i].cnt;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}