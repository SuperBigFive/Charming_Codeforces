#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int n, x, y, z;
struct stu{
	int math;
	int eng;
	int tot;
	int sum;
}people[maxn];
bool vis[maxn];

void charming () {
	cin >> n >> x >> y >> z;
	for (int i = 1; i <= n; ++i) {
		cin >> people[i].math;
		people[i].tot = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> people[i].eng;
		people[i].sum = people[i].math + people[i].eng;
	}
	sort (people + 1, people + 1 + n, [] (stu x, stu y) {
		if (x.math == y.math) return x.tot < y.tot;
		return x.math > y.math;
	});
	vi res;
	int cnt = 0, tott = 1;
	for (int i = 1; tott <= x; ++i) {
		res.pb (people[i].tot);
		++tott;
		vis[people[i].tot] = true;
	}
	sort (people + 1, people + 1 + n, [] (stu x, stu y) {
		if (x.eng == y.eng) return x.tot < y.tot;
		return x.eng > y.eng;
	});
	tott = 1;
	for (int i = 1; tott <= y; ++i) {
		if (!vis[people[i].tot])
		++tott,
		res.pb (people[i].tot), vis[people[i].tot] = true;
	}
	sort (people + 1, people + 1 + n, [] (stu x, stu y) {
		if (x.sum == y.sum) return x.tot < y.tot;
		return x.sum > y.sum;
	});
	tott = 1;
	for (int i = 1; tott <= z; ++i) {
		if (!vis[people[i].tot])
		++tott,
		res.pb (people[i].tot), vis[people[i].tot] = true;
	}
	sort (res.begin (), res.end ());
	for (auto it : res) {
		cout << it << endl;
	}
}

signed main () {
	charming ();
	return 0;
}