#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int n, m;

void init () {}

void charming () {
	set <int> s;
	int arr[5];
	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
		s.insert (arr[i]);
	}
	cout << s.size () << endl;
}

signed main () {
	charming ();
	return 0;
}