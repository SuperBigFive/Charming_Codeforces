#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
string s, t, ans;

void init () {}

void opt (int l, int r) {
	t = s;
	for (int i = l; i <= r; ++i) {
		if (s[r - (i - l)] == t[i]) {
			t[i] = (t[i] == 'd' ? 'p' : 'd');
		}
	}	
}

void cmp () {
	for (int i = 0; i < n; ++i) {
		if (t[i] != ans[i]) {
			if (t[i] < ans[i]) ans = t;
			break;
		}
	}
}

void charming () {
	init ();
	cin >> n;
	cin >> s;
	ans = s;
	int id = -1;
	for (int i = 0; i < s.size (); ++i) {
		if (s[i] == 'p') {
			id = i;
			break;
		}
	}
	for (int i = 0; i <= id; ++i) {
		for (int j = id; j < s.size (); ++j) {
			if (s[i] == 'd' && s[j] == 'd') continue;
			if (s[i + j - id] != 'p') continue;
			opt (i, j);
			cmp ();
		}
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}