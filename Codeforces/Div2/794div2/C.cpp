#include <bits/stdc++.h>
using namespace std;
const int maxn  = 1e5 + 5;

int t, n;
int i, j, k;
int arr[maxn], a[maxn], b[maxn], c[maxn];
char str[maxn];
bool flag1, flag2;

void init () {}

bool valid () {}

void solve () {
	cin >> n;
	for (i = 1; i <= n; ++i) scanf ("%d",&arr[i]);
	sort (arr + 1, arr + 1 + n);
	c[n+1] = 0;
	for (i = 1; i <= (n+1)/2; ++i) {
		a[i] = arr[i];
	}
	for (i = (n+1)/2 + 1; i <= n; ++i) {
		b[i - (n+1)/2] = arr[i];
	}
	int tot = 0;
	for (i = 1; i <= (n+1)/2 + 1; ++i) {
		c[++tot] = a[i];
		if (tot < n) c[++tot] = b[i]; 
	} 
	for (i = 2; i <= n; i += 2) {
		if (c[i] <= c[i+1] || c[i] <= c[i-1]) {
			printf ("NO\n");
			return;
		}
	}
	if (c[n] <= c[n-1] || c[n] <= c[1]) {
		printf ("NO\n");
		return;
	}
	printf ("YES\n");
	for (i = 1; i <= n; ++i) printf ("%d ",c[i]);
	printf ("\n");
}

int main (void) {
	/*ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);*/
	cin >> t;
	while (t--) solve ();
}
