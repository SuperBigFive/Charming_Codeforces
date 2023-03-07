#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t;

void init () {

}

void charming () {
	init ();
	int cnt[30];
	char ch[4];
	fill (cnt, cnt + 30, 0);
	for (int i = 0; i < 4; ++i) {
		cin >> ch[i];
		++cnt[ch[i] - 'a' + 1];
	}
	vector <int> kind;
	for (int i = 1; i <= 26; ++i) {
		if (cnt[i]) kind.emplace_back (cnt[i]);
	}
	if (kind.size () == 1) {
		cout << 0 << endl;
		return;
	}
	if (kind.size () == 2) {
		cout << 1 << endl;
		return;
	}
	if (kind.size () == 3) {
		cout << 2 << endl;
		return;
	}
	cout << 3 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}