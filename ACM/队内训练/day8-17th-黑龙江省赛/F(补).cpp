#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, a1, a2, b1, b2;

void init () {}

void charming () {
	init ();
	cin >> a1 >> a2 >> b1 >> b2;
	array <int, 8> dis1 = {0, 0, 1, 1, 2, 3, 3, 4};
	array <int, 8> dis2 = {0, 1, 0, 2, 1, 2, 2, 3};
	array <int, 8> dis3 = {0, 1, 2, 0, 1, 2, 2, 3};
	array <int, 8> dis4 = {0, 2, 1, 1, 0, 1, 1, 2};
	array <int, 8> dis5 = {0, 3, 2, 2, 1, 0, 2, 1};
	array <int, 8> dis6 = {0, 3, 2, 2, 1, 2, 0, 1};
	array <int, 8> dis7 = {0, 4, 3, 3, 2, 1, 1, 0};
	vector <array <int, 8> > ans;
	ans.emplace_back (dis1);
	ans.emplace_back (dis1);
	ans.emplace_back (dis2);
	ans.emplace_back (dis3);
	ans.emplace_back (dis4);
	ans.emplace_back (dis5);
	ans.emplace_back (dis6);
	ans.emplace_back (dis7);
	cout << min (ans[a1][b1] + ans[a2][b2], 
	ans[a1][b2] + ans[a2][b1]) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}