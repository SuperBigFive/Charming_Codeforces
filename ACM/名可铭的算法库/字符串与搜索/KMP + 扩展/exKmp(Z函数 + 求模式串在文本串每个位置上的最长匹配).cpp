#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e7 + 5;

int len_s, len_t;
int z[maxn], p[maxn];
char s[maxn], t[maxn];

void init () {}

void get_z () {
	int l = 0, r = 0;
	for (int i = 2; i <= len_t; ++i) {
		if (i <= r && z[i - l + 1] < r - i + 1) {
			z[i] = z[i - l + 1];
			continue;
		}
		z[i] = max (0ll, r - i + 1);
		while (i + z[i] <= len_t 
		&& t[z[i] + 1] == t[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	z[1] = len_t;
}

void get_p () {
	int l = 0, r = 0;
	for (int i = 1; i <= len_s; ++i) {
		if (i <= r && z[i - l + 1] < r - i + 1) {
			p[i] = z[i - l + 1];
			continue;
		}
		p[i] = max (0ll, r - i + 1);
		while (i + p[i] <= len_s 
		&& s[i + p[i]] == t[p[i] + 1]) ++p[i];
		if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
	}
}

void charming () {
	cin >> s + 1, cin >> t + 1;
	len_s = strlen (s + 1), len_t = strlen (t + 1);
	get_z (), get_p ();
	int res_z = 0, res_p = 0;
	for (int i = 1; i <= len_t; ++i) {
		res_z ^= (z[i] + 1) * i;
	}
	for (int i = 1; i <= len_s; ++i) {
		res_p ^= (p[i] + 1) * i;
	}
	cout << res_z << endl;
	cout << res_p << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}