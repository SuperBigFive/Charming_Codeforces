#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, len_s, len_t, p;
int nxt[maxn];
char s[maxn], t[maxn];

void init () {}

void get_nxt () {
	p = 0;
	for (int i = 2; i <= len_s; ++i) {
		if (s[i] == s[nxt[i - 1] + 1]) nxt[i - 1] = nxt[nxt[i - 1]];
		while (p && s[i] != s[p + 1]) p = nxt[p];
		if (s[i] == s[p + 1]) ++p;
		nxt[i] = p; 
	}
}

void get_ans () {
	int len = len_s + len_t;
	for (int i = len_s + 1; i <= len; ++i) s[i] = t[i - len_s];
	for (int i = len_s + 1, tmp_p = p; i <= len; ++i) {
		while (tmp_p && s[i] != s[tmp_p + 1]) tmp_p = nxt[tmp_p];
		if (s[i] == s[tmp_p + 1]) ++tmp_p;
		nxt[i] = tmp_p;
		cout << nxt[i] << " \n"[i == n];
	}
}

void charming () {
	cin >> s + 1, len_s = strlen (s + 1);
	get_nxt ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t + 1;
		len_t = strlen (t + 1);
		get_ans ();
	}
}

signed main () {
	charming ();
	return 0;
}