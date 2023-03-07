#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<math.h>
#include<bitset>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
int pre[maxn], siz[maxn];
vector <int> adjant[maxn];
set <int> component;

void make_component (int tot) {
	pre[tot] = tot;
	siz[tot] = 1;
	component.insert (tot);
}

int find (int x) {return x == pre[x] ? x : pre[x] = find (pre[x]);}

void joint (int x, int y) {
	int fx = find (x), fy = find (y);
	if (siz[fx] >= siz[fy]) {
		pre[fy] = fx;
		siz[fx] += siz[fy];
		component.erase (fy);
	}
	else {
		pre[fx] = fy;
		siz[fy] += siz[fx];
		component.erase (fx);
	}
}

void charming () {
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		adjant[u].push_back (v);
		adjant[v].push_back (u);
	}
	for (int i = 1; i <= n; ++i) {
		make_component (i);
		map <int, int> to;
		for (int j = 0; j < adjant[i].size (); ++j) {
			if (adjant[i][j] < i) ++to[find (adjant[i][j])];
		}
		set <int> tmp = component;
		
		for (auto ul : tmp) {
			if (find (ul) != find (i)) {
				if (siz[ul] > to[ul]) {
					joint (i, ul);
				}
			}
		}
	}
	cout << component.size () - 1 << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
