#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int arr[maxn];
bool Fir_win[maxn];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	if (n == 1) {
		cout << "First" << endl;
		return;
	}
	Fir_win[n] = true;
	for (int i = n - 1; i >= 1; --i) {
		if (!Fir_win[i+1]) {
			Fir_win[i] = true;
			continue;
		}
		else if (arr[i] == 1) {
			Fir_win[i] = false;
			continue;
		}
		else {
			Fir_win[i] = true;
			continue;
		}
	}
	if (Fir_win[1]) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
