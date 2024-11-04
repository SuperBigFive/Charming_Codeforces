#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> arr (n), stk;
	for (auto &it : arr) cin >> it;
	int id = -1;
	stk.emplace_back (arr[n - 1]);
	for (int i = n - 2; i >= 0; --i) {
		if (arr[i] > arr[i + 1]) {
			id = i;
			break;
		}
		stk.emplace_back (arr[i]);
	}
	sort (stk.begin (), stk.end (), greater <int> ());
	int mx = -1, id2;
	for (int i = 0; i < stk.size (); ++i) {
		if (stk[i] < arr[id] && mx < stk[i]) {
			mx = stk[i]; 
			id2 = i;
		}
	}
	swap (arr[id], stk[id2]);
	for (int i = id + 1; i < n; ++i) {
		arr[i] = stk[i - id - 1];
	}
	for (auto it : arr) cout << it << " \n"[it == arr.back ()];
}

signed main () {
	charming ();
	return 0;
}