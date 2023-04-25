#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	string s;
	cin >> s;
	vector <pair <int, char> > cnt (26);
	vector <pair <int, char> > old;
	for (int i = 0; i < 26; ++i) cnt[i].second = (char) 'a' + i;
	for (auto &ch : s) ++cnt[ch - 'a'].first;
	old = cnt;
	sort (cnt.begin (), cnt.end (), [] (pair <int, char> &x,
	pair <int, char> &y) {return x.first > y.first;});
	vector <int> rk (26);
	for (int i = 0; i < 26; ++i) rk[cnt[i].second - 'a'] = i;
	int res = INT_MAX;
	string res_str;
	for (int i = 0; i < 26; ++i) {
		if (n % (i + 1)) continue;
		int ave = n / (i + 1), step = 0;
		string tmp = s;
		vector <pair <int, char> > ncnt = old;
		for (int j = 0, num; j < n; ++j) {
			num = s[j] - 'a';
			if ((rk[num] <= i && ncnt[num].first > ave) || rk[num] > i) {
				for (int k = 0; k < 26; ++k) {
					if (rk[k] <= i && ncnt[k].first < ave) {
						tmp[j] = 'a' + k;
						++ncnt[k].first, --ncnt[num].first;
						++step;
						break;
					}
				}
			}
		}
		if (step < res) {
			res = step;
			res_str = tmp;
		}
	}
	cout << res << endl;
	cout << res_str << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}