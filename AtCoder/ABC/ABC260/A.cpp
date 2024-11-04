#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int n;
char s[maxn];
int cnt[maxn];

void charming () {
	cin >> s + 1;
	for (int i = 1; s[i] != '\0'; ++i) {
		++cnt[s[i] - 'a' + 1];
	}	
	bool ok = false;
	char ch;
	for (int i = 1; i <= 26; ++i) {
		if (cnt[i] == 1) {
			ch = 'a' + i - 1;
			cout << ch << endl;
			return;
		}
	}
	cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}