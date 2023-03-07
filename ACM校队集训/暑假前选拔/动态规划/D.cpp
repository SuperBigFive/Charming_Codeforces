#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;

int n, m, dist, dist1, dist2, mmin;
int i, j, k;
int start[3];
int hit_point[maxn];
int dp[maxn][maxn];

void check (int a, int b, int c) {
	dist1 = min (abs (start[a] - hit_point[1]), m - abs (start[a] - hit_point[1]));
	dist2 = min (abs (start[b] - hit_point[2]), m - abs (start[b] - hit_point[2])); 
	dist = dist1 + dist2;
	if (dist < dp[2][start[c]]) dp[2][start[c]] = dist; 
}

void init () {
	mmin = INT_MAX;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			dp[i][j] = INT_MAX >> 1;
		}
	}
	dist = INT_MAX;
	
	check (0, 1, 2);
	check (1, 0, 2);
	check (2, 0, 1);
	check (0, 2, 1);
	check (1, 2, 0);
	check (2, 1, 0);
	
	/*dist1 = min (abs (start[0] - hit_point[1]), n - abs (start[0] - hit_point[1]));
	dist2 = min (abs (start[1] - hit_point[2]), n - abs (start[1] - hit_point[2])); 
	if (dist1 + dist2 < dist) {
		dist = dist1 + dist2;
		dp[2][start[3]] = dist; 
	}
	dist1 = min (abs (start[1] - hit_point[1]), n - abs (start[1] - hit_point[1]));
	dist2 = min (abs (start[0] - hit_point[2]), n - abs (start[0] - hit_point[2])); 
	if (dist1 + dist2 < dist) {
		dist = dist1 + dist2;
		dp[2][start[2]] = dist; 
	}
	dist1 = min (abs (start[1] - hit_point[1]), n - abs (start[1] - hit_point[1]));
	dist2 = min (abs (start[2] - hit_point[2]), n - abs (start[2] - hit_point[2])); 
	if (dist1 + dist2 < dist) {
		dist = dist1 + dist2;
		dp[2][start[0]] = dist; 
	}
	dist1 = min (abs (start[2] - hit_point[1]), n - abs (start[2] - hit_point[1]));
	dist2 = min (abs (start[1] - hit_point[2]), n - abs (start[1] - hit_point[2])); 
	if (dist1 + dist2 < dist) {
		dist = dist1 + dist2;
		dp[2][start[0]] = dist; 
	}
	dist1 = min (abs (start[0] - hit_point[1]), n - abs (start[0] - hit_point[1]));
	dist2 = min (abs (start[2] - hit_point[2]), n - abs (start[2] - hit_point[2])); 
	if (dist1 + dist2 < dist) {
		dist = dist1 + dist2;
		dp[2][start[1]] = dist; 
	}dist1 = min (abs (start[2] - hit_point[1]), n - abs (start[2] - hit_point[1]));
	dist2 = min (abs (start[0] - hit_point[2]), n - abs (start[0] - hit_point[2])); 
	if (dist1 + dist2 < dist) {
		dist = dist1 + dist2;
		dp[2][start[1]] = dist; 
	}*/
}

void solve () {
	cin >> n >> m;
	for (i = 0; i < 3; ++i) cin >> start[i];
	for (i = 1; i <= n; ++i) cin >> hit_point[i];
	init ();
	for (i = 2; i < n; ++i) {
		for (j = 1; j <= m; ++j) {
			dp[i+1][j] = min (dp[i][j] + min (abs (hit_point[i-1] - hit_point[i+1]), m - abs (hit_point[i-1] - hit_point[i+1])), dp[i+1][j]);
			dp[i+1][hit_point[i-1]] = min (dp[i][j] + min (abs (j - hit_point[i+1]), m - abs (j - hit_point[i+1])), dp[i+1][hit_point[i-1]]);
		}
	}
	for (i = 1; i <= m; ++i) mmin = min(mmin, dp[n][i]);
	cout << mmin << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve ();
}
