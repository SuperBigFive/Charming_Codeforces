#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pait <int, int> 
#define pb push_back
#define fi first
#define second
using namespace std;
const int maxn = 4e3 + 5;
const ll p_ = 131;
const int mod = 198574683923457;

int n;
ll hash_;
ll cnt1[maxn][30], cnt2[maxn][30], tmp_cnt[30];
char s1[maxn], s2[maxn], tmp[maxn];

ll get_hash () {
	hash_ = 0;
	for (int i = 1; i <= 26; ++i) {
		hash_ = (hash_ * p_ + tmp_cnt[i]) % mod;
	}
	return hash_;
}

void charming () {
	cin >> s1 + 1;
	cin >> s2 + 1;
	int len1 = strlen (s1 + 1), len2 = strlen (s2 + 1);
	if (len1 < len2) {
		for (int i = 1; i <= len1; ++i) {
			tmp[i] = s1[i];
		}
		for (int i = 1; i <= len2; ++i) {
			s1[i] = s2[i];
		}
		for (int i = 1; i <= len1; ++i) {
			s2[i] = tmp[i];
		}
		swap (len1, len2);
	}
	int num;
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= 26; ++j) {
			cnt1[i][j] = cnt1[i - 1][j];
		}
		num = s1[i] - 'a' + 1;
		++cnt1[i][num];
	}
	for (int i = 1; i <= len2; ++i) {
		for (int j = 1; j <= 26; ++j) {
			cnt2[i][j] = cnt2[i - 1][j];
		}
		num = s2[i] - 'a' + 1;
		++cnt2[i][num];
	}
	for (int len = len2; len >= 1; --len) {
		map <int, bool> exist;
		for (int i = 1; i + len - 1 <= len1; ++i) {
			for (int j = 1; j <= 26; ++j) {
				tmp_cnt[j] = cnt1[i + len - 1][j] - cnt1[i - 1][j];
			}
			exist[get_hash ()] = true;
		}
		for (int i = 1; i + len - 1 <= len2; ++i) {
			for (int j = 1; j <= 26; ++j) {
				tmp_cnt[j] = cnt2[i + len - 1][j] - cnt2[i - 1][j];
			}
			if (exist[get_hash ()]) {
				cout << len << endl;
				return;
			}
		}
	}
	cout << 0 << endl;
}

signed main () {
	charming ();
	return 0;
}