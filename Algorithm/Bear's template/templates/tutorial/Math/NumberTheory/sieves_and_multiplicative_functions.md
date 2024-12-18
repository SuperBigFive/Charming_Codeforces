## 积性函数

定义（数论函数）：定义域在正整数上，且值域中元素能互相做加法和乘法（即在某个交换环中）的函数称为数论函数。

定义（积性函数）：给定数论函数$f$，若对任意互质的$a,b$有$f(ab)=f(a)f(b)$，则称$f$为积性函数。

命题：$f(1)=1$。证明显然。

命题：给定任意一个积性函数在所有质数的幂次$p^e$上的取值，则可以唯一确定这个积性函数。

证明：对于任意正整数$n$，考虑$n$的质因子分解$\displaystyle n=\prod p_i^{q_i}$，则$\displaystyle f(n)=\prod f(p_i^{q_i})$。

涉及到积性函数的计算中经常出现对某个函数$f$在某个数$n$的所有因子位置上的值求和，这个符号记为$\displaystyle \sum_{d|n}f(d)$。

即对所有能够整除$n$的数$d$统计$f(d)$的和。

### 除数函数

定义（除数函数）：$\sigma_0(n)$为$n$的因子数量。

一般地，$\sigma_k(n)$被定义为
$$
\sigma_k(n)=\sum_{d|n}d^k
$$
命题：设$n$的质因子分解为$\displaystyle n=\prod p_i^{q_i}$，则$\displaystyle \sigma_0(n)=\prod(q_i+1)$。

证明：对于$n$的任意因子$x$，$x$的每个质因子的在$x$中幂次必然小于等于其在$n$中的幂次。因此对于在$n$中幂次为$q_i$的质因子，其在$n$的因子中有$q_i+1$种可能，且与其他质因子互相独立。

命题：除数函数是积性函数。

证明：由上式显然。

命题：
$$
\sum_{i=1}^n\sigma_k(n)=\sum_{i=1}^n\sum_{j|i}j^k=\sum_{j=1}^nj^k\sum_{j|i}^n1=\sum_{j=1}^nj^k\lfloor n/j \rfloor
$$
命题：$\sigma_0(n)$的前缀和是$O(n \log n)$级别的。

证明：
$$
\sum_{i=1}^n\sigma_0(n)=\sum_{i=1}^n\sum_{j | i}1=\sum_{j=1}^n\sum_{j | i}1=\sum_{j=1}^n\left\lfloor\frac nj \right\rfloor \leq n\sum_{j=1}^n\frac1j =O(n\log n)
$$



命题：
$$
\sigma_0(n_1n_2)=\sum_{d_1|n_1}\sum_{d_2|n_2}[\gcd(d_1,d_2)=1]
$$
可以这样构造一个双射：

当$\gcd(d_1, d_2)=1$时，考察$d_1d_2$的每个质因子$p$的幂次，设该质因子在$n_1$中幂次为$e_1$，在$n_2$中幂次为$e_2$。

若该幂次来自于$n_2$则将其加上$e_1$，否则不进行操作。这是一个单射。

对于每个$n_1n_2$的因子，考察其每个质因子$p$的幂次$e$。初始状态$d_1=d_2=1$。若该幂次大于$e_1$则将$d_2$乘上$p^{e-e_1}$。否则将$d_1$乘上$p^{e}$。这也是一个单射。

例(SDOI2015 约数个数和)：求
$$
\sum_{i=1}^n\sum_{j=1}^m\sigma_0(ij)
$$
解：
$$
\sum_{i=1}^n\sum_{j=1}^m\sigma_0(ij)=\sum_{i=1}^n\sum_{j=1}^m\sum_{d_1|i}\sum_{d_2|j}[\gcd(d_1,d_2)=1]\\
\sum_{i=1}^n\sum_{j=1}^m\sum_{d_1|i}\sum_{d_2|j}\sum_{e|d_1,e|d_2}\mu(e)=\sum_{e=1}^{\min(n,m)}\mu(e)\sum_{e|d_1}\sum_{e|d_2}\sum_{d_1|i}\sum_{d_2|j}1\\
=\sum_{e=1}^{\min(n,m)}\mu(e)\sum_{e|d_1}\left\lfloor \frac N {d_1}\right\rfloor\sum_{e|d_2}\left\lfloor \frac N {d_2}\right\rfloor
=\sum_{e=1}^{\min(n,m)}\mu(e)\sum_{i=1}^{\lfloor N/e \rfloor }\left\lfloor \frac N {ei}\right\rfloor\sum_{i=1}^{\lfloor M/e \rfloor }\left\lfloor \frac M {ei}\right\rfloor
$$
右边两坨预处理后左边整除分块即可。

```cpp
ll sum = 0;
for (int l = 1, r; l <= min(n, m); l = r + 1) {
    r = min(n / (n / l), m / (m / l));
    sum += 1ll * (smu[r] - smu[l - 1]) * f[n / l] * f[m / l];
}
```

### 欧拉函数

定义（欧拉函数）：$\varphi(n)$为$1$到$n-1$中与$n$互质的数的数量。

命题：设$n$的质因子分解为$\displaystyle n=\prod p_i^{q_i}$，则$\displaystyle \varphi(n)=n\prod(1-\frac{1}{p_i})$。

证明：考虑容斥。设$n$的质因子分别是$p_1,p_2,\cdots,p_k$，则$1$到$n$能被$p_i$整除的数的数量是$n/p_i$，能被$p_ip_j$整除的数量是$n/p_ip_j$，等等。由此可以写出
$$
\varphi(n)=n-\sum_{1 \leq i \leq k}\frac n{p_i}+\sum_{1 \leq i < j \leq k}\frac n{p_ip_j}- \cdots=n\left(1-\frac{1}{p_1}\right)\left(1-\frac{1}{p_2}\right)\cdots\left(1-\frac{1}{p_k}\right)
$$
注：将右边展开，每带上一个质因子都会乘上一个$-1$，因此每一项的符号为$(-1)^{质因子数量}$

命题：欧拉函数是积性函数。

证明：由上式显然。

命题：$\displaystyle \sum_{d|n}\varphi(d)=n$

证明：
$$
\sum_{d|n}\varphi(d)=\sum_{d|n}\varphi\left(\frac nd\right)=\sum_{d|n}\sum_{i=1}^{\frac nd}[\gcd\left(i,\frac nd\right)=1]\\
=\sum_{d|n}\sum_{k=1}^n[\gcd(k,n)=d]=n
$$
注：$\varphi(n/d)$等于$1,2,\cdots,n$内和$n$的$\gcd$为$d$的数的数量。

命题：$n$以内的欧拉函数值可在$O(n \log n)$的时间复杂度内计算出来。

由上一个命题可得$\varphi(n)=n-\sum_{d|n,d \neq n}\varphi(d)$。

```cpp
int phi[N];
void get_phi(int n) {
    for (int i = 1; i <= n; ++i) {
        phi[i] = i;
        for (int j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
    }
}
```

### 默比乌斯函数

定义（默比乌斯函数）：
$$
\mu(n)=\begin{cases}(-1)^{k} & n=p_1p_2\cdots p_k\\1&n=1\\0&else\end{cases}
$$

命题：若$n$有平方因子，则$\mu(n)=0$。由定义显然。

命题：默比乌斯函数是积性函数。

证明：若$a,b$中任意一个有平方因子，则$ab$也有平方因子，因此$\mu(ab)=\mu(a)\mu(b)=0$。

若$a,b$均没有平方因子且互质，则$ab$也能写成一串不同质数的乘积，因此$\mu(n)=(-1)^{k_a+k_b}=(-1)^{k_a}(-1)^{k_b}=\mu(a)\mu(b)$。得证。

命题：$\displaystyle \sum_{d|n}\mu(n)=[n=1]$。

证明：$n=1$时显然成立。

当$n \neq 1$时，设$n$的不同质因子集合为$S=\{p_1,p_2,\cdots,p_k\}$，因为$\mu$在含有平方因子的数处的取值为$0$，因此只需考虑$n$的没有平方因子的因子。
$$
\sum_{d|n}\mu(n)=\sum_{T \subseteq S}\mu(\prod_{p_i \in T}p_i)=\sum_{T\subseteq S}\prod_{p_i \in T}\mu(p_i)=\sum_{T \subseteq S}(-1)^{|T|}=\sum_{i=0}^k\sum_{|S|=i}(-1)^i=\sum_{i=0}^k\binom ki(-1)^i
$$
易得当$k=0$时为$1$，否则由二项式定理得该式为$0$。

命题：$n$以内的默比乌斯函数值可在$O(n \log n)$的时间复杂度内计算出来。

由上个命题可得
$$
\mu(n)=[n=1]-\sum_{d|n,d \neq n}\mu(d)
$$

```cpp
int mu[N];
void get_mu(int n) {
    mu[1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 2 * i; j <= n; j += i)
            mu[j] -= mu[i];
}
```

### 狄利克雷卷积

定义（狄利克雷卷积）：设$f,g$为数论函数，则$f,g$的狄利克雷卷积$h = f * g$被定义为
$$
h(n)=\sum_{d|n}f(d)g\left( \frac n d \right)
$$
命题：若$f,g$都是积性函数，则$f,g$的狄利克雷卷积也是积性函数。

证明：
$$
h(n_1n_2)=\sum_{d|n_1n_2}f(d)g\left(\frac nd\right)=\sum_{d_1|n_1}\sum_{d_2|n_2}f(d_1d_2)g\left(\frac{n_1n_2}{d_1d_2}\right)\\
=\sum_{d_1|n_1}\sum_{d_2|n_2}f(d_1)f(d_2)g\left(\frac{n_1}{d_1}\right)g\left(\frac{n_2}{d_2}\right)=\sum_{d_1|n_1}f(d_1)g\left(\frac{n_1}{d_1}\right)\sum_{d_2|n_2}f(d_2)g\left(\frac{n_2}{d_2}\right)
=h(n_1)h(n_2)
$$
命题：狄利克雷卷积满足交换律。

证明：
$$
(f*g)(n)=\sum_{d|n}f(d)g\left( \frac n d \right)=\sum_{d|n}f\left( \frac n d \right)g(d)=(g*f)(n)
$$


命题：狄利克雷卷积满足结合律，即$(f*g)*h=f*(g*h)$。

证明：
$$
((f*g)*h)(n)=\sum_{d_1|n}\left(\sum_{e_1|d_1}f(e_1)g\left(\frac {d_1}{e_1}\right)\right)h\left(\frac n{d_1}\right)
$$
设$d_2=\frac{n}{e_1},e_2=\frac{n}{d_1}$，则有
$$
=\sum_{d_2|n}f\left(\frac{n}{d_2}\right)\left(\sum_{e_2|d_2}g\left(\frac{d_2}{e_2}\right)h(e_2)\right)=(f*(g*h))(n)
$$
命题：设$f_1,f_2,\cdots,f_k$为数论函数，则
$$
(f_1*f_2*\cdots*f_k)(n)=\sum_{d_1d_2\cdots d_k|n}f_1(d_1)f_2(d_2)\cdots f_k(d_k)
$$
证明：由定义一层层展开即可。

定义（单位函数）：$e(n)=[n=1]$。

命题：对于任意数论函数$f$有$f * e=1$。

定义（常数函数）：$1(n)=1$

定义（恒等函数）：$id (n)=n$，类似的有$id^k(n)=n^k$。

命题：$\mu * 1=e$。由定义显然。

这个命题能用来展开形如$[\gcd(x,y,z,\cdots)=1]$的部分。

例1：求$m$以内与$n$互质的数的数量。
$$
f(m,n)=\sum_{i=1}^{m}[\gcd(i,n)=1]=\sum_{i=1}^me(\gcd(i,n))=\sum_{i=1}^m\sum_{e|\gcd(i,n)}\mu(e)\\=\sum_{i=1}^m\sum_{e|i \wedge e|n}\mu(e)=\sum_{e|n}\mu(e)\sum_{e|i\wedge i \leq m}1=\sum_{e|n}\mu(e)\left\lfloor\frac me \right\rfloor
$$
例2：求$m$以内与$n$的$\gcd$为$d$的数的个数
$$
g(m,n,d)=\sum_{i=1}^m[\gcd(i,n)=d]=\sum_{d|i \wedge i \leq m}[\gcd(i,n)=d]=\sum_{j=1}^{\lfloor m/d\rfloor}[\gcd(j,n/d)=1]=f(m/d,n/d);
$$
命题：$\varphi *1=id$。因为$\displaystyle (\varphi * 1)(n)=\sum_{d|n}\varphi(d)=n$。

命题：$\displaystyle \sum_{d|n}\mu(d)/d=\varphi(n)/n$

证明：
$$
\varphi(n)=(\varphi*1*\mu)(n)=(id*\mu)(n)=\sum_{d|n}\mu(d)\frac{n}{d}\\
$$
两边同除$n$即可。

命题：$\mu *id=\varphi$

证明：$\mu*id=\mu*(1 *\varphi)=(\mu*1)*\varphi=e*\varphi=\varphi$

定理（默比乌斯反演）：对于积性函数$f$，设$g=f*1$，则$f=g*\mu$。

将每项写出来即是
$$
g(n)=\sum_{d|n}f(d) \Leftrightarrow f(n)=\sum_{d|n}\mu(n/d)g(d)
$$
证明：$g*\mu=(f*1)*\mu=f*(1*\mu)=f$。

同时也有
$$
g(d)=\sum_{d|n}f(n) \Leftrightarrow f(d)=\sum_{d|n}\mu(n/d)g(n)
$$
证明：
$$
\sum_{d|n}\mu(n/d)g(n)=\sum_{d|n}\mu(n/d)\sum_{n|m}f(m)=\sum_{d|m}f(m)\sum_{d|n|m}\mu(n/d)\\=\sum_{d|m}f(m)\sum_{T|\frac md}\mu(t)=\sum_{d|m}f(m)[m/d=1]=f(d)
$$
例(CF1139D)：有一个空数列$\{ a \}$，每一轮向$\{ a \}$中加入一个范围在$[1,m]$内的随机整数，当$\{ a \}$中所有数的$\gcd$为$1$时停止，问停止时$\{ a \}$的长度$X$的期望值。
$$
E[X]=\sum_{i=1}^{\infty}i\Pr[X=i]=\sum_{i=1}^{\infty}\Pr[X\geq i]\\
$$
当$i=1$时$\Pr[x\geq 1]=1$，否则$\Pr[X \geq i+1]=\Pr[X>i]$，即长度为$i$的值域在$[1,m]$内的随机数列的$\gcd$不为$1$的概率。

设$f(d)$为长度为$i$的满足$d=\gcd \{a\}$的数列$\{a\}$数量，$g(d)$为长度为$i$的满足$d|\gcd\{a\}$的数列$\{a\}$数量，则有
$$
g(d)=\lfloor m/d \rfloor^i =\sum_{d|n}f(n)\Rightarrow f(d)=\sum_{d|n}\mu(n/d)g(n)=\sum_{d|n}\mu(n/d)\lfloor m/n\rfloor^i
$$
于是
$$
\Pr[X>i]=\frac {1}{m^i} \left(m^i-f(1)\right)=\frac {1}{m^i} \left(m^i-\sum_{n \geq 1}\mu(n)\lfloor m/n \rfloor ^i\right)\\=\frac {1}{m^i} \left(m^i-m^i-\sum_{n \geq 2}\mu(n)\lfloor m/n \rfloor ^i\right)=-\frac {1}{m^i}\sum_{n=2}^m\mu(n)\lfloor m/n \rfloor ^i
$$
因此
$$
\sum_{i=1}^{\infty}\Pr[X\geq i]=1+\sum_{i=1}^{\infty}\Pr[X>i]=1+\sum_{i=1}^{\infty}\left(-\frac {1}{m^i}\sum_{n=2}^m\mu(n)\lfloor m/n \rfloor ^i\right)\\=1-\sum_{n=2}^m\mu(n)\sum_{i=1}^{\infty}(\lfloor m/n \rfloor/m)^i=1-\sum_{n=2}^m\mu(n)\frac{\lfloor m/n \rfloor/m}{1-\lfloor m/n \rfloor/m}=1+\sum_{n=2}^m\mu(n)\frac{\lfloor m/n \rfloor}{\lfloor m/n \rfloor-m}
$$

#### 导数

对于算数函数$f(n)$，可定义其导数为$f'(n)=f(n)\log (n)$。其中$\log(n)$满足$\log(ab)=\log(a)+\log(b)$。

则有

命题：$(f+g)'(n)=f'(n)+g'(n)$

证明：$(f+g)'(n)=f(n)\log (n)+g(n)\log (n)=f'(n)+g'(n)$

命题：$(f*g)'(n)=(f'*g)(n)+(f*g')(n)$

证明：
$$
(f*g)'(n)=\log(n)\sum_{d|n}f(d)g(n/d)=\sum_{d|n}\left[f(d)\log(d)g(n/d)+f(d)g(n/d)\log(n/d)\right]\\=(f'*g)(n)+(f*g')(n)
$$
命题：$(f^{-1})'=-f'*(f^{-1})^2$

证明：展开$e'$后移项即可。
$$
0=e'=(f*f^{-1})'=f'*f^{-1}+f*(f^{-1})'
$$

注：可以定义$\log n$为$n$的质因子个数。

### 圆上整点

定义：$\chi(n)$为完全积性函数， 满足
$$
\chi(p)=\begin{cases}
1 & p \bmod 4=1\\
-1 & p \bmod 4=3\\
0 & \text{other}
\end{cases}
$$
则不定方程$x^2+y^2=n$的解数为
$$
4\sum_{d|n}\chi(d)
$$
证明：考虑$n$在高斯整环$\Z[i]$上的分解。。。

### 球上整点

见区间筛部分。

### 一些技巧

拆$\gcd$：
$$
[\gcd(i,j)=1]=\sum_{e|\gcd(i,j)}\mu(e)=\sum_{e|i,e|j}\mu(e)\\
\gcd(i,j)=\sum_{e|\gcd(i,j)}\varphi(e)=\sum_{e|i,e|j}\varphi(e)
$$

HDU5728:求$\varphi(in)$的前缀和，其中$\mu(n) \neq 0$。
$$
S(n,m)=\sum_{i=1}^m\varphi(in)=\sum_{i=1}^m\varphi(i)\varphi(n)\frac{\gcd(n,i)}{\varphi(\gcd(n,i))}\\
=\varphi(n)\sum_{d|n}\frac{d}{\varphi(d)}\sum_{i=1}^m\varphi(i)[\gcd(i,n)=d]
=\varphi(n)\sum_{d|n}\frac{d}{\varphi(d)}\sum_{i=1}^{\lfloor m/d \rfloor}\varphi(id)[\gcd(i,n/d)=1]\\
=\varphi(n)\sum_{d|n}\frac{d}{\varphi(d)}\sum_{i=1}^{\lfloor m/d \rfloor}\varphi(id)\sum_{e|i \wedge e | n/d}\mu(e)=\varphi(n)\sum_{d|n}\frac {d}{\varphi(d)}\sum_{de|n}\mu(e)\sum_{i=1}^{\lfloor m/de\rfloor}\varphi(ide)\\
=\varphi(n)\sum_{t|n}S(t,\lfloor m/t \rfloor)\sum_{d|t}\frac{d}{\varphi(d)}\mu(T/d)
$$
注意到右边那坨是积性函数，设其为$f(T)$且$f(p)=\frac{p}{p-1}\mu(1)+\mu(p)=1/\varphi(p)$，所以
$$
S(n,m)=\varphi(n)\sum_{d|n}S(d,\lfloor m/d\rfloor)/\varphi(d)
$$
边界为$S(n,0)=0$与$S(1,m)=\sum\varphi(i)$，用线筛预处理$\varphi$后复杂度$3^{\lambda(n)}$。

## 筛法

### 区间筛

有些问题只需要一段较短区间内的质数/积性函数相关信息，而区间端点却很大。如求$[L,R]$内的质数个数/积性函数值，且$R-L \leq 10^6$。

因为区间$[L,R]$中的所有合数都有至少一个$\sqrt R$的质因子，因此使用小于等于$\sqrt R$的所有质数即可筛出区间内的所有质数和区间内所有合数的积性函数值的一部分（剩下那部分是个大于$\sqrt R$的质数）。

因为区间$[L,R]$中的所有数都至多只有一个大于$\sqrt R$的质因子，因此使用小于等于$\sqrt R$的质数筛出区间内合数的积性函数值的质因子小于等于$\sqrt R$的那部分后，剩下的将会是一个大于$\sqrt R$的质数。

如用${2,3,5,7}$筛区间$[100,105]$内的欧拉函数值：

|      | $100=2^25^2$    | $101=101$      | $102=2^13^117^1$   | $103=103$      | $104=2^313^1$  | $105=3^15^17^1$      |
| ---- | --------------- | -------------- | ------------------ | -------------- | -------------- | -------------------- |
| $2$  | $2\varphi(5^2)$ | $\varphi(101)$ | $\varphi(3^117^1)$ | $\varphi(103)$ | $4\varphi(13)$ | $\varphi(3^15^17^1)$ |
| $3$  | $2\varphi(5^2)$ | $\varphi(101)$ | $2\varphi(17)$     | $\varphi(103)$ | $4\varphi(13)$ | $2\varphi(5^17^1)$   |
| $5$  | $40$            | $\varphi(101)$ | $2\varphi(17)$     | $\varphi(103)$ | $4\varphi(13)$ | $8\varphi(7)$        |
| $7$  | $40$            | $\varphi(101)$ | $2\varphi(17)$     | $\varphi(103)$ | $4\varphi(13)$ | $48$                 |
| $p$  | $40$            | $100$          | $32$               | $102$          | $48$           | $48$                 |

例(2019南京现场赛E)：求半径在$[L,R]$内的球面上的整点个数。其中$1 \leq L \leq R \leq 10^{13},R-L+1 \leq 10^6$。

打表发现答案是一个积性函数的六倍，且满足
$$
f(p^e)=\begin{cases}
1 & p=2\\
p^e & p\bmod 4 =1\\
pf(p^{e-1}) +2 & p \bmod 4=3\\
\end{cases}
$$

```cpp
vector<ll> solve(ll l, ll r) {
    vector<ll> res(r - l + 1, 1), rem(r - l + 1);
    for (ll i = l; i <= r; ++i) rem[i - l] = i;
    ll s = sqrt(r);
    for (int p : ps) {
        if (p > s) break;
        ll f[50], q[50];
        f[0] = q[0] = 1;
        ll x = r; int c = 1;
        while (x / p >= p) x /= p, c++;
        for (int i = 1; i <= c; ++i) {
            //	Calculate f(p^i)
            if (p % 4 == 1) f[i] = p * f[i - 1];
            else if (p % 4 == 3) f[i] = p * f[i - 1] + 2;
            else f[i] = 1;                
            q[i] = q[i - 1] * p;
            ll lb = (l - 1) / q[i] + 1, rb = r / q[i];
            for (ll j = lb; j <= rb; j ++)
                if (j % p != 0)
                    res[j * q[i] - l] *= f[i],
                    rem[j * q[i] - l] /= q[i];
        }
    }
    for (ll i = l; i <= r; ++i) {
        if (rem[i - l] != 1) {
            ll p = rem[i - l];
            ll f;	//	Calculate f(p)
            if (p % 4 == 3) f = p + 2;
            else if (p % 4 == 1) f = p;
            else f = 1;
            res[i - l] *= f;
        }
        if (i != 0) res[i - l] *= 6;
    }
    return res;
}
```

复杂度大概是$O((R-L)\log R)$。

### 欧拉筛

前面提到的埃式筛的时间复杂度是$O(n \log \log n)$，没能做到线性复杂度的原因是有一些合数可能被筛去多次（如$36$被$2$和$3$分别筛了一次）。

欧拉筛做到了线性的时间复杂度，即$O(n)$内找到$n$以内的所有质数。

对于每个最小质因子为$p$的合数$i$，欧拉筛遍历小于等于$p$的所有质数$q$并将$qi$筛去。

因为对于最小质因子为$q$的合数$j$，$j/q$的最小质因子大于等于$q$，所以其必定会被$j/q$筛去。注意到这个分解有唯一性，所以其只会被$j/q$筛去。即对于最小质因子为$q$的合数$j$，其只会在外层循环枚举到$i=j/q$，内层循环枚举到$q$时被筛去。因此欧拉筛时间复杂度是线性的。

欧拉筛的性质很适合用来预处理一些积性函数的值。

考虑对于积性函数$f$，当筛去合数$qi$时如何计算$f(qi)$ 。

若$q \nmid i$，则$f(qi)=f(q)f(i)$。否则设$q$在$qi$中的幂次为$e$，则$f(qi)=f(q^e)f(qi/q^e)$。

因此需要快速获得积性函数在质数幂次处的取值，还需要预处理对于合数$i$，其最小质因子$p$在其中的幂次$e$和$p^e$。

```cpp
bool is_prime[N];
vector<int> primes;
int pe[N], pp[N];
int f[N];
int get_f(int p, int e, int q);	//	returns f[q]; q=pow(p,e);
void euler_sieve(int n) {
    fill_n(is_prime + 1, n, true);
   	is_prime[1] = 0;
    pe[1] = 0; pp[1] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            pe[i] = 1;
            pp[i] = i;
            f[i] = get_f(i, 1, i);
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = 0;
            if (i % p != 0) {
            	pe[i * p] = 1;
                pp[i * p] = p;
                f[i * p] = f[i] * f[p];
            }
            else {
                pe[i * p] = pe[i] + 1;
                pp[i * p] = pp[i] * p;
                f[i * p] = get_f(p, pe[i * p], pp[i * p]) * f[i / pp[i]];
                break;
            }
        }
    }
}

```

$e$和$p^e$在代码中分别为`pe`和`pp`。

对于常见的积性函数，`get_f`的取值如下

$d(n):$`get_f(p,e,q)=(e+1)`

$\mu(n):$`get_f(p,e,q)=(e==1?-1:e==0)`

$\varphi(n):$`get_f(p,e,q)=(e==0?1:(q/p)*(p-1))`

上面的代码对于$\mu,\varphi$等简单的积性函数还能进一步简化。

### 杜教筛

有一些问题涉及到求解积性函数的前缀和，且线性的时间复杂度无法满足要求。

给定积性函数$f$，若存在积性函数$g,h$满足$f*g=h$且$g$和$h$的前缀和能够很快求出，则可用下面的式子
$$
S_h(n)=\sum_{i=1}^nh(i)
=\sum_{i=1}^n\sum_{d|i}g(d)f\left(\frac id\right)
=\sum_{d=1}^ng(d)\sum_{d|i,i \leq n}f\left(\frac id \right)\\
=\sum_{d=1}^ng(d)\sum_{j=1}^{\left \lfloor \frac nd \right \rfloor}f(j)
=\sum_{d=1}^ng(d)S_f\left(\left \lfloor \frac nd \right \rfloor\right)
=g(1)S_f(n)+\sum_{d=2}^ng(d)S_f\left(\left \lfloor \frac nd \right \rfloor\right)\\
S_f(n)=\left(S_h(n)-\sum_{d=2}^ng(d)S_f\left(\left \lfloor \frac nd \right \rfloor\right)\right)/g(1)=S_h(n)-\sum_{d=2}^ng(d)S_f\left(\left \lfloor \frac nd \right \rfloor\right)
$$
递归求出$S_f(n)$的值。

注：积性函数在$1$处的取值必为$1$。

观察到仅需要形如$\lfloor n / x\rfloor$的数的位置上的取值并记忆化，则计算$f(n)$时需要进行$2\sqrt n$次求和，因此最终的复杂度是
$$
T(n)=\sum_{i=1}^\sqrt n{\sqrt i}+\sum_{i=1}^{\sqrt n}\sqrt {n/i}\leq \int_0^\sqrt n\left(\sqrt n+\sqrt {n/i}+C\right)=O(n^{3/4})
$$
其中$C$为某个小常数。

若利用欧拉筛提前筛出前$n^{2/3}$的值，则最终的时间复杂度为
$$
T(n)=O(n^{2/3})+\sum_{i=1}^{\sqrt[3]{n}}\sqrt{n/i}=O(n^{2/3})
$$

记忆化可以不用`unordered_map`，因为只需要存储$S_f$在$\lfloor n/x \rfloor$位置的取值，所以对于$x \geq \sqrt n$可以将$S_f(x)$放在记忆化数组的下标$\lfloor n/x\rfloor$处。

```cpp
namespace sieve {

const int N = 1000001;
int sf[N];				//	f的前缀和，用欧拉筛取得
int sg(int n);			//	计算g的前缀和
int sh(int n);			//	计算h的前缀和
void eulerian_sieve();	//	...
    
int m[N]; ll n;

int cal(ll x) {
    if (x < N) return sf[x];
    int& sum = m[n / x];
    if (sum != -1) return sum;
    sum = sh(x);
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        sum = sub(sum, mul(sub(sg(r % P), sg((l - 1) % P)), cal(x / l)));
    }
    return sum;
}

//	init之后可O(1)获得所有n/x位置的取值
void init(ll n_) {
    n = n_;
    fill_n(m, (int)sqrt(n) + 2, -1);
    cal(n);
}
    
}
```

例：设$f(n)=\varphi(n)n^2$，求$f(n)$的前缀和。$n \leq 10^9$。

解：设$g=id^2$，则
$$
(f*g)(n)=\sum_{d|n}d^2\varphi\left(\frac nd \right)\frac{n^2}{d^2}=n^2\sum_{d|n}\varphi\left(\frac nd \right)=n^3=h(n)
$$

### min25筛

给定积性函数$f$，若$f$在质数位置上的取值是一个多项式且对于任意质数$p$，$f(p^e)$可以快速求，则可在$O(n^{3/4}/\log n)$的时间复杂度内求出$\displaystyle \sum_{i =1}^nf(i)$。

算法共分两步。

第一步**筛**出$f$在$n$以内质数位置上的取值之和。

第二步将合数位置上的取值加回去。

#### 第一步：求$g(n,j)$

定义：设$p_i$为第$i$个质数，$g(n,j)$是使用埃氏筛筛掉$n$以内所有最小质因子小于等于$j$的合数后剩下的数的个数。（$1$最开始就被筛掉了）

根据定义，$g(n,j)$可分为两部分。一部分是小于等于$p_j$的质数，另一部分是最小质因子大于$p_j$的数。

考虑埃氏筛筛掉$p_j$的所有倍数时哪些数被筛掉了（即$g(n,j-1)$与$g(n,j)$之差），这些数都形如$xp_j$，其中$x$的最小质因子大于等于$p_j$。

因此被筛掉的数的数量等于$\lfloor n / p_j \rfloor$以内最小质因子大于等于$p_j$的数的数量。这个数量等于
$$
g(\lfloor n/p_j\rfloor,j-1)-g(p_j-1,j - 1)
$$
注：$x$也可以是$p_j$。

由此可写出递推式：
$$
g(n,j)=g(n,j-1)-\left[g(\lfloor n/p_j \rfloor, j -1)-g(p_j-1,j-1)\right]
$$
边界是$g(n,0)=n-1$。

每轮筛$p_j$的倍数时需要对$n$从大到小更新$g(n,j)$。

因为$n$以内的每个合数的最小质因子都小于等于$\sqrt n$，所以用$p_j$去筛小于等于$p_j^2$的$g(n,j)$不会发生任何事。

使用滚动数组实现时，每轮对$n$从大到小更新$g$的值，当$n<p_j^2$时停止。

观察到仅需要$g$在形如$\lfloor n / x\rfloor$的数的位置上的取值，这样的数仅有$O(\sqrt n)$个，因此空间复杂度为$O(\sqrt n)$，可以证明时间复杂度为$O(n^{3/4}/ \log n)$。

注：因为只用枚举$\sqrt n$以内的质数，所以需要用到的形如$p_j-1$的数也是形如$\lfloor n / x\rfloor$的数。

上面的过程仅筛出了$n$以内的质数个数，可以将其扩展筛出$n$以内质数的$k$次幂之和（质数个数可看做零次幂之和）。递推式为
$$
g_k(n,j)=g_k(n,j-1)-p_j^k\left[g_k(\lfloor n/p_j \rfloor, j -1)-g_k(p_j-1,j-1)\right]
$$
求出所有$g_k$后，$f$在质数位置上的取值之和即可用一堆$g_k(n,\pi(\sqrt n))$乘上系数拼出来。

```cpp
ll n, s, w[N]; int c;
ll g[K][N];
int id(ll x) { return !x ? 0 : x > s ? n / x : c - x + 1; }

void cal_g(ll n0) {
    n = n0; s = sqrt(n); c = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        ll v = n / l; r = n / v; w[++c] = v;
        for (int k = 0; k < K; ++k)
            //  g[k][c] = ...;
    }
    for (int p : ps) {
        if (1ll * p * p > n) break;
        for (int i = 1; 1ll * p * p <= w[i]; ++i) {
            ll q = 1;
            for (int k = 0; k < K; ++k, q *= p)
                g[k][i] = sub(g[k][i], mul(q % P, sub(g[k][id(w[i] / p)], g[k][id(p - 1)])));
        }
    }
}

```

若要求$n$以内模$m$为$i \in \{0,1,\cdots,m-1\}$的质数$k$次幂和$g_{k,i}(n,j)$，因为模$m$为$i$的合数会对模$m$为$ip_j$的$g$产生贡献，因此可用以下的递推式：
$$
g_{k,ip_j \bmod m}(n,j)=g_{k,ip_j \bmod m}(n,j-1)-p_j^k\left[g_{k,i}(\lfloor n/p_j \rfloor, j -1)-g_{k,i}(p_j-1,j-1)\right]
$$
筛$p_j$的倍数时把$i$过一遍即可。注意边界。

#### 第二步：求$s(n,j)$

定义：$s(n,j)$为$f$在所有最小质因子大于等于$p_j$的数的位置上的和。

可以直接递归计算$s(n,j)$。

1. 当$n<p_j$时，$s(n,j)$为$0$。

2. 当$p_j \leq n < p_j^2$时，因为$n$以内最小质因子大于等于$p_j$的数只有质数，所以此时$s(n,j)$为$f$在所有大于等于$p_j$的质数的位置上的和，这东西可以直接用$g$算出来。
3. 否则枚举$p_j$的幂次$e$，加入$f$在所有最小质因子为$p_j$的数的位置上的取值，递归计算$s(n,j)$。

即
$$
s(n,j)=\begin{cases}
0 & n<p_j\\
\displaystyle \sum_{k=0}^Ka_k \left(g_k(n)-g_k(p_j-1)\right) & p_j \leq n < p_j^2\\
\displaystyle s(n,j+1)+\sum_{e = 1}^{\lfloor \log_{p_j}n\rfloor }f(p_j^e)\left(s(\lfloor n/p_j^e\rfloor,j+1)+1\right) & p_j^2 \leq n
\end{cases}
$$
复杂度$O(能过)$。

```cpp
ll cal_s(ll n, int j) {
    const int p = ps[j];
    if (p > n) return 0;
    if (1ll * p * p > n)
        return a[0]*(g[0][id(n)]-g[0][id(ps[j-1])])+...;
	ll sum = cal_s(n, j + 1);
    ll q = p;
    for (int e = 1; q <= n; ++e, q *= p)
        sum += f(p,e,q) *(cal_s(n / q, j + 1) + 1);
    return sum;
}
```

### Meissel-Lehmer

Meissel-Lehmer算法可以用来统计$n$以内的质数个数。思路大概来源于埃氏筛。

定义$\phi(x,a)$为$n$以内无法被前$a$个质数整除的数，即埃氏筛过程中筛掉前$a$个质数的所有倍数后剩下来的数的数量。

这个东西可以用容斥表达（似乎没什么用但是看起来很炫酷），即先筛去所有$p_i$以内质数的倍数，再加上$p_i$以内质数两两相乘所得数的倍数等等。

定义(Legendre's Formula):
$$
\phi(x,a)=x-\sum_{1 \leq i \leq a}\lfloor x/p_i\rfloor+\sum_{1 \leq i <j \leq a}\lfloor x/p_ip_j\rfloor-\sum_{1 \leq i <j<k \leq a}\lfloor x/p_ip_jp_k\rfloor+\cdots
$$
同时这个东西满足递推式：
$$
\phi(x,i)=\phi(x,i-1)-\phi(\lfloor x/p_i\rfloor,i-1)
$$
递推边界为
$$
\phi(x,0)=x
$$
证明：考虑埃氏筛的过程。将$p_i$的所有倍数筛掉时，相比上一轮，新筛掉的数的最小质因子为$p_i$。每一个这样的数除去$p_i$

后都与一个最小质因子至少为$p_i$且小于等于$\lfloor x/p_i\rfloor $的数一一对应。这样的数的数量即对$\lfloor x / p_i \rfloor$以内的数进行埃氏筛时将$p_{i-1}$的所有倍数筛掉后剩下的数的数量，即$\phi(\lfloor x/p_i\rfloor,i-1)$。

考虑如何利用另一种方式表达筛剩下来的数，令$P_k(x,a)$为$x$以内能够表达成$k$个大于$p_a$的质数相乘的数的数量。

枚举最小质因子，则有
$$
P_1(x,a)=\pi(x)-a\\
P_2(x,a)=\sum_{i=a+1}P_1(\lfloor x/p_i \rfloor,i-1)=\sum_{i=a+1}^{\pi(\sqrt x)}\left[\pi(\lfloor x/p_i\rfloor)-(i-1)\right]
$$
这个过程的一般化即
$$
P_k(x,a)=\sum_{i=a+1}^{\pi(\sqrt[k]x)}P_{k-1}(\lfloor x/p_i\rfloor, i-1)
$$
我们可以利用这些$P_k$来表示筛掉前$a$个质数的所有倍数后剩下来的数，即Legendre公式的变种：
$$
\phi(x,a)=1+\pi(x)-a+P_2(x,a)+P_3(x,a)+\cdots
$$
特别地，当$a=\pi(\sqrt n)$时，剩下的数除了$1$以外至多只有一个质因子，即$P_2(x,a)=P_3(x,a)=\cdots=0$。

此时有$\phi(x,\pi(\sqrt x))=\pi(x)-\pi(\sqrt x)+1$。这个过程的变种即为min25筛的第一步，此时复杂度为$O(n^{3/4}/\log n)$。

令$b = \pi(\sqrt x),c = \pi(\sqrt[3]x)$，则筛掉前$c$个质数后剩下来的合数至多只有$2$个质因子，即当$k \geq 3$时$P_k(x,c)=0$，此时有
$$
\phi(x,c)=1+\pi(x)-c+P_2(x,a)=1+\pi(x)-c+\sum_{i=c+1}^{b}[\pi(\lfloor x/p_i\rfloor)-(i-1)]\\
$$
移项化简得

定义(Meissel's Formula):
$$
\pi(x)=\phi(x,c)+c-1-P_2(x,a)\\
=x-\sum_{1 \leq i \leq a}\lfloor x/p_i\rfloor+\sum_{1 \leq i <j \leq a}\lfloor x/p_ip_j\rfloor-\sum_{1 \leq i <j<k \leq a}\lfloor x/p_ip_jp_k\rfloor+\cdots+\sum_{i=c-1}^{b-1}i-\sum_{i=c+1}^{b}\pi(\lfloor x/p_i\rfloor)
$$
将那个等差数列和换成$(b+c-2)(b-c+1)/2$即为常见版本。

注：那个$c-1$跑到等差数列里面去了

这个东西可以进一步扩展，即放宽至$P_3(x,a)$不为$0$。

定义(Lehmer's Formula):
$$
\pi(x)=\varphi(x,a)+a-1-P_2(x,a)-P_3(x,a)\\
=\varphi(x,a)+\frac 12(b+a-2)(b-a+1)-\sum_{i=c+1}^{b}\pi(\lfloor x/p_i\rfloor)-\sum_{i=a+1}^{\pi(\sqrt[3] x)}\sum_{j=i}^{\pi(\sqrt {x / p_i})}\left[\pi(x/p_ip_j)-(j-1)\right]
$$
基于上面两个公式分别实现的质数计数，我觉得`meissel_pi`已经够用了。时间复杂度$O(好像挺快的)$。

```cpp
namespace ML {

const int N = 10000001, P = 7, M = 2*3*5*7*11*13*17;
bool ip[N]; int ps[N], pi[N];
int phi[P+1][M+1], sz[P+1], pc;
void init() {
    fill_n(ip, N, 1); pc = 0; ip[1] = 0;
    for (int i = 2; i < N; ++i) {
        pi[i] = pi[i - 1];
        if (ip[i]) ps[++pc] = i, pi[i]++;
        for (int j = 1; j <= pc && i * ps[j] < N; ++j) {
            ip[i * ps[j]] = 0;
            if (i % ps[j] == 0) break;
        }
    }  
    iota(phi[0], phi[0] + M + 1, 0);
    for (int i = sz[0] = 1; i <= P; ++i) {
        sz[i] = ps[i] * sz[i - 1];
        for (int j = 1; j <= M; ++j)
            phi[i][j] = phi[i - 1][j] - phi[i - 1][j / ps[i]];
    }
}

int sq(ll x) { return (int)floor(sqrt(x)); }
int cb(ll x) { return (int)floor(cbrt(x)); }

ll legendre_phi(ll x, int a) {
    if (a == 0) return x;
    if (a <= P) return phi[a][x % sz[a]] + (x / sz[a]) * phi[a][sz[a]];
    if (x <= 1ll * ps[a] * ps[a]) return pi[x] - a + 1;
    if (x <= 1ll * ps[a] * ps[a] * ps[a] && x < N) {
        int b = pi[sq(x)];
        ll res = pi[x] - 1ll * (b + a - 2) * (b - a + 1) / 2;
        for (int i = a + 1; i <= b; ++i)
            res += pi[x / ps[i]];
        return res;
    }
    return legendre_phi(x, a - 1) - legendre_phi(x / ps[a], a - 1);
}

ll meissel_pi(ll x) {
    if (x < N) return pi[x];
    int c = pi[cb(x)], b = pi[sq(x)];
    ll res = legendre_phi(x, c) + c - 1;
    for (int i = c + 1; i <= b; ++i)
        res -= meissel_pi(x / ps[i]) - i + 1;
    return res;
}

ll lehmer_pi(ll x) {
    if (x < N) return pi[x];
    int a = pi[sq(sq(x))], b = pi[sq(x)], c = pi[cb(x)];
    ll res = legendre_phi(x, a) + 1ll * (b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; ++i) {
        ll w = x / ps[i];
        res -= lehmer_pi(w);
        if (i > c) continue;
        for (int j = i, bi = pi[sq(w)]; j <= bi; ++j)
            res -= lehmer_pi(w / ps[j]) - (j - 1);
    }
    return res;
}

}
```

性能：`meissel_pi`和`lehmer_pi`差别不大，前者略快。未尝试通过记忆化优化计算过程。

当`P=7`时允许的计算次数大约如下，将`P`增大后性能提升不大。

| $n=$ | $10^8$ | $10^9$ | $10^{10}$ | $10^{11}$ | $10^{12}$ |
| ---- | ------ | ------ | --------- | --------- | --------- |
| 1s   | 20000  | 4000   | 500       | 40        | 5         |

筛$k$次前缀和：
$$
\phi_k(x,a)=S_k(x)-\sum_{1 \leq i \leq a}p_i^kS_k(\lfloor x/p_i\rfloor)+\sum_{1 \leq i <j \leq a}p_i^kp_j^kS_k(\lfloor x/p_ip_j\rfloor)-\cdots\\
=\phi_k(x,a-1)-p_a^i\phi_k(\lfloor x / p_a\rfloor,a-1)\\
\phi_k(x,0)=S_k(x)\\

\phi_k(x,a)=1+\pi_k(x)-\pi_k(p_a)+P_2(x,a)+\cdots\\
\pi_k(x)=\phi_k(x,a)+\pi_k(p_a)-1-P_2(x,a)\\
=\phi_k(x,a)+\pi_k(p_a)-a-\sum_{i=a+1}^{\pi(\sqrt x)}p_i(\pi_k(x/p_i)-\pi_k(p_{i-1}))
$$
