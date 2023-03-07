#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 4e5 + 5;
const int maxrk = 4e5 + 5;

int n, tot, pow2, st;
int sa[maxn], rk[maxn], tmp_sa[maxn], old_rk[maxn];
int cnt[maxrk];
char s[maxn], t[maxn], str[maxn], tmp_s[maxn], tmp_t[maxn];

void init () {
	for (int i = 1; i < maxn; ++i) {
		sa[i] = rk[i] = tmp_sa[i] = old_rk[i] = cnt[i] = 0;
	}
}

void key2_sort () {
	int cntt = 0;
	for (int i = n; i > n - pow2; --i) tmp_sa[++cntt] = i;
	for (int i = 1; i <= n; ++i) {
		if (sa[i] > pow2) tmp_sa[++cntt] = sa[i] - pow2;
	}
}

void key1_sort () {
	for (int i = 1; i <= n; ++i) ++cnt[rk[tmp_sa[i]]];
	for (int i = 1; i < maxrk; ++i) cnt[i] += cnt[i-1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[tmp_sa[i]]]--] = tmp_sa[i];
}

void update (int num) {
	if (old_rk[sa[num]] == old_rk[sa[num-1]] && old_rk[sa[num]+pow2] == old_rk[sa[num-1]+pow2]) {
		rk[sa[num]] = tot;
	}
	else rk[sa[num]] = ++tot;
}

int get_str () {
	if (st) init ();
	n = strlen (str + 1);
	
	for (int i = 1; i <= n; ++i) rk[i] = str[i], ++cnt[rk[i]];
	for (int i = 1; i < maxrk; ++i) cnt[i] += cnt[i-1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (pow2 = 1; pow2 < n; pow2 <<= 1) {
		key2_sort ();
		memset (cnt, 0 , sizeof cnt);
		key1_sort ();
		memcpy (old_rk, rk, sizeof rk);
		tot = 0;
		for (int i = 1; i <= n; ++i) update (i);
		if (tot == n) {
			for (int i = 1; i <= n; ++i) sa[rk[i]] = i;
			break;
		}
	}
	
	return sa[n];
	//for (int i = 1; i <= n; ++i) cout << sa[i] << " ";
	//cout << endl;
}

void charming () {
	scanf ("%s", s + 1);
	memcpy (str, s, sizeof str);
	int pos = get_str ();
	for (int i = pos; i <= n; ++i) {
		tmp_s[i - pos + 1] = str[i];
	}
	st = 1;
	int len_1 = n - pos + 1;
	scanf ("%s", t + 1);
	memcpy (str, t, sizeof str);
	pos = get_str ();
	for (int i = pos; i <= n; ++i) {
		tmp_t[i - pos + 1] = str[i];
	}
	int len_2 = n - pos + 1;
	int num1, num2 = tmp_t[1] - 'a' + 1;
	for (int i = 1; i <= len_1; ++i) {
		num1 = tmp_s[i] - 'a' + 1;
		if (num1 < num2 && i != 1) break;
		printf ("%c", tmp_s[i]);
	}
	for (int i = 1; i <= len_2; ++i) {
		printf ("%c", tmp_t[i]);
	}
	printf ("\n");
}

int main () {
	charming ();
	return 0;
}