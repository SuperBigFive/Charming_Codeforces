# 计数

## 一些计数定理

### Burnside引理

给定集合$S$，其在群$G$作用下的轨道数为
$$
\frac {1}{|G|}\sum_{g \in G}|X^g|
$$
其中$X_g=\{x \in S|gx=x\}$，即在元素$g$作用下的不动点集合。

$x$是置换$g$的不动点当且仅当$g$的每个轮换中的所有元素均相同。

例：$n$个点的环，每个点可以染$c$种颜色，问不同染色方案数。方案不同当且仅当旋转任意角度后两个环上存在至少一个颜色不相同的同位置的点。

置换群为$\Z_n$，设其生成元为$g$，则$g^d$由$\gcd(n,d)$个长度为$n/\gcd(n,d)$的轮换组成。

与其相同的置换有$\varphi(n/d)$种，因此方案数为
$$
\frac 1n\sum_{d|n}\varphi(n/d)c^{d}
$$

### LGV引理



### 矩阵树定理

#### 无向图

以下默认图中无自环。

定义（拉普拉斯矩阵）：无向图$G=(V,E)$的拉普拉斯矩阵被定义为$L(G)=D-A$，其中

$D$为度数矩阵，即对角元$D_{ii}$为$\deg(i)$的矩阵。

$A$为邻接矩阵，即$A_{ij}$ 为$i,j$之间的边数。

定义：

$T(G)$为$G$的生成树数量。

$L(G)[u]$为$L(G)$删去$u$对应行列后所得矩阵。类似的，$L(G)[u,v]$为$L(G)$分别删去$u,v$对应行列后所得矩阵。

命题：$|V|-\text{rank}\ L(G)$为$G$的连通块数量。

证明略。

定理(Kirchhoff)：$\forall u \in V,T(G)=\det L(G)[u]$。即无向图$G$的生成树数量为其拉普拉斯矩阵划去任意节点对应行列所得矩阵的行列式之值。

证明：

当$G$不连通时：按连通块可将$L(G)$划分成许多块。划去任意节点对应的行列后，余下来的每块行列和均为$0$，因此$\det L(G)[u]=0$。

当$G$连通时，对图中的边数做归纳：

当$|E|=0$时显然，否则存在一条边$(u,v) \in E$。

该图中的生成树可以根据是否包含$(u,v)$分为两类。

不包含$(u,v)$的生成树数量等于$T(G \setminus (u,v))$。其中$G\setminus (u,v)$为将$(u,v)$删去后的$G$。

包含$(u,v)$的生成树数量等于$T(G /(u,v))$。其中$G/(u,v)$为将$u,v$两点粘合成一点的$G$。

对$L(G)[u]$中点$v$对应行展开，设$C_{vw}$为$(L(G)[u])_{vw}$对应的代数余子式，可得
$$
\det L(G)[u]=\sum_{w}(L(G)[u])_{vw}C_{vw}\\
=(L(G)[u])_{vv}C_{vv}+\sum_{w \neq v}(L(G)[u])_{vw}C_{vw}
$$
注意到$L(G\setminus(u,v))[u]$与$L(G)[u]$的区别仅在于$(v,v)$位置上的元素多了$1$，于是有
$$
(L(G)[u])_{vv}=(L(G\setminus(u,v))[u])_{vv}+1\\
\forall w \neq v, (L(G)[u])_{vw}=(L(G\setminus(u,v))[u])_{vw}
$$
代入前式有
$$
=((L(G\setminus(u,v))[u])_{vv}+1)C_{vv}+\sum_{w \neq v}(L(G\setminus(u,v))[u])_{vw} C_{vw}\\
=C_{vv}+\sum_{w}(L(G\setminus(u,v))[u])_{vw}C_{vw}
$$
注意到

1. $C_{vv}$为$L(G)$删去$u$和$v$对应行列所得行列式，其恰好等于将$u,v$两点粘合成一点$(u,v)$后所得图$G/(u,v)$的拉普拉斯矩阵删去$(u,v)$对应行列所得矩阵$L(G/(u,v))[(u,v)]$，因此$\det C_{vv}$即为$G$中包含边$(u,v)$的生成树数量。

2. 而$C_{vw}$等于$(L(G \setminus (u,v)))_{vw}$对应的代数余子式，因此后半部分即为$\det L(G\setminus (u,v))[u]$，即为$G$中不包含$(u,v)$的生成树数量。

$$
T(G)=\det L(G)[u]=\det L(G /(u,v))[(u,v)]+\det L(G\setminus (u,v))[u]=T(G \setminus (u,v))+T(G /(u,v))
$$


注：本证明译自某谱图论专著相关讲义

**若将两点之间的边数视为权值并定义生成树的权值为边权之积，则矩阵树统计的是所有生成树的权值和。**

例（洛谷P5296 [北京省选集训2019]生成树计数）：定义生成树权值为边权之和，计算所有生成树的权值的$k$次方之和。

可以通过将边权转化为指数函数的低阶展开来将乘法转化为加法。即将权为$w$的边变成权为$\exp wx$的边。不难发现
$$
(\exp w_1x)(\exp w_2x)=\exp \left((w_1+w_2)x\right)
$$
若求的是权值和的$k$次方之和，则卷积时保留前$k$次方即可，答案即为结果的$k$次项乘上$k!$。

#### 有向图

类比无向图，可以得出有向图的矩阵树定理。

有向图中的矩阵树定理计算的是两类树形图的数量。

定义：

根向树形图：根的出度为$0$，其他所有点出度均为$1$的无环子图。

叶向树形图：根的入度为$0$，其他所有点入度均为$1$的无环子图。

矩阵树定理（有向图形式）：

定义：设

$D^{out}$为出度矩阵，即对角元$D^{out}_{ii}$为点$i$的出度（从点$i$指向其他点的边数）的矩阵。

$D^{in}$为入度矩阵，即对角元$D^{in}_ii$为点$i$的入度（从其他点指向点$i$的边数）的矩阵。
$$
L^{out}(G)=D^{out}(G)-A(G)\\
L^{in}(G)=D^{in}(G)-A(G)
$$
$T^{out}_r(G)$为有向图$G$中以$r$为根的根向树形图数量

$T_r^{in}(G)$为有向图$G$中以$r$为根的叶向树形图数量。

则有
$$
T^{out}_r(G)=\det L^{out}(G)[r]\\
T^{in}_r(G)=\det L^{in}(G)[r]
$$
证明：先证根向树形图相关的。对点数做归纳，两个点时显然成立。

否则对于某个点$u$，该图中的根向树形图分为两类。

包含边$(u,r)$的根向树形图数量等于$a_{ur}T(G/(u,r))$，其中$G/(u,r)$是将图中指向$u$的所有边改为指向$r$并将点$u$删去所得的图。

不包含边$(u,r)$的根向树形图数量等于$T(G \setminus (u,r))$，其中$G \setminus(u,r)$是将边$(u,r)$删去后所得的图。

进行类似的观察，可以发现$L^{out}(G)[r]$和$L^{out}(G/(u,r))[r]$之间的区别仅在于删去了点$u$所在行列，而$L^{out}(G)[r]$和$L^{out}(G \setminus (u,r))[r]$之间的区别仅在于对角线上$u$位置处的元素多了$a_{ur}$。

对$u$所在行展开即得
$$
T^{out}_r(G)=\det L^{out}(G)[r]\\
=\det L^{out}(G/(u,r))[r]+\det L^{out}(G \setminus (u,r))[r]\\
=T_r^{out}(G/(u,r))+ T_r^{out}(G \setminus (u,r))
$$
对于叶向树形图，进行类似的分析后对任意一个$r$以外的点$u$所在列展开即得证。

### BEST定理

定理(BEST)：有向欧拉图$G=(V,E)$的欧拉回路个数$ec(G)$满足
$$
ec(G)=T^{out}_r\prod_{v \in V}(\delta^{out}(v)-1)!
$$
其中$r$是$G$中的任意一个点。

证明：可以构造一个从一个树形图到一组数量为$\displaystyle \prod_{v \in V}(\delta^{out}(v)-1)!$的欧拉回路的双射。

先钦定一个根$r$。对于任意一个欧拉回路，钦定其从$r$出发经过的第一条边为$(r,r')$。对于$V$中的任意一个点，其在该欧拉回路的边列表中的最后一次出边组成的图是一个树形图。固定这些出边后，其他所有边的顺序可以任意选择。这样的方案数即$\displaystyle \prod_{v \in V}(\delta^{out}(v)-1)!$。

## 图计数

### Prufer序列

定义：一棵有标号树的Prufer序列为递归地将其最小的叶节点删去并将其邻点标号加入序列末尾直到剩余两个点所得序列。

Prufer序列转化为树：

维护一个集合$S$，初始$S=\{1,2,...,n\}$。对于序列中从左到右的每个元素$u$，找到未在其右侧出现的$S$中的最小元素$v$并将$u,v$连边，然后将$v$从$S$中删去，最后将$S$中剩余两个点连边即可完成对树的还原。

扩展——森林的Prufer序列：

定义：一个$n$个点的有$k$个连通块组成的森林的Prufer序列与树的构造方式几乎相同，唯一的区别是剩余$k+1$个点时停止。易得$n$个点$k$个连通块组成的森林的$Prufer$序列长度为$n-k-$

1. 先钦定$k$个根

2. 第$n-k$个位置的值为$k$个根之一。

3. 前$n-k-1$个位置上的值任意。

不难得到$n$个点，有$k$个连通块的森林数量为$\displaystyle \binom nk kn^{n-k-1}$

### 有标号无根树计数

定理(Caylay)：$n$个点的有标号无根树共有$n^{n-2}$种。从Prufer序列的构造与还原不难看出一棵树对应着一个Prufer序列，而每个Prufer序列在其$n-2$个位置均有$n$种取值可能。

法2：

枚举叶子个数$k$，可得到

当$0 \leq n \leq 2$时有$F(n)=1$，否则有$\displaystyle F(n)=\sum_{k=1}^{n-1}{\binom nk (n-k)^{k}F(n-k)}$

### 有标号有根树计数

给每个有标号无根树定一个根即可得到有标号有根树，因而$n$个点的有标号有根树共有$n^{n-1}$种。

### 有标号基环树计数

法1：考虑魔改Prufer序列，先钦定$k$个点在环上，方案为$\displaystyle \binom nk$。

将环上的边都断开并将所有环上的点连向一个标号为正无穷的特殊点。

该树的Prufer序列具有如下性质：

1. 最后$k$个位置的值均为正无穷。

2. 第$n-k$个位置的值必为环上的$k$个点之一。

3. 前$n-k-1$个位置上的值任意。

0k个点的环排列有$\frac{1}{2}k!$种，因而$n$个点的基环树个数为

$$
\sum_{k=3}^n{\binom nk \frac{k!}{2}n^{n-k-1}}=\frac 12 \sum_{k=3}^n{\frac{n!}{(n-k)!}n^{n-k-1}}
$$

考虑$n$个点基环树数量的OGF:

$$
F(x)=\frac 12 \sum_{i=0}^\infty\frac{x^i}{i!}\sum_{k=3}^i\frac{i!}{(i-k)!}i^{i-k-1}=\frac 12 \sum_{i=0}^\infty\frac{x^i}{i!}\sum_{k=0}^{i-3}\frac{i!}{k!}i^{k-1}=\frac 12 \sum_{i=0}^\infty x^i\sum_{k=0}^{i-3}\frac{i^{k-1}}{k!}
$$

法2：

考虑有标号的每个点有恰好$1$条出边，可以存在自环的有向图，其每个连通块去掉方向后可以分为三类：

1. 基环树
2. 有自环的树
3. 有重边的树

因此考虑这类有向图计数的EGF：
$$
F(x)=1+x+2^2x^2+3^3x^3=\sum_{i=0}^{\infty}i^ix^i
$$
对其取$\log$可得上面三类图数量之和对应的生成函数。

因为基环树的环有两种定向方法，有自环的树有恰好$n\times n^{n-2}$种，有重边的树有恰好$(n-1)\times n^{n-2}$种，所以$n$个点的基环树数量为
$$
\frac 12 \left([x^n]\log F -(2n-1)n^{n-2}\right )
$$

### 无标号有根树计数

钦定根后剩下的子树方案数相当于一个完全背包。

考虑欧拉变换的定义可写出OGF相关的方程：

$$
f(x)=x \mathscr E(f(x))=x \exp \left( \sum_{j=1}^{\infty} \frac {f(x^j)}{j} \right)
$$

两边取对数

$$
\ln f(x)= \ln x + \sum_{j=1}^{\infty}\frac{f(x^j)}{j}
$$

两边求导

$$
\frac{f'(x)}{f(x)}=\frac 1 x+ \sum_{j=1}^{\infty}x^{j-1}f'(x^j)
$$

$$
x f'(x)=f(x)\left(1+\sum_{j=1}^{\infty}x^jf'(x^j)\right)
$$

设

$$
g(x)=\sum_{j=1}^{\infty}x^jf'(x^j)
$$

可得

$$
b_i=\sum_{j | i}ia_i
$$

$$
i a_i=a_i+\sum_{j=1}^{i-1}a_jb_{i-j}
$$

$$
a_i=\frac 1{i-1}\sum_{j=1}^{i-1}a_jb_{i-j}
$$

注：这里$a_0=b_0=0,a_1=1$。

使用有依赖的分治卷积，计算`f`和`g`的部分为

```cpp
g[l] = (l == 1 ? 1 : mul(g[l], inv(l - 1)));
for (int j = l; j < f.size(); j += l)
    f[j] = add(f[j], mul(l, g[l]));
```

然后直接`conv(f,g,1,n+1)`后`g`即为所求。

#### 烷基计数

即度数限制为$3$的有根树。

因为无标号，所以使用Burnside引理去重。

置换群为$S_3$，$e$对应的方案数为$F(x)^3$，$(123)$和$(132)$对应的方案数为$2F(x^3)$，$(12),(23),(31)$对应的方案数分别为$3F(x)F(x^2)$。

因此有
$$
F(x)=1+x\frac{F(x)^3+2F(x^3)+3F(x)F(x^2)}{6}
$$
牛顿迭代时$F(x^2)$与$F(x^3)$的系数均已知，因此可以当作常数处理。构造方程：
$$
t(F)=\frac16x(F^3+2B+3FA)+1-F
$$
则
$$
t'(F)=\frac 16x(3F^2+3A)-1
$$
得迭代式
$$
G=F-\frac{x(F^3+2B+3FA)+6-6F}{x(3F^2+3A)-6}
$$

```cpp
vi alkyl(int n1) {
    if (n1 == 1) return vi(1, 1);
    int n2 = (n1 + 1) >> 1;
    vi f = alkyl(n2); f.resize(n1, 0);
    vi a = pmul(xpow(f, 2), 3), b = pmul(xpow(f, 3), 2);
    vi f2 = pmul(f, f, n1), f3 = pmul(f2, f, n1);
    vi h1 = padd(f3, padd(b, pmul(a, f, n1)));
    h1.insert(h1.begin(), 0);
    h1[0] = add(h1[0], 6);
    h1 = psub(h1, pmul(f, 6));
    vi h2 = padd(pmul(f2, 3), a);
    h2.insert(h2.begin(), 0);
    h2[0] = sub(h2[0], 6);
    return psub(f, pmul(h1, pinv(h2), n1));
}
```

例(JSOI2011 同分异构体计数)：

统计有多少个环上点数不超过$m$的$n$个点的烃。

环上每个点可以接上两个烷基。方案树即即根度数至多为$2$，其他点度数至多为$3$的有根树数量。生成函数为
$$
G(x)=\frac 12 x(F(x)^2+F(x^2))
$$
接下来要把这种东西插到环上后去重。

对于固定的一个环长$k$，置换群为$D_k$。

对于形如$g^n$的元素，即$Z_k$中的元素，总方案数为
$$
\sum_{d|k}\varphi(k/d)[x^{n/(k/d)}]G(x)^{d}
$$
对于$e$以外的满足$g^2=e$的元素，若$k \equiv 1 \bmod 2$，则总方案数为
$$
k\sum_{i=(k-1)/2}^{\lfloor (n-1)/2 \rfloor}[x^i]G(x)^{(k-1)/2}[x^{n-2i}]G(x)
$$
否则总方案数为
$$
\frac k2\sum_{i=k/2-1}^{\lfloor(n-2)/2\rfloor}[x^i]G(x)^{k/2-1}[x^{n-2i}]G(x)
$$
这一类对应对称轴过正$k$边形顶点的情况，左边为对称轴两边的方案数，右边为对称轴上两点的方案数。

若$n \equiv 2 \bmod 0$，则还需加上
$$
\frac k2[x^{n/2}]G(x)^{k/2}
$$
这一类对应对称轴不过正$k$边形顶点的情况。

预处理出$G(x)$的$1$至$m$次幂，加起来除以$2k$即为答案。

### 无标号无根树计数

统计方法为无标号有根树的数量减去根不是重心的无标号有根树的数量。

若根不是重心，则根有一个大小至少为$\left \lfloor \frac n2 \right \rfloor + 1$的子树。枚举该子树大小可得

$$
g_n=f_n-\sum_{i=\left \lfloor \frac n2 \right \rfloor + 1}^{n-1}f_if_{n-i}
$$

注意到有两个重心的时候，有一类树被统计了两次。即有两个重心且两边不同构的树。该类树的数量为$\binom {f_{\frac n2}}{2}$，减去即可。

因此有
$$
G(x)=F(x)-\frac 12\left(F(x^2)-(F(x)-1)^2\right)
$$

#### 烷烃计数

先计算根度数至多为$4$其他点度数至多为$3$的有根树数量。

考虑Burnside引理，置换群为$S_4$。

$e$对应方案数为$F(x)^4$

$(12),(13),(14),(23),(24),(34)$对应方案数为$6F(x^2)F(x)^2$

$(12)(34),(13)(24),(14)(23)$对应方案数为$3F(x^2)^2$

$(123),(234),(134),(124),(132),(243),(143),(142)$对应方案数为$8F(x^3)F(x)$

$(1234),(1243),(1324),(1342),(1423),(1432)$对应方案数为$6F(x^4)$

得
$$
G(x)=1+\frac{1}{24}x\left(F(x)^4+6F(x^2)F(x)^2+3F(x^2)^2+8F(x^3)F(x)+6F(x^4)\right)
$$
接下来考虑去重。

只有一个重心时，非重心点必有一个大于$\lfloor n/2 \rfloor$的子树。这一部分的方案数为
$$
b_n-\sum_{i=\lfloor n/2 \rfloor+1}a_ia_{n-i}
$$
有两个重心时，有一类树被统计了两次，因此需减去$\displaystyle \binom{a_{n/2}}{2}$

最终的生成函数为
$$
H(x)=G(x)+\frac 12(F(x^2)-(F(x)-1)^2-1)
$$

```cpp
vi alkane(int n) {
    int n1 = n + 1;
    vi a = alkyl(n1);
    vi a2 = pmul(a, a, n1), a4 = pmul(a2, a2, n1);
    vi a_2 = xpow(a, 2);
    vi b = pmul(padd(a4, padd(pmul(pmul(a_2, a2, n1), 6),padd(pmul(pmul(a_2, a_2, n1), 3),padd(pmul(pmul(xpow(a, 3), a, n1), 8), pmul(xpow(a, 4), 6))))), inv(24));
    b.insert(b.begin(), 1);
    b = padd(b, pmul(psub(psub(xpow(a, 2), {1}), pmul(psub(a, {1}), psub(a,{1}), n1)), inv(2)));
    b.pop_back();
    return b;
}
```

### 有标号连通图计数

对于满足某些性质的图（如欧拉图，即顶点度数均为偶数），用可以不连通的所有方案推广到连通的所有方案的情况可通过将所有方案减去不连通的方案获得。如枚举$1$号点所在连通块大小$k$，则除$1$号点之外的点共有$\binom{n-1}{k-1}$种方案：

$$
f_n=g_n-\sum_{k=1}^{n-1}{\binom{n-1}{k-1}f_kg_{n-k}}
$$

也可通过指数生成函数进行计数，即$G(x)=\ln F(x)$，其中$F(x),G(x)$分别为$f_n,g_n$的EGF。具体见“$e^{F(x)}$的组合意义”

### 有标号二分图计数

法1：

设大小为$n$，有$m$个连通块的二分图数量为$F(n,m)$，则有：

$$
F(n,m)=\sum_{k=1}^{n-m+1}{\binom{n-1}{k-1}F(k,1)F(n-k,m-1)}
$$
设$G(n)$为大小为$n$，对顶点进行了黑白染色的二分图数量，钦定$m$个黑点余下为白点并任意连边可得:

$$
G(n)=\sum_{m=0}^n{\binom{n}{m}2^{m(n-m)}}=\sum_{m=1}^n{2^mF(n,m)}
$$

$$
=2^1F(n,1)+\sum_{m=2}^n{2^m\sum_{k=1}^{n-m+1}{\binom{n-1}{k-1}F(k,1)F(n-k,m-1)}}
$$

$$
=2F(n,1)+\sum_{k=1}^{n-1}{\binom{n-1}{k-1}F(k,1)\sum_{m=2}^{n-k+1}{2^mF(n-k,m-1)}}
$$

$$
=2F(n,1)+2\sum_{k=1}^{n-1}{\binom{n-1}{k-1}F(k,1)\sum_{m=1}^{n-k}{2^mF(n-k,m)}}
$$

$$
=2F(n,1)+2\sum_{k=1}^{n-1}{\binom{n-1}{k-1}F(k,1)G(n-k)}
$$

可得递推式:

$$
F(n,1)=\frac{1}{2}G(n)-\sum_{k=1}^{n-1}{\binom{n-1}{k-1}{F(k,1)G(n-k)}}
$$

注：
$$
G(n)=\sum_{m=0}^n{\binom{n}{m}2^{m(n-m)}}=\sum_{m=0}^n{\binom{n}{m}2^{nm-m^2}}
=\sum_{m=0}^n{\frac{n!}{m!(n-m)!}2^{\frac{1}{2}(n^2+m^2-(n-m)^2)-m^2}}\\
=n!2^\frac{n^2}{2}\sum_{m=0}^n{\frac{1}{m!(n-m)!}2^{-\frac{(n-m)^2}{2}-\frac{m^2}{2}}}
=n!2^\frac{n^2}{2}\sum_{m=0}^n{\frac{2^{-\frac{(n-m)^2}{2}}}{(n-m)!}\frac{2^{-\frac{m^2}{2}}}{m!}}
$$

法2：

考虑$n$个点的二染色的连通二分图的EGF为$H(x)$，二染色的二分图的EGF为$G(x)$，连通二分图的EGF为$F_1(x)$，二分图的EGF为$F_2(x)$，则显然$G(x)=\exp {H(x)}$，且$H(x)=2F_1(x)$,$F_2(x)=\exp {F_1(x)}$。

于是$F_2(x)=\exp {F_1(x)}=\exp {\frac{1}{2}H(x)}=\exp {\frac{1}{2} \log G(x)}=\sqrt{G(x)}$。

### 有标号DAG计数

注意到DAG中存在一类特殊的点，即出度为$0$的点，我们通过枚举这些点进行计算。

设$f_{n,S}$为$n$个点，$S$中每个点出度均为$0$，其他点出度均大于$0$的DAG数量。

设$g_{n,S}$为$n$个点，$S$中每个点出度均为$0$，其他点出度任意的DAG数量。

$n$个点的DAG数量即$g_{n, \emptyset}$。

由定义有
$$
g_{n,S}=\sum_{T \supseteq S}f_{n,T}
$$
则由容斥有
$$
f_{n,S}=\sum_{T \supseteq S}(-1)^{|T|-|S|}g_{n,T}
$$
对于$g_{n,S}$，其他点与$S$中点连边任意，因此其他点与$S$中点的连边方案数为$2^{|S|(n-|S|)}$，其他点之间的连边方案为$g_{n-|S|, \emptyset}$
$$
g_{n,S}=2^{|S|(n-|S|)}g_{n-|S|,\emptyset}
$$
因此
$$
g_{n,\emptyset}=\sum_{T\neq \emptyset}f_{n,T}=\sum_{T\neq \emptyset}\sum_{U \supseteq T}(-1)^{|U|-|T|}g_{n,U}\\
=\sum_{T\neq \emptyset}\sum_{U \supseteq T}(-1)^{|U|-|T|}2^{|U|(n-|U|)}g_{n-|U|,\emptyset}\\
=\sum_{U \neq \emptyset}(-1)^{|U|}2^{|U|(n-|U|)}g_{n-|U|,\empty}\sum_{\emptyset \neq T \subseteq U}(-1)^{|T|}\\
=\sum_{k=1}^{n}\binom nk(-1)^{k+1}2^{k(n-k)}g_{n-k,\emptyset}
$$
得到递推式
$$
a_n=\sum_{k=1}^{n}\binom nk (-1)^{k+1}2^{k(n-k)}a_{n-k}
$$
注：上述过程与思路过于奇妙深刻，暂时未能完全理解。

考虑优化，有
$$
k(n-k)=kn-k^2=\frac{n^2+k^2-(n-k)^2}{2}-k^2=\frac{n^2}2-\frac{k^2}{2}-\frac{(n-k)^2}{2}
$$
因此
$$
a_n=\sum_{k=1}^n\frac{n!}{k!(n-k)!}(-1)^{k+1}2^{\frac{n^2}2-\frac{k^2}{2}-\frac{(n-k)^2}{2}}a_{n-k}\\
=-2^{n^2/2}n!\sum_{k=1}^{n}\frac{(-1)^k2^{-k^2/2}}{k!} \frac{2^{-(n-k)^2/2}a_{n-k}}{(n-k)!}\\
=-2^{n^2/2}n!\sum_{k=0}^{n-1}\frac{(-1)^{n-k}2^{-(n-k)^2/2}}{(n-k)!} \frac{2^{-k^2/2}a_{k}}{k!}\\
$$
边界为$a_0=1$。

法1：使用分治卷积，在边界将系数乘上即可，复杂度$O(n\log^2 n)$。

法2：令
$$
G(x)=\sum_{i=0}^{\infty}\frac{a_n}{2^{n^2/2}n!}x^i=\sum_{i=0}^{\infty}b_ix^i\\H(x)=\sum_{i=0}^{\infty}\frac{(-1)^{n+1}2^{-n^2/2}}{n!}x^i=\sum_{i=0}^{\infty}c_ix^i
$$
则有
$$
n\geq 1 \to b_n=\sum_{k=0}^{n-1}b_{k}c_{n-k}=\sum_{k=0}^{n}b_kc_{n-k}-b_{n}c_0=\sum_{k=0}^{n}b_kc_{n-k}+b_n\\
\sum_{k=0}^{n}b_kc_{n-k}=-[n=0]
$$
因此$G(x)H(x)=-1$，求逆即可，复杂度$O(n\log n)$。

```cpp
    vi f(n + 1);
    for (int i = 0; i <= n; ++i)
        f[i] = mul(mul(i & 1 ? 1: P - 1, inv(qpm(sqrt2, 1ll*i*i % (P - 1)))), ifac[i]);
    vi g = pinv(f);
    for (int i = 0; i <= n; ++i)
        g[i] = sub(0, mul(g[i], mul(qpm(sqrt2,1ll * i * i % (P - 1)), fac[i])));
    f = iegf(log(egf(g)));
```

### 有标号强连通图计数

设$n$个点的有标号有向图的数量为$a_n$，有标号强连通图数量为$b_n$，有标号DAG数量为$c_n$则
$$
a_n=\sum_{k=1}^nc_k[x^n]\frac{G(x)^k}{k!}\\
F(x)=H(G(x))\\
G(x)=H^{-1}(F(x))
$$


设$n$个点的有标号有向图的数量为$a_n$，有标号强连通图数量为$b_n$，有标号的每个弱连通分量都是强连通的有向图数量为$c_n$。

对于所有大小为$n$的有向图，设$f(S)$为有且仅有$S$中点都在出度为$0$的SCC中的方案数，$g(S)$为$S$中点组成了一些出度为$0$的SCC中的方案数，则有



确定了哪些点在出度为$0$的强连通分量中之后就可以将其他点与这些点随意连边。此时有
$$
g(S)=\sum_{S \subseteq T}f(T)=2^{|S|(n-|S|)}c_{|S|}a_{n-|S|}\\
f(S)=\sum_{S \subseteq T}(-1)^{|T|-|S|}g(T)
$$

$$
a_n=\sum_{S \subseteq V}f(S)=\sum_{S \subseteq V}\sum_{S \subseteq T}(-1)^{|T|-|S|}2^{|T|(n-|T|)}c_{|T|}a_{n-|T|}\\
=\sum_{k=0}^n\sum_{|T|=k}(-1)^{k}2^{k(n-k)}c_ka_{n-k}\sum_{S \subseteq T}(-1)^{|S|}\\
=\sum_{k=0}^n\binom nk(-1)^{k}2^{k(n-k)}c_ka_{n-k}[k=0]
$$








设$n$的点的强连通图数量的生成函数为$F(n)$，考虑用所有$n$个点的有向图的个数$H(n)$减去非强连通图的方案数来计算答案。

考虑DAG计数的过程，我们枚举非强连通图缩点后出度为$0$的强连通分量由哪些点组成，其他点与这些点之间可以任意连边。

可得：

$$
F(n)=H(n)-\sum_{k=1}^{n}{\binom nk 2^{k(n-k)}H(n-k)G(k)}+F(n)
$$
其中$G(k)$表示$k$个点组成数个互不相连的强连通分量的方案数。

右边加入$F(n)$的原因是，当$k$取到$n$时，该项表示的方案为$n$个点组成数个互不相连的强连通分量的方案数，即恰好包括了一个$F(n)$，因此要将其加回去。

由DAG计数可知，因为对$H(n-k)$中的连边方案没有任何限制，所以余下$n-k$个点中的点在缩点后也可能产生新的0出度点，即上述计数过程会造成重复统计。

我们仿照DAG计数，令$G(n,i)$表示$n$个点组成$i$个互不相连的强连通分量的方案数，并令$G(n)=\sum_{i=1}^{k}{(-1)^{i-1}G(n,i)}$,加入容斥系数来避免重复统计。

由前式可得关于$G(n)$的递推式：

$$
H(n)=\sum_{k=1}^{n}{\binom nk 2^{k(n-k)}H(n-k)G(k)}
$$

$$
=\sum_{k=1}^{n-1}{\binom n k 2^{k(n-k)}H(n-k)G(k)}+G(n)
$$

于是

$$
G(n)=H(n)-\sum_{k=1}^{n-1}{\binom nk 2^{k(n-k)}H(n-k)G(k)}
$$

考虑用$G(n)$获得$F(n)$的递推式，因为$F(n)=G(n,1)$，因此我们考虑通过枚举1号点所在强连通分量大小计算$\sum_{i=2}^{n}{(-1)^iG(n,i)}$然后加到$G(n)$上去。

$$
F(n)=G(n,1)=G(n)+\sum_{i=2}^{n}{(-1)^iG(n,i)}
$$

$$
=G(n)+\sum_{i=2}^{n}{(-1)^i\sum_{k=1}^{n-i+1}{\binom {n-1}{k-1}G(k,1)G(n-k,i-1)}}
$$

$$
=G(n)+\sum_{k=1}^{n-1}{\binom {n-1}{k-1} G(k,1)\sum_{i=1}^{n-k}{(-1)^{i-1}G(n-k,i)}}
$$

$$
=G(n)+\sum_{k=1}^{n-1}{\binom {n-1}{k-1} F(k)G(n-k)}
$$

注：$G(n,i)$可通过枚举1号点所在连通块大小获得递推式

$$
G(n,i)=\sum_{k=1}^{n-i+1}{\binom {n-1}{k-1}G(k,1)G(n-k,i)}
$$

### 有标号仙人掌计数

设$n$个点的有标号有根仙人掌数量的EGF为$F(x)$。

考虑一棵有根仙人掌的根，与其相邻的结构有两种：

1. 桥。桥对面恰好是一棵有根仙人掌。对应的生成函数即为$F(x)$。
2. 环。将环上的边删去后，环上的每一个点都是某棵仙人掌的根。对应的生成函数即为$\frac 12 F(x)^{i-1}$。

将这些方案加起来后$\exp$即得$n-1$个点的有根仙人掌数量。由此得到方程：
$$
F(x)=x\exp\left(F(x)+\frac 12\sum_{i=2}^{\infty}F(x)^i\right)\\
=x \exp\left(F(x)+\frac{F^2(x)}{2-2F(x)}\right)=x \exp\left(\frac{2F(x)-F(x)^2}{2-2F(x)}\right)
$$
考虑牛顿迭代：
$$
t(F)=x \exp\left(\frac{2F-F^2}{2-2F}\right)-F\\
t'(F)=x \exp\left(\frac{2F-F^2}{2-2F}\right)\left(1+2\frac{2F-F^2}{(2-2F)^2}\right)-1\\
$$
一大坨糊上去即可。

```cpp
vi cactus(int n) {
    if (n == 1) { return { 0 }; }
    vi f = cactus0((n + 1) >> 1); f.resize(n);
    vi h1 = pinv(psub({2},pmul(f,2))), h2 = psub(pmul(f,2),pmul(f, f, n)), h3 = pmul(h2, h1, n), h4 = pmul(h3, h1, n);
    h3 = exp(h3); h3.insert(h3.begin(), 0); h3.pop_back();
    return psub(f, pmul(psub(h3, f), pinv(psub(pmul(h3, padd({1}, pmul(h4, 2)), n), {1})), n));
}
```

### 有标号点双连通图计数

设$n$个点的有根连通图的EGF为$F(x)$，$n$个点的点双连通图数量为$g_n$。

每个有根连通图的根都在几个点双中。对于其所在的某个点双，将属于这个点双中的边全部拆掉后剩下来的每个点都对应一个有根连通图。设这个点双大小为$i+1$，则该点双中的方案数对应的EGF为$\displaystyle g_{i+1}\frac{F(x)^{i}}{i!}$。

令$\displaystyle G(x)=\sum_{i=1}^{\infty}g_{i+1}\frac{x^i}{i!}$，则有
$$
F(x)=x\exp \left(\sum_{i=1}^{\infty}g_{i+1}\frac{F(x)^{i}}{i!}\right)=x \exp(G(F(x)))
$$

将$F^{-1}(x)$代入$x$得
$$
x=F^{-1}(x)\exp (G(x))\\
G(x) = \ln\frac{x}{F^{-1}(x)}
$$
令$H(x)=\ln\frac{F(x)}{x}$，则有$G(x)=H(F^{-1}(x))$。

则$n+1$个点的带标号点双连通图个数为
$$
n![x^{n}]G(x)=n!\frac 1n[x^{n-1}]H(F^{-1}(x))=(n-1)![x^{n-1}]H'(x)\left(\frac{x}{F(x)}\right)^{n}\\=(n-1)![x^{n-1}]H'(x)\left(\frac{1}{\exp(H(x))}\right)^{n}=(n-1)![x^{n-1}]H'(x){\exp(-nH(x))}
$$

```cpp
int vbcc(int n) {
    n--;
    if (!n) return 1;
    int n1 = n + 2;
    vi f(n1, 0);
    f[0] = 1;
    for (int i = 1; i < n1; ++i)
        f[i] = qpm(2, (1ll * i * (i - 1) / 2) % (P - 1));
    f = log(egf(f));
    for (int i = 0; i < n1; ++i)
        f[i] = mul(f[i], i);
    f.erase(f.begin());
    vi h = log(f);
    vi hh = pmul(deriv(h), exp(pmul(h, sub(0, n))), n);
    return mul(fac[n - 1], hh[n - 1]);
}
```

### 有标号边双连通图计数

设$n$个点的有根连通图EGF为$F(x)$，$n$个点的有根边双连通图EGF为$G(x)$。

每个有根连通图的根都在某个有根边双中。对于其所在的边双，将属于这个边双的边全部拆掉后剩下来的每个点都连接着数个有根连通图。

设这个边双大小为$i$，则该边双的方案数为$\displaystyle g_i \frac{\exp(F(x))^i}{i!}$

总方案数为
$$
F(x)=\sum_{i=1}^{\infty}g_i\frac{(x \exp(F(x)))^i}{i!}=G(x \exp (F(x)))
$$
令$H(x)=x \exp(F(x))$
$$
F(x)=G(H(x))
$$
将$H^{-1}(x)$代入$x$得
$$
G(x)=F(H^{-1}(x))
$$
则$n$个点的有标号有根边双个数为
$$
n![x^n]G(x)=n!\frac 1n[x^{n-1}]F'(x)\left(\frac{x}{H(x)}\right)^n=(n-1)![x^{n-1}]F'(x)\exp(-nF(x))
$$

```cpp
int ebcc(int n) {
    int n1 = n + 1;
    vi f(n1, 0);
    f[0] = 1;
    for (int i = 1; i < n1; ++i)
        f[i] = qpm(2, (1ll * i * (i - 1) / 2) % (P - 1));
    f = log(egf(f));
    for (int i = 0; i < n1; ++i)
        f[i] = mul(f[i], i);
    vi hh = pmul(deriv(f), exp(pmul(f, sub(0, n))), n);
    return mul(invs[n], mul(fac[n - 1], hh[n - 1]));
}
```

