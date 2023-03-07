#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n;
ll arr[maxn];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	sort (arr + 1, arr + 1 + n);
	ll cnt = 0, idx = 1;
	arr[0] = -2;
 	for (int i = 1; i < n; ++i) {
		if (arr[i] == arr[i + 1]) ++cnt, idx = i;
	}
	if (cnt >= 2 || (!arr[1] && !arr[2]) || arr[idx - 1] >= arr[idx] - 1) {
		cout << "cslnb" << endl;
		return;
	}
	ll diff = 0, beg = -1;
	for (int i = 1; i <= n; ++i) {
		if (beg >= arr[i] - 1) {
			beg = arr[i];
			continue;
		}
		diff += arr[i] - beg - 1;
		++beg;
	}
	if (diff & 1) {
		cout << "sjfnb" << endl;
	}
	else cout << "cslnb" << endl;
}

int main () {
	charming ();
	return 0;
}