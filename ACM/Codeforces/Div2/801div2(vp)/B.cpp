#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int arr[maxn];

void charming () {
	cin >> n;
	int even_min = INT_MAX, odd_min = INT_MAX;
	int pose = 0, poso = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (i & 1)  {
			if (odd_min > arr[i]) {
				odd_min = arr[i];
				poso = i;
			}
		}
		else {
			if (even_min > arr[i]) {
				even_min = arr[i];
				pose = i;
			}
		}
	}
	if (n & 1) {
		cout << "Mike" << endl;
	}
	else {
		if (odd_min < even_min || (odd_min == even_min && poso < pose)) {
			cout << "Joe" << endl;
		}
		else cout << "Mike" << endl;
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
