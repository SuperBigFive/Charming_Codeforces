#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;
string wa = "Time to play Genshin Impact, Teacher Rice!";

void init () {}

void charming () {
	init ();
	cin >> n;	
	string mes;
	map <string, bool> vis;
	for (int i = 1, m; i <= n; ++i) {
		cin >> m;
		vector <string> ans;
		for (int j = 1; j <= m; ++j) {
			cin >> mes;
			if (mes.size () < 3 || vis[mes]) continue;
			for (int k = 0; k <= mes.size () - 3; ++k) {
				if (mes.substr (k, 3) == "bie") {
					ans.emplace_back (mes);
					vis[mes] = true;
					break;
				}
			}
		}
		if (!ans.size ()) cout << wa << endl;
		else for (auto &it : ans) cout << it << endl;
	}	
}

signed main () {
	charming ();
	return 0;
}