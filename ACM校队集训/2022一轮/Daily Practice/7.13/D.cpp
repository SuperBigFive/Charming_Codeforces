#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int n;
char str1[maxn], str2[maxn];
ll cnt1[3], cnt2[3];

void init () {
	memset (cnt1, 0, sizeof cnt1);
	memset (cnt2, 0, sizeof cnt2);
}

void charming () {
	init ();
	cin >> n;
	cin >> str1 + 1;
	cin >> str2 + 1;
	int num1, num2;
	for (int i = 1; i <= n; ++i) {
		num1 = str1[i] - 'a' + 1;
		num2 = str2[i] - 'a' + 1;
		++cnt1[num1];
		++cnt2[num2];
	}
	for (int i = 1; i <= 2; ++i) {
		if ((cnt1[i] + cnt2[i]) & 1) {
			cout << -1 << endl;
			return;
		}
	}
	vector <pair <char, int> > v;
	for (int i = 1; i <= n; ++i) {
		if (str1[i] != str2[i]) {
			v.pb ({str1[i], i});
		}
	}
	sort (v.begin (), v.end ());
	vector <pair <int, int> > res;
	bool flag = cnt1[1] - cnt2[1] > 0 ? true : false;
	int diff = abs (cnt1[1] - cnt2[1]) / 2;
	int p1, p2, ans = diff;
	if (flag) {
		p1 = 0, p2 = 0;
		while (p2 < v.size () && v[p2].fir == 'a' ) ++p2;
		--p2; 
	} 
	else {
		p1 = v.size () - 1, p2 = v.size () - 1;
		while (p1 >= 0 && v[p1].fir == 'b') --p1;
		++p1;
	}
	while (diff) {
		int pos1 = v[p1].se, pos2 = v[p2].se;
		char tmp = str1[pos1];
		res.pb ({pos1, pos2});
		str1[pos1] = str2[pos2];
		str2[pos2] = tmp;
		++p1;
		--p2;
		--diff;
	}
	v.clear ();
	for (int i = 1; i <= n; ++i) {
		if (str1[i] != str2[i]) v.pb ({str1[i], i});
	}
	sort (v.begin (), v.end ());
	ans += v.size () / 2;
	int p3, p4;
	p1 = 0, p2 = 0, p3 = v.size () - 1, p4 = v.size () - 1;
	while (p2 < v.size () && v[p2].fir == 'a') ++p2;
	--p2;
	while (p3 >= 0 && v[p3].fir == 'b') --p3;
	++p3;
	for (int i = 0; i < v.size () / 4; ++i) {
		res.pb ({v[p1].se, v[p2].se});
		res.pb ({v[p3].se, v[p4].se});
		++p1, --p2, ++p3, --p4;
	}
	if (v.size () % 4) {
		res.pb ({v[p3].se, v[p3].se});
		res.pb ({v[p3].se, v[p2].se});
		++ans;
	}
	cout << ans << endl;
	for (int i = 0; i < res.size (); ++i) {
		cout << res[i].fir<< ' ' << res[i].se << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}