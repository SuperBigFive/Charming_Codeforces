#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 1e5 + 5;

int t, n1, n2, n3;
char str1[51][maxn];
char str2[51][maxn];
char str3[51][maxn];

void charming () {
	cin >> n1 >> n2 >> n3;
	for (int i = 1; i <= n1; ++i) {
		cin >> str1[i] + 1;
	}
	for (int i = 1; i <= n2; ++i) {
		cin >> str2[i] + 1;
	}
	for (int i = 1; i <= n3; ++i) {
		cin >> str3[i] + 1;
	} 
	int v1 = 0, v2 = 0, v3 = 0;
	int y1 = 0, y2 = 0, y3 = 0;
	
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; str1[i][j] != '\0'; ++j) {
			if (str1[i][j] == 'A' || str1[i][j] == 'E' || str1[i][j] == 'I' || str1[i][j] == 'O' || str1[i][j] == 'U' 
			|| str1[i][j] == 'a' || str1[i][j] == 'e' || str1[i][j] == 'i' || str1[i][j] == 'o' || str1[i][j] == 'u')
			++v1;
			if (str1[i][j] == 'Y' || str1[i][j] == 'y')
			++y1;
		}
	}
	
	for (int i = 1; i <= n2; ++i) {
		for (int j = 1; str2[i][j] != '\0'; ++j) {
			if (str2[i][j] == 'A' || str2[i][j] == 'E' || str2[i][j] == 'I' || str2[i][j] == 'O' || str2[i][j] == 'U'
			|| str2[i][j] == 'a' || str2[i][j] == 'e' || str2[i][j] == 'i' || str2[i][j] == 'o' || str2[i][j] == 'u')
			++v2;
			if (str2[i][j] == 'Y' || str2[i][j] == 'y')
			++y2;
		}
	}
	
	for (int i = 1; i <= n3; ++i) {
		for (int j = 1; str3[i][j] != '\0'; ++j) {
			if (str3[i][j] == 'A' || str3[i][j] == 'E' || str3[i][j] == 'I' || str3[i][j] == 'O' || str3[i][j] == 'U'
			|| str3[i][j] == 'a' || str3[i][j] == 'e' || str3[i][j] == 'i' || str3[i][j] == 'o' || str3[i][j] == 'u')
			++v3;
			if (str3[i][j] == 'Y' || str3[i][j] == 'y')
			++y3;
		}
	}
	
	if (v1 > 5 || v2 > 7 || v3 > 5) {
		cout << "NO" << endl;
		return;
	}
	if (v1 + y1 >= 5 && v2 + y2 >= 7 && v3 + y3 >= 5) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

int main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
