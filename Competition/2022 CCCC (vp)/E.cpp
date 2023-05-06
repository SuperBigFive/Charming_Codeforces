#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	vector <int> a (6);
	for (auto &it : a) cin >> it;
	cin >> n;
	vector <vector <int> > b (6, vector <int> (6));
	for (int i = 0, j, cnt; i < 6; ++i) {
		b[i][a[i] - 1] = 1, cnt = n;
		for (j = 5; j >= 0 && cnt > 0; --j) {
			if (b[i][j] == 0) --cnt;
			if (cnt == 0) {cout << j + 1 << " \n"[i == 5]; break;}
		}
	}
}

signed main () {
	charming ();
	return 0;
}