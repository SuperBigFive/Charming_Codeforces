#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	map <int, int> cnt;
	set <int> s;
	vector <int> digit;
	int tmp = n;
	while (tmp) {
		digit.emplace_back (tmp % 10);
		++cnt[tmp % 10];
		s.insert (tmp % 10);
		tmp /= 10;
	}
	int siz = digit.size ();
	int ans = pow (10, siz) - 1;
	if (s.size () <= k) {
		cout << n << endl;
		return;
	}
	for (int i = 0, cur, ok; i < siz; ++i) {
		cur = digit[i] + (i > 0);
		int carry = (cur >= 10);
		if (carry) {
			cnt.clear (), s.clear ();
			for (int j = i; j < siz; ++j) {
				digit[j] += carry;
				carry = digit[j] / 10;
				digit[j] %= 10;
				++cnt[digit[j]];
				s.insert (digit[j]);
			}
		}
		cur %= 10;
		--cnt[digit[i]], ++cnt[cur];
		if (!cnt[digit[i]]) s.erase (digit[i]);
		s.insert (cur);
		if (s.size () < k) {
			vector <int> res = digit;
			res[i] = cur;
			for (int j = 0; j < i; ++j)
			res[j] = 0;
			for (int j = siz - 1; j >= 0; --j)
			cout << res[j];
			cout << endl;
			return;
		}
		if (s.size () - 1 == k && cnt[cur] <= 1) {
			ok = INT_MAX;
			for (auto it : s) {
				if (it > cur) {
					ok = min (ok, it);
					break;
				}
			}
			if (ok < INT_MAX && s.size () - 1 == k) {
				vector <int> res = digit;
				res[i] = ok;
				--cnt[cur], ++cnt[res[i]];
				if (!cnt[cur]) s.erase (cur);
				s.insert (res[i]);
				for (int j = 0; j < i; ++j) {
					res[j] = *s.lower_bound (-1);
				}
				for (int j = siz - 1; j >= 0; --j)
				cout << res[j];
				cout << endl;
				return;
			}
		}
		if (s.size () == k) {
			vector <int> res = digit;
			res[i] = cur;
			for (int j = 0; j < i; ++j)
			res[j] = *s.lower_bound (-1);
			for (int j = siz - 1; j >= 0; --j)
			cout << res[j];
			cout << endl;
			return;
		}
		--cnt[cur];
		if (!cnt[cur]) s.erase (cur);
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}