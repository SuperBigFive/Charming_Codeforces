#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Lyndon {
	int n;
	string s;
	
	Lyndon (string &s) {
		this -> n = s.size ();
		this -> s = '#' + s;
	}
	
	vector <pair <int, string> > Divide () {
		vector <pair <int, string> > ans;
		for (int i = 1, j = 2, k = 1; i <= n;) {
			if (j > n || s[j] < s[k]) {
				while (i <= k) {
					ans.emplace_back (make_pair (i + j - k - 1, s.substr (i, j - k)));
					i += (j - k);
				}
				j = i + 1, k = i;		
			}
			else if (s[j] == s[k]) {
				++j, ++k;
			}
			else {
				++j, k = i;
			}
		}
		return ans;
	}
};
	
void init () {} 

void charming () {
	init ();
	string s;
	cin >> s;
	vector <pair <int, string> > ans = Lyndon (s).Divide ();
	for (auto [p, subs] : ans) cout << p << " \n"[p == ans.back ().first];
}

signed main () {
	charming ();
	return 0;
}