#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int t, len1, len2;
int num1[26], num2[26], arr[maxn];
char s[maxn], p[maxn];
bool vis[maxn];

void init () {}

bool check (int pos) {
	memset (vis, 0, sizeof vis);
	for (int i = 1; i <= pos; ++i) vis[arr[i]] = true;
	int now = 1;
	for (int i = 1; i <= len1 && now <= len2; ++i) {
		if (vis[i]) continue;
		if (s[i] == p[now]) ++now;
	}
	if (now <= len2) return false;
	return true;
}

void charming () {
	init ();
	cin >> s + 1;
	cin >> p + 1;
	len1 = strlen (s + 1), len2 = strlen (p + 1);
	for (int i = 1; i <= len1; ++i) cin >> arr[i];
	int l = 0, r = len1, mid;
	while (l < r) {
		mid = (l + r - 1) / 2 + 1;
		if (check (mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
