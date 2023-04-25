#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
const int p_ = 131;
const int mod = 1e9 + 7;

int n, q;
ll p[maxn];
ll hash1[maxn], hash2[maxn];
char str1[maxn], str2[maxn];

void get_p () {
	p[0] = 1;
	for (int i = 1; i < maxn; ++i) p[i] = (p[i - 1] * p_) % mod;
}

void get_hash () {
	for (int i = 1; i <= n; ++i) {
		hash1[i] = (hash1[i - 1] * p_ + str1[i] - 'a' + 1) % mod;
		hash2[i] = (hash2[i - 1] * p_ + str2[i] - 'a' + 1) % mod;
	}
}

bool check (int l, int r) {
	int r2 = n - l + 1;
	int l2 = n - r + 1;
	int diff = r - r2;
	ll tmp1 = (hash1[r] - (hash1[l - 1] * p[r - l + 1]) % mod) % mod;
	ll tmp2 = (hash2[r2] - (hash2[l2 - 1] * p[r2 - l2 + 1]) % mod) % mod;

	return ((tmp1 % mod) + mod) % mod == (tmp2 % mod + mod) % mod;
}

void charming () {
	scanf ("%d%d", &n, &q);
	scanf ("%s", str1 + 1);
	for (int i = n; i >= 1; --i) {
		str2[n - i + 1] = str1[i];
	}
	get_p ();
	get_hash ();
	int l, r;
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d", &l, &r);
		if (check (l, r)) {
			printf ("Budada\n");
			continue;
		}
		if ((r - l) & 1) {
			printf ("Budada\n");
		}
		else {
			printf ("Putata\n");
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}