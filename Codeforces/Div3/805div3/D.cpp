#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int t, n, p;
int cnt[30], tmp[30];
int loss[30];
char str[maxn];
char res[maxn];

void init () {
	memset (cnt, 0, sizeof cnt);
	memset (tmp, 0, sizeof tmp);
	memset (loss, 0, sizeof loss);
}

void charming () {
	init ();
	scanf ("%s", str + 1);
	scanf ("%d", &p);
	int len = strlen (str + 1);
	ll sum = 0;
	for (int i = 1; i <= len; ++i) {
		++cnt[str[i] - 'a' + 1];
		sum += str[i] - 'a' + 1;
	}
	int p1 = 26;
	ll ans = 0;
	for (int i = 1; i <= 26; ++i) tmp[i] = cnt[i];
	while (sum > p) {
		if (cnt[p1]) {
			sum -= p1;
			--cnt[p1];
		}
		else --p1;
	}
	for (int i = 1; i <= 26; ++i) {
		loss[i] = tmp[i] - cnt[i];
	}
	int tot = 0;
	for (int i = 1; i <= len; ++i) {
		if (loss[str[i] - 'a' + 1]) {
			--loss[str[i] - 'a' + 1];
		}
		else cout << str[i];
	}
	cout << endl;
}

int main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}