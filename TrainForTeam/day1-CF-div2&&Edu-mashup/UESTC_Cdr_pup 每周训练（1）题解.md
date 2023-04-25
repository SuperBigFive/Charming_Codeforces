#### UESTC_Cdr_pup 每周训练（1）题解

> Edu115(D题): [Educational Codeforces Round 115 Editorial - Codeforces](https://codeforces.com/blog/entry/95890) 
>
> Edu116(CDE三题): [Educational Codeforces Round 116 Editorial - Codeforces](https://codeforces.com/blog/entry/96454) 
>
> Edu117(CDE三题): [Educational Codeforces Round 117 — Editorial - Codeforces](https://codeforces.com/blog/entry/97164) 
>
> Edu119(CDE三题): [Educational Codeforces Round 119 Editorial - Codeforces](https://codeforces.com/blog/entry/98061) 

注：题目序号是随机打乱的（防止自己提前知道难度了降低训练体验），反正就这四个来源，补题时想看题解大不了一个个匹配，也就 $O(1)$ 的复杂度。

训练前盲猜最后能写出来五题。$E$ 题放了三道但感觉基本开不出来，或者没时间开。$C$ 题就纯签到了，$D$ 题争取多做，$E$ 题能做出来一题就算赢。

希望 $D$ 题场上没做完的赛后尽量都补掉，毕竟补题对于提升水平还是很重要的。

第一次拉比赛，各方面可能还有很多不足，望以后越来越好。

---

附（1）：Mashup具体操作：

1. 在 $CF$ 网站 $HOME$ 页点击 $GYM$；
2. 往下拉，右边有 $mashup$ 选项，点击；
3. 设置名字，比赛时间，加题目；
4. “$Create\ Mashup\ Contest$“之后不是立即开始了，依然可以加题目；
5. 开始时间结束时间在点击”$Create\ Mashup\ Contest$“之后可以设置(在题目界面点击 $EDIT$)。



附（2）：随机序号代码，要用的话可以自取（很简单，放在这里单纯是省的你们再浪费时间写了，~~不介意提前知道难度的话当我没说~~）。
使用方法：把要加的题目的编号(格式如 $1314B$ )都输入进去，最后输入$0$，回车。

```cpp
#include <bits/stdc++.h.>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
mt19937 rnd {random_device {} ()};

int n;
int seq[maxn];

void init () {n = 0;}

void charming () {
	init ();
	vector <string> prob;
	string s;
	while (true) {
		cin >> s;
		if (s[0] == '0') break;
		prob.emplace_back (s);
		++n;
	}
	for (int i = 1; i <= 20; ++i) cout << "-";
	cout << endl;
	for (int i = 0; i < n; ++i) seq[i] = i;
	shuffle (seq, seq + n, rnd);
	for (int i = 0; i < n; ++i) {
		cout << prob[seq[i]] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}
```

