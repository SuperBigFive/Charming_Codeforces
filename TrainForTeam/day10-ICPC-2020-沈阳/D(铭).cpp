#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n;
string s (N, 'b');

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	vector <vector <int> > ans;
	
	auto dfs1 = [&] (auto && me, int cur) {
		if (cur >= n) {
			int cnt = 0;
			for (int i = 0; i < n; ++i)
			for (int j = i, sum = 0; j < n; ++j) {
				if (a[j] == 1) ++sum;
				if (sum & 1) ++cnt;
			}
			if (((((n & 1) == 1) && cnt == (n + 1) / 2 * (n + 1) / 2) ||
			(((n & 1) == 0) && cnt == n / 2 * (n / 2 + 1))) && ans.size () < 100) 
			ans.emplace_back (a);
			return;
		}
		a[cur] = 0, me (me, cur + 1);
		a[cur] = 1, me (me, cur + 1);
	};
	
	vector <int> b;
	vector <vector <int> > res[3];
	
	auto dfs2 = [&] (auto && me, int cur, int lim, int zeros, int id) {
		if (cur >= lim) {
			int cnt = 0;
			for (int i = 0; i < lim; ++i)
			for (int j = i, sum = 0; j < lim; ++j) {
				if (b[j] == 1) ++sum;
				if (sum & 1) ++cnt;
			}
			for (int i = 0, sum = 0; i < lim; ++i) {
				if (b[i] == 1) ++sum;
				if (sum & 1) cnt += zeros;
			}
			if (((((n & 1) == 1) && cnt == (n + 1) / 2 * (n + 1) / 2) ||
			(((n & 1) == 0) && cnt == n / 2 * (n / 2 + 1))) && res[id].size () < 100) 
			res[id].emplace_back (b);
			if (res[0].size () + res[1].size () + n - (n / 2 - 1) >= 100) {
				int remain = 99 - n + (n / 2 - 1) + 1 - ((n & 1) == 0);
				for (int i = 0; i < 2; ++i) {
					for (int j = 0; j < res[i].size (); ++j) {
						cout << s.substr (0, n / 2 - i - 2);
						for (int k = 0; k < res[i][j].size (); ++k)
						cout << (res[i][j][k] ? 'r' : 'b');
						cout << endl;
						--remain;
						if (remain <= 0) exit (0);
					}
				}
			}
			return;
		}
		if (cur) b[cur] = 0, me (me, cur + 1, lim, zeros, id);
		b[cur] = 1, me (me, cur + 1, lim, zeros, id);
	};
	if (n & 1) {
		cout << (n + 1) / 2  * (n + 1) / 2 << endl;
	}
	else {
		cout << n / 2 * (n / 2 + 1) << endl;
	}
	if (n <= 12) {
		dfs1 (dfs1, 0);
		for (int i = 0; i < ans.size (); ++i) {
			for (int j = 0; j < ans[i].size (); ++j)
			cout << (ans[i][j] ? 'r' : 'b');
			cout << endl;
		}
		cout << endl;
	}
	else {
		int be = n / 2 + 1, zeros = be - 1, remain = 100;
		cout << s.substr (0, be - 1) << 'r' << s.substr (0, n - be) << endl;
		--remain, --zeros, --be;
		if (1 + n - be + ((n & 1) == 0) >= 100) {
			for (int i = 1; i <= 99; ++i) {
				cout << s.substr (0, be - 1);
				for (int j = be; j <= n; ++j) {
					if (j == be) cout << 'r';
					else if (j == n - i + 1 + ((n & 1) == 0) || j == n - i + 2 + ((n & 1) == 0)) cout << 'r';
					else cout << 'b';
				}
				cout << endl;
			}
			return;
		}
		else {
			for (int i = 1; i <= n - be + ((n & 1) == 0); ++i) {
				cout << s.substr (0, be - 1);
				for (int j = be; j <= n; ++j) {
					if (j == be) cout << 'r';
					else if (j == n - i + 1 + ((n & 1) == 0) || j == n - i + 2 + ((n & 1) == 0)) cout << 'r';
					else cout << 'b';
				}
				cout << endl;
			}
		}
		for (int i = 0; i < 2; ++i) {
			--remain, --zeros, --be;
			b.clear (), b.resize (n - be + 1);
			dfs2 (dfs2, 0, n - be + 1, zeros, i);
			remain -= res[i].size ();
			if (remain <= 0) break;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}