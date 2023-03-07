#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int n;
char str[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	cin >> str + 1;
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	char last = str[1];
	int ans = n;
	for (int i = 2; i <= n; ++i) {
		if (last == '0') {
			last = str[i];
			continue;
		}
		if (str[i] == last) {
			continue;
		}
		else {
			--ans;
			last = '0';
		}
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}