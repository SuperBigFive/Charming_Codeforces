#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e3 + 5;

int cnta, cntb, k;
long double a, b;
int da[maxn], db[maxn], num[maxn];

void init () {}

bool check (int siz) {
	int ans[maxn], newa[maxn];
	memset (ans, 0, sizeof ans);
	memset (newa, 0, sizeof newa);
	for (int i = 1; i <= cntb; ++i) {
		for (int j = siz; j >= 1; --j) {
			ans[i + siz - j] += db[i] * num[j];
		}
	}
	int mx = 0;
	for (int i = 1, carry = 0; i < maxn; ++i) {
		int tmp = ans[i];
		ans[i] = (ans[i] + carry) % 10;
		carry = (tmp + carry) / 10;
		if (ans[i]) mx = i;
	}
	for (int i = 1; i <= cnta; ++i) {
		newa[i + siz] = da[i];
	}
	if (siz + cnta > mx) return false;
	for (int i = mx; i >= 1; --i) {
		if (newa[i] != ans[i]) return newa[i] < ans[i];
	}
	return true;
}

void charming () {
	init ();	
	cin >> a >> b >> k;
	int olda = a;
	int tmp = a;
	while (tmp) {
		da[++cnta] = tmp % 10;
		tmp /= 10;
	}
	tmp = b;
	while (tmp) {
		db[++cntb] = tmp % 10;
		tmp /= 10;
	}
	a = (int) a % (int) b;
	for (int i = 1; i <= k + 1; ++i) {
		for (int j = 1; j < 10; ++j) {
			num[i] = j;
			if (check (i)) {
				num[i] = j - 1;
				break;
			}
		}
	}
	num[k] += (num[k + 1] >= 5);
	for (int i = k, carry = 0; i >= 1; --i) {
		int tmp = num[i];
		num[i] = (num[i] + carry) % 10;
		carry = (tmp + carry) / 10;
	}
	cout << (int) olda / (int) b + num[0] << ".";
	for (int i = 1; i <= k; ++i) cout << num[i];
}

signed main () {
	charming ();
	return 0;
}