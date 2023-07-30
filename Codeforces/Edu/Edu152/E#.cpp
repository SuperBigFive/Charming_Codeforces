#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ans = 0, sum = 0, p1 = 0, p2 = 0;
	vector <int> stk_asc (n + 5), stk_desc (n + 5);
	multiset <int> s;
	s.insert (0);
	for (int i = 1, id, val; i <= n; ++i) {
		while (p1 > 0 && a[stk_asc[p1]] > a[i]) {
			auto pre = s.lower_bound (stk_asc[p1]);
			--pre;
			if (stk_asc[p1] != *s.rbegin ()) ans -= stk_asc[p1] - *pre;
			s.erase (s.find (stk_asc[p1--]));
		}
		while (p2 > 0 && a[stk_desc[p2]] < a[i]) {
			auto pre = s.lower_bound (stk_desc[p2]);
			--pre;
			ans += stk_desc[p2] - *pre;
			s.erase (s.find (stk_desc[p2--]));
		}
		stk_asc[++p1] = i, stk_desc[++p2] = i;
		s.insert (i), s.insert (i);
		sum += ans;
	}
	cout << sum << endl;
}

signed main () {
	charming ();
	return 0;
}