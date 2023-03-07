#include <bits/stdc++.h>
#define ll long long 
#define kl key_l
#define kr key_r
#define tr tmp_radius
using namespace std;
const int maxn = 2e7 + 5;

int tot, key_l, key_r, tmp_radius, ans, opt, len, add;
int radius[maxn<<1];
char str[maxn<<1], tmp_str[maxn];
bool flag;

void init () {tot = 0, opt = 0, add = 0, key_l = 0, key_r = -1;}

void pre_deal (){
	len = strlen (tmp_str + 1);
	int start = 1;
	while (tmp_str[start] == tmp_str[len - start + 1] && start <= len - start + 1) ++start;
	if (start > len - start + 1) flag = true;
	int endd = len - start + 1;
	for (int i = start; i <= endd; ++i) {
		str[++tot] = '#';
		str[++tot] = tmp_str[i];
	}
	str[++tot] = '#';
	add = 2*(start - 1);
}

void updata (int pos, int r) {
	if (pos + r - 1 > key_r) {
		key_l = pos - r + 1;
		key_r = pos + r - 1;
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
	if (flag) {
		cout << len << endl;
		return 0;
	}
	for (int i = 1; i <= tot; ++i) {
		if (i > key_r) {
			tmp_radius = 1;
			brute_build (i, tmp_radius);
		}
		else {
			tmp_radius = min (radius[key_l+key_r-i], key_r - i);
			brute_build (i, tmp_radius);
		}
		updata (i, tmp_radius);
	}
	for (int i = 1; i <= tot; ++i) {
		if (i - radius[i] <= 1 || i + radius[i] >= tot) {
			if (str[i] != '#') {
				if (radius[i]/2 > ans) {
					ans = radius[i]/2;
					opt = 1;
				}
			}
			else {
				if ((radius[i] - 1)/2 >= ans) {
					ans = (radius[i] - 1)/2;
					opt = 2;
				}
			}
		}
	}
	if (opt == 1) cout << ans*2 - 1 + add << endl;
	else cout << ans*2 + add << endl;
	return 0;
}
