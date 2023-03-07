#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n, last, tot;
int cnt[maxn];
int fail[maxn], len[maxn];
int trie[maxn][30];
char s[maxn];

void init () {tot = -1;}

int add_node (int l) {
	len[++tot] = l;
	fail[tot] = 0;
	return tot;
}

int get_fail (int ids, int idn) {
	while (s[ids] != s[ids - len[idn] - 1]) 
	idn = fail[idn];
	return idn;
}

int ins (int id) {
	int num = s[id] - 'a';
	int now = get_fail (id, last);
	int son = trie[now][num];
	if (!son) {
		son = add_node (len[now] + 2);
		fail[son] = trie[get_fail (id, fail[now])][num];
		trie[now][num] = son;
	}
	cnt[son] = cnt[fail[son]] + 1;
	last = trie[now][num];
	return cnt[son];
}

void charming () {
	init ();
	cin >> s + 1, n = strlen (s + 1);
	add_node (0), add_node (-1);
	fail[0] = fail[1] = 1;
	int res = ins (1);
	cout << res << " \n"[1 == n];
	for (int i = 2; i <= n; ++i) {
		s[i] = (s[i] - 97 + res) % 26 + 97;
		res = ins (i);
		cout << res << " \n"[i == n];
	}
}

signed main () {
	charming ();
	return 0;
}