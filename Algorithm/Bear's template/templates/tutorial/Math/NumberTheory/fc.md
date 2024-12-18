## 顶和底

定义（顶和底）：给定实数$x$，将$\lfloor x \rfloor$定义为小于等于$x$的最大整数，$\lceil x\rceil$定义为大于等于$x$的最小整数。

命题：对于正整数$a,b,c$有$\lfloor\lfloor a / b\rfloor /c \rfloor=\lfloor a/(bc)\rfloor$。

证明：设$a = q_1b+r_1(0 \leq r_1 <b)$，$q_1=q_2c+r_2(0 \leq r_2 < c)$，因为$a=(q_2c+r_2)b+r_1=q_2bc+r_2b+r_1$，而$r_2b+r_1\leq (c-1)b+(b-1)=bc-1<bc$，所以$\lfloor\lfloor a / b\rfloor /c \rfloor=q_2=\lfloor a/(bc)\rfloor$。

命题：对于正整数$n,x(x \leq \sqrt n)$有$\lfloor n / \lfloor n / x \rfloor \rfloor=x$。

证明：设$n = qx +r(0 \leq r < x),n=tq+s(0 \leq s < q)$。因为$0 \leq r <x \leq \sqrt n\leq q$，所以$s=r,t=x$。

命题：对于正整数$n,x(x<n)$，有$\lfloor n/ \lfloor n/\lfloor n/x\rfloor\rfloor\rfloor=\lfloor n/x\rfloor$。

证明：若$x \leq \sqrt n$，则可将$\lfloor n/\lfloor n/x\rfloor\rfloor$换成$x$。否则$\lfloor n/x \rfloor \leq \sqrt n$，则可将外两层去掉。得证。

命题：对于正整数$n,x(x<n)$，若存在$a$使得$\lfloor n/a\rfloor=x$，则$\max \{ a|\lfloor n/a \rfloor=x\}\leq \lfloor n/x \rfloor$。

证明：设$n=ax+b(0 \leq b < a)=qx+r(0 \leq r < x)$，则$a = (r-b)/x+q \leq r/x+q<x/x+q=q+1$

因此$a \leq q= \lfloor n/x \rfloor$。

命题：对于正整数$n,u(u<n)$，$\max \{v|\lfloor n/v\rfloor=\lfloor n/u\rfloor\}=\lfloor n/\lfloor n/u\rfloor\rfloor$。

因为$\lfloor n/\lfloor n/\lfloor n/u\rfloor\rfloor\rfloor=\lfloor n/u\rfloor$，且由上个命题有$v \leq \lfloor n/\lfloor n/u\rfloor\rfloor$，因此加上条件$x=\lfloor n/u\rfloor$后上一个命题中的等号成立。

命题：对于正整数$n$，集合$S=\{\lfloor n/i \rfloor|1 \leq i \leq n\}$的大小为$2s-[\lfloor i/s\rfloor=s]$，其中$s=\lfloor \sqrt n \rfloor$。

引理：对于正整数$n$，不大于$\sqrt n$的任意两个不相等的正整数$x,y$满足$\lfloor n/x \rfloor \neq \lfloor n/y \rfloor$。

证明：设$n = qx+r(0 \leq r < x)$，则$\lfloor n/x \rfloor=q$。因为$q \geq \sqrt n \geq x > r$，所以$q(x+1)=qx+q>qx+r=n$。所以$\lfloor n/(x+1) \rfloor < \lfloor n/x \rfloor$。不妨设$x < y$，即得$\lfloor n/y \rfloor <\lfloor n/(y-1) \rfloor< \cdots < \lfloor n/x \rfloor$。得证。

算法（整除分块）：由前两个条件可以在$O(\sqrt n)$内求出形如
$$
\sum_{x=1}^{n}f(\lfloor n/x\rfloor)
$$
的和式的值。（若$f$能$O(1)$求得）

因为$\lfloor n/x \rfloor$的取值只有$O(\sqrt n)$种，且对于一个$l$可以直接求出相同取值的右端点$r=\lfloor n/ \lfloor n/l \rfloor \rfloor$。

```
int sum = 0;
for (int l = 1, r; l <= n; l = r + 1) {
	r = n / (n / l);
	sum += (r - l + 1) * f(n / l);
}
```

注：求值范围为$L \leq x \leq R$时也可以只用一次for完成。