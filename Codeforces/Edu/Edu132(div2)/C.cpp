#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, len;
int cnt_l[maxn], cnt_r[maxn];
char str[maxn];
vi l, r;

void init () {
	l.clear (), r.clear ();
	for (int i = 1; i <= len; ++i) {
		cnt_l[i] = cnt_r[i] = 0;
	}
}

void charming () {
	init ();
	cin >> str + 1;
	len = strlen (str + 1);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= len; ++i) {
		if (str[i] == '(') ++cnt1;
		if (str[i] == ')') ++cnt2;
	}
	int give_l = len / 2 - cnt1, give_r = len / 2 - cnt2;
	for (int i = 1; i <= len; ++i) {
		if (str[i] == '?') {
			if (give_l > 0) {
				str[i] = '(';
				l.pb (i);
				--give_l;
			}
			else {
				str[i] = ')';
				r.pb (i);
				--give_r;
			}
		}
	}
	for (int i = 1; i <= len; ++i) {
		cnt_l[i] = cnt_l[i - 1];
		cnt_r[i] = cnt_r[i - 1];
		if (str[i] == '(') ++cnt_l[i];
		else ++cnt_r[i];
	}
	if ((!r.size ()) || (!l.size ())) {
		cout << "YES" << endl;
		return;
	}
	int beg = l[l.size () - 1], en = r[0];
	for (int i = beg; i < en; ++i) {
		--cnt_l[i], ++cnt_r[i];
	}
	for (int i = beg; i <= en; ++i) {
		if (cnt_l[i] < cnt_r[i]) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}