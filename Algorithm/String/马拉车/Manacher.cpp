#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e7 + 5;

struct Manacher {
	int n;
	string s, ns;
	vector <int> ra;
	
	Manacher (string &s) {
		this -> n = s.size ();
		this -> s = s;
		ns += '#', ns += '#';
		for (int i = 0; i < n; ++i) ns += s[i], ns += '#';
		n = n << 1 | 1;
		this -> ra = vector <int> (n + 5);
	}
	
	void Get_ra () {
		for (int i = 1, l = 0, r = 0; i <= n; ++i) {
			if (i <= r) ra[i] = min (r - i + 1, ra[l + r - i]);
			while (i + ra[i] <= n && i - ra[i] >= 1
			&& ns[i + ra[i]] == ns[i - ra[i]]) ++ra[i];
			if (i + ra[i] - 1 > r) r = i + ra[i] - 1, l = i - ra[i] + 1;
		}
	}
};

string s;

void init () {}

void charming () {
	init ();
	cin >> s;
	Manacher manacher (s);
	manacher.Get_ra ();
	vector <int> &ra = manacher.ra;
	cout << *max_element (ra.begin (), ra.end ()) - 1 << endl;
}

signed main () {
	charming ();
	return 0;
}