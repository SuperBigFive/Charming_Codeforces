#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int n, m;
int i, j, k;
ll max1, max2;
ll arr[maxn];


void init () {}

bool check () {}

void solve () {
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	for (i = n; i > 1; --i) {
		if (arr[i] == arr[i-1]) {
			max1 = arr[i];
			if (i > 3 && arr[i-2] == arr[i-3] && arr[i-2] == arr[i]){
				max2 = arr[i];
				cout << max1 * max2 << endl;
				return;
			}
			break;
		}
	}
	for (i = n; i > 1; --i) {
		if (arr[i] == arr[i-1] && arr[i] != max1) {
			max2 = arr[i];
			break;
		}
		
	}
	cout << max1*max2 << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	solve ();
}
