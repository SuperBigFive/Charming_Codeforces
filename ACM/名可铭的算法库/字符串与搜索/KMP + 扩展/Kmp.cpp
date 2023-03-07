#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int tot, len_s, len_p;
int nxt[maxn];
char s[maxn], p[maxn];
vector <int> pos;

void init () {}

void get_nxt () {
	for (int i = 2, j = 0; i <= len_p; ++i) {
		while (j && p[i] != p[j + 1]) j = nxt[j];
		if (p[i] == p[j + 1]) ++j;
		nxt[i] = j;
	}
}

void kmp () {
	for (int i = 1, j = 0; i <= len_s; ++i) {
		while (j && s[i] != p[j + 1]) j = nxt[j];
		if (s[i] == p[j + 1]) ++j;
		if (j == len_p) {
			pos.emplace_back (i - len_p + 1);
			j = nxt[j];
		}
	}
}

void charming () {
	cin >> s + 1;
	cin >> p + 1;
	len_s = strlen (s + 1);
	len_p = strlen (p + 1);
	get_nxt ();
	kmp ();
	for (auto it : pos) cout << it << endl;
	for (int i = 1; i <= len_p; ++i) 
	cout << nxt[i] << " \n" [i == len_p];
}

signed main () {
	charming ();
	return 0;
}