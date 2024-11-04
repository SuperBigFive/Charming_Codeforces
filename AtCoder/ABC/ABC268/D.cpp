#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;
const int p_ = 137;
const int mod = 821574353564343;

int n, m, tot;
int seq[15], num_[15];
bool vis[15];
string str, s[15], t;
map <int, int> mp;

void init () {}

int get_hash (string &st) {
	int res = 0;
	for (int i = 0, num; i < st.size (); ++i) {
		num = st[i] - 'a';
		if (st[i] == '_') num = 26;
		res = (res * p_ + num) % mod;
	}
	return res;
}

bool check () {
	str.clear ();
	for (int i = 1; i < n; ++i) {
		str += s[seq[i]];
		for (int j = 1; j <= num_[i]; ++j) {
			str += '_';
		}
	}
	str += s[seq[n]];
	if (str.size () < 3 || str.size () > 16) return false;
	if (!mp[get_hash (str)]) return true;
	return false;
}

void dfs2 (int now, int rem) {
	if (now > n - 1) {
		if (check ()) {
			cout << str << endl;
			exit (0);
		}
		return;
	}
	for (int i = 1; i <= rem - (n - 1 - now); ++i) {
		num_[now] = i;
		dfs2 (now + 1, rem - i);
	}
}
 
void dfs1 (int now, int len) {
	if (now > n) dfs2 (1, 16 - len);
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = true, seq[now] = i;
		dfs1 (now + 1, len + s[i].size ());
		vis[i] = false;
	}
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= m; ++i) {
		cin >> t;
		++mp[get_hash (t)];
	}
	if (n == 1) {
		seq[1] = 1;
		if (check ()) {
			cout << str << endl;
			return;
		}
		cout << -1 << endl;
		return;
	}
	dfs1 (1, 0);
	cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}