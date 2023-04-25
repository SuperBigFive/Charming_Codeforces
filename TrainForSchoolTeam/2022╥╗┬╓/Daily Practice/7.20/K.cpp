#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
#define format pair <int, pair <int, int > >
using namespace std;
const int maxn = 2e5 + 5;

int t, n, tot, cnt;
ll pos[maxn];
char s[maxn];
char tmp[maxn];
ll pow2[61];

void init () {
	
}

void build_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i <= 60; ++i) {
		pow2[i] = pow2[i - 1]  * 2;
	}
}

void get_digit (int num) {
	cnt = 0;
	while (num) {
		if (num & 1) tmp[++cnt] = '1';
		else tmp[++cnt] = '0';
		num >>= 1;
	}
	reverse (tmp + 1, tmp + 1 + cnt);
}

void get_pos () {
	pos[1] = 2, pos[2] = 3;
	int cnt;
	for (int i = 3; pos[i - 2] <= 1000000001; ++i) {
		pos[i] = pos[i - 1] + (i - 1) * pow2[i - 2];
		cnt = i;
	}
	cnt = cnt;
}
void charming () {
	init ();
	/*for (int i = 1; i <= 65; ++i) {
		get_digit (i);
		for (int j = 1; j <= cnt; ++j) {
			s[++tot] = tmp[j];
		}
		s[++tot] = '|';
	}
	for (int i = 1; i <= tot; ++i) printf ("%c", s[i]);*/
	ll k;
	cin >> k;
	ll ans = 0;
	while (k >= pos[ans + 1]) 
	++ans;
	cout << ans << endl;
}

signed main () {
	build_pow2 ();
	get_pos ();
	cin >> t;
	while (t--)	charming ();
	return 0;
}