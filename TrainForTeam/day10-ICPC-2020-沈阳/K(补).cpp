#include <bits/stdc++.h>
#define double long double
using namespace std;
const int N = 1e6 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	int TP = 0, FN = 0, FP = 0, TN = 0;
	vector <pair <char, int> > a (n);
	for (auto &it : a) {
		cin >> it.first >> it.second;
		if (it.first == '+') ++TP;
		else ++FP;
	}
	vector <pair <double, double> > b;
	auto TPR = [&] () -> double {
		return (double) TP / (double) (TP + FN);
	};
	auto FPR = [&] () -> double {
		return (double) FP / (double) (TN + FP);
	};
	sort (a.begin (), a.end (), [] (pair <char, int> &x,
	pair <char, int> &y) {return x.second < y.second;});
	b.emplace_back (make_pair (FPR (), TPR ()));
	//cout << TP << " " << FN << endl;
	//cout << FP << " " << TN << endl << endl;
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (a[j].second == a[i].second) {
			if (a[j].first == '+') --TP, ++FN;
			else --FP, ++TN;
			++j;
		}
		b.emplace_back (make_pair (FPR (), TPR ()));
		//cout << TP << " " << FN << endl;
		//cout << FP << " " << TN << endl << endl;
	}
	sort (b.begin (), b.end ());
	double res = b[0].first * b[0].second;
	for (int i = 1; i < b.size (); ++i) {
		b[i].second = max (b[i].second, b[i - 1].second);
		res += (b[i].first - b[i - 1].first) * b[i - 1].second;
	}
	res += (1 - b.back ().first) * b.back ().second;
	cout << setprecision (10) << fixed << res << endl;
	
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}