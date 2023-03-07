#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

namespace Game_theoty {
	/*——————巴什博弈——————
		n 个物品，两个玩家依此取
		最少取 1 个，最多取 m 个
		对于给定的 n 和 m
		先手 win or lose？
		分析：从 0 开始依此递增
		通过能否转移到上一个 lose状态 
		判断当前个数物品 win or lose
		例如：0(l) 1 ~ m(w) m + 1(l)
		m + 2 ~ 2*m + 1(w) 2*m + 2(l)
		……………………………………
		可以发现，当 n 为 m + 1 的
		整数倍时，先手必败*/
	void Bash_game () {
		int n, m;
		cin >> n >> m;
		if (n % (m + 1))  cout << "Win" << endl;
		else cout << "Lose" << endl; 
	} 
	//————————————————//
	
	/*————威佐夫博弈———————— 
		有两堆石子，石子数可以不同。
		两人轮流取石子，
		每次可以在一堆中取，
		或者从两堆中取走相同个数的石子，
		数量不限，取走最后一个石头的人获胜。
		判定先手是否必胜。
		结论：假设两堆石子为 (a , b)，其中 a < b。
		先手必败，当且仅当
		(b - a) * (sqrt (5.0) + 1.0) / 2 == a*/
	void Wythoff_game () {
		int a, b;
		cin >> a >> b;
		if (a > b) swap (a, b);
		if (((b - a) * ((sqrt (5.0)) + 1.0) / 2) == a) cout << "Lose" << endl;
		else cout << "Win" << endl;
	}
	//————————————————//
	
	/*——————Nim游戏——————
	*/ 
}

void charming () {
	
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
}
