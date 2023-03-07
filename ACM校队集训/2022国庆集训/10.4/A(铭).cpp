#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, tot;
int notok[10][10];
int lim[10], limb[10], skip[10];
char s[10], color[10], ch[10], ans[10];
char res[10000][10];

void init () {}

bool check () {
	if (ans[1] == '1' && ans[2] == '4' && ans[4] == '4' && ans[5] == '2' && ans[7] == '5') {
		int a = 1;
	}
	int cnt[10];
	memset (cnt, 0, sizeof cnt);
	for (int i = 1, num; i <= n; ++i) {
		if (skip[i]) continue;
		num = ans[i] - '0';
		++cnt[num];
		if (notok[num][i]) return false;
	}
	for (int i = 0; i < 10; ++i) 
	if (cnt[i] < lim[i] || (cnt[i] != lim[i] && limb[i])) return false;
	int val = (ans[1] - '0') * 10 + ans[2] - '0' + (ans[4] - '0') * 10 + ans[5] - '0';
	return val == (ans[7] - '0') * 10 + ans[8] - '0';
}

void dfs (int cur) {
	if (cur > n) {
		if (check ()) {
			++tot;
			for (int i = 1; i <= n; ++i)
			res[tot][i] = ans[i];
		}
		return;
	}
	if (skip[cur]) dfs (cur + 1);
	else {
		for (int i = 0; i <= 9; ++i) {
			ans[cur] = ch[i];
			dfs (cur + 1);
		}
	}
}
			
void charming () {
	init ();
	cin >> s + 1;
	cin >> color + 1;
	n = strlen (s + 1);
	for (int i = 0; i < 10; ++i)
	ch[i] = '0' + i;
	for (int i = 1, num; i <= n; ++i) {
		if (s[i] == '+') {
			ans[i] = '+';
			skip[i] = 1;
			continue;
		}
		else if (s[i] == '=') {
			ans[i] = '=';
			skip[i] = 1;
			continue;
		}
		else { 
			num = s[i] - '0';
			if (color[i] == 'G') ans[i] = s[i], skip[i] = 1;
			else if (color[i] == 'P') {
				++lim[num];
				notok[num][i] = 1;
			}
			else notok[num][i] = 1, ++limb[num];
		}
	}
	dfs (1);
	cout << tot << endl;
	for (int i = 1; i <= tot; ++i) {
		for (int j = 1; j <= n; ++j)
		cout << res[i][j];
		cout << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}