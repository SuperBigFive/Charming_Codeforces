

## FWT

## 曼哈顿距离与切比雪夫距离

命题：
$$
\max(a,b)=\frac{1}{2}(a+b+|a-b|)
$$
证明：

当$a \geq b$时，$|a-b|=a-b$。此时右侧等于$a$。

当$a < b$时，$|a-b|=b-a$，此时右侧等于$b$。

命题：
$$
|a|+|b|=\max(|a+b|,|a-b|)
$$
证明：由上一个命题有
$$
\max(|a+b|,|a-b|)=\frac{1}{2}(|a+b|+|a-b|+\left||a+b|-|a-b|\right|)
$$
当$a+b\geq0$且$a-b\geq0$时有，$-a \leq b \leq a$因此$a\geq0$，此时右侧等于
$$
\frac 12 (a+b+a-b+|a+b-a+b|)=a+|b|=|a|+|b|
$$
当$a+b\geq0$且$a-b\leq0$时有$-b \leq a \leq b$，因此$b\geq0$，此时右侧等于
$$
\frac12(a+b+b-a+|a+b-b+a|)=b+|a|=|a|+|b|
$$
当$a+b\leq 0$且$a-b \geq 0$时有$b \leq a \leq -b$，因此$b \leq 0$，此时右侧等于
$$
\frac12 (-a-b+a-b+|-a-b-a+b|)=-b+|-a|=|a|+|b|
$$
当$a+b\leq 0$且$a-b \leq 0$时有$a\leq b \leq -a$，因此$a \leq 0$，此时右侧等于
$$
\frac 12(-a-b+b-a+|-a-b+a-b|)=-a+|-b|=|a|+|b|
$$
因此令$u=x+y,v=x-y$后有
$$
|x_1-x_2|+|y_1-y_2|= \max(|x_1-x_2+y_1-y_2|,|x_1-x_2-y_1+y_2|)=\max(|u_1-u_2|,|v_1-v_2|)
$$
逆变换为
$$
x=\frac{u+v}{2},y=\frac{u-v}{2}
$$








