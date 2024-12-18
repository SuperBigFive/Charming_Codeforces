# 匹配

定义：

匹配：一张图$G=(V,E)$里的一个匹配$M$是$G$的一个任意两边不共点的子图。匹配的大小为匹配的边数，记为$|M|$。

极大匹配：对于一张图$G=(V,E)$上的一个匹配$M$，若对于$E$中的任意一条边$(u,v)$，$M \cup \{(u,v)\}$不是匹配，则$M$是$G$上的一个极大匹配。

性质：对于一个极大匹配，不在匹配中的点形成了一个独立集。

最大匹配：对于一张图$G=(V,E)$上的一个匹配$M$，若对于$G$上的任意一个匹配$M'$都有$|M| \geq |M'|$，则$M$是$G$上的一个最大匹配。

完美匹配：对于一张图$G=(V,E)$上的一个匹配$M$，若$V$中的任意一个顶点都在$M$中，则$M$是$G$的一个完美匹配。

性质：完美匹配大小为图中点数的一半。

带权匹配：对于一张带权$w:E\rightarrow\R$的图$G=(V,E)$上的一个匹配$M$，$M$的权值为其包含的所有边权之和。即$w(M)=\sum_{e\in E}w(e)$。

最大权匹配：对于一张带权$w:E\rightarrow\R$的图$G=(V,E)$上的一个匹配$M$，若对于$G$上的任意一个匹配$M'$都有$w(M) \geq w(M')$，则$M$是$G$上的一个最大权匹配。

最大权完美匹配：对于一张带权$w:E\rightarrow\R$的图$G=(V,E)$上的一个完美匹配$M$，若对于$G$上的任意一个完美匹配$M'$都有$w(M) \geq w(M')$，则$M$是$G$上的一个最大权完美匹配。

********

二分图上的匹配问题可以归约到网络流问题上，但存在针对这些问题专门设计的算法（往往是前者的特例），实现难度与常数均较小。

一般图上的匹配问题则较难归约到网络流问题上，且难度较二分图上的匹配问题显著增大。

**常见的匹配算法一般使用增广路寻找最大（权）匹配。**

********

## 增广路

定义：

对称差：$S_1,S_2$的对称差包含那些不同时存在于$S_1$和$S_2$中的元素，对应位运算中的异或，记为$S_1 \Delta S_2=S_1\cup S_2-S_1 \cap S_2$。

交错路：对于一张图$G=(V,E)$与其上的一个匹配$M$，$G$上的一条简单路径$P=\{u_1, u_2,...,u_k\}$被成为交错路当且仅当$P$中任意两条相邻边$e_1, e_2$均满足其中一条是匹配边而另一条不是。

命题：任意一条交错路与匹配的对称差依然是一个匹配。

证明：交错路与匹配的对称差即将交错路上所有边的匹配状态反转。这一过程不会影响到其他边，但可能影响到匹配的大小。

**增广路**：对于一张图$G=(V,E)$与其上的一个匹配$M$，$G$上的一条交错路$P=\{u_1, u_2,...,u_k\}$是增广路当且仅当其起点$u_1$与终点$u_k$均未被匹配。

性质：增广路的长度为奇数，因为其首尾两条边均未被匹配。

命题：匹配与增广路的对称差是一个比原匹配多出一条边的新匹配。

********

利用对称差的性质可以证明重要的增广路定理。

定理（Berge）：**对于一张图$G=(V,E)$与其上的一个匹配$M$，$M$是$G$的一个最大匹配当且仅当不存在增广路。**

充分性：已知$G$中不存在增广路，接下来需要证明$M$是最大匹配。设$G$的任意一个最大匹配为$M'$，考虑边集$E'=M \Delta M'$：

性质1：$E'$中的任意一个顶点度数不超过2。因为任意一个顶点只能被至多两条边作为端点，一条属于$M$而一条属于$M'$。那么$E'$中的任意一个连通分量只能是链或者环。

性质2：$E'$中的任意一个连通分量都不是长度为奇数的链。
若是则其必定是$M'$或$M$的增广路，则要么$M'$不是最大匹配，要么对于$M$存在增广路，矛盾。所以$E'$中的任意一条链状连通分量都包含相等数量的$M$与$M'$中的边。

性质3：$E'$中的任意一个连通分量都不是长度为奇数的环。
若是则环上必定有两条相邻边属于同一个匹配，产生矛盾。所以$E'$中的任意一个环连通分量都包含相等数量的$M$与$M'$中的边。

由性质2和3，$E'$中任意个连通分量要么是长度为偶数的链，要么是长度为偶数的环。所以$E'$中包含相等数量的$M$与$M'$中的边，因此$M$是一个最大匹配。

必要性：已知$M$是最大匹配。若$G$中存在增广路则可将其匹配状态翻转使$M$增大，导出矛盾。所以$G$中不存在增广路。

定理（Berge）：**对于一张图$G=(V,E)$与其上的一个匹配$M$，若$M$中不存在从$u$出发的增广路，则存在某个最大匹配$M'$使得$u$在$M'$中未被匹配**

证明：对于任意一个最大匹配$M''$，要么$M''$不包含$u$要么可以利用$M''$构造一个不包含$u$的最大匹配。

对于任意一个最大匹配$M''$，考虑$E'=M \Delta M''$中$u$的度数。

若$u$在$E'$中为$0$度点，则显然$M'$不包含$u$。

若$u$在$E'$中为$1$度点，因为$M$中不存在从$u$出发的增广路，所以$u$在$E'$中的连通分量是一条长度为偶数的链$P$。则$M'' \Delta P$为一个可得到一个不包含$u$的最大匹配。

若$u$在$E'$中为$2$度点，则$u$在$M$中已经被匹配，矛盾。

## 二分图匹配

定义（二分图最大匹配）：给定一个二分图$G=(X \cup Y,E)$，求$G$中的一个最大匹配。

### 匈牙利算法(最大匹配)

原理：即增广路定理。

过程：依次从每个点出发用dfs寻找增广路。若失败则将其跳过。

正确性证明：

若从某点$u$出发未找到增广路，则可将$u$删去而不影响图中的一些最大匹配。

********

实现：

```cpp
const int N = 100001;
typedef pair<int, int> pii;

namespace matching {

vector<int> g[N];   //  g[u]:X中顶点$u$的邻接表
bool vis[N];        //  vis[u]:当前dfs中Y中顶点u是否已被访问过
int lnk[N];         //  lnk[u]:Y中顶点u对应的匹配点。若u未被匹配则lnk[u]=0

//  从X顶点u出发寻找增广路
bool dfs(int u) {
    for (int v : g[u]) {
        //  v已被访问过，且无法从v出发找到增广路或增广路的上一个节点是v则跳过
        if (vis[v] || lnk[v] == u) continue;
        //  v未被访问过，标记v
        vis[v] = 1;
        //  v已有匹配点，且无法从v出发找到增广路则跳过
        if (lnk[v] && !dfs(lnk[v])) continue;
        //  v没有匹配点或找到从lnk[v]出发的增广路，则设v的匹配点为u
        lnk[v] = u; return true;
    }
    //  找不到增广路
    return false;
}

//  接口:
//  int nl: X节点数; X中节点编号为[1...nl]
//  int nr: Y节点数; Y中节点编号为[1...nr]
//  const vector<pii>& es: 二分图中的边集。pii的first为X中节点编号，second为Y中节点编号
//  返回值vector<pii> res: 得到的最大匹配。
vector<pii> match(int nl, int nr, const vector<pii>& es) {
    //  初始化，建图
    for (int i = 1; i <= nl; ++i)
        g[i].clear();
    fill_n(lnk + 1, nr, 0);
    for (pii e : es)
        g[e.first].push_back(e.second);
    //  依次从每个点出发寻找增广路
    for (int i = 1; i <= nl; ++i) {
        fill_n(vis + 1, nr, false);
        dfs(i);
    }
    //  按Y中每个点i的匹配点lnk[i]得到结果
    vector<pii> res;
    for (int i = 1; i <= nr; ++i)
        if (lnk[i]) res.emplace_back(lnk[i], i);
    return res;
}

}
```

********

复杂度分析：匈牙利算法的时间复杂度为$O(VE)$，空间复杂度为$O(V+E)$。

共进行$V$轮时间复杂度为$O(E)$的DFS寻找增广路，因此时间复杂度为$O(VE)$。

注：若使用BFS寻找增广路，则该算法等价于Edmonds-Karp算法。

### Hopcroft-Karp

原理：每次在分层图上寻找多条增广路。

## 二分图最大权匹配

### 匈牙利算法（最大权完美匹配）

注：也叫Kuhn-Munkres算法（这两个人是匈牙利人）

原理：相等子图中的完美匹配是原图中的最大权完美匹配

KM为每个顶点定义了一个被称为顶标的值，在算法运行的每个阶段保持对于任意一条边$(u,v)$有$A(u)+B(v)\geq w(u,v)$。同时称由满足$A(u)+B(v)=w(u,v)$的所有边组成的子图为相等子图。

注2：如非特别注明，本段中$u \in X, v \in Y, w(u,v)$为边$(u,v)$的权，$X$中点$u$的顶标被记为$A(u)$，$Y$中点$v$的顶标被记为$B(v)$。

原理证明：

若相等子图中存在完美匹配$M$，显然$w(M)=\sum_{u \in X}A(u)+\sum_{v \in Y}B(v)$。注意到对于图中的任意一个完美匹配$M'$有$w(M')=\sum_{(u,v)\in M'}w(u,v)\leq\sum_{(u,v)\in M'}A(u)+B(v)=w(M)$，所以$M$是最大权完美匹配。

过程：

与寻找二分图最大匹配的过程类似，依次从每个点出发**在相等子图中**寻找增广路。若无法找到则通过调整顶标使相等子图扩大。

在无法找到增广路的情况下，从每个点出发的交错路形成了一棵交错树，其所有叶子都是$X$顶点。不妨设交错树中的$X$顶点集合为$S$，而$Y$顶点集合为$T$。考虑如何调整顶标才能在满足约束$\forall(u,v) \in E,A(u)+B(v) \geq w(u,v)$的情况下使得：

1. 原来在交错树中的边之后依然在交错树中。
2. 一部分原来$X$顶点在交错树，而$Y$顶点不在交错树中的边被加入相等子图。

由约束1，对于交错树中的每条边，其$X$顶点的顶标的调整值与$Y$顶点的顶标的调整值必须互为相反数。即对于交错树中的所有$X$顶点，其顶标必须被加上一个数，而$Y$顶点的顶标需要被减去一个数，不妨设其为$d$。

考虑到这样的调整对原来$X$顶点在交错树中而$Y$顶点不在交错树中的边的影响，为满足这些边对顶标带来的约束，必有

$$
d = \min_{u \in S, v \notin T}A(u)+B(v)-w(u,v)
$$
考虑这种调整对图中所有边造成的影响：

1. $u \in S, v \in T$，$A(u)-d+B(v)+d=A(u)+B(v)\geq w(u,v)$，没有影响。
2. $u \notin S, v \notin T$，没有影响。
3. $u \in S, v \notin T$，$A(u)-d+B(v)\geq w(u,v)$，一些这类边被加入了相等子图中
4. $u \notin S, v \in T$，$A(u)+B(v)+d > w(u,v)$，没有影响。

由二分图最大匹配的经验我们很容易写出暴力寻找调整值$d$的算法。其复杂度如下：

1. 从每个顶点出发尝试寻找增广路，至多寻找$O(n)$次。
2. 每次寻找增广路，至多遍历$O(n^2)$条边。
3. 寻找失败则调整顶标，每次调整会使得至少一个Y顶点被加入交错树，所以至多调整$O(n)$次。
4. 通过遍历边集来计算调整值，至多遍历$O(n^2)$条边。

因此这种暴力的时间复杂度是$O(n^4)$。

考虑如何优化寻找增广路与计算顶标调整值的过程。因为交错树一直在扩大，所以每次我们不需要重新DFS尝试增广，而是以类似BFS的形式从交错树的叶子开始增广，并在这一过程中同时计算调整值。

不难设计出如下过程：

1. 从每个顶点出发尝试寻找增广路，至多寻找$O(n)$次。
2. 对当前顶点$u$，设$u$的匹配点为$0$。设$v=0$并重复如下过程。
3. 设$v$已被访问。
4. 对$v$的匹配点的邻接表中的边$(u',v')$。
5. 若$v'$已被访问则回到3。
6. 若$(u',v')$不在相等子图中则令$d=\min(d,A(u')+B(v')-w(u',v'))$，并设$pre(v')=v$。
7. 若$(u',v')$

```cpp
namespace matching {

vector<int> g[N];
int lnk[N], pre[N];
bool vis[N];

ll a[N], b[N], w[N][N], sl[N];

vector<pair<pii, ll>> match(int nl, int nr, const vector<pair<pii, ll>>& es) {
    nr = max(nl, nr);
    fill_n(lnk + 1, nr, 0);
    for (int i = 1; i <= nl; ++i)
        fill_n(w[i] + 1, nr, 0);
    for (pair<pii, ll> e : es)
        w[e.first.first][e.first.second] = max(w[e.first.first][e.first.second], e.second);
    for (int i = 1; i <= nl; ++i)
        a[i] = *max_element(w[i] + 1, w[i] + nr + 1);
    fill_n(b + 1, nr, 0);
    for (int i = 1, j, u, vt = 0; i <= nl; ++i) {
        fill_n(vis + 1, nr, 0);
        fill_n(sl + 1, nr, inf);
        fill_n(pre + 1, nr, 0);
        lnk[0] = i;
        for (j = 0; u = lnk[j]; j = vt) {
            ll d = inf; vis[j] = 1;
            for (int v = 1; v <= nr; ++v) {
                ll t = a[u] + b[v] - w[u][v];
                if (vis[v]) continue;
                if (sl[v] > t) sl[v] = t, pre[v] = j;
                if (sl[v] < d) d = sl[v], vt = v;
            }
            for (int v = 0; v <= nr; ++v) {
                if (vis[v]) a[lnk[v]] -= d, b[v] += d;
                else sl[v] -= d;
            }
        }
        for (; j; j = pre[j]) lnk[j] = lnk[pre[j]];
    }
    vector<pair<pii, ll>> res;
    for (int i = 1; i <= nr; ++i)
        res.emplace_back(pii(lnk[i], i), a[lnk[i]] + b[i]);
    return res;
}

}
```

## 二分图匹配的性质

定理（Konig）：若$G=(X \cup Y,E)$是二分图，则$\nu(G)=\tau(G)$。

证明：考虑二分图匹配的网络流建图。从源点向$X$中的点连容量为$1$的边，$X$与$Y$之间的边容量为无穷，从$Y$ 向汇点连容量为$1$的边。

1. 该图中的最大流对应着原图中的最大匹配。因为每个点只能流入/流出至多$1$的流，中间层有流量的边即为匹配中的边。

2. 该图中的最小割对应着原图中的最小点覆盖。因为该图中$X$与$Y$之间的每条边，其连接的两个端点与源/汇点之间的边至少有一条要被割掉，这与被端点覆盖等价。连着满流边的点即为点覆盖。

因为最大流等于最小割，所以命题得证。

定理（Hall）：对于二分图$G=(X \cup Y,E)$，设$\Gamma(S)$为点集$S$的邻点集合，则其对于$X$完美匹配当且仅当对于任意一个点集$A\subseteq X$有$|\Gamma(A)| \geq |A|$。

必要性：显然。

充分性（不使用Konig定理）：使用归纳法。$|X|=0,1$的情况显然。

若$\forall A \subset X,|\Gamma(A)|>|A|$，则可选取任意一条边$(a,b)$，将$a$和$b$删除。这个操作对$X-\{a\}$的子集的影响会使得$|\Gamma(A)|-|A|$减少至多$1$，此时依然满足Hall条件。

否则$\exist A \subset X, |\Gamma(A)|=|A|$。此时可证删去$A$与$\Gamma(A)$后的图的任意一个子集依然满足Hall条件。
$$
\forall A' \subseteq X-A,|\Gamma(A')-\Gamma(A)|=|\Gamma(A' \cup A)-\Gamma(A)|=|\Gamma(A'\cup A)|-|\Gamma(A)| \geq |A' \cup A|-|A|=|A'|
$$
充分性2（不使用Konig定理）：使用归纳法对左边子集大小从小到大归纳。$|X|=0,1$的情况显然。

若$X$的每个大小为$|X|-1$的子集都满足$N(X') > |X'|$，则挑选任意一条边删除。

若$X$存在一个大小为$|X|-1$的子集$X'$满足$N(X')=|X'|$，将其删除后$X$中将剩下至少一条边。



充分性（基于Konig定理）：若其对$X$没有完美匹配，则$\nu(G)<|X|$。由Konig定理有$\tau(G)=\nu(G)$，因此存在一个小于$|X|$的点覆盖$A\cup B$，其中$A \subset X,B \subset Y,|A|+|B|=\tau(G)<|X|$。由点覆盖的性质得$\Gamma(X-A) \subseteq B$，所以$|\Gamma(X-A)|\leq |B|=\tau(G)-|A|<|X|-|A|=|X-A|$，矛盾。





不难证明每一个最大权完美匹配都在KM算法运行完毕后最终的相等子图中，因此带权二分图中的以下问题可直接归约到相应的无权图中的问题。

### 一定在最大匹配中的边

问题：给出一个二分图，找到那些一定在最大匹配中的边。

先找出一个最大匹配$M$。

定理：$(u,v)$在一个交错环中是$(u,v)$不一定在最大匹配中的充要条件。

充分性：如果一条边$(u,v)$在交错环中则将交错环中的边的匹配情况反转可得到一个新的最大匹配$M'$使得$(u,v)$不属于$M'$。

必要性：设存在一个最大匹配$M'$使得$(u,v)\notin M'$，考虑$M \Delta M'$的点集中没有大于等于3度的点，因此$(u,v)$在交错环或交错链中。

找交错环可将整个图中的边进行定向，如非匹配边全部定向为左至右，匹配边全部定向为右至左。

### 可能在最大匹配中的边

问题：给出一个二分图，找到那些可能在最大匹配中的边。

先找出一个最大匹配$M$。

对于边$(u,v)$，若其在某个最大匹配$M'$中而不在$M$中，则对称差$M \Delta M'$中其属于某个交错环或交错链。



## 一般图匹配

## Tutte矩阵与Tutte定理

设$G$是一个简单无向图，$G'$是将$G$中所有边任意定向所得有向图，定义Tutte矩阵
$$
T(G')_{uv}= \begin{cases}
x_{uv} & (u,v) \in G'\\
-x_{vu} & (v,u) \in G'\\
0 & other
\end{cases}
$$
定理(Tutte)：$G$有完美匹配当且仅当$|T(G')|$不恒为$0$。

证明：由行列式的定义有
$$
|T(G')|=\sum_{\pi \in S_n}\text{sgn}(\pi)\prod_{i=1}^nT(G')_{i,\pi(i)}
$$
每个置换都对应$G'$的一个子图，其对$|T(G')|$的贡献为$\text{sgn}(\pi)$乘以其所有边权之积。

对于包含奇数长度轮换的置换$\pi$，设$\pi'$为将其第一个奇轮换反向所得置换。这两个置换的奇偶性相同且贡献相反，因此$\pi$与$\pi'$的贡献两两抵消。因此只有仅包含偶数长度轮换的置换对$|T(G')|$有贡献。若一个长度为偶数的置换对$|T(G')|$的贡献非$0$，则其子图为一些孤立边与偶环的并，由此可以直接构造出一个完美匹配。而对于一个边集为$\{(u_1,v_1),\cdots,(u_{n/2},v_{n/2})\}$的完美匹配$M$，与其对应的置换对$|T(G')|$的贡献为$\displaystyle \sum_{i=1}^{n/2}(-x_{u_iv_i}^2)$，因此不会被抵消掉。


