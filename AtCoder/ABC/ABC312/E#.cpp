#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 105;

struct Surface {
	array <int, 5> p[6];
};

int n;
int	tag[M][M][M];

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <Surface> cub (n);
	for (int i = 0, x1, y1, z1, x2, y2, z2; i < n; ++i) {
		cin >> x2 >> y2 >> z2 >> x1 >> y1 >> z1;
		++x1, ++x2, ++y1, ++y2, ++z1, ++z2;
		cub[i].p[0] = {x1, y1, x2, y2, z1};
		cub[i].p[1] = {x1, z1, x2, z2, y1};
		cub[i].p[2] = {y1, z1, y2, z2, x1};
		cub[i].p[3] = {x1, y1, x2, y2, z2};
		cub[i].p[4] = {x1, z1, x2, z2, y2};
		cub[i].p[5] = {y1, z1, y2, z2, x2};
	}
	vector <int> ans (n);
	
	auto Solve = [&] (int id) {
		memset (tag, 0, sizeof tag);
		for (int i = 0; i < n; ++i) {
			auto [x1, y1, x2, y2, z] = cub[i].p[id];
			for (int x = x2; x < x1; ++x) {
				for (int y = y2; y < y1; ++y) tag[x][y][z] = i + 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			auto [x1, y1, x2, y2, z] = cub[i].p[(id + 3) % 6];
			unordered_set <int> s;
			for (int x = x2; x < x1; ++x) {
				for (int y = y2; y < y1; ++y) if (tag[x][y][z]) {
					s.insert (tag[x][y][z]);
				}
			}
			ans[i] += s.size ();
		}
	};
	
	for (int i = 0; i < 6; ++i) Solve (i);
	for (int i = 0; i < n; ++i) cout << ans[i] << endl;
}

signed main () {
	charming ();
	return 0;
}