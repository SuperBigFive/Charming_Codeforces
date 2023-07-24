#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;  
const int N = 1e5 + 5;
const int M = 26;

struct KMP {
	int n;
	string t;
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
		s = '#' + s;
		for (int i = 1, j = 0; i <= siz; ++i) {
			while (j && t[j + 1] != s[i]) j = fail[j];
			if (t[j + 1] == s[i]) ++j;
			if (j >= n) {
				ans.emplace_back (i - n + 1);
				j = fail[j];
			}
		}
		return ans;
	}
};

int t, n, m, tot;

void init () {}

void charming () {
	string s, t;
	cin >> s >> t;
	KMP kmp (t);
	vector <int> pos = kmp.Match (s);
	for (int i : pos) cout << i << endl;
	for (int i = 1, siz = t.size (); i <= siz; ++i) {
		cout << kmp.fail[i] << " \n"[i == siz];
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
 