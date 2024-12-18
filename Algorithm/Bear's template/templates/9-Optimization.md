---
title: "Optimization"
author: forgottencsc
date: Dec 11, 2020
geometry: margin=1cm
output: pdf_document
---

# 最优化

前半部分为连续优化，后半部分为离散优化。

## 向量微积分

以下用$\boldsymbol{A}, \boldsymbol{B}$指代矩阵，$\boldsymbol{x}, \boldsymbol{y}$指代列向量，$f, g, k,l$指代标量。

定义（向量对标量求导）：
$$
\frac{\partial \boldsymbol{x}}{\partial k}=\left({\frac{\partial x_1}{\partial k},\frac{\partial x_2}{\partial k}, \cdots \frac{\partial x_n}{\partial k}}\right)^T
$$
定义（矩阵对标量求导）：
$$
\frac{\partial \boldsymbol{A}}{\partial k}=
\begin{bmatrix}
\frac{\partial a_{11}}{\partial k} & \frac{\partial a_{12}}{\partial k} & \cdots & \frac{\partial a_{1m}}{\partial k}\\
\frac{\partial a_{21}}{\partial k} & \frac{\partial a_{22}}{\partial k} & \cdots & \frac{\partial a_{2m}}{\partial k}\\
\vdots & \vdots & \ddots & \vdots\\
\frac{\partial a_{n1}}{\partial k} & \frac{\partial a_{n2}}{\partial k} & \cdots & \frac{\partial a_{1m}}{\partial k}\\
\end{bmatrix}
$$
定义（标量对向量求导）：
$$
\frac{\partial f}{\partial \boldsymbol{x}}=\left({\frac{\partial f}{\partial x_1},\frac{\partial f}{\partial x_2}, \cdots \frac{\partial f}{\partial x_n}}\right)^T
$$
例：$\displaystyle \frac{\partial }{\partial \boldsymbol{x}}{\boldsymbol{x}}^T\boldsymbol{x}= \left({\frac{\partial {\boldsymbol{x}}^T\boldsymbol{x}}{\partial x_1},\frac{\partial {\boldsymbol{x}}^T\boldsymbol{x}}{\partial x_2}, \cdots \frac{{\partial \boldsymbol{x}}^T\boldsymbol{x}}{\partial x_n}}\right)^T=\left({2x_1,2x_2, \cdots, 2x_n}\right)^T=2 \boldsymbol{x}$

例：$\displaystyle \frac{\partial }{\partial \boldsymbol{x}} \boldsymbol{y}^T\boldsymbol{x}=\left({y_i}\right)^T=\boldsymbol{y}$

例：
$$
\begin{split}
\begin{aligned}
&\frac{\partial }{\partial \boldsymbol{x}} {\boldsymbol{x}}^T \boldsymbol{A} \boldsymbol{x}=\frac{\partial }{\partial \boldsymbol{x}} \left({\sum_{i=1}^n\sum_{j=1}^na_{ij}x_ix_j}\right)^T=\left({\frac{\partial }{\partial x_k}\sum_{i=1}^n\sum_{j=1}^na_{ij}x_ix_j}\right)^T\\
= & \left({2a_{kk}x_k+\sum_{i=1 \wedge i \neq k}^na_{ik}x_i+\sum_{j=1 \wedge j \neq k}^na_{kj}x_j}\right)^T=\left({\sum_{i=1}^na_{ik}x_k+\sum_{j=1}^nx_ka_{kj}}\right)^T\\
= &\boldsymbol{A} \boldsymbol{x}+(\boldsymbol{x}^T \boldsymbol{A})^T=(\boldsymbol{A}+\boldsymbol{A}^T)\boldsymbol{x}
\end{aligned}
\end{split}
$$
当$\boldsymbol{A} = {\boldsymbol{A}}^T$时，有$\frac{\partial }{\partial \boldsymbol{x}} {\boldsymbol{x}}^T \boldsymbol{A} \boldsymbol{x}=2\boldsymbol{A} \boldsymbol{x}$

定义（向量对向量求导）：
$$
\frac{\partial \boldsymbol{y}}{\partial \boldsymbol{x}}=\begin{bmatrix}
\frac{\partial y_1}{\partial x_1} & \frac{\partial y_2}{\partial x_1} & \cdots & \frac{\partial y_m}{\partial x_1}\\
\frac{\partial y_1}{\partial x_2} & \frac{\partial y_2}{\partial x_2} & \cdots & \frac{\partial y_m}{\partial x_2}\\
\vdots & \vdots & \ddots & \vdots\\
\frac{\partial y_1}{\partial x_n} & \frac{\partial y_2}{\partial x_n} & \cdots & \frac{\partial y_m}{\partial x_n}\\
\end{bmatrix}
$$
例：

$$
\displaystyle \frac{\partial \boldsymbol{A}^T\boldsymbol{x}}{\partial \boldsymbol{x}}=\begin{bmatrix}
\frac{\partial }{\partial x_1}\sum_{k=1}^na_{k1}x_k & \frac{\partial }{\partial x_1}\sum_{k=1}^na_{k2}x_k & \cdots & \frac{\partial }{\partial x_1}\sum_{k=1}^na_{km}x_k\\
\frac{\partial }{\partial x_2}\sum_{k=1}^na_{k1}x_k & \frac{\partial }{\partial x_2}\sum_{k=1}^na_{k2}x_k & \cdots & \frac{\partial }{\partial x_2}\sum_{k=1}^na_{km}x_k\\
\vdots & \vdots & \ddots & \vdots\\
\frac{\partial }{\partial x_n}\sum_{k=1}^na_{k1}x_k & \frac{\partial }{\partial x_n}\sum_{k=1}^na_{k2}x_k & \cdots & \frac{\partial }{\partial x_n}\sum_{k=1}^na_{km}x_k\\
\end{bmatrix}=\boldsymbol{A}
$$

当自变量确定时（如为$\boldsymbol{x}$），一般将$\displaystyle \frac{\partial f}{\partial \boldsymbol{x}}, \frac{\partial \boldsymbol{g}}{\partial \boldsymbol{x}}$记作$\nabla f, \nabla \boldsymbol{g}$。即$f,\boldsymbol{g}$的梯度。

## 一维单峰函数

考虑优化问题
$$
\min_x f(x)
$$
其中$f$是单峰的，即满足
$$
\exists p,\forall x < y \leq p,f(x) >f(y) \wedge \forall p \leq y < x,f(x)>f(y)
$$
即存在一个点$p$使得$p$左边$f$单调减，右边$f$单调增。这里$p$即是最小值点。

若确定三个点$x<y<z$使得$f(x)<f(y)<f(z)$，则$p<y$，因为若$p\geq y$则一定有$f(x) > f(y)$，矛盾。

类似的若确定三个点$x<y<z$使得$f(x)>f(y)>f(z)$，则$p>y$，因为若$p \leq y$则一定有$f(y)<f(z)$，矛盾。

对于区间$[l,r]$，取其两个三等分点计算$f$后利用前面的规则缩短区间即可。

三分法在每轮迭代中将区间长度缩短$1/3$，迭代$k$次过程中计算$2k$次$f$并将区间长度缩短至原来的$(2/3)^k$。

每轮迭代中计算两次$f$显得有些没必要。当计算$f$开销巨大时两倍的常数是很恐怖的（如最速下降法）。

考虑如何在下一轮迭代中复用中间两个点的值。

设当前区间为$[l_1,r_1]$，选取的两个中间点分别为$l_2,r_2$，则每轮会将区间缩短至$[l_1,r_2]$或$[l_2,r_1]$。

设$r_2-l_1=r_1-l_2=p(r_1-l_1)$。

缩短至$[l_1,r_2]$时，复用点$l_2$的值；缩短至$[l_2,r_1]$时，复用点$r_2$的值。

为保证每轮缩短的比例相同，应有$l_2-l_1=r_1-r_2=p(r_2-l_1)=p(r_1-l_2)$。

于是有$r_1-l_1=(r_1-r_2)+(r_2-l_1)=p^2(r_1-l_1)+p(r_1-l_1)$。

消去$r_1-l_1$得$p^2+p-1=0$。解得$p=(\sqrt 5-1)/2$，即黄金分割比。

注：为保证精度，每轮迭代需重新按比例计算$r_2$或$l_2$，而不能用$r_2=r_1-(l_2-l_1)$之类的式子计算。

## 一阶必要条件

给定一阶可微函数$f$，若$\boldsymbol{x}_0$使得$f$取得极值，则必有$\nabla f(\boldsymbol{x}_0)=0$。

注：这个应该每本高数书都证过了。

这是极值点的必要条件，也意味着可以通过寻找必要条件来缩小极值点的范围，进而寻找最值点。

给定一阶可微的函数$f : \mathbb{R} ^n \rightarrow \mathbb{R}$和一阶可微的约束函数$\boldsymbol{g} : \mathbb{R}^n\rightarrow\mathbb{R}^{k},\boldsymbol{h} : \mathbb{R}^n\rightarrow\mathbb{R}^{m}$，对于带约束优化问题
$$
\begin{array}{lcl}
\min & &f(\boldsymbol{x})\\
s.t.& &\boldsymbol{h}(\boldsymbol{x}) = 0\\
& &\boldsymbol{g}(\boldsymbol{x}) \leq 0
\end{array}
$$

接下来寻找极值点满足的必要条件。（类似前面的梯度为0）

定义（可行域）：对于上述优化问题，定义其可行域为
$$
D=\{ x \in \mathbb {R}^n|\boldsymbol{h}(\boldsymbol{x}) =\boldsymbol{0} \wedge \boldsymbol{g}(\boldsymbol{x}) \leq \boldsymbol{0}\}
$$
例：这里可以想象$\mathbb {R}^3$中有一个球形约束$g(\boldsymbol{x})=||\boldsymbol{x}||^2-r \leq0$，和一个平面约束$h(\boldsymbol{x})=\boldsymbol{w}^T\boldsymbol{x}-\boldsymbol{b}=0$ 。这两个约束的交（即可行域）是一个圆盘。

接下来寻找在可行域内的极值点的类似无约束情况下梯度等于$0$的特殊性质。

注意到任意一个满足约束的极小值点$\boldsymbol{x}_0$附近，朝着可行域内的任意一个方向走都不能让$f$减小（否则就不是极小点了）。

考虑每种约束对可行域中方向的约束：

等式约束：可行域中方向在等式约束的梯度方向上分量为$0$。

取等号的不等式约束：可行域中方向在取等号的不等式约束的梯度方向上分量非正

未取等号的不等式约束：不起作用。

最终可行域中的方向是前两者的交，记为$V_1$。

不让$f$减小的方向即在目标函数的梯度上分量非负，记为$V_2$。

朝着可行域内任意一个方向走都不能让$f$减小意味着$V_1 \subseteq V_2$。

取补得$\mathbb {R}^n - V_1 \supseteq \mathbb {R}^n - V_2$。

$\mathbb {R}^n-V_1$即每个约束取反的并，即在等式约束梯度方向上分量不为$0$或在不等式约束梯度方向上有正分量。

记作$\displaystyle v_1=\sum_{i=1}^m\lambda_ih_i+\sum_{i=1}^k\mu_ig_i$，$\mu_i\geq 0$。对于不起作用的不等式约束，其梯度系数为$0$。即$\boldsymbol{\mu}^T\boldsymbol{g}=0$。

$\mathbb {R}^n-V_2$即在$f$的梯度方向上有负分量，即$v_2=\eta \nabla f(\boldsymbol{x})$，$\eta <0$。

前者包含后者即$v_2$能被$v_1$表示，两边除以$-\eta$移项得
$$
\nabla f(\boldsymbol{x}_0)+\boldsymbol{\lambda}^T\nabla \boldsymbol{h}(\boldsymbol{x}_0)+\boldsymbol{\mu}^T\nabla \boldsymbol{g}(\boldsymbol{x}_0)=0\\
\boldsymbol{\mu}^T \boldsymbol{g}(\boldsymbol{x})=0
$$
最终形态如下（Karush–Kuhn–Tucker条件）：

给定$f,\boldsymbol{g}, \boldsymbol{h}$，$f$在可行域中的极值点满足存在$\boldsymbol{\lambda} \in \mathbb{R}^m, \boldsymbol{\mu} \in \mathbb{R}^k$使得
$$
\begin{split}
\nabla f(\boldsymbol{x})+\boldsymbol{\lambda}^T\nabla \boldsymbol{h}(\boldsymbol{x})+\boldsymbol{\mu}^T\boldsymbol{g}(\boldsymbol{x})=\boldsymbol{0}\\
\boldsymbol{h}(\boldsymbol{x})=\boldsymbol{0}\\
\boldsymbol{g}(\boldsymbol{x}) \leq \boldsymbol{0}\\
\boldsymbol{\mu} \geq 0\\
\boldsymbol{\mu}^T\boldsymbol{g}(\boldsymbol{x})= \boldsymbol{0}\\
\end{split}
$$
## 牛顿法

求$f(x)=0$的零点。

可看作求出了曲线$y=f(x)$在点$(x_k,f(x_k))$处的切线并解出了切线与$x$轴交点$(x_{k+1},0)$，并从该点继续迭代。

对于该点有切线方程为$y-f(x_k)=f'(x_k)(x-x_k)$。其与$x$轴交点为$\displaystyle x_{k+1}=x_k-\frac{f(x_k)}{f'(x_k)}$。

## 拉格朗日函数与对偶

定义（拉格朗日函数）：
$$
\mathscr L(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu})=f(\boldsymbol{x})+\boldsymbol{\lambda}^T \boldsymbol{h}(\boldsymbol{x})+\boldsymbol{\mu}^T\boldsymbol{g}(\boldsymbol{x})\\
$$
里面的$\boldsymbol{\lambda}$和$\boldsymbol{\mu}$被称为拉格朗日乘子（后者为KKT乘子）。

注意到KKT条件的第一个式子等价于
$$
\frac{\partial \mathscr L}{\partial \boldsymbol{x}}\bigg|_{\boldsymbol{x}=\boldsymbol{x}_0}=0
$$
接下来利用拉格朗日函数构造一个与原问题同解的无约束优化问题。

设
$$
\displaystyle \theta_{primal}(\boldsymbol{x})=\max_{\boldsymbol{\lambda},\boldsymbol{\mu} \geq 0} \mathscr L(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu})
$$
注：$\boldsymbol{\lambda} , \boldsymbol{\mu} \geq 0$不是$\boldsymbol{\lambda} \geq 0 \wedge \boldsymbol{\mu} \geq 0$。

则
$$
\min_{\boldsymbol{x}}\theta_{primal}(\boldsymbol{x})=\min_{\boldsymbol{x}\in D}f(\boldsymbol{x})
$$
注：$D$为可行域。

证明：对于不在可行域中的任意一个点$\boldsymbol{x}$，存在一个$h_i$或$g_i$使得$h_i(\boldsymbol{x}) \neq 0$或$g_i(\boldsymbol{x}) > 0$，因而改变对应的乘子分量即可使$\mathscr L$增大，且没有上限。而对于未取等号的不等式约束$g_i(\boldsymbol{x})<0$，为使$\theta_{primal}$尽可能大，其对应的乘子必定是$0$。因而自动满足$\boldsymbol{\mu}^T\boldsymbol{g}=0$。所以$\theta_{primal}$在可行域外的取值是正无穷，且在可行域内自动满足$\boldsymbol{\mu}^T\boldsymbol{g}=0$，因而其最小值等于$f$在可行域中的最小值。

定义（对偶问题）
$$
\theta_{dual}(\boldsymbol{\lambda}, \boldsymbol{\mu})=\min_{\boldsymbol{x}} \mathscr L(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu})
$$
有弱对偶定理
$$
\theta_{dual}(\boldsymbol{\lambda}, \boldsymbol{\mu})=\min_{\boldsymbol{x}} \mathscr L(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu}) \leq \mathscr L(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu}) \leq \max_{\boldsymbol{\lambda}, \boldsymbol{\mu} \geq 0} \mathscr L(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu}) =\theta_{primal}(\boldsymbol{x})
$$
因而有$\displaystyle \max_{\boldsymbol{\lambda}, \boldsymbol{\mu} \geq 0}\theta_{dual}(\boldsymbol{\lambda}, \boldsymbol{\mu})\leq \min_{\boldsymbol{x}}\theta_{primal}(\boldsymbol{x})$

定理（Slater条件）：当$\boldsymbol{h}(\boldsymbol{x})=0$是仿射约束且$f$和$g_i$都是凸的，则有强对偶性
$$
\displaystyle \max_{\boldsymbol{\lambda}, \boldsymbol{\mu} \geq 0}\theta_{dual}(\boldsymbol{\lambda}, \boldsymbol{\mu})= \min_{\boldsymbol{x}}\theta_{primal}(\boldsymbol{x})
$$
证明略。

对偶问题有时候会比原问题好解。

例：支持向量机(SVM)是一个解决二分类问题的模型。其基本思想是使用一个超平面将两类数据点分开。

这里考虑SVM的训练过程，训练的目的即是选定一个超平面，使两类点到该超平面的距离尽可能大。

数据集中第$i$个条数据为$\boldsymbol{x}_i \in \mathbb{R}^n$，标签为$y_i \in \{-1, 1\}$。

超平面方程为${\boldsymbol{w}}^T \boldsymbol{x}+b=0$，$\boldsymbol{w}$相当于超平面的法向量。

预测函数为$y=\boldsymbol{w}^T\boldsymbol{x}+b$。约束即使得训练集中不存在使得$|\boldsymbol{w}^T \boldsymbol{x}+b| <1$的点。

恰好满足$|\boldsymbol{w}^T \boldsymbol{x}_i+b|=1$的点即是支持向量，即离超平面最近的那些点。

即若第$i$个数据点是支持向量，则有$y_i(\boldsymbol{w}^T \boldsymbol{x}_i+b)=1$。

接下来考虑解出支持向量到超平面的距离。

$\boldsymbol{x}_i$在超平面上的投影$\boldsymbol{p}$满足：$\boldsymbol{w}^T\boldsymbol{p}+b=\boldsymbol{w}^T(\boldsymbol{x}_i+k \boldsymbol{w})+b=0$。

展开：$\boldsymbol{w}^T \boldsymbol{x}_i+b+k\boldsymbol{w}^T\boldsymbol{w}=0$

代入：$y_i+k \boldsymbol{w}^T\boldsymbol{w}=0$

解得$\displaystyle k=\frac{y_i}{\boldsymbol{w}^T\boldsymbol{w}}$。即$\boldsymbol{x}_i$到超平面的距离的平方为$||k\boldsymbol{w}||^2=\displaystyle k^2\boldsymbol{w}^T\boldsymbol{w}=\frac{y_i^2}{\boldsymbol{w}^T\boldsymbol{w}}=\frac{1}{||\boldsymbol{w}||^2}$。

得到优化问题
$$
\begin{split}
\max_{\boldsymbol{w},b} \frac{1}{||\boldsymbol{w}||^2}\\
s.t. \quad \forall i, y_i(\boldsymbol{w}^T\boldsymbol{x}_i+b) \geq 1
\end{split}
$$
等价于解
$$
\begin{split}
\min_{\boldsymbol{w},b} \frac 12 \boldsymbol{w}^T\boldsymbol{w}\\
s.t. \quad \forall i, 1-y_i(\boldsymbol{w}^T\boldsymbol{x}_i+b) \leq 0
\end{split}
$$

设
$$
g_i(\boldsymbol{w})=1-y_i(\boldsymbol{w}^T\boldsymbol{x}_i+b)
$$

由KKT条件有
$$
\begin{split}
\mathscr L= \frac 12 \boldsymbol{w}^T\boldsymbol{w}+ \sum_{i=1}^k\mu_ig_i=\frac 12 \boldsymbol{w}^T\boldsymbol{w}+ \sum_{i=1}^k\mu_i\left({1-y_i(\boldsymbol{w}^T\boldsymbol{x}_i+b)}\right)\\
s.t. \\
\frac{\partial \mathscr L}{\partial \boldsymbol{w}}=\boldsymbol{w}-\frac{\partial}{\partial \boldsymbol{w}}\left({\sum_{i=1}^k\mu_i-\sum_{i=1}^k\mu_iy_i\boldsymbol{w}^T\boldsymbol{x}_i-\sum_{i=1}^k\mu_iy_ib}\right)=\boldsymbol{w}-\sum_{i=1}^k\mu_iy_i\boldsymbol{x}_i=0\\
\frac{\partial \mathscr L}{\partial b}=-\sum_{i=1}^k{\mu_iy_i}=0\\
\quad \mu_i \geq 0\\
1-y_i(\boldsymbol{w}^T\boldsymbol{x}_i+b) \leq 0
\end{split}
$$
代回$\mathscr L$有
$$
\mathscr L=\frac 12 \sum_{i=1}^m\sum_{j=1}^m\mu_i\mu_jy_iy_j\boldsymbol{x}_i^T\boldsymbol{x}_j+\sum_{i=1}^m\mu_i-\sum_{i=1}^m\mu_iy_i\left({\sum_{j=1}^m\mu_jy_j\boldsymbol{x}_j^T}\right)\boldsymbol{x}_i\\
=\sum_{i=1}^m\mu_i-\frac 12 \sum_{i=1}^m\sum_{j=1}^m\mu_i\mu_jy_iy_j\boldsymbol{x}_i^T\boldsymbol{x}_j
$$

由拉格朗日对偶和Slater条件,这里可以丢掉不等式约束。原问题答案为
$$
\min _{\boldsymbol{w}} \max_{\boldsymbol{\mu} \geq 0} \mathscr L
$$
前式中$\boldsymbol{w}$已被消去，因此
$$
\max_{\boldsymbol{\mu} \geq 0} \mathscr L=\max_{\boldsymbol{\mu} \geq 0}\sum_{i=1}^m\mu_i-\frac 12 \sum_{i=1}^m\sum_{j=1}^m\mu_i\mu_jy_iy_j\boldsymbol{x}_i^T\boldsymbol{x}_j
$$

这个问题属于半正定规划，比原问题更好求解，且有比半正定规划求解器更好的算法（SMO等）。

本节在不同程度上参考了

[1]https://www.zhihu.com/question/23311674/answer/235256926

[2]https://www.cnblogs.com/90zeng/p/Lagrange_duality.html

[3]西瓜书

[4]一万个维基百科页面

## 线性规划

这一段中不会（且没有必要）再用粗体区分向量和标量

定义（标准形式的线性规划）：给定代价$c \in \mathbb {R}^{n \times 1}$，约束矩阵$A \in \mathbb {R} ^{m \times n}$和向量$b \in \mathbb {R}^{n \times 1}$，求解
$$
\begin{split}
\max_{x \geq 0} c^T x\\
s.t. Ax \leq b
\end{split}
$$

### 对偶

考虑标准型线性规划
$$
\begin{split}
\max_{x \geq 0} c^T x\\
s.t. Ax \leq b
\end{split}
$$
构造拉格朗日函数
$$
\mathscr L(x, y, \mu)=-c^Tx+y^T(Ax-b)-\mu^Tx
$$
由KKT条件有
$$
\frac{\partial \mathscr L}{\partial x}=-c+A^Ty-\mu=0
$$
同时因为$\mu \geq 0$，所以
$$
A^Ty-c=\mu\geq 0
$$
代回得
$$
\mathscr L(x,y,\mu)=(-c+y^TA-\mu)^Tx-y^Tb=-y^Tb
$$
其拉格朗日对偶问题为
$$
\begin{split}
\max_{y \geq 0, \mu \geq 0} \min_{x\geq 0}-y^Tb=\min_{y \geq 0}b^Ty\\
s.t. A^Ty \geq c
\end{split}
$$
由Slater条件得这两个问题的解相等。

考虑一般型线性规划
$$
\begin{split}
\max_{x \geq 0} c^T x\\s.t. Ax =b
\end{split}
$$
构造其拉格朗日函数：
$$
\mathscr L(x,y,\mu)=-c^Tx+y^T(Ax-b)+\mu^Tx
$$
和前面一样，只是$y$没有大于等于$0$的约束。

最后得到的对偶问题是（和上面的区别在于没有$y \geq 0$的限制）
$$
\begin{split}
\min_y b^Ty\\
s.t. A^Ty \geq c
\end{split}
$$

原问题：
$$
\begin{split}
\displaystyle\max_{x \geq 0} c^T x \\ s.t. Ax \leq b
\end{split}
$$
对偶问题：
$$
\begin{split}
\displaystyle\min_{y \geq 0} b^T y \\ s.t. A^Ty \geq c
\end{split}
$$
原问题：
$$
\begin{split}
\displaystyle\max_{x \geq 0} c^T x \\ s.t. Ax = b
\end{split}
$$
对偶问题：
$$
\begin{split}
\displaystyle\min_{y} b^T y \\ s.t. A^Ty \geq c
\end{split}
$$
定理（互补松弛定理）：咕了，好像长这样
$$
y^T(Ax-b)=x^T(A^Ty-c)=0
$$

### 单纯形法

先考虑标准型线性规划，即约束是不等式的情况。

考虑$\mathbb {R}^3$中的线性规划问题，若每个约束都是一个半空间，则最终的可行域将是一堆超平面和三个坐标轴平面围成的凸包。

观察到代价函数在这个凸包上某个顶点一定能取到最优值，一个最朴素的想法即是枚举这个凸包的每个顶点。

但因为代价函数由非常好的性质（线性），所以可以考虑从某个顶点，如原点开始贪心地往旁边代价更低的顶点转移，这样可以避免枚举每个顶点，但复杂度很玄学（仍然是指数级的，但是跑的很快）。

若周围的顶点代价均大于等于当前点，那么算法终止。

接下来考虑如何表示这个凸包的顶点。

凸包的顶点一定是许多超平面的交。

点$x$在某个超平面上代表着该超平面对应的不等式约束取到了等号。

在$\mathbb {R}^3$中，三个超平面的交即可确定一个点（不考虑退化情况），同理在$\mathbb {R}^n$中$n$个超平面的交即可确定一个点。

考虑将标准型表示成特殊的一般型：即将$A$的列重排可获得一个单位矩阵的一般型。

对于该凸包的一个顶点，其经过的超平面数量必定大于等于$n$。

用$m+n$个约束中的$n$个超平面来表示顶点。（除了$A$中的$m$行外还有$n$个$x_i\geq 0$）

当点位于这$n$个超平面的交时，对应的约束方程取到等号。

对于不等式约束，可以通过将等式左右的差定义为一个松弛变量来将不等式约束转化为等式约束。松弛变量取值为$0$即表示原来的不等式约束取到了等号。

引入松弛变量$x'$，原来的不等式约束$Ax \leq b$即转化为$Ax+Ix'=b$。

对于$b\geq 0$的标准型，初始解即可设为$x=0$。此时$x'=b$。其他不等式约束对应的松弛变量值即被唯一确定。

记$X={x'\\x}$，其分量记为$x_i,1 \leq i \leq m+n$。对于线性规划问题
$$
\begin{split}
\max_{X \geq 0} \begin{bmatrix}0 & c^T\end{bmatrix}X\\
s.t.\begin{bmatrix}I & A\end{bmatrix}X=b
\end{split}
$$
记矩阵
$$
\begin{split}
\begin{bmatrix}0 & 0 & c^T\\b & I & A\end{bmatrix}
\end{split}
$$
为该线性规划的初始单纯形表。左上角的$0$即当前所在点的目标函数值。

单纯形表中除了最左边的那一列之外的每一列都对应着$X$的一个分量。

取$0$的变量被称为非基变量，其余的被称为基变量。

在任意时刻，基变量有$m$个，非基变量有$n$个。基变量的值等于单纯形表左侧第一列除第一行外的值。

初始的基变量即为原问题中属于$Ax \leq b$的松弛变量。

不考虑具体的原来的$m$个半空间约束，对于当前的$m$个等式约束，因为有$m<m+n$，所以当前的等式约束确定的解集有$m+n-m=n$个自由度。

所以将任意$n$个变量置$0$即可解出余下的$m$个变量的值。

这$n$个变量代表了这$m+n$个超平面中的$n$个。而这$n$个超平面的交即是当前点。

单纯形表维护了$m+1$个等式。初始状态如下：
$$
\begin{bmatrix}0 & c^T\\
I & A\end{bmatrix}\begin{bmatrix}b\\0\end{bmatrix}=\begin{bmatrix}0\\b\end{bmatrix}
$$
单纯形法通过对单纯形表进行初等行变换来将当前点移动到相邻的顶点。同时维护移动的代价对目标函数值的影响。

设而移动前变量$x_e=0$是非基变量（对应的约束取到等号，即在该约束的超平面上），变量$x_l>0$（对应约束未取到等号，即不在该约束的超平面上）。

移动后变量$x_e>0$，且变量$x_l = 0$；此时称$x_e$为入基变量，$x_l$为出基变量。

（咕了）

```cpp
// Max z=cTx, Ax<=b.
// a[0][i]=c[i], a[i][0]=b[i]
int n, m, c[5001]; dbl a[4001][201], x[201], z;

int dcmp(dbl d) { return d < -eps ? -1 : d <= eps ? 0 : 1; }

void pivot(int u, int v) {
    swap(c[n + u], c[v]);
    dbl k = a[u][v]; a[u][v] = 1;
    for (int j = 0; j <= n; ++j) a[u][j] /= k;
    for (int i = 0; i <= m; ++i) {
        if (i == u || !dcmp(a[i][v])) continue;
        k = a[i][v]; a[i][v] = 0;
        for (int j = 0; j <= n; ++j)
            a[i][j] -= a[u][j] * k;
    }
}

bool init() {
    for (int i = 1; i <= n; ++i) c[i] = i;
    while (1) {
        int u = 0, v = 0;
        for (int i = 1; i <= m; ++i)
            if (dcmp(a[i][0]) == -1 && (!u || dcmp(a[u][0] - a[i][0]) == 1)) u = i;
        if (!u) return 1;
        for (int j = 1; j <= n && !v; ++j)
            if (dcmp(a[u][j]) == -1) v = j;
        if (!v) return 0;
        pivot(u, v);
    }
}

int simplex() {
    if (!init()) return 0;
    while (1) {
        int u = 0, v = 0;
        for (int j = 1; j <= n; ++j)
            if (dcmp(a[0][j]) == 1 && (!v || a[0][j] > a[0][v])) v = j;

        if (!v) {
            z = -a[0][0];
            for (int i = 1; i <= m; ++i)
                x[c[n + i]] = a[i][0];
            return 1;
        }

        dbl w = 1e20;
        for (int i = 1; i <= m; ++i)
            if (dcmp(a[i][v]) == 1 &&
                dcmp(w - a[i][0] / a[i][v]) == 1) {
                w = a[i][0] / a[i][v];
                u = i;
            }
        if (!u) return 2;
        pivot(u, v);
    }
}
```

## 拟阵

给定全集$U$。$U$与$u$的子集族$\mathcal M$组成的二元组$(U,\mathcal M)$是$U$上的拟阵当且仅当其满足以下两条拟阵公理：

1. 遗传性
   $$
   \forall X \in \mathcal M, \forall Y \subseteq X, Y \in \mathcal M
   $$

2. 独立性
   $$
   \forall X, Y \in \mathcal M, |X| < |Y| \rightarrow \exists y \in Y - X, |X| \cup \{y\} \in \mathcal M
   $$

拟阵中的元素被称为**独立集**。

上面两条公理换成人话即：(1) 独立集的子集也是独立的。 (2) 对于任意一个比独立集$X$大的独立集$Y$，我们总能从$Y$中挑一个不属于$X$的元素$y$使得$X$并上$\{y\}$还是独立集。

拟阵的例子：

图拟阵：给定无向图$G=(V,E)$，定义在$E$上的拟阵满足：一个边集$X$独立当且仅当其无环。

均匀拟阵：给定任意集合$U$，$U$上的均匀拟阵满足：一个集合$X$独立当且仅当$|X| \leq k$。

线性拟阵：给定定义在域$\mathbb F$上的向量空间$V$，定义在$V$上的拟阵满足：一个向量集合$X$独立当且仅当其线性无关。

命题：图拟阵是一种线性拟阵。

证明：将边$(u,v)$映射至一个01向量（即$\mathbb F_2^{n}$中的向量），其中只有$u$和$v$对应的分量是$1$，其他都是$0$。一组边集对应的01向量线性相关当且仅当这组边集存在环。

拟阵中的极大元素（这里的大指集合大小）被称为“基”。

由公理(2)易得拟阵中的所有基大小相同。

### 拟阵的贪心性质

问题：给定全集$U$，$U$上的拟阵$\mathcal M$和F权函数$w:2^U \rightarrow \mathbb R$，找出$\mathcal M$中权值最小的基。

这个问题在图拟阵上即为最小/大生成树问题。

算法：维护一个集合$X$，将$U$中的元素按权值从小到大依次尝试加入$X$，若加入某元素$x$后$X$不再是独立集则跳过$x$。即
$$
\begin{split}
w(x_1) \leq w(x_2) \leq \cdots \leq w(x_n)\\
X_i=\begin{cases}
X_{i-1} \cup \{x_i\} & X_{i-1} \cup \{x_i\} \in \mathcal M\\
X_{i-1} & X_{i-1} \cup \{x_i\} \notin \mathcal M
\end{cases}\\
\end{split}
ans = X_n
$$
证明：对于$\mathcal M$中的任意一个基$Y$，设$Y$中元素的权值从小到大为$w_1,w_2,...,w_k$。

设$X$中元素的权值从小到大为$w'_1,w'_2,...,w'_k$，在算法运行的任意一个阶段我们都可以由公理(2)证明$w'_i \leq w_i$。即存在一个权值$\leq w_i$的元素$y$使得$X \cup \{y\}$仍为独立集。

（不妨设$Y'$由权值为$w_1,w_2,...,w_k$的元素组成，$X'$由权值为$w'_1,w'_2,...,w'_{k-1}$的元素组成。由公理2$Y'-X'$中存在一个元素$y$，$w(y)\leq w_k$，其加入$X$后$X$仍为独立集。）

因此算法最终所得集合$X$满足对于任意一个基$Y$都有$w'_k \leq w_k$，即$\sum w'_k$最小。

同时我们还能得到另外一个结论，任意两个权值最小的基中，权值为任意$w$的元素数量相等。

### 拟阵交

定义（拟阵交）：求两个拟阵$(U, \mathcal M_1)$与$(U,\mathcal M_2)$的交$\mathcal M_1 \cap \mathcal M_2$中的最大独立集$X$。
$$
C_i(X,y)=\{x \in X|(X \cup \{y\})-\{x\} \in \mathcal M_i\}
$$
令$X=\empty$。

建立有向二分图，左边是$X$中元素，右边是$Y=U-X$中元素。

若$x \in C_1(X,y)$，则建边$(x,y)$。

若$x \in C_2(X,y)$，则建边$(y,x)$。

若$X \cup \{y\} \in \mathcal M_1$，则建边$(s,y)$。

若$X \cup \{y\} \in \mathcal M_2$，则建边$(y,t)$。

跑一个从$s$到$t$的最短路。不存在泽结束，否则将所有路上元素是否属于$X$的情况反转后进行下一次迭代。
