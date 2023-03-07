## CF [1665D - GCD Guess](https://codeforces.com/contest/1665/problem/D) 

### 题目描述

交互题，找出固定的数 $x$，最多询问 $30$ 次，每次询问可得到 $gcd (x + a, x + b)$。

### 数据范围

$1 ≤ x ≤ 10^{9}, 1 ≤ a, b ≤ 2 * 10^{9}$

------

### 题解报告

由询问 $30$ 次想到，本题进行位运算的相关操作。

尝试寻找一种一次询问获得 $x$ 二进制上一位的信息的方法。

从最低位考虑，如果 $x \ mod \ 2 = 1$，可得知最低位为1， 否则为0；

如果 $x = (...000)_{2}$，那么 $x \ mod \ 2 ^{3}$必然等于 $2 ^ {3}$；

假设我们已经知道 $x$ 的后 $k$ 位二进制的大小，即为 $r$，

想要求 $x$ 的 $k + 1$位是 $0$ 还是 $1$，

如果是 $1$，那么 $gcd (x - r + (1 << (k)), 1 << (k + 1))$ 必然等于 $2 ^{k + 1}$；

如果是 $0$，则不等于 $2^{k + 1}$；

根据这个性质，迭代计算  $30$ 次，即可获得 $x$ 的后 $30$ 位二进制的大小，

由 $x$ 的数据范围，二进制下 $x$ 的位数不超过 $30$，所以询问 $30$ 次必然能够找出 $x$。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t;

int ask (int a, int b) {
	cout << "? " << a << " " << b << endl;
	fflush (stdout);
	int tmp;
	cin >> tmp;
	return tmp;
}

void ans (int x) {
	cout << "! " << x << endl;
	fflush (stdout);
}

void charming () {
	int r = 0;
	for (int i = 1, tmp; i <= 30; ++i) {
		tmp = ask (-r + (1 << (i - 1)), -r + (1 << (i - 1)) + (1 << i));
		if (tmp == (1 << i)) r += 1 << (i - 1);
	}
	ans (r);
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
```

-----

### 收获&总结

当初写这道题的时候，思路刚开始就错了，一直在想找出 $x$ 的所有质数；

通过本题的训练，应该强化位运算的意识，尤其是看到最多 $30$ 次询问这样的，要么二分，要么位运算。