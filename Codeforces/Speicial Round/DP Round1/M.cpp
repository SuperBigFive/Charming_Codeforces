#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e9 + 7;

int n, x;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	for (auto &it : a) cin >> it;	
	vector <vector <int> > SamePre;
	SamePre.emplace_back (a);
	vector <vector <int> > nSamePre;
	int inv_0 = 0, inv_1 = 0;
	for (int i = 30; i >= 0; --i) {
		nSamePre.clear ();
		int ninv_0 = 0, ninv_1 = 0;
		for (int j = 0; j < SamePre.size (); ++j) {
			int zeros = 0, ones = 0, siz = SamePre[j].size ();
			vector <int> b, c;
			for (int k = siz - 1; k >= 0; --k) {
				if (!((SamePre[j][k] >> i) & 1)) {
					++zeros, ninv_0 += ones;
					b.emplace_back (SamePre[j][k]);
				}
				else {
					++ones, ninv_1 += zeros;
					c.emplace_back (SamePre[j][k]);
				}
			}
			reverse (b.begin (), b.end ());
			reverse (c.begin (), c.end ());
			if (b.size ()) nSamePre.emplace_back (b);
			if (c.size ()) nSamePre.emplace_back (c);
		}
		inv_1 += max (ninv_1, ninv_0), inv_0 += min (ninv_1, ninv_0);
		if (ninv_1 > ninv_0) {
			x ^= (1 << i);
			for (int j = 0; j < n; ++j)
			a[j] ^= (1 << i);
			for (int j = 0; j < nSamePre.size (); ++j) {
				for (int k = 0; k < nSamePre[j].size (); ++k) {
					nSamePre[j][k] ^= (1 << i);
				}
			}
		}
		SamePre = nSamePre;	
	}
	cout << inv_0 << " " << x << endl;
}

signed main () {
	charming ();
	return 0;
}