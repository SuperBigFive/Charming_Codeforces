#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 6e5 + 5;

int n;
int len[maxn];
char tmp[maxn];
string str[maxn];
vector <char> s[maxn];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf ("%s", tmp + 1);
		len[i] = strlen (tmp + 1);
		s[i].pb ('#');
		s[i].pb ('#');
		for (int j = 2; j <= len[i]; ++j)
		s[i].pb (tmp[j]);
	}
	int p;
	for (int i = n - 1; i >= 1; --i) {
		p = 1;
		while (s[i][p] == s[i + 1][p] && p <= len[i] && p <= len[i + 1])
		++p;
		if (p > len[i]) continue;
		if (p > len[i + 1]) {
			len[i] = p - 1;
			continue;
		}
		if (s[i][p] > s[i + 1][p]) {
			len[i] = p - 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= len[i]; ++j)
		printf ("%c", s[i][j]);
		printf ("\n");
	}
}

signed main () {
	charming ();
	return 0;
}