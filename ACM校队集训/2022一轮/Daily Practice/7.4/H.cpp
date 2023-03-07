#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
ll arr[maxn];

void charming () {
	cin >> n;
	int cnt = 1;
	if (!(n & 1)) cout << "NO" << endl;
	else {
		for (int i = 1; i <= n; ++i) {
			if(cnt & 1) {
				arr[i] = (i << 1) - 1;
				arr[i + n] = i << 1;
			}
			else {
				arr[i + n] = (i << 1) - 1;
				arr[i] = i << 1;
			}
			++cnt;
		}
		cout << "YES" << endl;
		for (int i = 1; i <= (n << 1); ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
