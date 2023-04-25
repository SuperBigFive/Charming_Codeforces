#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, siz;
vector <int> pos0, diff;
vector <int> ans_ok (maxn);
string s, t, ans, test, tmp;

void init () {}

void check (int be, int len) {
	test.clear ();
	for (int i = be; i <= be + len - 1; ++i) {
		test += t[i];
	}
	tmp = t;
	for (int i = pos0[0]; i <= pos0[0] + len - 1; ++i) {
		if (tmp[i] == '1' || test[i - pos0[0]] == '1') tmp[i] = '1';
		else tmp[i] = '0';
	}
	if (ans < tmp) ans = tmp;
}


/*void check (int be, int len) {
	vector <int> ok (siz);
	if (t[be] == '0') return;
	ok[0] = true;
	for (int i = 0; i < diff.size (); ++i) {
		be += diff[i];
		if (be >= t.size ()) break;
		if (t[be] == '1') ok[i + 1] = true;
		else break;
	}
	for (int i = 0; i < siz; ++i) {
		if (ans_ok[i] == false && ok[i] == true) {
			ans_ok = ok;
			return;
		}
		else if (ans_ok[i] == true && ok[i] == false) return;
	}
}*/

void charming () {
	init ();
	cin >> n >> s;
	int be = 0;
	while (s[be] == '0') ++be;
	t = s.substr (be, n - be);
	n = t.length ();
	for (int i = 0; i < n; ++i) {
		if (t[i] == '1') continue;
		pos0.emplace_back (i); 
	}
	if (t.size () == 0) {
		cout << 0 << endl;
		return;
	}
	else if (pos0.size () == 0) {
		cout << t << endl;
		return;
	}
	ans = t;
	for (int i = 1; i < pos0.size (); ++i)
	diff.emplace_back (pos0[i] - pos0[i - 1]);
	siz = pos0.size ();
	int len = t.size () - pos0[0];
	for (int i = 0; i + len - 1 < n; ++i) {
		check (i, len);
	}
	cout << ans << endl;
	return;
	int cnt = 0;
	for (auto it : t) {
		if (it == '1') cout << "1";
		else if (ans_ok[cnt]) cout << "1", ++cnt;
		else cout << "0", ++cnt;
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}