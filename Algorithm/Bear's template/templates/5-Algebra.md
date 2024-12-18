---
title: "Algebra"
author: forgottencsc
date: Dec 11, 2020
geometry: margin=1cm
output: pdf_document
---

## 行列式与线性方程组

### Cramer法则

对于非齐次线性方程组$A\vec x= \vec b$，其中$A=\begin{bmatrix}\vec{a}_1, \vec{a}_2, \cdots, \vec{a}_n\end{bmatrix};A \in \mathbb{R}^{n\times n};\vec a_i, b \in \mathbb{R}^{n \times 1}; |A| \neq 0$。

设$A_i=\{\vec a_1, \cdots, \vec a_{i-1}, \vec b, \vec a_{i+1}, \cdots, \vec a_n\}$，则$\vec x$的第$i$个分量等于$\frac{|A_i|}{|A|}$。

## 高斯消元与逆矩阵

### 逆矩阵

#### 模质数

```cpp
mat inv(mat a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        a[i].resize(2 * n, 0);
        a[i][n + i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]);
        if (!a[i][i]) return {};
        for (int j = i, t = inv(a[i][i]); j < 2 * n; ++j)
            a[i][j] = mul(a[i][j], t);
        for (int j = 0; j < n; ++j) if(j != i)
            for (int k = i, t = a[j][i]; k < 2 * n; ++k)
                a[j][k] = sub(a[j][k], mul(t, a[i][k]));
    }
    for (int i = 0; i < n; ++i) {
        copy_n(a[i].begin() + n, n, a[i].begin());
        a[i].resize(n);
    }
    return a;
}
```

#### 实数

```cpp
mat inv(mat a) {
    const int n = a.size();
    for (int i = 0; i < n; ++i) {
        a[i].resize(2 * n, 0);
        a[i][n + i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            if (abs(a[j][i]) > abs(a[i][i]))
                swap(a[i], a[j]);
        if (!sgn(a[i][i])) return {};
        for (int k = 2 * n - 1; k >= i; --k)
            a[i][k] /= a[i][i];
        for (int j = 0; j < n; ++j)
            for (int k = 2 * n - 1; j != i && k >= i; --k)
                a[j][k] -= a[j][i] * a[i][k];
    }
    for (int i = 0; i < n; ++i) {
        copy_n(a[i].begin() + n, n, a[i].begin());
        a[i].resize(n);
    }
    return a;
}
```

#### Sherman–Morrison/Woodbury matrix identity

若$A$可逆且$A+uv^T$可逆，则
$$
(A+uv^T)^{-1}=A^{-1}-\frac{A^{-1}uv^TA^{-1}}{1+v^{T}A^{-1}u}
$$
证明：

先证若$A+uv^T$可逆则$1+v^TA^{-1}u$非零。

证其逆否命题：若$1+v^TA^{-1}u=0$，则$v^{T}A^{-1}u=-1$，则$u$非零，则$A^{-1}u$非零。

此时$(A+uv^T)(A^{-1}u)=AA^{-1}u+uv^TA^{-1}u=u+u(-1)=0$，即非零向量$A^{-1}u$属于$(A+uv^T)$的核，因此$(A+uv^T)$不可逆。现在有
$$
\left(A^{-1}-\frac{A^{-1}uv^TA^{-1}}{1+v^{T}A^{-1}u}\right)(A+uv^T)\\=I+A^{-1}uv^T-\frac{A^{-1}uv^T}{1+v^{T}A^{-1}u}-\frac{A^{-1}uv^TA^{-1}}{1+v^{T}A^{-1}u}uv^T\\
=I+\frac{(1+v^TA^{-1}u)A^{-1}uv^T-A^{-1}uv^T-A^{-1}u(v^TA^{-1}u)v^T}{1+v^{T}A^{-1}u}
=I
$$

```cpp
void modify(mat& a, mat& b, vec u, vec v) {
    const int n = a.size();
    int w = 1;
    vec x(n, 0), y(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = add(a[i][j], mul(u[i], v[j])),
            w = add(w, mul(v[i], mul(b[i][j], u[j]))),
            x[i] = add(x[i], mul(b[i][j], u[j])),
            y[i] = add(y[i], mul(b[j][i], v[j]));
    assert(w); w = inv(w);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = sub(b[i][j], mul(w, mul(x[i], y[j])));
}
```

应用：用来维护矩阵的逆，而逆可以用来计算伴随阵，而伴随阵可以用来计算行列式。

可以将$u$和$v$推广到$n \times k$的情况（虽然好像没什么用）：
$$
(A+UV^T)^{-1}=A^{-1}-A^{-1}U(I_k+V^TA^{-1}U)^{-1}V^TA^{-1}
$$
注：中间的$I_k$是$k$阶单位阵。

### 求伴随阵

例([OpenJ_POJ - C19J](https://vjudge.net/problem/OpenJ_POJ-C19J/origin))

定义：$n$阶方阵$A$中元素$a_{ij}$的余子式被定义为划去其所在行列后所得矩阵的行列式乘上$(-1)^{i+j}$。

定义：$n$阶方阵的伴随阵$A^*$满足
$$
(A^*)_{ij}= M_{ji}
$$
命题：当$A$可逆时，有$A^*=A^{-1}|A|$。

命题：当$\text {rk} A= n-1$时，有$\text{rk} A^*=1$。

命题：当$\text {rk} A \leq n-2$时，有$A^*=0$。

求模意义下的伴随阵：

若秩不是$n-1$则特判。

因为$A^*$的秩是$1$，所以存在两个$n$维列向量$u,v$满足$A^*=uv^T$。

因此求出$A^*$的某一行和某一列即可求出整个$A^*$。

前提是这一行与这一列的交非零，所以需要找到任意一个非$0$的$n-1$阶余子式。

对$A$进行消元必定在某一步失败，记这一行为`fj`。同理对$A^T$消元必在某一步失败，记这一列为`fi`。

则划去$A$的第`fi`行第`fj`列剩下的矩阵必定可逆。代码可以参考下面的`rk`，返回的是秩，往`f`里放的是失败时所在行/列（第一次失败时行等于列）。

将$A$的第`fi`行换成一堆随机数后大概率可逆，因此可以通过求逆得到这个矩阵的伴随阵。

此时按伴随阵的定义，结果的第`fi`列即$A^*$的第`fi`列。

同理可求得$A^*$的第`fj`行。

然后就做完了。

```cpp
int rk(mat a, int& f) {
    const int n = a.size(), m = a[0].size();
    int i = 0;
    for (int j = 0; i != n && j != m; j++) {
        for (int k = j + 1; !a[i][j] && k < n; ++k)
            if (a[k][j]) swap(a[k], a[j]);
        if (!a[i][j]) { f = i; continue; }
        for (int k = i + 1, t = inv(a[i][j]); k < n; ++k)
            for (int l = j, w = mul(a[k][j], t); l < m; ++l)
                a[k][l] = sub(a[k][l], mul(w, a[i][l]));
        i++;
    }
    return i;
}

bool adj0(mat& b) {
    const int n = b.size(); int d = 1;
    mat a(n, vec(2 * n, 0));
    for (int i = 0; i < n; ++i) {
        copy_n(b[i].begin(), n, a[i].begin());
        a[i][n + i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]), d = sub(0, d);
        d = mul(d, a[i][i]);
        for (int j = i, t = inv(a[i][i]); j < 2 * n; ++j)
            a[i][j] = mul(a[i][j], t);
        for (int j = 0; j < n; ++j) if(j != i)
            for (int k = i, t = a[j][i]; k < 2 * n; ++k)
                a[j][k] = sub(a[j][k], mul(t, a[i][k]));
    }
    if (!d) return false;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            b[i][j] = mul(a[i][n + j], d);
    return true;
}

mat adj(mat a) {
    int n = a.size(), fi, fj;
    if (n == 1)
        return mat(1, vec(1, a[0][0] ? 1 : 0));
    int r = rk(a, fj);
    if (r == n) { adj0(a); return a; }
    if (r <= n - 2) return mat(n, vec(n, 0));
    uniform_int_distribution<int> uid(0, P - 1);
    mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
    mat b(n, vec(n, 0)), c = a;
    do for (int i = 0; i < n; ++i) c[i][fj] = uid(mt);
    while (!adj0(c));
    for (int i = 0; i < n; ++i) b[fj][i] = c[fj][i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[i][j] = a[j][i];
    rk(c, fi);
    do for (int j = 0; j < n; ++j) c[j][fi] = uid(mt);
    while (!adj0(c));
    for (int j = 0; j < n; ++j) b[j][fi] = c[fi][j];
    int w = inv(b[fj][fi]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != fj && j != fi)
                b[i][j] = mul(mul(b[fj][j], b[i][fi]), w);
    return b;
}
```

### 行列式

定义：
$$
\det A=\sum_{\sigma \in S_n}\mathbb {sgn}(\sigma)\prod_{i=1}^na_{i\sigma_i}
$$

#### 模质数

高斯消元，$O(n^3)$。

```cpp
typedef vector<int> vec;
typedef vector<vec> mat;

int det(mat a) {
    const int n = a.size(); int res = 1;
    for (int i = 0; i != n; ++i) {
        for (int j = i + 1; j != n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]), res = sub(0, res);
        if (!a[i][i]) return 0; else res = mul(res, a[i][i]);
        for (int j = i + 1, t = inv(a[i][i]); j != n; ++j)
            for (int k = i, w = mul(a[j][i], t); k != n; ++k)
                a[j][k] = sub(a[j][k], mul(w, a[i][k]));
    }
    return res;
}
```

#### 模合数

高斯消元+辗转相除，$O(n^3 \log U)$。其中$U$是模数。

```cpp
typedef vector<int> vec;
typedef vector<vec> mat;

int det(mat a) {
    const int n = a.size(); int res = 1, f = 0;
    for (int i = 0; i != n; ++i) {
        for (int j = i + 1; j != n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]), f ^= 1;
        if (!a[i][i]) return 0;
        for (int j = i + 1; j != n; swap(a[i], a[j]), f ^= 1, ++j)
            for (; a[i][i]; swap(a[i], a[j]), f ^= 1)
                for (int k = i, q = a[j][i] / a[i][i]; k != n; ++k)
                    a[j][k] = sub(a[j][k], mul(q, a[i][k]));
        res = mul(res, a[i][i]);
    }
    return f ? sub(0, res) : res;
}
```

#### 实数

高斯消元，$O(n^3)$

```cpp
typedef double dbl;
const dbl eps = 1e-10;
int sgn(dbl f) { return f < -eps ? -1 : f > eps; }

typedef vector<dbl> vec;
typedef vector<vec> mat;

dbl det(mat a) {
    const int n = a.size(); dbl res = 1;
    for (int i = 0; i != n; ++i) {
        for (int j = i + 1; j != n; ++j)
            if (abs(a[j][i]) > abs(a[i][i]))
                swap(a[i], a[j]), res = -res;
        if (!sgn(a[i][i])) return 0; else res *= a[i][i];
        for (int j = i + 1; j != n; ++j) {
            if (!sgn(a[j][i])) continue;
            double w = a[j][i] / a[i][i];
            for (int k = i; k != n; ++k)
                a[j][k] -= w * a[i][k];
        }
    }
    return res;
}
```

## 线性空间与线性算子

### 基

线性无关的极大向量组被称为线性空间的一组基。

命题：所有基大小相同。

命题：设$V$，$W$分别为$\mathbb F$上的$n,m$维线性空间，则对于$V$的一组基$B$，$W$的一组基$C$来说$T:V\to W$有唯一的矩阵表示$A \in \mathbb F^{m \times n}$。

证明：考虑域$F$上的$n$维线性空间$V$，$m$维线性空间$W$和线性算子$T:V \to W$

设$B=\begin{bmatrix}v_1,v_2,\cdots,v_n\end{bmatrix}$为$V$的基，$C=\begin{bmatrix}w_1,w_2,\cdots,w_m\end{bmatrix}$为$W$的一组基

对于$V$中的向量$v$，其在$B$下的坐标为$x$，$W$中向量$w$，其在$C$下的坐标为$y$，$T$在基$B,C$下的矩阵表示为$A$，设
$$
T(v_i)=\sum_{j=1}^mw_ja_{ji}
$$
则有
$$
T(\vec v)=T(B\vec x)=T\sum_{i=1}^n\vec v_ix_i=\sum_{i=1}^nT(\vec v_ix_i)=\sum_{i=1}^nT(\vec v_i)x_i\\
=\sum_{i=1}^n\sum_{j=1}^ma_{ji}\vec w_jx_i=\sum_{j=1}^m\vec w_j\sum_{i=1}^na_{ji}x_i=\sum_{j=1}^m\vec w_jy_j
$$
由此有
$$
A=\{a_{ij}\},\vec y=A\vec x
$$

### 基变换

设$B=\{\vec v_1,\cdots,\vec v_n\}$为$V$的一组基，$B'=\{\vec v'_1,\cdots,\vec v'_n\}$为另一组基。

由基的定义，可将$v'_i$用$B$展开。即
$$
\vec v'_i=\sum_{j=1}^n\vec v_jp_{ji}
$$
写作矩阵形式即
$$
B'=\begin{bmatrix}\vec v'_1,\cdots,\vec v'_n\end{bmatrix}
=\begin{bmatrix}\displaystyle\sum_{j=1}^np_{ij}\vec v_j\end{bmatrix}
=\begin{bmatrix}\vec v_1, \cdots, \vec v_n\end{bmatrix}
\begin{bmatrix}
p_{11} & p_{12} & \cdots & p_{1n}\\
p_{21} & p_{22} & \cdots & p_{2n}\\
\vdots & \vdots & \ddots & \vdots\\
p_{n1} & p_{n2} & \cdots & p_{nn}
\end{bmatrix}
=BP
$$
考虑基变换对向量的影响：设向量$\vec v$在$B$中坐标为$\vec x$，在$B'$中坐标为$\vec x'$，则
$$
\vec v=B\vec x=B'\vec x'
$$
所以有
$$
\vec x'=P^{-1}\vec x
$$
设$C=\{\vec w_1, \cdots , \vec w_m\}$为$W$的一组基，$C'=\{w'_1, \cdots, w'_m\}$为另一组基，同上有$C'=CQ$。

考虑基变换对线性变换$T:v \to w$在基$B,C$下的矩阵的影响。

设$T(v)=w$，则因$v=Bx=B'x'.w=Cy=C'y'$有

$T(B'x')=C'y'$



### 子空间投影

定理：设子空间$W$的一组基为$A=\begin{bmatrix}a_1,a_2,\cdots,a_m\end{bmatrix} \in \mathbb{R}^{n\times m}$，则矩阵$P=A(A^TA)^{-1}A^T \in \mathbb{R}^{n \times n}$将任何$\mathbb{R}^n$中的向量投影至该子空间中。

证明：设$x$的投影为$x'$，$x'$在$A$下的坐标为$y$，则有
$$
A^T(Ay)=A^Tx
$$
由$x'=Ay$，有
$$
x'=Ay=A(A^TA)^{-1}A^Tx=Px
$$
命题：$A^TA$正定，因此$(A^TA)^{-1}$存在。

证明：对于任意$x \in \mathbb{R}^m \setminus \{0\}$，有
$$
x^T(A^TA)x=(Ax)^T(Ax)>0
$$

## 特征值与特征向量

对域$\mathbb F$上的矩阵$A \in \mathbb F^{n \times n}$，若存在$\lambda \in \mathbb F,\vec x \in \mathbb F^{n \times 1}$使得$A\vec x=\lambda \vec x$，则$\lambda$被称为$A$的特征值，而$\vec x$为$A$的特征向量。

### 特征多项式

矩阵$A \in \mathbb F^{n \times n}$的特征多项式为：$f(\lambda) = |\lambda I-A|$

定理(Hamilton-Caylay)：$f(A)=0$

注：若$A$为$n$阶方阵，则其特征多项式$f(x)$的次数至多为$n$。

## 杂项

### Vandermonde矩阵

定义(Vandermonde矩阵)：
$$
V_{ij}=(x_j)^i
$$
即
$$
V=\begin{bmatrix}
x_1 & x_2 & \cdots & x_n\\
x_1^2 & x_2^2 & \cdots & x_n^2\\
\vdots & \vdots & \ddots & \vdots \\
x_1^n & x_2^n & \cdots & x_n^n\\
\end{bmatrix}
$$
其逆为
$$
V^{-1}_{ij}=\frac{\sigma_{n-j}(x_1, \cdots, x_{i-1}, x_{i+1}, \cdots, x_n)}{x_i\displaystyle\prod_{i  \neq j}(x_j-x_i)}
$$
因为
$$
\prod_{i=1}^n(x-x_i)=\sum_{i=0}^{n}\sigma_{n-i}(x_1, \cdots, x_n) x^i
$$
所以可以在$O(n^2)$复杂度内通过将上式除以$x-x_i$来求出所有的$\sigma_{j}(x_1, \cdots, x_{i-1}, x_{i+1}, \cdots, x_n)$，每个$i$需要$O(n)$。

求逆总复杂度$O(n^2)$。

```c++
mat inverse_of_vandermonde(vec x) {
    const int n = x.size();
    vec c(n + 1, 0); c[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j >= 1; --j)
            c[j] = add(c[j], mul(x[i - 1], c[j - 1]));
    mat a(n, c);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = sub(a[i][j], mul(x[i], a[i][j - 1]));
    vec b = x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (j != i) b[i] = mul(b[i], sub(x[j], x[i]));
    for (int i = 0; i < n; ++i)
        b[i] = inv(b[i]);
    mat r(n, vec(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            r[i][j] = (j & 1 ? sub : add)(0, mul(b[i], a[i][n - j - 1]));
    return r;
}
```

### 循环矩阵

设$\omega_n$为$n$次单位根，则

### 积和式

定义：$n$阶方阵的积和式被定义为
$$
\mathbb {perm} A = \sum_{\sigma \in S_n}\prod_{i=1}^na_{i\sigma_i}
$$
直接计算复杂度是$O(n!)$的。

若从每一行任意取一个元素乘起来求和，则答案为每一行之和之积。

考虑使用容斥把不符合条件（即每一行取的列不能相同）的东西去掉。

令$f(S)$为每一行所选取的列之并恰好为$S$的答案，$g(S)$为每一行选取的列之并是$S$的某个子集的答案，则有
$$
g(S)=\sum_{T \subseteq S}f(T)=\prod_{i=1}^n\sum_{j \in S}a_{ij}\\
\mathbb{perm} A=f([n])=\sum_{T \subseteq [n]}(-1)^{n-|T|}g(T)
$$
预处理每一列的子集和复杂度是$O(2^n)$的，最终复杂度$O(n2^n)$。

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

## 群结构

抽象代数主要的研究对象是集合上的**运算**，和运算产生的**结构**。群结构是其中最典型的一种。

由于作者水平有限，本章与Artin第二章和第六章的部分是基本同构的。

为了关注代数部分中与算法竞赛关联更加紧密的部分（主要还是菜），本章内的部分定理的表述和证明会比较龙鸣，请不要在意这些细节。

本章中的许多内容与算法竞赛没有直接关联，但偶尔能够给一些题目（往往是那些具有良好对称性或有代数背景的题目）的解决过程提供有效的直觉。

### 群的基本性质

#### 运算与群

定义（二元运算）：对于一个集合$S$，$S$上的运算是一个从$S \times S$到$S$的函数。

例：实数加法，实数乘法都是从$\mathbb{R} \times \mathbb{R}$到$\mathbb{R}$上的运算。整数除法则不是，因为其结果可能在$\mathbb Q$中而不在$\mathbb{Z}$中。

定义（单位元）：对于一个集合$S$上的运算$\times$，若存在元素$e\in S$使得$\forall s \in S$有$e \times s = s \times e = s$则称$e$为运算$\times$的单位元。

例1：0是实数加法的单位元。

例2：1是实数乘法的单位元。

例3：单位矩阵是方阵乘法的单位元。

例4：单位置换（不动的那个）是置换复合的单位元。

命题：若单位元存在则唯一。

证明：设$e_1$，$e_2$均满足单位元性质，则$e_1=e_1e_2=e_2$.

定义（可逆）：对于$S$上的存在单位元的运算$\times$，若对于$S$中任意元素$s$存在元素$s^{-1}$使得$s\times s^{-1}=s^{-1}\times s=e$则运算$\times $可逆，称$s^{-1}$为$s$的逆或逆元。

例1：实数$x$的的加法逆元是$-x$.

例2：非零实数$x$的乘法逆元是$\frac 1x$。

例3：方阵的矩阵乘法逆元即其逆矩阵。

命题：若$\times$满足结合律则逆元存在且唯一。

证明：设$s \times t_1=t_1 \times s = s \times t_2 = t_2 \times s = e$，$t_1=t_1\times (s\times t_2)=(t_1\times s)\times t_2=t_2$。

例：对于群$G$，若$g$的逆为$g^{-1}$，$h$的逆为$h^{-1}$，则$(gh)^{-1}=h^{-1}g^{-1}$。

定义（群）：群是一个集合$G$和定义在$G$上的**结合的**，**存在单位元的**，**可逆的**二元运算$\times$组成的二元组$(G,\times)$。若运算$\times$满足交换律则称$G$为交换群（阿贝尔群）。该集合的大小被称为群的阶。

例1：集合是有理数集$\mathbb Q$，运算是加法。记为$\mathbb Q^+$。

例2：集合是非零有理数集$\mathbb Q -\{0\}$，运算是乘法。记为$\mathbb Q^\times$。

例3：集合是整数集$Z$，运算是加法。记为$\mathbb{Z}^+$。

例4：集合是非零实数集，运算是乘法，记为$\mathbb{R}^\times$

例5：集合是复平面上的单位圆，运算是复数乘法。记为$U(1)$。

例6：集合是复平面单位圆上的所有$k$次单位根$\{\exp \frac{2\pi i}{k}|i\in \{0,1,\cdots,k-1\}\}$，运算是复数乘法。

例7：集合中的元素是模$n$意义下的$n$个剩余类，运算是模$n$意义下的加法。这一类群记为$\mathbb{Z} _n$。

例8：集合中的元素是模质数$p$意义下的$p-1$个不包含$0$的剩余类，运算是模$p$意义下的乘法。这一类群记为$\mathbb F_p^\times$。

例9：集合中的元素是$\mathbb{R}$上的所有行列式非0的$n$阶方阵，运算是矩阵乘法。记为$GL(\mathbb{R},n)$，称为一般线性群。

例10：集合中的元素是$\mathbb{R}$上的所有行列式为$1$的$n$阶方阵，运算是矩阵乘法。记为$SL(\mathbb{R},n)$，称为特殊线性群。

例11：集合中的元素是$\mathbb{R}$上所有$n$阶正交矩阵，运算是矩阵乘法。记为$O_n$，称为$n$阶正交群。

例12：集合中的元素是全体三维旋转，运算是旋转的复合。记为$SO(3)$，称为$3$维旋转群。

例13：集合中的元素是长度为$n$的所有置换，运算是置换的复合。记为$S_n$，称为$n$阶对称群。

例14：集合中的元素是长度为$n$的所有偶置换，运算是置换的复合。记为$A_n$，称为$n$阶交错群。

例15：集合中的元素是二维平面上的等距变换（即任意两点之间的距离在变换前后不发生改变），运算是变换的复合。

例16：集合中的元素是将中心在原点的正12边形旋转$\frac {k\pi} 6$弧度，运算是旋转的复合。

例17：集合中的元素是将中心在原点的正12边形旋转$\frac {k\pi} 6$弧度和翻转后旋转$\frac {k\pi} 6$弧度，运算是旋转/翻转的复合。

例18：集合中的元素是四元数的基$\{e,i,j,k,-1,-i,-j,-k\}$，运算是四元数乘法。记为$Q$，称为四元数群。

例19：集合上的元素是$\mathbb{Z}$上所有行列式为$1$的$n$阶方阵，运算是矩阵乘法，即$SL(\mathbb{Z},n)$ 。

对称性即是**变换下的不变性**。而变换的集合与变换之间的复合往往形成了一个群。因此群可以看作对对称性的进一步抽象。

例子中的一些群拥有一个共同的性质，即它们中的元素都可以表示成某个单一元素的“幂”。（如整数加法群里$2$的三次“幂”不是$8$而是$6$，因为这个群的运算是加法而不是乘法）这种群被称为循环群。

定义（循环群）：对于群$G$，若存在元素$x$使得$\forall g \in G, \exists k \in \mathbb{Z} ,g=x^k$，则$G$是由$x$生成的循环群，记为$G=<x>$，$x$被称为$G$的**生成元**。大小为$n$的循环群记为$C_n$。

例3，6，7，8，16中的群都是循环群。

类似循环群，很多群中的所有元素都能仅用其某个子集中的元素来表达。

定义（生成元）：若$G$中的每个元素都能用其子集$S$中的元素表达，则称$G$由$S$生成。

例1：$\mathbb{Z}$由$\{1\}$生成，也可以由$\{-1\}$生成。

例2：$Q$由集合$\{i,j\}$生成。

例3：$S_n$由$\{(12),(13),\cdots,(1n)\}$生成。

例4：$A_n$由$\{(123),(124),\cdots,(12n)\}$生成。

注：最小的非交换群是对称群$S_3$。

例子中的另一些群中的元素是置换，这些群称为置换群。

注：群中的运算可以不交换，如可逆方阵构成的乘法群和置换构成的置换群，还有上面的例17和例18。

#### 子群

集合可以有子集，线性空间可以有子空间，群也可以有子群。

线性空间的子空间保留了原空间的线性结构，由此可以推广出子群的定义。

定义（子群）：$G$的满足群公理的子集$H$（即运算对$H$封闭，结合，可逆，单位元存在）被称为$G$的子群。有些书上记作$H \leq G$。

例1：正实数乘法群是实数乘法群的子群

例2：所有偶数和加法组成的群是$\mathbb{Z}^+$的子群。

例3：对于正整数$n$，所有$n$的倍数和它们的相反数和加法组成的群是$\mathbb{Z}^+$的子群，记为$n\mathbb{Z}$。

例4：群$<\{0,2,4,6,8,10\},+>$，$<\{0,3,6,9\},+>$都是模12加法群$\mathbb{Z}_{12}$的子群。

例5：$A_n$是$S_n$的子群。

例6：$SL(\mathbb F,n)$是$GL(\mathbb F,n)$的子群。

例7：$C_n$是$D_n$的子群。

#### 同态与同构

这些群之间有一些相似之处，如何刻画这种相似的关系？

定义（同态与同构）：不同的群之间存在一些**保持运算结构**的的映射。若对于两个群$G,H$，函数$\rho:G\rightarrow H$满足$\forall g_1, g_2 \in G,\rho(g_1)\rho(g_2)=\rho(g_1g_2)$则称$\rho$是从$G$到$H$的**同态**。若一个同态是双射，则称其为**同构**。若两个群之间存在同构则称这两个群同构，记作$\cong$。

注：上面略去了具体运算。

例1：$\exp(x)$是实数加法群到实数乘法群的同态，因为$\forall a, b \in \mathbb{R},\exp(a)\exp(b)=\exp(a+b)$。

例2：$\det(A)$是一般线性群到非零实数乘法群的同态，因为$\forall A, B \in GL(\mathbb{R},n), |A||B|=|AB|$。

例3：对于质数$p$和模$p$意义下的原根$g$，$\rho (x)=g^x$是从$\mathbb{Z}_{p-1}$到$\mathbb F_{p}^{\times}$的同构。

例4：$n$次单位根与复数乘法构成的群与$\mathbb{Z}_n$与循环群$C_n$是同构的。

命题：阶数相同的循环群是互相同构的。

证明：对于阶数相同的循环群$G_1$和$G_2$，将$G_1$中任意一个生成元$g_1$及其幂映射到$G_2$的任意一个生成元$g_2$及其对应的幂即可构造一个同构。

定理(Caylay)：任意一个有限群都与某个相同大小的置换群同构。

注：不是那个特征多项式的，更不是那个数树的。

证明：设$G$是一个大小为$n$的有限群，那么可以将$G$的元素编号为$1~n$。对于$G$的任意一个元素$g$，不妨设将其左乘到$G$的编号为$i$的元素上可以得到编号为$j$的元素，这形成了一个自然的置换关系。不难验证由群$G$的每个元素所对应的置换能够构成一个与$G$同构的群。

定义（同态的核与像）：对于同态$\rho : G \rightarrow H$，被映射到$H$的单位元的$G$中元素组成的集合被称为$\rho$的核，记作$\text{Ker} \rho$。由存在$G$中元素$g$使得$\rho (g)=h$的$h$中元素组成的$H$的子集被称为$\rho$的像，记作$\text {Im} {\rho}$。

例1：上面例1中同态的核只有加法单位元0，像是所有正实数。

例2：上面例2中同态的核是特殊线性群$SL(\mathbb{R},n)$，像是所有非零实数。

例3：上面例3中同态的核是加法单位元0，像是乘法单位元1。

命题：对于同态$\rho : G \rightarrow H$，$\text {Ker} \rho $是$G$的子群，$\text{Im} \rho$是$H$的子群。

证明$\text {Ker} \rho $是$G$的子群：

1. 封闭性：$\forall k_1, k_2 \in \text {Ker} \rho ,\rho(k_1k_2)=\rho (k_1)\rho (k_2)=e_He_H=e_H$，所以$k_1k_2 \in \text{Ker} \rho$。
2. 结合律：显然。
3. 单位元存在性：显然。
4. 逆元存在性：$\forall k \in \text{Ker}\rho,e_H=\rho(e_G)=\rho(kk^{-1})=\rho(k)\rho(k^{-1})=e_H\rho (k^{-1})$，因此$\rho (k^{-1})=e_H$，$k^{-1} \in \text{Ker} \rho$。

证明$\text {Im} \rho $是$H$的子群留给读者作为练习。

#### 陪集

不难发现，$\mathbb{Z}_n$的子群都与某个$\mathbb{Z}_d$同构，其中$d$是$n$的因子。为了将这个规律推广成定理，我们先给出陪集的概念。

定义（陪集）：给定群$G$的子群$H$，对于群$G$的中的某个元素$g$我们定义$H$关于$g$的左陪集$gH=\{gh|h \in H\}$。

例1：对$\mathbb{Z}_{12}$的子群$<\{0,2,4,6,8,10\},+>$，其有两个陪集，一个是它自己，另一个是$\{1,3,5,7,9,11\}$。

例2：$\mathbb{R}^3$中$x$轴上的所有向量组成了$<\mathbb{R}^3,+>$的一个子群。其有无数个陪集，且均是平行于$x$轴的直线。这些陪集与$yOz$平面中的元素一一对应。

例3：$\mathbb{R}^3$中$xOy$平面上的所有向量$<\mathbb{R}^3,+>$的一个子群。其有无数个陪集，且均是平行于$xOy$平面的平面。这些陪集与$z$轴上的元素一一对应。

例4：对称群$S_3$中的子群$\{e,(12)\}$有$3$个左陪集，$\{e,(12)\},\{(123),(13)\},\{(132),(23)\}$。

注：上面描述的陪集都是左陪集（有些同时也是右陪集，但不全是）。我们可以用同样的方法定义右陪集，但对于某些子群$H$，划分出来的左右陪集可能完全不同！如上面例$4$的三个右陪集分别是$\{e,(12)\},\{(123),(23)\},\{(132),(13)\}$。

对这些例子的观察可以发现三个规律：

1. 陪集之间两两互不相交
2. 陪集大小相同（有限群）
3. 陪集大小是原群大小的因子（有限群）

接下来我们尝试进行证明。

规律1：
观察到若两个元素$g_1,g_2$同属一个陪集$gH$，则$\exists h_1, h_2 \in H$使得$g_1=gh_1,g_2=gh_2$，即$g_1^{-1}g_2=(h_1^{-1}g^{-1})(gh_2)=h_1^{-1}(g^{-1}g)h_2=h_1h_2\in H$。

构造关系$\sim$，$g_1 \sim g_2$当且仅当$g_1^{-1}g_2 \in H$。可以证明这是一个等价关系：

传递性：已知$g_1\sim g_2,g_2 \sim g_3$，则$g_1^{-1}g_2g_2^{-1}g_3=g_1^{-1}g_3\Rightarrow g_1 \sim g_3$
对称性：已知$g_1\sim g_2$，则$g_1^{-1}g_2\in H\Rightarrow g_2^{-1}g_1=\left(g_1^{-1}g_2\right)^{-1}\in H$
自反性：$g_1^{-1}g_1=e\in H$

因此不同陪集之间两两交为空。陪集组成的集合即是将原来的群商掉这个等价关系后剩下来的商集。若在这个商集上也可以定义一个与原群的运算相容的运算，则将其称为商群。商群将在下一节进行讨论。

规律2：
反证法。设$|gH|\neq|H|$，则要么将$g$乘到$H$的每个元素上能获得比$|H|$更多的元素，要么存在两个元素$h_1,h_2 \in H$乘上$g$后得到了相同的元素。因为群运算是可逆的，所以这两者都不可能。

规律3：
这意味着对于$G$的子群$H$，我们通过一个等价关系将$G$均匀的划分成了许多大小相同的集合，所以$|H|$必定能够整除$|G|$。

定理(Lagrange)：对于有限群$G$的任意一个子群$H$，$|H|$必定能够整除$|G|$。（即规律3）

#### 积群和商群

集合可以做笛卡尔积，线性空间可以做直积，群也可以做积。

定义（积群）：给定两个群$G,H$，称$G \times H$是$G$和$H$的积群，其集合为两个群的笛卡尔积，运算定义为$(g_1,h_1)\times (g_2,h_2)=(g_1g_2, h_1h_2)$。

数论选手喜闻乐见的中国剩余定理等价于以下事实：
若$\gcd (m,n)=1$，则$\mathbb{Z}_m\times \mathbb{Z}_n \cong \mathbb{Z}_{mn}$。

例：对于$a \in \mathbb{Z}_m$，$b \in \mathbb{Z}_n$，则可以构造一个同构：$(a,b)\mapsto an+b$。（类似的，$(a,b) \mapsto a+bm$）

集合可以商掉等价关系变成商集，线性空间可以商掉子空间变成商空间，群也可以商掉一类特殊的子群变成商群。

商群中的元素是某个子群的陪集。即商群描述的是陪集之间的与原群运算相容的运算结构。

但不是对任意一个子群的陪集之间都能定义合适的运算（如前面对$S_3$的那个大小为$2$的子群找的陪集），这里我们不加证明的给出能够在陪集之间定义符合原群的运算的条件。

定义（正规子群）：给定群$G$，$G$的子群$N$是正规的当且仅当其任意左陪集与右陪集相等，即$gN=Ng$，有时也写作$gNg^{-1}=N$。有些书上记作$N \trianglelefteq G$

例1：$A_n$是$S_n$的正规子群（证明？）。

例2：交换群的任何子群都是正规子群。

例3：$SL(\mathbb F,n)$是$GL(\mathbb F, n)$的正规子群。

例4：$\{e,(123),(132)\}$是$S_3$的正规子群。

注：$G$的任何大小为$G/2$的群都是$G$的正规子群。

群$G$对其任意一个正规子群的商群的陪集之间都可以定义与原群相容的运算。

定义（商群）：给定群$G$和$G$的一个正规子群$N$，由$N$的所有陪集和原群的运算可以定义一个新群，记作$G/N$。对于$G/N$中的任意一个元素（即某个陪集），可以选取其中任意一个元素作为代表元参与运算（为什么？）。考虑$g_1N$与$g_2N$的积，$(g_1N)(g_2N)=g_1(Ng_2)N=g_1(g_2N)N=g_1g_2N=(g_1g_2)N$。

有了商群我们就可以描述非常炫酷的同态定理了。

定理（群同态基本定理）：设$G,H$是群，$\rho$是从$G$到$H$的同态且$\text{Ker} \rho = K$，则商群$G / \text{Ker} \rho \cong \text{Im} \rho $

先证可以对$K$做商，即证$K$是$G$的正规子群。

前面已经证过$K$是$G$的子群，所以这里只用证$\forall g \in G,gKg^{-1}=K$。

证明（$K$是$G$的正规子群）：$\forall g \in G,\forall k \in K,\rho(gkg^{-1})=\rho (g)\rho(k)\rho(g^{-1})=\rho(g)\rho(g^{-1})=\rho(gg^{-1})=\rho(e_G)=e_H$，因此$gkg^{-1}\in K$，进而$gKg^{-1}=K$。因此$K$是$G$的正规子群。

证明（群同态基本定理）：要证这两个群同构，可以从$\rho$构造一个同构。

定义同构$\rho':G/K\rightarrow \text{Im}\rho $，$\rho '(gH)=\rho (g)$。

先证这是一个同态：$\rho'(g_1H)\rho'(g_2H)=\rho(g_1)\rho(g_2)=\rho(g_1g_2)=\rho'(g_1g_2H)=\rho'((g_1H)(g_2H))$。

再证明这是一个双射：$\rho'(g_1H)=\rho'(g_2H) \Leftrightarrow \rho(g_1)=\rho(g_2)\Leftrightarrow\rho(g_1g_2^{-1})=e_H\Leftrightarrow g_1g_2^{-1} \in H\Leftrightarrow g_1$与$g_2$同属同一个陪集。

因此$\rho'$是一个同构，定理得证。

例1：设$G=GL(\mathbb{R},n),H=\mathbb{R},\rho =\det$，则有$\text{ker} \rho =SL(\mathbb{R}, n),\text{im} \rho = \mathbb{R} - \{0\}$，即$GL(\mathbb{R},n)/SL(\mathbb{R},n)\cong \mathbb{R}$。

### 关于循环群的进一步讨论

对于任意一个群$G$，其中任意一个元素$g$生成的群由定义自然是一个循环群。这个循环群大小被称为该元素在$G$中的阶，记为$ord_G(g)$。

该定义等价于$\displaystyle ord(g)= \min_{x \in \mathbb N^+, g^x=e}x$

对于循环群$\mathbb{Z}_n$的元素$a$，设其阶数为$x$，则有$ax=kn$。于是$ax=\text{lcm}(a,n)=\displaystyle \frac{an}{\gcd(a,n)}$，即$x=\displaystyle \frac{n}{\gcd(a,n)}$。

前面已经证明了大小相同的循环群互相同构，因此$G$内对于阶数为$x$的元素$g$，存在一个从由$g$生成的群到$\mathbb{Z}_x$的同构，其将$g^k$映射到$k$。

由此可以证明以下命题：
$$
ord_G(g^k)=ord_{\mathbb{Z}_x}(k)=\frac{x}{\gcd(k,x)}=\frac{ord_G(g)}{\gcd(k,ord_G(g))}
$$
特别的，当$k|ord_G(g)$时有$ord_G(g^k)=ord_G(g)/k$。



### 群作用与轨道

群经常被用来刻画各种集合的对称性，如二面体群$D_n$刻画了正$n$边形的对称性，而我们可以将这个过程描述为二面体群**作用**在了正多边形的顶点集上。群作用则是对这个动作的抽象。

定义（群作用）：给定一个群$G$和一个集合$S$，$G$在$S$上的群作用是一个二元函数$\rho:G \times S \rightarrow S$，一般记作$\rho(g,s)=gs$，满足结合律（$\forall g_1, g_2 \in G,\forall s \in S,g_1(g_2s)=(g_1g_2)s$），且对于$G$的幺元$e$有$\forall s \in S, es=s$。

命题：对于$G$的任意元素$g$，映射$\rho_g:s \mapsto gs$是一个双射。

证明：首先，$\rho_e$是双射。其次，对$G$的任意元素$g$，有$g^{-1}(gs)=(g^{-1}g)s=es=s$是双射。因此$\rho_g$与$\rho_{g^{-1}}$都是双射。证毕。

例1：循环群$C_n$作用在正$n$边形的顶点集上。

例2：二面体群$D_n$作用在正$n$边形的顶点集上。

例3：三维旋转群$SO(3)$作用在三维球体上。

我们取出$SO(3)$的由绕某一个轴$\vec v$的所有旋转组成的子群$H_{\vec v}$（这个群与$U(1)$同构）。这个子群作用在一个球上，将这个球划分为许多环。对于每个环中的任意两个点$s_1,s_2$，存在旋转$g \in H_{\vec v}$使得$gs_1=s_2$。从这个例子不难抽象出轨道的概念。

定义（轨道）：给定一个$G$在$S$上的作用，可以定义一个$s$上的关系$\sim$，$s_1 \sim s_2 \Leftrightarrow \exists g \in G,g s_1 = s_2$。不难证明这是一个等价关系。这个等价关系将$G$划分为许多等价类，我们将每个等价类称为一个$G-$轨道，简称轨道。元素$s$所在的轨道记为$O_s$。由定义得$O_s=\{s' \in S|\exists g \in G,s'=gs \}$。

例1：前面的例1中，只有一个轨道，就是正$n$边形的顶点集全体。

例2：前面的例2中，二面体群中的每个翻转元素都对应一个对称轴。对于2由某一个翻转元素生成的子群，将其作用在正$n$边形上，若其对称轴经过两个顶点，则将正$n$边形的顶点集划分成了$\frac n2+1$个轨道；若其对称轴经过一个顶点，则将正$n$边形的顶点集划分成了$\frac {n-1}2+1$个轨道；若其对称轴经过零个顶点，则将正$n$边形的顶点集划分成了$\frac n2$个轨道；

例3：前面的例3中，球体被划分成了许多个环，每个环是一个轨道。



同样的例子，我们取出$SO(3)$的由绕某一个轴$\vec v$的所有旋转组成的子群$H_{\vec v}$，在这个轴上的所有点被$H_{\vec v}$中的任何元素作用都保持原状。但除球心以外的点被$H_{\vec v}$以外的任何元素作用都会使其偏离原来的位置。由此我们可以抽象出稳定化子的概念。

定义（稳定化子）：给定一个$G$在$S$上的作用，对于$S$的某个元素$t$或某个子集$T$，由$G$中满足$gt=t$或$\forall t \in T, gt \in T$的元素组成的子集（不难证明这是一个群）被称为$t/T$ 的稳定化子，记作$G_t/G_T$。有些书上也记作$Stab(t)/Stab(T)$ 。

例1：前面的例1中，每个顶点/顶点集的稳定化子都是平凡群（仅由单位元组成的群）。

例2：前面的例2中，每个顶点的稳定化子是由单位元和对称轴经过该顶点的翻转组成的。

例3：前面的例3中，球中每个点的稳定化子是由单位元和旋转轴经过该点的旋转组成的。

同一个轨道中的元素在群作用下看起来没有任何区别。但它们的稳定化子却不一定相同。



定义（共轭）：给定群$G$的两个元素$a,b$，如果存在$g$使得$b=g^{-1}ag$则称$a$与$b$共轭。

由共轭可以定义一个等价关系$\sim:a \sim b \Leftrightarrow \exists g \in G,b=g^{-1}ag$。

自反性和对称性显然，这里只证传递性：
$$
b=g_1^{-1}ag_1,c=g_2^{-1}bg_2=g_2^{-1}g_1^{-1}ag_1g_2=(g_1g_2)^{-1}a(g_1g_2)
$$
$G$的子集之间也有共轭的概念。即$A$与$B$共轭当且仅当$\exists g \in G, B=gAg^{-1}$。

命题：设$G$作用在$S$上，则对$S$的任何一个轨道$O$有$\forall a, b \in O,\exists g, G_b=g^{-1}G_ag$。

即对于某个轨道，其元素的稳定化子互相共轭。

证明：因为$a,b$属于同一个轨道，所以$\exists g, b=ga$。

则$\forall h \in G_b, g^{-1}hga=g^{-1}hb=g^{-1}b=a$，即$G_a=g^{-1}G_bg$。



定理（轨道—稳定化子）：设有限群$G$作用在有限集$S$上，则对于$\forall s \in S$有$|O_s||G_s|=G$。

在证明这个定理之前，先证明一个命题，即$O_s$中的元素与$G_s$的陪集一一对应。

命题：$O_s$中的元素与$G_s$的陪集一一对应。

证明：对于$\forall t \in O_s,\exists g \in G,t=gs$。设$\varphi:O_s\rightarrow G/G_s:t \mapsto gG_s$。$\varphi$显然是满射，因此这里只用证$\varphi$是单射。 设$t_1=g_1s,t_2=g_2s$则
$$
\varphi(t_1)=\varphi(t_2)\Leftrightarrow g_1G_s=g_2G_s \Leftrightarrow g_2^{-1}g_1 \in G_s
\Leftrightarrow t_1=g_2g_2^{-1}t_1=g_2g_2^{-1}g_1s=g_2s=t_2
$$
因此$|O_s|=|G|/|G_s|$，证毕。



定理（Burnside）：设$G$作用在$S$上，则$S$的轨道数$T$满足
$$
T=\frac 1 {|G|}\sum_{g \in G}|X^g|
$$
其中$X^g=\{s \in S|gs=s\}$，即$g$对应置换的不动点集。

证明：
$$
T=\sum_{O \subseteq S}1=\sum_{s \in S}{\frac 1{|O_s|}}=\sum_{s \in S}\frac{|G_s|}{|G|}=\frac 1 {|G|}\sum_{s \in S}\left|\{g \in G|gs=s\}\right|\\=\frac 1{|G|}\left|\{s \in S,g \in G|gs=s\}\right|=\frac{1}{|G|}\sum_{g \in G}\left|\{s \in S|gs=s\}\right|=\frac 1 {|G|}\sum_{g \in G}|X^g|
$$

例：求使用$k$种颜色给长度为$n$的环形珠串染色的方案数

本题中置换群为$\mathbb{Z}_n$。对于循环移动$i$格的操作，设$\gcd(i,n)=d$，则其对应的排列可以被分解成$d$个长度为$n/d$的轮换。因为每个轮换其不动点数为$k^{d}$。

因此答案为$\displaystyle \sum_{i=1}^nk^{\gcd(i,n)}=\sum_{d|n}k^{d}\varphi(n/d)$。



命题：设$G$作用在$S$上，若$G$稳定$S$的子集$T$，则$T$是一些$G-$轨道的并。证明略。

命题：设$G$作用在$G$上。对于$G$的子集$U$有$|G_U|$整除$|U|$。

证明：设$H=G_U$，因为$U$是一些$H-$轨道的并，而每个$H-$轨道都是$H$的某个陪集。

定理(Sylow)：设$|G|=p^rm$，其中$p \nmid m$。则$G$有至少一个大小为$p^r$的子群。

证明：考虑$G$的所有大小为$p^r$的子集组成的集合$S$。因为
$$
S= \binom {mp^r}{p^r}=\prod_{i=1}^{p^r}\frac{(m-1)p^r+i}{i}
$$
而$\gcd((m-1)p^r+i,p^r)=\gcd(i,p^r)$，所以$p$在分子分母中的幂次是一样的，从而$p \nmid S$。所以存在一个轨道$O$使得$p \nmid O$，而这个轨道中任意元素的稳定化子（其设大小为$w$）都满足$|O|w=m p^r$，所以$m=k_1|O|,w=k_1p^r$，因此$p^r | w$。同时因为其是大小为$p^r$的子集的中心化子，所以$w|p^r$（前面刚证的命题）。所以存在一个轨道$O$使得其任意元素的稳定化子大小$w$满足$p^r|w|p^r$，因此$w=p^r$。

## 环结构

理想$I$是极大理想当且仅当$R/I$是域

### 分圆多项式

$$
\Phi_n=\prod_{\gcd(d,n)=1}(x-\omega_{n}^d)
$$

当$n$是质数时，有
$$
\Phi_n=\sum_{i=0}^{n-1}x^i
$$

| $\Phi_4$ | $\Phi_6$  | $\Phi_8$ | $\Phi_9$    | $\Phi_{10}$               | $\Phi_{12}$ |
| -------- | --------- | -------- | ----------- | ------------------------- | ----------- |
| $1+x^2$  | $1-x+x^2$ | $1+x^4$  | $1+x^3+x^6$ | $1 - x + x^2 - x^3 + x^4$ | $1-x^2+x^4$ |

分圆多项式在$\mathbb {Q}$上不可约。

## 域结构

咕了