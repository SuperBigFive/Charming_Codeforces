#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

char s[maxn], t[maxn];
char tmp_s[maxn], tmp_t[maxn];
int cnts[maxn], cntt[maxn];

void charming () {
	init ();
	cin >> s + 1;
	cin >> t + 1;
	int lens = strlen (s + 1);
	int lent = strlen (t + 1);
	/*for (int i = 1; s[i] != lens; ++i) {
		int j = i;
		int cnt1 = 0;
		while (s[i] == s[j] && j <= )
	}*/
	
	
	int tot1 = 0, tot2 = 0;
	for (int i = 1; s[i] != '\0'; ++i) {
		if (s[i] != s[i - 1]) tmp_s[++tot1] = s[i], ++cnts[tot1];
		else ++cnts[tot1];
	}
	for (int i = 1; t[i] != '\0'; ++i) {
		if (t[i] != t[i - 1]) tmp_t[++tot2] = t[i], ++cntt[tot2];
		else ++cntt[tot2];
	}
	if (tot1 != tot2) {
		cout << "No" << endl;
		return;
	}
	for (int i = 1; i <= tot2; ++i) {
		if (tmp_s[i] != tmp_t[i] || (cnts[i] == 1 && cntt[i] > 1)|| (cnts[i] > cntt[i])) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
