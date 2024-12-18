## 容斥与反演

### 单位根反演

将$[i|n]$展开为$\omega_n$：

设$i \mod n=r$，则当$r\neq 0$时有
$$
\sum_{j=0}^{n-1}\omega_{n}^{ij}=\frac{\omega_n^{in}-1}{\omega_n^i-1}=\frac{(\omega_n^n)^i-1}{\omega_{n}^i-1}=0
$$
否则有
$$
\sum_{j=0}^{n-1}\omega_{n}^{knj}=n
$$
因此有
$$
[i|n]=\frac 1n\sum_{j=0}^{n-1}\omega_{n}^{ij}
$$

### 莫比乌斯反演

将$[n=1]$展开为$\mu$：
$$
[n=1]=\sum_{d|n}\mu(d)=\sum_{d}[d|n]\mu(d)
$$

### 一般偏序集上的容斥与反演

在一般偏序集上有一些二元函数$f:S \times S \to R$，其中$<$是$S$上的偏序，$R$是任意一个环。这些函数满足性质
$$
f(x,y) \neq 0 \to x \leq y
$$
可以定义这些函数之间的卷积：
$$
h(x,y) = \sum_{x \leq z \leq y}f(x,z)g(z,y)
$$
注：不满足$x \leq y$时不存在满足$x \leq z \leq y$的$z$，此时$h(x,y)=0$。

可以验证这种卷积满足结合律，即
$$
(f*g)*h=f*(g*h)
$$
定义($\delta$函数)：
$$
\delta(x,y)=[x=y]
$$
不难验证$\delta$为卷积的单位元。

对于满足$f(x,x)\neq 0$的函数可以定义其左逆$g$满足$g*f=\delta$
$$
\sum_{x \leq z \leq y}g(x,z)f(z,y)=\delta(x,y)
$$
因此有
$$
g(x,y)=\begin{cases}
1/f(y,y) & x=y\\
\displaystyle -\frac{1}{f(y,y)}\sum_{x \leq z < y}g(x,z)f(z,y)
\end{cases}
$$
可以用类似的方式定义右逆$h$满足$f*h=\delta$。由此有：
$$
g=g*\delta=g*(f *h)=(g*f)*h=\delta*h=h
$$
因此若函数$f$有逆则其逆唯一且同时为左逆和右逆。

定义($\zeta$函数)：
$$
\zeta(x,y)=[x \leq y]
$$
定义($\mu$函数)：
$$
\sum_{x \leq z \leq y}\mu(x,z)\zeta(z,y)=\delta(x,y)=[x=y]
$$
$\mu$为$\zeta$的逆。

当$(S,<)$为$(\N^+,|)$时，即集合为正整数而偏序关系为整除关系时，对每个$f:S \times S \to R$定义对应的一元函数
$$
f(x,y)=f(y/x)
$$
则有卷积
$$
(f*g)(x,y)=\sum_{x \leq z \leq y}f(x,z)g(z,y)=\sum_{x | z | y}f(z/x)g(y/z)=\sum_{d|(x/y)}f(d)g((x/y)/d)
$$
令$n=x/y$，则
$$
(f*g)(n)=\sum_{d|n}f(d)g(n/d)
$$
此时卷积即为狄利克雷卷积，$\zeta$函数即为常函数$1$，$\mu$函数即为数论中的$\mu$函数。

当$(S,<)$为$(2^X,\subset)$时，即集合为某个集合$X$的所有子集而偏序关系为包含关系时，对每个$f:2^X \times 2^X \to R$定义对应的一元函数
$$
f(S,T)=f(T-S)
$$
则有卷积
$$
(f*g)(S,T)=\sum_{S \subseteq U \subseteq T}f(S,U)g(U,T)=\sum_{S \subseteq U \subseteq T}f(U-S)g(T-U)=\sum_{U \subseteq S-T}f(U)g((T-S)-U)=\sum_{T\subseteq S}f(T)g(S-T)
$$
令$U=T-S$，则
$$
(f*g)(U)=\sum_{S \subseteq U}f(S)g(U-S)
$$
此时卷积即为子集卷积，$\zeta$即为常函数$1$，$\mu$函数为$\mu(S)=(-1)^{|S|}$。

### 二项式反演

此即$(2^X,\subset)$上的一种特殊形式。若
$$
f(S)=a_{|S|},g(S)=b_{|S|}=\sum_{T \subseteq S}f(T)\\
$$
则有
$$
b_{i}=\sum_{j=0}^i\binom ija_j,a_i=\sum_{j=0}^i\binom ij (-1)^{i-j}b_j
$$

### 斯特林反演

## 生成函数

### 形式幂级数

$$
\frac 1 {1-x}=\sum_{i=0}^{\infty}x^i=1+x+x^2+\cdots\\
\frac x{(1-x)^2}=\sum_{i=0}^{\infty}nx^n=x+2x^2+3x^3+\cdots\\
\frac {x(x+1)}{(1-x)^3}=\sum_{i=0}^{\infty}n^2x^n=x+4x^2+9x^3+\cdots\\
\exp x=\sum_{i=0}^{\infty} \frac {x^i}{i!}=1+x+\frac {x^2}{2}+\frac {x^3}{6}+\cdots\\
\log (1+x)=\sum_{i=1}^{\infty}\frac{(-1)^{i+1}}{i}x^i=x-\frac {x^2}2+\frac {x^3}3+\cdots\\
(1+x)^n=\sum_{i=0}^{n}\binom ni x^i\\
$$

### 多元幂级数

$$
\frac {1}{1-(1+x)y}=\sum_{i=0}^{\infty}(1+x)^iy^i=\sum_{i=0}^{\infty}\sum_{j=0}^{i} \binom ij x^jy^i
$$

### 常见变换

|                                             | $xf(x)$    | $(f(x)-a_0)/x$  | $f'(x)$        | $\displaystyle \int f(x)dx$ |
| ------------------------------------------- | ---------- | --------------- | -------------- | --------------------------- |
| $[x^n]$                                     | $a_{n-1}$  | $a_{n+1}$       | $(n+1)a_{n+1}$ | $a_{n-1}/n$                 |
| $\displaystyle \left[\frac{x^n}{n!}\right]$ | $na_{n-1}$ | $a_{n+1}/(n+1)$ | $a_{n+1}$      | $a_{n-1}$                   |

OGF第$i$项乘$i$：
$$
(Tf)(x)=xf'(x)=\sum_{i=0}^{\infty}ia_ix^i
$$
设$\displaystyle (T^{(n)}f)(x)=\sum_{k=0}^{n}c_{n,k}x^kf^{(k)}(x)$，则 
$$
(T^{(n+1)}f)(x)=x(T^{(n)}f)'(x)=x\left[\sum_{k=0}^nc_{n,k}(x^kf^{(k+1)}(x)+kx^{k-1}f^{(k)}(x)\right]\\
=\sum_{k=0}^nc_{n,k}(x^{k+1}f^{(k+1)}(x)+kx^{k}f^{(k)}(x))\\

=\sum_{k=0}^nc_{n,k}kx^{k}f^{(k)}(x)+\sum_{k=1}^{n+1}c_{n,k-1}x^{k}f^{(k)}(x)
$$
考虑到$c_{n,n+1}=0$，因此有/
$$
=\sum_{k=0}^{n+1}(kc_{n,k}+c_{n,{k-1}})x^{k}f^{(k)}(x)=\sum_{k=0}^{n+1}c_{n+1,k}x^{k}f^{(k)}(x)
$$
即$c_{n,k}=kc_{n-1,k}+c_{n-1,k-1}$。结合初始条件有$\displaystyle c_{n,k}={n \brace k}$。即
$$
(T^{(n)}f)(x)=\sum_{k=0}^{n}{n \brace k} x^kf^{(k)}(x)
$$
例：令$f(x)=(1-x)^{-1}$，即得
$$
f^{(k)}(x)=\sum_{i=k}^{\infty}i^{\underline k}x^{i-k}\\
(T^{(k)}f)(x)=\sum_{i=0}^{\infty}i^kx^i=\sum_{i=0}^k {k \brace i}  x^i\sum_{j=i}^{\infty}j^{\underline i}x^{j-i}=\sum_{i=0}^k {k \brace i} \sum_{j=i}^{\infty}j^{\underline i}x^{j}\\
=\sum_{j=0}^{\infty}x^j\sum_{i=0}^k{k \brace i}j^{\underline i}
=\sum_{j=0}^{\infty}x^j\sum_{i=0}^k{k \brace i} \binom jii!
$$
因此有
$$
j^k=\sum_{i=0}^k{k \brace i} \binom jii!
$$
卷上一个$(1+x)^{-1}$即得
$$
\sum_{j=0}^nj^k=\sum_{j=0}^n\sum_{i=0}^k{k \brace i} \binom jii!=\sum_{i=0}^k{k \brace i}i!\sum_{j=0}^n\binom ji=\sum_{i=0}^k{k \brace i}i!\binom{n+1}{i+1}
$$


### 一般生成函数(OGF)

$$
f(x)=\sum_{i=0}^{\infty}a_i x^i
$$

一般生成函数一般用于组合的计数（位置不可区分，或无标号）

#### OGF卷积的组合意义

考虑$f$和$g$的卷积：

$$
h(x)=f(x)g(x)=\sum_{i=0}^{\infty}\left(\sum_{j=0}^ia_jb_{i-j}\right)x^i=\sum_{i=0}^{\infty}c_i x^i
$$

可以理解为：有两类物品组合。第一类中大小为$i$的有$a_i$种，第二类中大小为$i$的有$b_i$种。则分别从第一类和第二类中分别选出两个组合将其合并，大小为$i$的有$c_i$种。

#### 欧拉变换

大小为$i$的组合有$a_i$种，现在计算总大小为$i$的由一个或多个组合组成的组合方案数量。

因为组合之间不可区分，所以可以枚举大小为$i$的组合中每一个用了多少次。即

$$
\mathscr E(f)(x)=\left(1+x+x^2+\cdots\right)^{a_1}\left(1+x^2+x^4+\cdots\right)^{a_2}\cdots=\prod_{i=1}^{\infty}\left(\frac{1}{1-x^i}\right)^{a_i}
$$

$$
= \exp\left(\sum_{i=0}^{\infty} a_i \ln \frac{1}{1-x^i}\right)=\exp\left(\sum_{i=0}^{\infty} -a_i \ln{(1-x^i)}\right)
$$

$$
= \exp\left(\sum_{i=0}^{\infty} a_i \sum_{j=1}^{\infty}\frac{x^{ij}}{j}\right)
= \exp\left(\sum_{j=1}^{\infty}\frac{1}{j}\sum_{i=0}^{\infty}a_ix^{ij}\right)=\exp\left(\sum_{j=1}^{\infty}\frac {f(x^j)}{j}\right)
$$

### 指数生成函数(EGF)

$$
f(x)=\sum_{i=0}^{\infty}a_i \frac{x^i}{i!}
$$

指数生成函数一般用于排列的计数（位置可区分，或有标号）

#### EGF卷积的组合意义

考虑$f$和$g$的卷积：

$$
h(x)=f(x)g(x)=\sum_{i=0}^{\infty}\left(\sum_{j=0}^i\frac{a_j}{j!}\frac{b_{i-j}}{(i-j)!}\right)x^i=\sum_{i=0}^{\infty}\left(\sum_{j=0}^i\binom ija_jb_{i-j}\right)\frac{x^i}{i!}=\sum_{i=0}^{\infty}c_i x^i
$$

可以理解为：有两类物品排列。第一类中大小为$i$的有$a_i$种，第二类中大小为$i$的有$b_i$种。则分别从第一类和第二类中分别选出两个排列将其合并，大小为$i$的有$c_i$种。

注：先钦定来自第一类的物品放在哪些位置，来自第二类的物品放在剩下那些位置，因此有个二项式系数。

#### $\exp f(x)$的组合意义

大小为$i$的排列有$a_i$种，现在计算大小为$i$的由数个排列组成的排列方案。

由$k$个排列组成的方案数的生成函数是
$$
\frac{f(x)^k}{k!}
$$
除以$k!$的原因是排列之间没有先后顺序。

枚举$k$可以得到
$$
g(x)=\sum_{k=1}^{\infty}\frac{f(x)^k}{k!}=\exp f(x)
$$

### 狄利克雷生成函数(DSGF)

$$
f(s)=\sum_{i=1}^{\infty}\frac{a_i}{i^{s}}
$$

例：常数序列$1$的DSGF是黎曼$\zeta$函数。

#### DSGF卷积的组合意义

$$
h(s)=f(s)g(s)=\sum_{i=1}^{\infty}\sum_{j|i}\frac{a_jb_{i/j}}{j^s(i/j)^s}=\sum_{i=1}^{\infty}\frac{1}{i^s}\sum_{j|i}a_jb_{i/j}
$$

不难发现这个就是狄利克雷卷积。

若$\lambda(i)=a_i$是积性的，则
$$
f(s)=\sum_{i=1}^{\infty}\frac{a_i}{i^s}=\prod_{p \in \mathbb P}(\lambda(1)+\lambda(p)+\lambda(p^2)+\cdots)=\prod_{p \in \mathbb P}\sum_{i=0}^{\infty}a_{p^i}
$$

### 卷积相关

|                   基本形式                   |                             变形                             |
| :------------------------------------------: | :----------------------------------------------------------: |
| $\displaystyle c_i=\sum_{j=0}^{i}a_jb_{i-j}$ | $\displaystyle c_i=\sum_{j=i}^{n}a_{j}b_{j-i} {\overset {i=n-i'}{\Longrightarrow}} c_{n-i}=\sum_{j=0}^{i}a_{n-j}b_{i-j}\\$ |

## 常见计数模型

### 球盒(十二模式)

将$n$个球放到$m$个盒子里，球可/不可区分，盒子可/不可区分，映射无限制/单射/满射。



小球不可区分，盒子可区分，映射是单射：

等价于在$m$个盒子中选择$n$个放球，答案为$\displaystyle \binom mn$

小球不可区分，盒子可区分，映射是满射：

等价于在长度为$n$的序列中的$n-1$个空隙中插入$m-1$个隔板，因此答案为$\displaystyle \binom {n-1}{m-1}$

小球不可区分，盒子可区分，映射无限制：

等价于在长度为$n+m$的序列中的$n+m-1$个空隙中插入$m-1$个隔板，因此答案为$\displaystyle \binom {n+m-1}{m-1}$

生成函数为
$$
[x^n](1+x+x^2+\cdots+x^n)^m=[x^n]\left(\frac{x^{n+1}-1}{x-1}\right)^m
$$


小球可区分，盒子可区分，映射是单射：

等价于从$m$个盒子中选择$n$个进行排列，答案为$m(m-1)\cdots(m-n+1)=m!/(m-n)!$

小球可区分，盒子可区分，映射是满射：

等价于将$n$个元素划分为$m$个非空集合后对每个集合进行标号，答案为$\displaystyle {n \brace m}m!$

小球可区分，盒子可区分，映射无限制：

每个球有$m$种策略，互相独立，因此答案为$m^n$种。

小球不可区分，盒子不可区分，映射是单射：

若$n>m$，则答案为$0$，否则答案为$1$。

小球不可区分，盒子不可区分，映射是满射：

等价于将整数$n$拆分成恰好$m$个正整数的方案数，即$p_{n,m}$。

小球不可区分，盒子不可区分，映射无限制：

等价于将整数$n$分拆成至多$m$个正整数的方案数。等价于将$n+m$拆分成恰好$m$个正整数的方案数，即$p_{n+m,m}$。

小球可区分，盒子不可区分，映射是单射：

若$n>m$，则答案为$0$，否则答案为$1$。

小球可区分，盒子不可区分，映射是满射：

等价于将$n$个元素划分为$m$个非空集合的方案数，答案为$\displaystyle {n \brace m}$。

小球可区分，盒子不可区分，映射无限制：

等价于将$n$个元素划分为至多$m$个非空集合的方案数，答案为$\displaystyle \sum_{k=1}^{m}{n \brace k}$。

### 整数分拆

定义：

拆分数$p_n$是将$n$拆分为数个无序正整数之和的方案数。

拆分数$p_{n,k}$是将$n$拆分成$k$个无序正整数之和的方案数。

命题：将$n$拆分成$k$个无序正整数之和的方案数等于将$n-k$拆分成至多$k$个正整数之和的方案数。

证明：可以构造一个双射。对于前者的每个方案，将每个数减去$1$。对于后者的每个方案，将每个数加上$1$并用$1$补齐至$k$个。

定义(Ferrers图)：对于任意一个拆分方案，设其中第$i$大的数是$x_i$，则其对应的Ferrers图的第$i$行有$x^i$个点。

如$12=5+3+3+1$，则其Ferrers图为

```
00000
000
000
0
```

命题：将$n$拆分成至多$k$个正整数之和的方案数等于将$n$拆分成数个不超过$k$的正整数之和的方案数。

证明：前者的每个方案的Ferrers图至多有$k$行，后者的每个方案的Ferrers图有至多$k$列。这构成了一个双射，映射即为Ferrers图的转置。

考虑其生成函数，枚举$i$被用了$j$次：
$$
F(x)=\sum_{i=1}^{\infty}p_ix^i=\prod_{i=1}^{\infty}\sum_{j=0}^{\infty}x^{ij}=\prod_{i=1}^{\infty}\frac 1{1-x^i}\\
F_k(x)=\sum_{i=1}^{\infty}p_{i+k,k}x^i=\prod_{i=1}^k\sum_{j=0}^{\infty}x^{ij}=\prod_{i=1}^k\frac 1{1-x^i}
$$
命题：将$n$拆分成数个奇数之和的方案数等于将$n$拆分成数个互不相同的数之和的方案数。

证明1：构造一个双射。

对于前者的每个方案，若方案中某个奇数$w$出现了$x$次，考虑$x$的二进制展开$x=b_02^0+b_12^1+\cdots$，若$b_i$为$1$则往方案中加一个$2^iw$。这是一个单射。

对于后者的每个方案，若方案中存在某个偶数$2^kw$，则将其拆成$2^k$个$w$。这也是一个单射。证毕。

证明2：考虑生成函数。

前者的生成函数:
$$
F(x)=\prod_{i=1}^{\infty}\frac 1{1-x^{2i-1}}\\
$$
后者的生成函数：
$$
G(x)=\prod_{i=1}^{\infty}(1+x^i)=\prod_{i=1}^{\infty}\frac{1-x^{2i}}{1-x^{i}}=\prod_{i=1}^{\infty}(1-x^{2i})\bigg/\prod_{i=1}^{\infty}(1-x^i)=\prod_{i=1}^{\infty}\frac 1{1-x^{2i-1}}=F(x)
$$
命题：将$n$拆分成数个模$3$不为$0$的正整数的方案数等于将$n$拆分成每种数出现至多两次的方案数。

证明：考虑生成函数。

前者的生成函数：
$$
F(x)=\prod_{i=1}^{\infty}\frac 1{1-x^{3i-1}}\frac 1{1-x^{3i-2}}
$$
后者的生成函数：
$$
G(x)=\prod_{i=1}^{\infty}(1+x^i+x^{2i})=\prod_{i=1}^{\infty}\frac{1-x^{3i}}{1-x^i}=F(x)
$$

### 格路径

考虑一个有$n$行$m$列的网格。从左下角$(0,0)$开始，每次只能往右/上方走。

#### 无限制

从$(0,0)$走到$(n,m)$共有$\displaystyle \binom {n+m}n$种走法。

证明：一共只走$n+m$步，其中恰好$n$步向右走，恰好$m$步向上走。

因此每种走法唯一对应一个有$n$个0和$m$个1的01序列，其中0代表向上走，1代表向右走。

这样的方案数为$\displaystyle \binom {n+m}n$。

#### 有一个限制

从$(0,0)$走到$(n,m)$且不经过直线$l:y=x+k$上的任何一个点的方案数为$\displaystyle \binom{n+m}{n}-\binom{n+m}{n+k}$，其中$m<n+k$且$k>0$，或$m>n+k$且$k<0$。

证明：对于任意一个不合法方案，设其第一次经过$l_1$的位置为点$p$，将该方案对应的折线$p$以后的部分沿$l_1$翻转，可以得到一个从$(0,0)$走到$(m-k,n+k)$的方案。不难证明这是一个双射。

#### 有两个限制

计算从$(0,0)$走到$(n,m)$且不经过直线$l_1:y=x+k_1$和$l_2:y=x+k_2$上的任何一个点的方案数，其中$n+k_1<m<n+k_2$且$k_1<0<k_2$。

考虑容斥。

对于每个方案，按其经过$l_1$和$l_2$的顺序可以对应一个交错$12$串。即每连续数次经过$l_1$则加上一个$1$，每连续数次经过$l_2$则加上一个$2$。

如先经过两次$l_1$，再经过三次$l_2$，再经过一次$l_1$的方案对应的串为$121$。

考虑推广前面仅有一个限制时的做法。

将$(n,m)$翻转到其沿$l_1$的对称点，对应的是在终点前连续数次经过$l_1$的方案，即以$1$或$12$结尾的所有方案。

在这个基础上再沿$l_2$翻转一次，对应的是在终点前连续数次经过$l_2$再连续数次经过$l_1$的方案，对应的是以$21$和以$212$结尾的所有方案。

将$(n,m)$翻转到其沿$l_2$的对称点，对应的是在终点前经过了一次$l_2$的方案，即以$2$或$21$结尾的所有方案。

在这个基础上再沿$l_1$翻转一次，对应的是在终点前连续数次经过$l_1$再连续数次经过$l_2$的方案，对应的是以$12$和以$121$结尾的所有方案。

依此类推，翻转奇数次的所有方案减去翻转偶数次的所有方案即是以$1$结尾或以$2$结尾的所有方案之和，即不合法方案数。

```cpp
int cal(int n, int m, int k1, int k2) {
    if (m <= n + k1 || m >= n + k2 || k1 >= 0 || k2 <= 0) return 0;
    int res = bi(n + m, n), d[2] = { k1, -k2 };
    for (int x = n + d[0], t = 0; x >= 0 && x <= n + m; x += d[t ^= 1])
        res = (t ? add : sub)(res, bi(n + m, x));
    for (int x = m + d[1], t = 1; x >= 0 && x <= n + m; x += d[t ^= 1])
        res = (t ? sub : add)(res, bi(n + m, x));
    return res;
}
```

