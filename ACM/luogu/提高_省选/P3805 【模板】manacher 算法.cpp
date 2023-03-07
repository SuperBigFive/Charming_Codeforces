#include <bits/stdc++.h>
#define ll long long 
#define kl key_l
#define kr key_r
#define tr tmp_radius
using namespace std;
const int maxn = 3e7 + 5;

int tot, key_l, key_r, tmp_radius, ans;
int radius[maxn<<1];
char str[maxn<<1], tmp_str[maxn];

void init () {tot = 0, key_l = 0, key_r = -1;}

void pre_deal (){
	for (int i = 1; tmp_str[i] != '\0'; ++i) {
		str[++tot] = '#';
		str[++tot] = tmp_str[i];
	}
	str[++tot] = '#';
}

void updata (int pos, int r) {
	if (pos + r - 1 > kr) {
		kl = pos - r + 1;
		kr = pos + r - 1;
	}
	radius[pos] = r;
}

void brute_build (int pos, int &r) {
	while (pos - r >= 1 && pos + r <= tot && str[pos-r] == str[pos+r]) ++r;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> tmp_str + 1;
	pre_deal ();
	for (int i = 1; i <= tot; ++i) {
		if (i > key_r) {
			tr = 1;
			brute_build (i, tr);
		}
		else {
			tmp_radius = min (radius[kl+kr-i], kr - i);
			brute_build (i, tr);
		}
		updata (i, tr);
	}
	for (int i = 1; i <= tot; ++i) {
			if (str[i] != '#') {
				ans = max (ans, radius[i] - 1);
			}
			else {
				ans = max (ans, radius[i] - 1);
			}
	}
	cout << ans << endl;
	return 0;
}
