#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

//std::random_device本身是均匀分布整数随机数生成器，通常仅用于播种
//定义一个uint32范围内的伪随机数生成器：
//std::mt19937 rnd (std::random_device {} ());
//std::mt19937 rnd (chrono::system_clock::now ().time_since_epoch ().count ());

void charming () {
	std::vector <int> vec {1, 2, 3, 4, 5, 6};
	//洗牌算法
  std::mt19937 rnd (std::random_device {} ());
  std::shuffle (vec.begin(), vec.end(), rnd);
}

signed main () {
	charming ();
	return 0;
}