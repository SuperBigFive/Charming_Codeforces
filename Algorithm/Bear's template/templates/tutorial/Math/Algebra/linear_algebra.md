$$
\def\brac#1{\left(#1\right)}
\def\mat#1{\left[\begin{array}{cl}#1\end{array}\right]}
$$

# 线性代数

## 行列式与线性方程组

### Cramer法则

对于非齐次线性方程组$A\vec x= \vec b$，其中$A=\begin{bmatrix}\vec{a}_1, \vec{a}_2, \cdots, \vec{a}_n\end{bmatrix};A \in \R^{n\times n};\vec a_i, b \in \R^{n \times 1}; |A| \neq 0$。

设$A_i=\{\vec a_1, \cdots, \vec a_{i-1}, \vec b, \vec a_{i+1}, \cdots, \vec a_n\}$，则$\vec x$的第$i$个分量等于$\frac{|A_i|}{|A|}$。

## 高斯消元与逆矩阵

### 解线性方程组

#### 模质数

#### 实数

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

证明：



命题：设$V$，$W$分别为$\mathbb F$上的$n,m$维线性空间，则对于$V$的一组基$B$，$W$的一组基$C$来说$T:V\to W$有唯一的矩阵表示$A \in \mathbb F^{m \times n}$。

证明：考虑域$F$上的$n$维线性空间$V$，$m$维线性空间$W$和线性算子$T:V \to W$

设$B=\mat{v_1,v_2,\cdots,v_n}$为$V$的基，$C=\mat{w_1,w_2,\cdots,w_m}$为$W$的一组基

对于$V$中的向量$v$，其在$B$下的坐标为$x$，$W$中向量$w$，其在$C$下的坐标为$y$，$T$在基$B,C$下的矩阵表示为$A$，设
$$
T(v_i)=\sum_{j=1}^mw_ja_{ji}
$$
则有
$$
T(\vec v)=T(B\vec x)=T\brac{\sum_{i=1}^n\vec v_ix_i}=\sum_{i=1}^nT(\vec v_ix_i)=\sum_{i=1}^nT(\vec v_i)x_i\\
=\sum_{i=1}^n\sum_{j=1}^ma_{ji}\vec w_jx_i=\sum_{j=1}^m\vec w_j\sum_{i=1}^na_{ji}x_i=\sum_{j=1}^m\vec w_jy_j
$$
由此有
$$
A=\{a_{ij}\},\vec y=A\vec x
$$

$$
\begin{CD}V@>T>>W\\@A{B}AA @AA{C}A\\\mathbb F^n @>A>>\mathbb F^m\end{CD}
$$

### 基变换

设$B=\{\vec v_1,\cdots,\vec v_n\}$为$V$的一组基，$B'=\{\vec v'_1,\cdots,\vec v'_n\}$为另一组基。

由基的定义，可将$v'_i$用$B$展开。即
$$
\vec v'_i=\sum_{j=1}^n\vec v_jp_{ji}
$$
写作矩阵形式即
$$
B'=\mat{\vec v'_1,\cdots,\vec v'_n}
=\mat{\displaystyle\sum_{j=1}^np_{ij}\vec v_j}
=\mat{\vec v_1, \cdots, \vec v_n}
\mat{
p_{11} & p_{12} & \cdots & p_{1n}\\
p_{21} & p_{22} & \cdots & p_{2n}\\
\vdots & \vdots & \ddots & \vdots \\
p_{n1} & p_{n2} & \cdots & p_{nn}
}
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

定理：设子空间$W$的一组基为$A=\mat{a_1,a_2,\cdots,a_m} \in \R^{n\times m}$，则矩阵$P=A(A^TA)^{-1}A^T \in \R^{n \times n}$将任何$\R^n$中的向量投影至该子空间中。

证明：设$x$的投影为$x'$，$x'$在$A$下的坐标为$y$，则有
$$
A^T(Ay)=A^Tx
$$
由$x'=Ay$，有
$$
x'=Ay=A(A^TA)^{-1}A^Tx=Px
$$
命题：$A^TA$正定，因此$(A^TA)^{-1}$存在。

证明：对于任意$x \in \R^m \setminus \{0\}$，有
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
