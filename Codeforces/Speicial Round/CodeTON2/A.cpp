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
char str1[maxn], str2[maxn];


void charming () {
	cin >> n >> m;
	cin >> str1 + 1;
	cin >> str2 + 1;
	int p1 = n, p2 = m;
	while (p2 > 1) {
		if (str1[p1] != str2[p2]) {
			cout << "NO" << endl;
			return;
		}
		--p1, --p2;
	}
	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= p1; ++i) {
		if (str1[i] == '0') ++cnt0;
		else ++cnt1;
	}
	if (str2[1] == '1' && cnt1 == 0 || str2[1] == '0' && cnt0 == 0) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	cin >> t;
	while (t--) charming ();
	return 0;
}