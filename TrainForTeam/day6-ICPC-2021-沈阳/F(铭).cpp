#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n;

void init () {}

string solve (string s) {
	int m = s.length ();
	int pos[30], vis[30], nxt[30], diff[1005];
	memset (vis, 0, sizeof pos);
	memset (pos, -1, sizeof vis);
	memset (nxt, -1, sizeof nxt);
	memset (diff, 0, sizeof diff);
	for (int i = m - 1, num; i >= 0; --i) {
		diff[i] = diff[i + 1];
		num = s[i] - 'a';
		if (!vis[num]) ++diff[i], pos[num] = i;
		vis[num] = true;
	}
	for (int i = 0; i < 26; ++i) if (pos[i] != -1) {
		nxt[i] = (char) 'a' + diff[pos[i] + 1];
	}
	for (auto &it : s) it = nxt[it - 'a'];
	return s;
}

void charming () {
	init ();	
	cin >> n;
	string s;
	cin >> s;
	vector <string> ans;
	for (int i = 1; i <= n; ++i) 
	ans.emplace_back (solve (s.substr (0, i)));
	sort (ans.begin (), ans.end ());
	cout << ans.back () << endl;
}

signed main () {
	charming ();
	return 0;
}