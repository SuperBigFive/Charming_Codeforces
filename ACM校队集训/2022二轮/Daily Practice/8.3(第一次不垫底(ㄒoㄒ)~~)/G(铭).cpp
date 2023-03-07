#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 3e5 + 5;

int n, a, b, d, res;
int val[maxn];

void init () {

}

bool check () {
	if (a + b > n + 1) return false;
	d = n / b;
	res = n - b * d;
	if (res > b) {
		res -= b;
		++d;
	}
	if (d > a || d == a && res) return false; 
	if (res + d < a) {
		--d;
		res += b;
	}
	return true;
}

void charming () {
	init ();
	cin >> n >> a >> b;
	bool change = false;
	if (a > b) {
		swap (a, b);
		change = true;
	}
	if (!check ()) {
		cout << -1 << endl;
		exit (0);
	}
	int beg = res + 1;
	for (int i = n - b + 1; i >= beg; i -= b) {
		for (int j = i; j <= i + b - 1; ++j) {
			val[j] = i + b - 1 - (j - i);
		}
	}
	int diff = a - d;
	--beg;
	for (int i = 1; i <= beg - diff; ++i) {
		val[i] = beg - i + 1;
	}
	for (int i = beg - diff + 1; i <= beg; ++i) {
		val[i] = i - (beg - diff);
	}
	if (!change) for (int i = 1; i <= n; ++i) cout << val[i] << ' ';
	else for (int i  = n; i >= 1; --i) cout << val[i] << ' ';
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}