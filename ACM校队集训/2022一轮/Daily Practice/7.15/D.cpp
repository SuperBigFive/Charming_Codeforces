#include <iostream>
#include <cstring>
#include <cmath>
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
const int N = 1e6 + 15, M = 1e6 + 15;

int t, mmin, lena, lenb;
char a[maxn], b[maxn], pre_b[maxn];
char p[N], s[M];
int ne[N];
int pos[N];
int tot;

bool kmp (int numm) {
	for (int i = 0; i < maxn; ++i) {
		ne[i] = 0;
	}
	for (int i = 0; i <= numm; ++i) p[i] = b[i];
	for (int i = 2, j = 0; i <= numm; ++i) {
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) ++j;
		ne[i] = j;
	}
	int times = 0;
	for (int i = 1, j = 0; i <= lena; ++i) {
		while (j && a[i] != p[j + 1]) j = ne[j];
		if (a[i] == p[j + 1]) ++j;
		if (j == numm) {
			++times;
			j = ne[j];
		}
	}
	return times >= mmin;
}

bool check (int num) {
	if (kmp (num)) return true;
	return false;
}

void charming () {
	lena = 0, lenb = 0;
	char ch = '&';
	int cnt = 1;
	while (cnt <= 2) {
		ch = getchar ();
		if (ch == 10) {
			++cnt;
			continue;
		}
		if (cnt == 1) a[++lena] = ch;
		else b[++lenb] = ch;
	}
	lena = strlen (a + 1);
	lenb = strlen (b + 1);
	cin >> mmin;
	int l = 0, r = lenb + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check (mid)) l = mid;
		else r = mid;
	}
	if (l) {
		for (int i = 1; i <= l; ++i) {
			cout << b[i];
		}
		cout << endl;
	}
	else cout << "-1" << endl;
}

int main() {
	cin >> t;
	while (t--) charming ();
	return 0;
}
