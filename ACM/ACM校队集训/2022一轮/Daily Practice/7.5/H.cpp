#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, k, a, b;
char str[maxn];
init () {}

void charming () {
	init ();
	cin >> n >> k >> a >> b;
	int cnt = 0, cntt = 0;
	
	if (a > b) {
		if ((b + 1) * k < a) {
			cout << "NO" << endl;
			return;
		}
		
		int upp = (a - 1) / (b + 1) + 1;
		if (upp > k) {
			cout << "NO" << endl;
			return;
		}
		
		int should = b + 1 - ((b + 1) * upp - a);
		for (int i = 1; i <= n; ++i) {
			if (cnt == upp) {
				str[i] = 'B';
				cnt = 0;
				++cntt;
				if (cntt == should) --upp;
				continue;
			}
			str[i] = 'G';
			++cnt;
		}
	}
	
	if (a < b) {
		if ((a + 1) * k < b) {
			cout << "NO" << endl;
			return;
		}
		
		int upp = (b - 1) / (a + 1) + 1;
		if (upp > k) {
			cout << "NO" << endl;
			return;
		}
		
		int should = a + 1 - ((a + 1) * upp - b);
		for (int i = 1; i <= n; ++i) {
			if (cnt == upp) {
				str[i] = 'G';
				cnt = 0;
				++cntt;
				if (cntt == should) --upp;
				continue;
			}
			str[i] = 'B';
			++cnt;
		}
	}
	
	if (a == b) {
		for (int i = 1; i <= n; i += 2) {
			str[i] = 'G';
			str[i+1] = 'B';
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << str[i];
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming (); 
}
