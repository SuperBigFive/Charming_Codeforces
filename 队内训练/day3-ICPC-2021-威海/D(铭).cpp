#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int n, q;
int z[maxn], sum[maxn];
char s[maxn];

void init () {}

void get_z () {
	for (int i = 2, l = 0, r = 0; i <= n; ++i) {
		if (i + z[i - l + 1] - 1 < r) {
			z[i] = z[i - l + 1];
			continue;
		}
		z[i] = max (0, r - i + 1);
		while (i + z[i] <= n &&
		s[i + z[i]] == s[z[i] + 1]) ++z[i];
		if (r < i + z[i] - 1) r = i + z[i] - 1, l = i;
	}
}

void charming () {
	init ();
	scanf ("%s", s + 1);
	n = strlen (s + 1);
	get_z ();
	for (int i = n; i >= 1; --i) {
		sum[i] = sum[i + 1] + (z[i] == n - i + 1);
	}
	scanf ("%d", &q);
	int p;
	while (q--) {
		scanf ("%d", &p);
		printf ("%d\n", sum[max (n - p + 1, p) + 1]);
	}
}

signed main () {
	charming ();
	return 0;
}