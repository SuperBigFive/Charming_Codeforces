#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		int a = n / 3;
		int b = n % 3;
		if (b) {
			if (b == 1) {
				cout << a << " " << a + 2 << " " << a - 1 << endl;
			}
			else {
				cout << a + 1 << " " << a + 2 << " " << a - 1 << endl; 
			}
		}
		else {
			cout << a << " " << a + 1 << " " << a - 1 << endl;
		}
	}
	return 0;
}
