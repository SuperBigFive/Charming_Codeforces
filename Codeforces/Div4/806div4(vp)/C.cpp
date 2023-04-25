#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n, k;
int digit[maxn];

void init () {
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> digit[i];
	}
	char opt[1000];
	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		cin >> opt + 1;
		int u = 0, d = 0;
		for (int i = 1; i <= num; ++i) {
			if (opt[i] == 'D') ++d;
			else ++u;
		}
		digit[i] += d - u;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ((digit[i] % 10 + 10) % 10) << " ";
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}