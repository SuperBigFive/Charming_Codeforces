#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define fir first
#define se second
using namespace std;
const int maxn = 1e5 + 5;

char str[4][maxn];
map <string, int> rot_times[2];
map <string, bool> vis;

void init () {
	
}

void charming () {
	for (int i = 1; i <= 3; ++i) cin >> str[i] + 1;
	int len = strlen (str[1] + 1);
	for (int i = 1; i <= len; ++i) {
		str[1][i + len] = str[1][i];
		str[2][i + len] = str[2][i];
		str[3][i + len] = str[3][i];
	}
	string tmp;
	for (int i = 1; i <= len; ++i) {
		tmp.clear ();
		for (int j = 1; j <= len; ++j) {
			tmp += str[1][i + j - 1];
		}
		if (!vis[tmp]) rot_times[0][tmp] = i - 1, vis[tmp] = true;
		else rot_times[1][tmp] = i - 1;
	}
	char ch[2];
	bool ok;
	int ans = INT_MAX;
	int ans1, ans2, ans3, ans4;
	for (int i = 1; i <= len; ++i) {
		tmp.clear ();
		ok = true;
		for (int j = 1; j <= len; ++j) {
			if (str[2][j + i - 1] == str[3][j]) {
				ok = false;
				break;
			}
			ch[0] = str[2][j + i - 1];
			ch[1] = str[3][j];
			if ('A' != ch[0] && 'A' != ch[1]) tmp += 'A';
			else if ('B' != ch[0] && 'B' != ch[1]) tmp += 'B';
			else tmp += 'C';
		}
		if (ok) {
			if (vis[tmp]) {
				ans1 = max (rot_times[0][tmp], i - 1);
				ans2 = max (len - rot_times[0][tmp], len - i + 1);
				ans3 = rot_times[0][tmp] + len - i + 1;
				ans4 = len - rot_times[0][tmp] + i - 1;
				
				ans = min (ans, min (ans1, min (ans2, min (ans3, ans4))));
				
				if (rot_times[1][tmp]) {
					ans1 = max (rot_times[1][tmp], i - 1);
					ans2 = max (len - rot_times[1][tmp], len - i + 1);
					ans3 = rot_times[1][tmp] + len - i + 1;
					ans4 = len - rot_times[1][tmp] + i - 1;
				}
				
				ans = min (ans, min (ans1, min (ans2, min (ans3, ans4))));
			}
		}
	}
	if (ans == INT_MAX) {
		cout << -1 << endl;
	}
	else cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}