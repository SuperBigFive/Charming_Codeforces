## 洛谷 [P3121 [USACO15FEB]Censoring G](https://www.luogu.com.cn/problem/P3121)

### 题目描述

给定一个字符串 $s$，和 $n$ 个单词 $t$，不断删除字符串 $s$ 中第一次出现的单词，直到 $s$ 中不含给定的任意一个单词为止。注意：删除单词后可能会组成新的单词。输出最终的 $s$。

### 数据范围

$1 \leq |s|,\ \sum ^{n}_{i = 1}|t_{i}|,\ n \leq 10^{5}$。

-----

### 题解报告

考虑使用AC自动机求解该题，把所有单词插入 $trie$ 树中。

当成功匹配到某个单词时，我们需要将其删除，删除后，$trie$ 指针应该指向何处？

应该指向，匹配到这个单词前一个位置时， $trie$ 指针指向的位置。

用一个单调栈维护每次匹配时 $trie$ 指针指向的位置，成功匹配后就弹出对应长度数量的元素，

然后让当前指针变成弹出后栈顶的元素（即回到了匹配该单词前的状态）。

每次未成功匹配，则把当前 $trie$ 指针塞进栈中。

这个方法也很方便得到最终的 $s$ (字符串 $ans$)，

跟栈的操作类似，栈弹出的时候 $ans$ 删末尾元素，栈塞东西的时候 $ans$ 末尾也塞 (当前在 $s$ 上进行匹配的字符)。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int n, tot, tail;
int fail[maxn];
int dep[maxn], stk[maxn];
int trie[maxn][26];
bool en[maxn];
string s, t, ans;

void init () {}

void ins () {
	int now = 0, num;
	for (auto it : t) {
		num = it - 'a';
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	en[now] = true;
}

void bfs () {
	queue <int> q;
	for (int i = 0; i < 26; ++i) if (trie[0][i]) {
		q.push (trie[0][i]);
		dep[trie[0][i]] = 1;
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 0; i < 26; ++i) {
			if (trie[now][i]) {
				fail[trie[now][i]] = trie[fail[now]][i];
				q.push (trie[now][i]);
				en[trie[now][i]] |= en[fail[trie[now][i]]];
				dep[trie[now][i]] = dep[now] + 1;
			}
			else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void charming () {
	cin >> s;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		ins ();
	}
	bfs ();
	int now = 0, num;
	bool ok;
	for (int i = 0; i < s.length (); ++i) {
		num = s[i] - 'a';
		now = trie[now][num];
		if (en[now]) {
			for (int j = 1; j < dep[now]; ++j) ans.pop_back ();
			tail -= dep[now] - 1;
			now = stk[tail];
		}
		else stk[++tail] = now, ans += s[i];
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
```

-----

### 收获&总结

这题做完之后其实并不难（虽然这么说有点马后炮），当时思路不对，把 $AC$ 自动机乱改一通，最后还是没解出来。

这种匹配过程中改变 $trie$ 指针的“断崖式“操作感觉作用挺大的，增加了匹配时的自由度。

如果做题时想到了匹配过程中暴力扩建 $trie$ 树时，不妨试试能不能从改变 $trie$ 指针入手。