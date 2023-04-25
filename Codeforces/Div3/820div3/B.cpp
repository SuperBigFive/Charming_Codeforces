#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int vis[maxn];
string s;

void init () {
	for (int i = 0; i <= n; ++i) vis[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	cin >> s;
	string ans;
	char ch[27];
	for (int i = 1; i <= 26; ++i) {
		ch[i] = 'a' + i - 1;
	}
	for (int i = s.size () - 1; i >= 0; --i) {
		if (s[i] == '0') {
			ans += ch[(s[i - 2] - '0') * 10 + s[i - 1] - '0'];
			i -= 2;
		}
		else ans += ch[s[i] - '0'];
	}
	for (int i = ans.size () - 1; i >= 0; --i) cout << ans[i];
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}