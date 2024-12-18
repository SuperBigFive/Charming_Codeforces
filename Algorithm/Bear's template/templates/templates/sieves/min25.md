定义：$g(n,j)$为$n$减去$n$以内的最小质因子小于等于$p_j$的合数个数，即$1$加上$n$以内的质数个数加上$n$以内的最小质因子大于$p_j$的合数个数。

性质：$n$以内不存在最小质因子大于$\sqrt n$的合数。因此$g(n, \pi(\sqrt n))=\pi(n)$。

观察到$n$以内的每个最小质因子为$p_j$的合数都形如$xp_j$，其中$x$是一个小于等于$\lfloor n/p_j \rfloor$且最小质因子大于等于$p_j$的数。

这样的$x$的数量等于$g(\lfloor n / p_j \rfloor, j - 1)$减去$1$和小于$p_j$的质数个数。后者等于$g(p_j - 1, j - 1)$

因此有
$$
g(n,j)-g(n,j-1)=g(\lfloor n/p_j \rfloor,j-1)-g(p_{j} - 1,j-1)
$$

$$
s(n,j)=s(n,j + 1)+f(p^e)(s(n / p_j^e, j+1)+1)
$$