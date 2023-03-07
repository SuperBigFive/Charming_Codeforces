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
#define rg register int
using namespace std;
const int maxn = 1e6 + 5;

inl int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar();
	}
	int k = ch -'0';
	while (ch = getchar(), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch-'0');
	}
	if (flag) return k;
	return -k;
}

int t, n, m;
int inf[maxn];
vi len;

void charming () {
	cin >> n >> m;
	len.clear ();
	for (int i = 1; i <= m; ++i) {
		cin >> inf[i];
	}
	sort (inf + 1, inf + 1 + m);
	len.pb (inf[1] + n - inf[m] - 1);
	for (int i = 1; i < m; ++i) {
		len.pb (inf[i + 1] - inf[i] - 1);
	}
	sort (len.begin (), len.end (), [] (int x, int y) {
		return x > y;
	});
	ll res = 0, day = 0;
	for (auto it : len) {
		it -= day * 2;
		if (it <= 0) break;
		if (it <= 2) {
			++res, ++day;
		}
		else {
			res += it - 1;
			day += 2;
		}
	}
	cout << n - res << endl;
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	cin >> t;
	while (t--) charming ();
	return 0;
}