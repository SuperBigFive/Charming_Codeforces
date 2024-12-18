## 线性递推

定义：数列$\{a_i\}$为线性递推数列当且仅当存在$k$与数列$c_1, c_2, \cdots, c_k$使得


$$
\forall i \geq k,a_i=\sum_{j=1}^kc_ja_{i-j}
$$

给定$a_0,a_1,...,a_{k-1}$，求$a_n$。

直接模拟的复杂度是$O(kn)$，一般不可接受。

### 矩阵快速幂

构造矩阵$C$与向量$\vec x_i$如下

$$
C=
\begin{bmatrix}
    c_1 & c_2 & c_3 & \cdots & c_{k-1} & c_k\\
    1 & 0 & 0 & \cdots & 0 & 0\\
    0 & 1 & 0 & \cdots & 0 & 0\\
    \vdots & \vdots & \vdots & \ddots & \vdots & \vdots\\
    0 & 0 & 0 & \cdots & 0 & 0\\
    0 & 0 & 0 & \cdots & 1 & 0
\end{bmatrix}
,
\vec x_i = \begin{bmatrix}
    a_{i+k-1}\\
    a_{i+k-2}\\
    \vdots\\
    a_{i+1}\\
    a_{i}
\end{bmatrix}
$$

易得$\vec x_i=C\vec x_{i-1}=C^i\vec x_0$。

利用快速幂可在$O(k^3 \log n)$内求出$a_n$。

### 快速线性递推

观察到对于正整数$n$，若存在序列$\{b_j\}$使得
$$
C^n=\sum_{j=0}^{k-1}b_jC^j
$$

将两边乘上$\vec x_0$：
$$
C^n \vec x_0=\sum_{j=0}^{k-1}b_j C^j \vec x_0=\sum_{j=0}^{k-1}b_j \vec x_j
$$

取出第一行：
$$
a_n=\sum_{j=0}^{k-1}b_ja_j
$$

则求出序列$\{b_j\}$后可在$O(k)$内求出$a_n$。

接下来考虑如何求序列$\{b_j\}$。

考虑$C$的特征多项式$f(x)$与多项式$g(x)=x^n$。

使用多项式除法将$g$除以$f$求出$q(x),r(x)$满足$g(x)=q(x)f(x)+r(x)$，则由Hamilton-Caylay定理（若$f(x)$是矩阵$C$的特征多项式，则$f(C)=0$）有$C^n=g(C)=q(C)f(C)+r(C)=r(C)$，即$x^n$除以$f(x)$所得余多项式的各项系数即为所求的序列$\{b_j\}$。

于是使用多项式快速幂计算$C^n$的时候对$f$取模可在$O(k \log k \log n)$内求出$\{b_i\}$。

注：这里的快速幂不是用对数和指数直接对$x^n$取模的那个。

接下来考虑如何求$C$的特征多项式。

计算矩阵$C$的特征多项式$f(x)$，即行列式

$$
\det(xI-C)=
\begin{vmatrix}
x-c_1 & -c_2 & -c_3 & \cdots & -c_{k-1} & -c_k\\
-1 & x & 0 & \cdots & 0 & 0\\
0 & -1 & x & \cdots & 0 & 0\\
\vdots & \vdots & \vdots & \ddots & \vdots & \vdots\\
0 & 0 & 0 & \cdots & x & 0\\
0 & 0 & 0 & \cdots & -1 & x
\end{vmatrix}
$$

对$i=k\cdots 2$，将第$i$列乘上$\frac 1 x$后加到第$i-1$列上后可得

$$f(x)=|xI-C|=x^{k-1}\left(x-c_1-\frac {c_2}x-\frac{c_3}{x^2}-\cdots\right)=x^k-\sum_{j=1}^kc_jx^{k-j}$$

即$f(x)=-c_k-c_{k-1}x-c_{k-2}x^2-\cdots -c_1x^{k-1}+x^k$。

```cpp
//	O(n^2)多项式乘法
vi mul(const vi& a, const vi& b) {
    const int n1 = a.size(), n2 = b.size();
    vi c(n1 + n2 - 1, 0);
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n2; ++j)
            c[i + j] = add(c[i + j], mul(a[i], b[j]));
    return c;
}

//	O(n^2)多项式除法
pair<vi, vi> div(const vi& a, const vi& b) {
    const int n1 = a.size(), n2 = b.size();
    if (n1 < n2) return { vi(), a };
    vi r = a, q(n1 - n2 + 1);
    for (int i = (int)q.size() - 1; i >= 0; --i) {
        q[i] = mul(r[i + n2 - 1], inv(b.back()));
        for (int j = 0; j < n2; ++j)
            r[i + j] = sub(r[i + j], mul(q[i], b[j]));
    }
    while (!r.empty() && !r.back()) r.pop_back();
    return { q, r };
}

//  n: 要求的是数列a的第n项
//  vector<int> a: 数列的(至少)前k项
//  vector<int> c: 长为k的线性递推式
//  return: a_n的值
//	O(k^2logn)
int linear_recursion(int n, const vi& a, const vi& c) {
    int k = c.size() - 1;
    vi f(k + 1, 0), g = { 0, 1 }, b = { 1 }; f[k] = 1;
    for (int i = 1; i <= k; ++i) f[k - i] = sub(0, c[i]);
    do if (n & 1) b = div(mul(b, g), f).second;
    while (g = div(mul(g, g), f).second, n >>= 1);
    int res = 0;
    for (int i = 0; i <= k - 1; ++i)
        res = add(res, mul(a[i], b[i]));
    return res;
}
```

### 特征值分解

考虑到若$C$存在特征值分解$C=P\Lambda P^{-1}$，可在$O(k^3+k \log n)$的复杂度内求出$a_n$。

设$\lambda$为$C$的某个特征值，发现对于$\vec x=\begin{bmatrix}\lambda ^{n-1}, \lambda ^{n-2}, \cdots, \lambda, 1\end{bmatrix}^T$有

$$
C\vec x=
\begin{bmatrix}
    c_1 & c_2 & c_3 & \cdots & c_{k-1} & c_k\\
    1 & 0 & 0 & \cdots & 0 & 0\\
    0 & 1 & 0 & \cdots & 0 & 0\\
    \vdots & \vdots & \vdots & \ddots & \vdots & \vdots\\
    0 & 0 & 0 & \cdots & 0 & 0\\
    0 & 0 & 0 & \cdots & 1 & 0
\end{bmatrix}
\begin{bmatrix}
    \lambda ^{n-1}\\
    \lambda ^{n-2}\\
    \lambda ^{n-3}\\
    \vdots \\
    \lambda\\
    1
\end{bmatrix}
=
\begin{bmatrix}
    \lambda ^{n}\\
    \lambda ^{n-1}\\
    \lambda ^{n-2}\\
    \vdots \\
    \lambda^{2}\\
    \lambda^{1}
\end{bmatrix}
=\lambda \vec x
$$

设$\vec x_i=\begin{bmatrix}\lambda_i ^{n-1}, \lambda_i ^{n-2}, \cdots, \lambda_i, 1\end{bmatrix}^T$，则由前式有$C \vec x_i=\lambda_i \vec x_i$。

令$P=\begin{bmatrix}{\vec x_1,\vec x_2, \cdots, \vec x_n}\end{bmatrix}, \Lambda=diag(\lambda_1, \lambda_2, \cdots, \lambda_n)$，则有$CP=P\Lambda$，即$C=P \Lambda P^{-1}$。

注：当$C$的特征多项式有$n$个不同的根时，$a_n$可以利用特征值分解表示成$n$个指数函数的线性组合。在其他某些情况下会退化成多项式。

### 线性递推数列的生成函数

设$\displaystyle F(x)=\sum_{i=0}^\infty a_ix^i$，则有
$$
F(x)=\sum_{i=0}^\infty a_ix^i=\sum_{i=0}^{k-1}a_ix_i+\sum_{i=k}^\infty\left(\sum_{j=1}^kc_{j}a_{i-j}\right)x^i\\
=\sum_{i=0}^{k-1}a_ix_i+\sum_{j=1}^kc_jx^j\sum_{i=k}^\infty a_{i-j}x^{i-j}=\sum_{i=0}^{k-1}a_ix_i+\sum_{j=1}^kc_jx^j\sum_{i=k-j}^\infty a_{i}x^{i}\\
=\sum_{i=0}^{k-1}a_ix_i+\sum_{j=1}^kc_jx^j\left(F(x)-\sum_{i=0}^{k-j-1}a_ix^i\right)\\
=\left(\sum_{j=1}^kc_jx^j\right)F(x)+\sum_{i=0}^{k-1}a_ix^i-\sum_{j=1}^{k-1}\sum_{i=0}^{k-j-1}c_ja_ix^{i+j}\\
=\left(\sum_{j=1}^kc_jx^j\right)F(x)+\sum_{i=0}^{k-1}a_ix^i-\sum_{j=1}^{k-1}\sum_{i=j}^{k-1}c_ja_{i-j}x^{i}\\
=\left(\sum_{j=1}^kc_jx^j\right)F(x)+\sum_{i=0}^{k-1}\left(a_i-\sum_{j=1}^{i}c_ja_{i-j}\right)x^{i}\\
$$
$$
F(x)={\displaystyle \sum_{i=0}^{k-1}\left(a_i-\sum_{j=1}^{i}c_ja_{i-j}\right)x^{i}}\bigg/\left({\displaystyle 1-\sum_{j=1}^kc_jx^j}\right)
$$
令$c_0=-1$可得
$$
F(x)=\displaystyle \sum_{i=0}^{k-1}\left(\sum_{j=0}^{i}c_ja_{i-j}\right)x^{i}\bigg/\displaystyle\sum_{j=0}^kc_jx^j
$$

例：斐波那契数列满足
$$
a_i=\begin{cases}
a_{i-1}+a_{i-2} & i>1\\
1 & 0 \leq i \leq 1
\end{cases}
$$
由定义其递推式为$c_1=c_2=1$，边界为$a_0=a_1=1$，因此其生成函数为
$$
F(x)=\frac{c_0a_0x^0+(c_0a_1+c_1a_0)x^1}{x^2+x-1}=-\frac{1}{x^2+x-1}
$$

### 最短线性递推式(Berlekamp-Massey)

定义：对于数列$\{a_0,a_1,\cdots,a_n\}$，求出最短的数列$\{c_1, c_2, \cdots, c_k\}$使得

$$
\forall i \geq k,a_i=\sum_{j=1}^kc_ja_{i-j}
$$

过程：依次对$\{a\}$的每个前缀求出最短线性递推式。

当加入$a_i$时，对当前递推式计算差值

$$
d=a_i-\sum_{j=1}^kc_ja_{i-j}
$$

若$d=0$则继续尝试加入$a_{i+1}$。否则

记之前某次$d \neq 0$时是在加入$a_p$的时候，且当时的最短递推式是$\{b_1, b_2, \cdots, b_m\}$，即

$$
d'=a_p-\sum_{j=1}^mb_ja_{p-j}
$$

注意到同时有

$$
\forall q, m \leq q < p, a_q-\sum_{j=1}^mb_ja_{q-j}=0
$$

两边拼起来：

$$
d=a_i-\sum_{j=1}^kc_ja_{i-j}=\frac{d}{d'}\left(a_p-\sum_{j=1}^m{b_j}a_{p-j}\right)
$$

移项：

$$
0=a_i-\sum_{j=1}^kc_ja_{i-j}-\frac{d}{d'}a_{i-(i-p)}+\frac{d}{d'}\sum_{j=(i-p)+1}^{(i-p)+m}b_{j-(i-p)}a_{i-j}
$$

于是

$$
c'_j=c_j+\frac{d}{d'}\begin{cases}1 & j=i-p\\-b_{j-(i-p)} & j > i-p\end{cases}
$$

因为$i$是固定的，要使新递推式长度最小即需要最大化$p-m$，维护一个最优位置（即$p-m$最大的位置的递推式）即可。

```cpp
//  vector<int> a: 要求最短线性递推式的数列
//  return vector<int> c: 最短线性递推式。即a[i]=a[i-1]c[1]+a[i-2]c[2]+...
vi berlekamp_massey(const vi& a) {
    int p = 0, d_ = a[0]; vi b = { 0 }, c = { 0 }; 
    for (int i = 0; i < a.size(); ++i) {
        int d = a[i], k = (int)c.size() - 1;
        for (int j = 1; j <= k; ++j) d = sub(d, mul(a[i - j], c[j]));
        if (!d) continue;
        if (!k) { c.resize(i + 2); p = i; d_ = a[i]; continue; }
        int m = (int)b.size() - 1, w = mul(d, inv(d_));
        vi b_ = c; c.resize(max((int)c.size(), i - p + m + 1), 0);
        c[i - p] = add(c[i - p], w);
        for (int j = i - p + 1; j <= i - p + m; ++j)
            c[j] = sub(c[j], mul(w, b[j - (i - p)]));
        if (i - p + m + 1 >= b_.size()) b = b_, d_ = d, p = i;
    }
    return c;
}
```

### 特殊的线性递推

$$
a_i=Aa_{i-1}+a_{i-2},a_0=0,a_1=1\\
$$

令$x_1,x_2$为其特征方程$x^2=A x+1$的两个解，其中
$$
a_i=\frac{x_1^{n}-x_2^{n}}{\sqrt{A^2+4}}\\
x_1+x_2=A\\
x_1-x_2={\sqrt{A^2+4}}\\
x_1x_2=-1\\
$$
观察到
$$
a_i^2=\frac{x_1^{2n}+x_2^{2n}-2x_1^nx_2^n}{A^2+4}=\frac{x_1^{2n}+x_2^{2n}-2(-1)^n}{A^2+4}\\
a_{i-1}a_{i+1}=\frac{x_1^{2n}+x_2^{2n}-x_1^{n-1}x_2^{n-1}(x_1^2+x_2^2)}{A^2+4}=\frac{x_1^{2n}+x_2^{2n}+(-1)^{n}((x_1+x_2)^2-2x_1x_2)}{A^2+4}=\frac{x_1^{2n}+x_2^{2n}+(-1)^{n}(A^2+2)}{A^2+4}
$$
因此
$$
a_{i-1}a_{i+1}-a_i^2=\frac{(-1)^{n}(A^2+4)}{A^2+4}=(-1)^n
$$
