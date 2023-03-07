## 洛谷 [P2743 [USACO5.1]乐曲主题Musical Themes](https://www.luogu.com.cn/problem/P2743)

### 题目描述

给定一个由 $n$ 个 $[1, 88]$ 的数字组成的字符串，定义 $s1$， $s2$，为相同串，当且仅当 $|s1| = |s2|$ 、两个字符串中对应下标的数字之差相同、两个字符串不重叠。输出相同串的最大长度，若小于 $5$ 则输出 $0$。

### 数据范围

$ 1 \leq n \leq 20000 $

------

### 题解报告

由对应下标数字只插相同，利用差分，

题目转化为求字符串的最长不重叠相同字串（最大长度加 $1$，差分舍弃了首位）。

两种做法，二分 + $Hash$，二分 + $SA$，均二分最大长度。

$Hash$ 本人写的常数太大过不去，这里就写个二分 + $SA$ 的题解报告。

对后缀排序同时求出 $height[]$ 数组，假设二分的最大长度为 $k$，

遍历 $height[]$ 数组，对于一段连续区间 $[i, j]$，

若该区间内 $height[]$ 的大小均大于等于 $k$，则必定存在 $(j - i + 1)$ 个长度为 $k$ 的字串相同；

为了判断这些子串中是否存在一对不重叠的，我们在该区间内记录最大的 $sa[i]$ 和最小的 $sa[i]$，

因为该区间内的每个 $sa[i]$ 均是一个长度为 $k$ 的字串的起始位置，

若最大减去最小的大于 $k$ （不能等于，考虑差分，边界情况会重叠一个字符），

则符合不重叠的限制条件。

$Hint：$每次连续区间 $[i, j]$ 断了的时候（即遍历到某个 $height[i]$ 小于 $k$），

这时候最大值最小值要更新为当前 $sa[i]$，因为 $height[i]$ 数组是，排名 $i$ 与排名 $i - 1$ 的 $LCP$，

对于一段连续区间 $[i, j]$，位置 $sa[i]$ 同样也应该纳入考虑范围内。

### AC代码：

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int n, m, w, tot;
int sa[maxn], rk[maxn], height[maxn];
int id[maxn], old_rk[maxn], cnt[maxn];
int s[maxn];

void init () {}

void key2_sort () {
	tot = 0;
	for (int i = n; i > n - w; --i) id[++tot] = i;
	for (int i = 1; i <= n; ++i) if (sa[i] - w > 0) {
		id[++tot] = sa[i] - w;
	}
}

void key1_sort () {
	fill (cnt + 1, cnt + 1 + m, 0);
	for (int i = 1; i <= n; ++i) ++cnt[rk[id[i]]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
}

void update () {
	tot = 0;
	memcpy (old_rk, rk, sizeof rk);
	for (int i = 1; i <= n; ++i) {
		if (old_rk[sa[i]] == old_rk[sa[i - 1]] 
		&& old_rk[sa[i] + w] == old_rk[sa[i - 1] + w])
		rk[sa[i]] = tot;
		else rk[sa[i]] = ++tot;
	}
}

void get_height () {
	for (int i = 1;i <= n;i++) rk[sa[i]] = i;
	for (int i = 1, k = 0; i <= n; ++i) {
		if (rk[i] == 1) continue;
		if (k) --k;
		while (s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
		height[rk[i]] = k;
	}
}

bool check (int k) {
	int mn = sa[1], mx = sa[1];
	for (int i = 2; i <= n; ++i) {
		if (height[i] >= k) {
			mx = max (mx, sa[i]);
			mn = min (mn, sa[i]);
			if (mx - mn > k) return true;
			continue;
		}
		mn = sa[i], mx = sa[i];
	}
	return false;
}

void charming () {
	char ch1, ch2;
	int num1, num2;
	cin >> num1;
	for (int i = 1; i < n; ++i) {
		cin >> num2;
		s[i] = num2 - num1 + 90;
		++cnt[rk[i] = s[i]];
		num1 = num2;
	}
	--n, m = 300;
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < n && tot < n; w <<= 1, m = tot) {
		key2_sort ();
		key1_sort ();
		update ();
	}
	
	get_height ();	
	int l = 1, r = n, res = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	if (res < 4) cout << 0 << endl;
	else cout << res + 1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> n;
	charming ();
	return 0;
}
```

-----

### 收获&总结

算是本人后缀数组第一次 $height[]$ 数组的应用，学到了 $height[]$ 数组可以被用来判断某些符合特定条件的字符串是否存在，重要想法是，$height[]$ 是 $LCP$ 长度，而每个$LCP$ 一定在该字符串内出现过。

也许后缀数组便是以这种方式储存了字符串的字串而不仅仅是后缀的信息。