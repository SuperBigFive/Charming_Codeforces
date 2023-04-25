#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	string s;
	vector <array <array <int, 3>, 2> > time_table (n);
	
	auto str2num = [] (vector <int> &num) -> int {
		int ans = 0;
		for (int i = 0; i < 2; ++i) ans = ans * 10 + num[i];
		num.clear ();
		return ans;
	};
	
	for (int i = 0, cnt; i < n; ++i) {
		cin >> s, cnt = 0;
		vector <int> num;
		for (auto it : s) {
			if (it == ':') time_table[i][0][cnt++] = str2num (num);
			else num.emplace_back (it - '0');
		}
		time_table[i][0][cnt++] = str2num (num);
		cin >> s >> s, cnt = 0;
		for (auto it : s) {
			if (it == ':') time_table[i][1][cnt++] = str2num (num);
			else num.emplace_back (it - '0');
		}
		time_table[i][1][cnt++] = str2num (num);
	}
	sort (time_table.begin (), time_table.end (), [] (array <array <int, 3>, 2> &x,
	array <array <int, 3>, 2> &y) {
		if (x[0][0] != y[0][0]) return x[0][0] < y[0][0];
		else if (x[0][1] != y[0][1]) return x[0][1] < y[0][1];
		else return x[0][2] < y[0][2];
	});
	
	auto arr2string = [] (array <int, 3> x, array <int, 3> y) -> string {
		string ans;
		for (int i = 0; i < 3; ++i) {
			char ch = '0' + (x[i] / 10);
			ans.append (1, ch);
			ch = '0' + (x[i] % 10);
			ans.append (1, ch);
			if (i != 2) ans.append (1, ':');
		}
		ans.append (1, ' ');
		ans.append (1, '-');
		ans.append (1, ' ');
		for (int i = 0; i < 3; ++i) {
			char ch = '0' + (y[i] / 10);
			ans.append (1, ch);
			ch = '0' + (y[i] % 10);
			ans.append (1, ch);
			if (i != 2) ans.append (1, ':');
		}
		return ans;
	};
	
	vector <array <array <int, 3>, 2> > ans; 
	array <int, 3> start = {0, 0, 0}, end = {23, 59, 59};
	if (start != time_table[0][0]) ans.emplace_back ((array <array <int, 3>, 2>) {start, time_table[0][0]});
	for (int i = 0; i < n - 1; ++i) {
		if (time_table[i][1] != time_table[i + 1][0]) {
			ans.emplace_back ((array <array <int, 3> , 2>) {time_table[i][1], time_table[i + 1][0]});
		}
	}
	if (time_table[n - 1][1] != end) ans.emplace_back ((array <array <int, 3>, 2>) {time_table[n - 1][1], end});
	for (auto [arr1, arr2] : ans) cout << arr2string (arr1, arr2) << endl;
}

signed main () {
	charming ();
	return 0;
}