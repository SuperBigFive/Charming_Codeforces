#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int n, tot;
int a[maxn], b[maxn], t[maxn];
int candi1[maxn], candi2[maxn];
bool ok;

void dfs (int cur) {
	if (ok) return;
	for (int j = 0; j <= 3; ++j) {
		if (ok) return;
		if (cur > 1 && b[cur - 1] == 1 && (j == 2 || j == 0)) continue;
		if (cur > 1 && b[cur - 1] == 2 && (j == 1 || j == 0)) continue;
		if (cur > 1 && b[cur - 1] == 3 && j != 3) continue;
		
		if (cur > 1 && a[cur - 1] == 1 && (j == 2 || j == 3)) continue;
		if (cur > 1 && a[cur - 1] == 2 && (j == 1 || j == 3)) continue;
		if (cur > 1 && a[cur - 1] == 0 && j != 0) continue;
	
		if (((j | t[cur + 1])== a[cur]) && ((j & t[cur + 1])== b[cur])) {
			t[cur] = j;
			if (cur == 1) ok = true;
			else dfs (cur - 1);
			if (ok) return;
		}
	}
}

void charming () {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		cin >> b[i];
	}
	int tn, tn_1;
	ok = false;
	for (tn_1 = 0; tn_1 <= 3; ++tn_1) {
		
		if (n > 2 && b[n - 2] == 1 && (tn_1 == 2 || tn_1 == 0)) continue;
		if (n > 2 && b[n - 2] == 2 && (tn_1 == 1 || tn_1 == 0)) continue;
		if (n > 2 && b[n - 2] == 3 && tn_1 != 3) continue;
		
		if (n > 2 && a[n - 2] == 1 && (tn_1 == 2 || tn_1 == 3)) continue;
		if (n > 2 && a[n - 2] == 2 && (tn_1 == 1 || tn_1 == 3)) continue;
		if (n > 2 && a[n - 2] == 0 && tn_1 != 0) continue;
		
		for (tn = 0; tn <= 3; ++tn) {
			if (((tn_1 | tn) == a[n - 1]) && ((tn_1 & tn) == b[n - 1])) {
				candi1[++tot] = tn_1, candi2[tot] = tn;
			}
		}
	}
	ok = false;
	if (n == 2) {
		for (int i = 1; i <= tot; ++i) {
			cout << "YES" << endl;
			cout << candi1[1] << " " << candi2[1] << endl;
			return;
		} 
		cout << "NO" << endl;
		return;
	}
	for (int i = 1; i <= tot; ++i) {
		if (!ok) {
			t[n] = candi2[i], t[n - 1] = candi1[i];
			dfs (n - 2);
		}
		else break;
	}
	if (ok) {
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++i) {
			cout << t[i] << ' ';
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
		return;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}