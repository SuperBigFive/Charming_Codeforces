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
const int maxn = 1e4 + 5;
const int maxlen = 1e3 + 5;

char str[maxlen];
map <string, char> table;

void charming () {
	while (cin >> str + 1) {
		string tmp;
		int len = strlen (str + 1);
		for (int i = 1; i <= len; ++i) {
			if (str[i] != '/') tmp += str[i];
			else {
				if (str[i - 1] == '/') printf (" ");
				else printf ("%c", table[tmp]);
				tmp = "";
			}
		}
		printf ("%c", table[tmp]);
		printf ("\n");
		//if (clock () - t > 500) return;
	}
}

int main () {
	table[".-"] = 'A', table["-..."] = 'B';
	table["-.-."] = 'C', table["-.."] = 'D';
	table["."] = 'E', table["..-."] = 'F';
	table["--."] = 'G', table["...."] = 'H';
	table[".."] = 'I', table[".---"] = 'J';
	table["-.-"] = 'K', table[".-.."] = 'L';
	table["--"] = 'M', table["-."] = 'N';
	table["---"] = 'O', table[".--."] = 'P';
	table["--.-"] = 'Q', table[".-."] = 'R';
	table["..."] = 'S', table["-"] = 'T';
	table["..-"] = 'U', table["...-"] = 'V';
	table[".--"] = 'W', table["-..-"] = 'X';
	table["-.--"] = 'Y', table["--.."] = 'Z';
	charming ();
	return 0;
}