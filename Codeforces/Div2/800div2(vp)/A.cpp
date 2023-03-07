#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 15;

int t;

void charming () {
	int a, b;
	cin >> a >> b;
	int c = abs (a - b);
	if (a < b) {
		while (a) {
			int cnt = 0;
			while (cnt < c && a) {
				--a;
				++cnt;
				cout << 0;
			} 
			cnt = 0;
			while (cnt < c && b) {
				--b;
				++cnt;
				cout << 1;
			}
		}
		while (b) {
			--b;
			cout << 1;
		}
	}
	else if (a > b){
		while (b) {
			int cnt = 0;
			while (cnt < c && b) {
				--b;
				++cnt;
				cout << 1;
			} 
			cnt = 0;
			while (cnt < c && a) {
				--a;
				++cnt;
				cout << 0;
			}
		}
		while (a) {
			--a;
			cout << 0;
		}
	}
	else {
		while (a) {
			cout << "01";
			--a;
		}
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
