#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct exKMP {
	int n, m;
	string s, t;
	vector <int> z, p;
	
	exKMP (string &t) {
		this -> t = '#' + t, this -> m = t.size ();
		this -> z = vector <int> (m + 5);
		Get_z ();
	}
	
	void Get_z () {
		for (int i = 2, l = 0, r = 0; i <= m; ++i) {
			if (i <= r) z[i] = min (r - i +  1, z[i - l + 1]);
			while (i + z[i] <= m && t[i + z[i]] == t[z[i] + 1]) ++z[i];
			if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
		}
		z[1] = m;
	}
	
	vector <int> Get_p (string &s) {
		this -> s = '#' + s, this -> n = s.size ();
		vector <int> p (n + 5);
		for (int i = 1, l = 0, r = 0; i <= n; ++i) {
			if (i <= r) p[i] = min (r - i + 1, z[i - l + 1]);
			while (i + p[i] <= n && p[i] + 1 <= m
			&& this -> s[i + p[i]] == t[p[i] + 1]) ++p[i];
			if (r < i + p[i] - 1) l = i, r = i + p[i] - 1;
		}
		return p;
	}
};

struct KMP {
	int n;
	string s, t;
	vector <int> fail;
	
	KMP (string &t) {
		this -> n = t.size ();
		this -> t = '#' + t;
		this -> fail = vector <int> (n + 5);
		Get_fail ();
	}
	
	void Get_fail () {
		for (int i = 2, j; i <= n; ++i) {
			j = fail[i - 1];
			while (j && t[j + 1] != t[i]) j = fail[j];
			if (t[j + 1] == t[i]) fail[i] = j + 1;
		}
	}
	
	vector <int> Match (string &s) {
		vector <int> ans;
		int siz = s.size ();
		this -> s = '#' + s;
		for (int i = 1, j = 0; i <= siz; ++i) {
			while (j && t[j + 1] != this -> s[i]) j = fail[j];
			if (t[j + 1] == this -> s[i]) ++j;
			if (j >= n) {
				ans.emplace_back (i - n + 1);
				j = fail[j];
			}
		}
		return ans;
	}
};

int t, n1, n2, n;

void init () {}

void charming () {
	init ();
	string t1, t2, s;
	cin >> t1 >> t2 >> s;
	n1 = t1.size (), n2 = t2.size (), n = s.size ();
	vector <int> pre (n + 5), pos = KMP (t2).Match (s);
	for (int i : pos) pre[i] = 1;
	for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
	
	vector <int> p1 = exKMP (t1).Get_p (s);
	
	reverse (t1.begin (), t1.end ());
	reverse (s.begin (), s.end ());
	vector <int> p2 = exKMP (t1).Get_p (s);
	reverse (p2.begin () + 1, p2.begin () + 1 + n);
	
	ll ans = 0;
	for (int i = 1, j = n1 + n2, l, r; j <= n; ++i, ++j) {
		r = i + p1[i], l = j - p2[j] - n2;
		l = max (0ll, l);
		if (r > l) ans += pre[r] - pre[l];
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}