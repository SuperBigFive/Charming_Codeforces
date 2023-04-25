#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

int t, n;
char str[maxn];
char ch;

void charming () {
	cin >> str + 1;
	cin >> ch;
	vector <int> pos;
	n = strlen (str + 1);
	for (int i = 1; i <= n; ++i) {
		if (str[i] == ch) pos.push_back (i);
	}
	for (int i = 0; i < pos.size (); ++i) {
		if (pos[i] & 1) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
}
