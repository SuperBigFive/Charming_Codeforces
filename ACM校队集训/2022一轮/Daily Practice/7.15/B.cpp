#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 1e4 + 5;

int n, tot;
int digit[10];
map <ll, int> cnt;

void get_digit (ll num) {
	tot = 0;
	memset (digit, 0, sizeof digit);
	while (num) {
		++digit[num % 10];
		num /= 10;
	}
}

ll get_num () {
	ll res = 0;
	for (int i = 1; i <= 9; ++i) {
		res = res * 10 + (digit[i] ? 1 : 0);
	}
	return res;
}

void charming () {
	while (cin >> n) {
		ll num, ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> num;
			get_digit (num);
			ll new_num = get_num ();
			if (!cnt[new_num]) {
				++ans, ++cnt[new_num];
			}
		}
		cout << ans << endl;
		cnt.clear ();
	}
}

int main () {
	charming ();
	return 0;
}