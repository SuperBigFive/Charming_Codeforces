#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn = 2e5 + 5;

int t;
char str[maxn];
int cntl, cntr, cntd, cntu;

void init () {
	cntl = cntr = cntd = cntu = 0;
}

void charming () {
	init ();
	scanf ("%s", str + 1);
	int n = strlen (str + 1);
	for (int i = 1; i <= n; ++i) {
		if (str[i] == 'L') ++cntl;
		else if (str[i] == 'R') ++cntr;
		else if (str[i] == 'D') ++cntd;
		else ++cntu;
	}
	int sum;
	cntl = cntr = min (cntl, cntr);
	cntu = cntd = min (cntu, cntd);
	if (!cntu && !cntr) {
		printf ("0\n");
		return;
	}
	if (!cntu) {
		printf ("2\n");
		printf ("LR\n");
		return;
	}
	if (!cntl) {
		printf ("2\n");
		printf ("UD\n");
		return;
	}
	sum = cntl + cntr + cntu + cntd;
	printf ("%d\n", sum);
	while (cntl) printf ("L"), --cntl;
	while (cntu) printf ("U"), --cntu;
	while (cntr) printf ("R"), --cntr;
	while (cntd) printf ("D"), --cntd;
	printf ("\n");
}

int main () {
	scanf ("%d", &t);
	while (t--)	charming ();
	return 0;
}
