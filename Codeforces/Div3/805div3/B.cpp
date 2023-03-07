#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
char str[maxn];

void charming () {
	cin >> str + 1;
	int len = strlen (str + 1);
	ll ans = 0;
	char ch1, ch2, ch3;
	for (int i = 1; i <= len; ++i) {
		int j = i;
		ch1 = str[i];
		while (j <= len && (str[j] == ch1)) ++j;
		if (j > len) {
			++ans;
			break;
		}
		ch2 = str[j];
		while (j <= len && (str[j] == ch1 || str[j] == ch2)) ++j;
		if (j > len) {
			++ans;
			break;
		}
		ch3 = str[j];
		while (j <= len && (str[j] == ch1 || str[j] == ch2 || str[j] == ch3)) ++j;
		++ans;
		i = j - 1;
	}
 	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}