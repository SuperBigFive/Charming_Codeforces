#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, tot;
bool flag;
int arr[maxn];
int ans[maxn];

void init () {tot = 0, flag = false;}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) {
		init ();
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> arr[i];
		for (int i = 1; i <= n; ) {
			int j = i;
			while (arr[j] == arr[i] && j <= n) ++j;
			if (j == i + 1) {
				flag = true;
				break;
			}
			ans[++tot] = j - 1;
			for (int k = i + 1; k < j; ++k) ans[++tot] = k - 1;
			i = j;
		}
		if (flag) {
			cout << -1 << endl;
		}
		else {
			for (int i = 1; i <= tot; ++i) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
