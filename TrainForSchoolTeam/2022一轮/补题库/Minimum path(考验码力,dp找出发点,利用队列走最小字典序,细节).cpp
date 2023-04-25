#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e3 + 5;
const int maxm = 4e6 + 5;

int n, k, mmax = -1;
int tmp_x[maxm], tmp_y[maxm], tmp_c[maxm];
int dx[2] = {0, 1}, dy[2] = {1, 0};
int dp[maxn][maxn];
char res[maxm];
char mmap[maxn][maxn];
bool vis[maxn][maxn];
queue <int> px, py;

void find_beg () {
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = dp[i-1][1];
		dp[1][i] = dp[1][i-1];
		if (mmap[i][1] != 'a') ++dp[i][1];
		if (mmap[1][i] != 'a' && i != 1) ++dp[1][i];
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			dp[i][j] = min (dp[i - 1][j], dp[i][j - 1]);
			if (mmap[i][j] != 'a') ++dp[i][j];
		} 
	}
	mmax = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] == k) 
			mmax = max (mmax, i + j);
		}
	}
	for (int i = 1; i <= mmax - 1; ++i) res[i] = 'a';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] == k && (i + j) == mmax) {
				px.push (i), py.push (j);  
			}
		}
	}
}

void charming () {
	cin >> n >> k;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ch;
			mmap[i][j] = ch;
		}
	}
	if (n == 1) {
	    if (k) cout << "a" << endl;
	    else cout << mmap[1][1] << endl;
	    return;
	}
	int nowx, nowy, tot = 0, tot2;
	char mmin;
	char tmp_chr, tmp_chd, tmp_ch;
	if (!k) {
		px.push (1), py.push (1);
		res[tot2 = 1] = mmap[1][1];
	}
	else find_beg (), tot2 = mmax - 1;
	if (dp[n][n] <= k && k) {
		for (int i = 1; i <= 2 * n - 1; ++i) {
			cout << "a";
		}
		cout << endl;
		return;
	}
	while (true) {
		tot = 0, mmin = 'z' + 1;
		while (!px.empty ()) {
			nowx = px.front ();
			nowy = py.front ();
			px.pop ();
			py.pop ();
			tmp_x[++tot] = nowx;
			tmp_y[tot] = nowy;
			tmp_chr = tmp_chd = 'z' + 1;
			if (nowx != n) {
				tmp_chd = mmap[nowx + 1][nowy];
			}
			if (nowy != n) {
				tmp_chr = mmap[nowx][nowy + 1];
			}
			if (tmp_chd < tmp_chr) {
				tmp_c[tot] = tmp_chd;
				tmp_x[tot] = nowx + 1;
				tmp_y[tot] = nowy;
			}
			if (tmp_chd > tmp_chr) {
				tmp_c[tot] = tmp_chr;
				tmp_x[tot] = nowx;
				tmp_y[tot] = nowy + 1;
			}
			if (tmp_chd == tmp_chr) {
				tmp_c[tot] = tmp_chd;
				tmp_x[tot] = nowx + 1;
				tmp_y[tot] = nowy;
				
				tmp_c[++tot] = tmp_chr;
				tmp_x[tot] = nowx;
				tmp_y[tot] = nowy + 1;
			}
			tmp_ch = min (tmp_chd, tmp_chr);
			mmin = min (mmin, tmp_ch);
		}
		for (int i = 1; i <= tot; ++i) {
			if (tmp_c[i] == mmin && !vis[tmp_x[i]][tmp_y[i]]) {
				px.push (tmp_x[i]), py.push (tmp_y[i]);
				vis[tmp_x[i]][tmp_y[i]] = true;
			}
		}
		res[++tot2] = mmin;
		if (tot2 == 2 * n - 2) {
			res[++tot2] = mmap[n][n];
			break;
		} 
	}
	for (int i = 1; i <= 2 * n - 1; ++i) {
		cout << res[i];
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL); 
	charming ();
	return 0; 
} 
