#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;

struct SA {
	int n, m, w, tot;
	string s;
	vector <int> sa, rk, height;
	vector <int> cnt, id, old_rk;
	
	SA (string &s) {
		this -> n = s.size (), this -> tot = 0;
		this -> s = '#' + s;
		this -> sa = this -> height = this -> id = 
		this -> rk = this -> old_rk = vector <int> (n << 1 | 1);
		this -> cnt = vector <int> (N);
	}
	
	void Sort () {
		m = 300;
		for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
		for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; --i) 
		sa[cnt[rk[i]]--] = i;
		
		auto Key2_sort = [&] () {
			tot = 0;
			fill (cnt.begin (), cnt.begin () + m + 5, 0);
			for (int i = n; i >= n - w + 1; --i) id[++tot] = i;
			for (int i = 1; i <= n; ++i) {
				if (sa[i] - w >= 1) id[++tot] = sa[i] - w;
			}
		};
		
		auto Key1_sort = [&] () {
			for (int i = 1; i <= n; ++i) ++cnt[rk[i]];
			for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
		};
		
		auto Update = [&] () {
			tot = 0;
			old_rk = rk;
			for (int i = 1; i <= n; ++i) {
				if (old_rk[sa[i]] == old_rk[sa[i - 1]] &&
				old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = tot;
				else rk[sa[i]] = ++tot;
			}
		};
		
		for (w = 1; w < n && tot < n; w <<= 1, m = tot) {
			Key2_sort ();
			Key1_sort ();
			Update ();
		}
	}
	
	void Get_height () {
		for (int i = 1, k = 0; i <= n; ++i) {
			if (rk[i] == 1) continue;
			if (k) --k;
			while (s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
			height[rk[i]] = k;
		}
	}
};

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	SA sa (s);	
	sa.Sort ();
	for (int i = 1, siz = s.size (); i <= siz; ++i) {
		cout << sa.sa[i] << " \n"[i == siz];
	}
}

signed main () {
	charming ();
	return 0;
}