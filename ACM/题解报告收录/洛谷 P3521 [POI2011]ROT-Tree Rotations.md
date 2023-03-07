## 洛谷 [P3521 [POI2011]ROT-Tree Rotations](https://www.luogu.com.cn/problem/P3521)

### 题目描述

 给定一颗有 $n$ 个叶节点的二叉树。每个叶节点都有一个权值 $p_i$（注意，根不是叶节点），所有叶节点的权值构成了一个 $1 \sim n$ 的排列。
对于这棵二叉树的任何一个结点，保证其要么是叶节点，要么左右两个孩子都存在。
现在你可以任选一些节点，交换这些节点的左右子树。
在最终的树上，按照先序遍历遍历整棵树并依次写下遇到的叶结点的权值构成一个长度为 $n$ 的排列，你需要最小化这个排列的逆序对数。 

### 输入格式

第一行是一个整数 $n$，表示树的叶节点个数。
接下来若干行，使用递归的形式来读入这棵树，读入任意一个子树的信息时，初始时读入其根节点。对于一个结点 $u$，首先有一行一个整数 $x$。

- 若 $x \neq 0$，则表示 $u$ 是一个叶节点，其权值为 $x$。
- 若 $x = 0$，则表示 $u$ 不是叶节点，则接下来若干行读入其左子树信息，左子树读入结束后接下来若干行读入其右子树信息。

### 数据范围

  $2 \leq n \leq 2 \times 10^5$，$0 \leq x \leq n$，所有叶子节点是 $1 \sim n$ 的一个排列。

------

### 题解报告

考虑用线段树合并解这道题。

首先每个题目在题目给定的树上每个节点开一颗权值线段树，

那么合并后，每个节点的权值线段树中应该包含以该节点为根的子树内所有叶子节点代表的数。

对题目所给定的树 $dfs$ 一遍，用 $ans[i]$ 数组统计每棵子树内最小逆序对个数。

观察发现，左儿子与右儿子的交换并不影响其祖先节点的交换。

所以可以从低向上地贪心地求解，

即只要在 $dfs$ 过程中每次合并都保证答案最小，那么最后得到的答案一定也是最小的。

合并给父亲节点时，我们分交换左右儿子节点和不交换两种情况，

记不叫唤时逆序对增加个数为 $c1$，交换时逆序对增加个数为 $c2$。

线段树合并过程中计算 $c1$ 和 $c2$。

以上过程完毕后，更新当前节点 $ans[i] = ans[ls[i]] + ans[rs[i]] + min (c1, c2)$。

至于如何计算 $c1$ 和 $c2$，假设当前合并区间为 $[l, r]$，合并的节点分别为 $x$, $y$。

则 $c1 += node[ls[y]] * node[rs[x]]$，$c2 += node[ls[x]] * node[rs[y]]$。

（可以自己手动模拟理解下上面的式子）（$node[i]$表示以节点 $i$ 为根的子树内叶子节点个数）

最后输出 $ans[0]$，表示整颗子树内最小逆序对个数。

### AC代码：

```cpp
//这个代码有很多可以优化的地方，比如 build 和 dfs 这两个过程其实可以合并为 1 个
//合并过程中其实可以不开点的（平时这么写是防止一些强制在线的题写习惯了）
//ans数组其实也没必要开，用一个变量每次加 min (c1, c2) 就好了
//AC时参考了别人的代码，因为实在调不出来，后来发现确实某个细节写假了，把自己代码改了之后AC的（还是自己写的舒服）
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, tot;
int root[maxn << 2], val[maxn << 2];
ll ans[maxn << 2], node[maxn * 40];
int ls[maxn * 40], rs[maxn * 40];

void init () {tot = 0;}

void modify (int &now, int l, int r, int pos) {
	if (!now) now = ++tot;
	node[now] = 1;
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) modify (ls[now], l, mid, pos);
	else modify (rs[now], mid + 1, r, pos);
}

void merge (int &now, int x, int y, int l, int r, ll &c1, ll &c2) {
	c1 += node[ls[y]] * node[rs[x]];
	c2 += node[ls[x]] * node[rs[y]];
	if (!x || !y) {
		now = x + y;
		return;
	}
	now = ++tot;
	node[now] = node[x] + node[y];
	if (l == r) return;
	int mid = l + r >> 1;
	merge (ls[now], ls[x], ls[y], l, mid, c1, c2);
	merge (rs[now], rs[x], rs[y], mid + 1, r, c1, c2);
}

void build (int cnt, int l, int r) {
	int tmp;
	int mid = l + r >> 1;
	cin >> tmp;
	if (!tmp) {
		build (ls[cnt] = ++tot, l, mid);
		build (rs[cnt] = ++tot, mid + 1, r);
	}
	else val[cnt] = tmp;
}

void dfs (int u) {
	if (!ls[u] && !rs[u]) {
		modify (root[u], 1, n, val[u]);
		return;
	}
	dfs (ls[u]), dfs (rs[u]);
	ll c1 = 0, c2 = 0;
	merge (root[u], root[ls[u]], root[rs[u]], 1, n, c1, c2);
	ans[u] = ans[ls[u]] + ans[rs[u]] + min (c1, c2);
}

void charming () {
	init ();
	cin >> n;
	build (0, 1, n);
	dfs (0);
	cout << ans[0] << endl;
}

signed main () {
	charming ();
	return 0;
}
```

-----

### 收获&总结

需要一定思考才能写出来的，难度也不是很大，很适合用来练习和加深对算法的理解。