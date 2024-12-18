$$
\def\brac#1{\left(#1\right)}
\def\mat#1{\left[\begin{array}{cl}#1\end{array}\right]}
$$



投影

设子空间的一组基为$A=\mat{a_1,a_2,\cdots,a_m} \in \R^{n\times m}$，则矩阵$P=A(A^TA)^{-1}A^T \in \R^{n \times n}$将任何$\R^n$中的向量投影至该子空间中。





对称与旋转

给定点$p_1=(x_1,y_1,z_1)$和平面$Ax+By+Cz+D=0$，求其对称点$p_2(x_2,y_2,z_2)$ 。

设平面法向量$v=(A,B,C)$，则
$$
p_2=p_1-2\frac{v^Tp_1}{v^Tv}v\\
U=Ax_1+By_1+Cz_1+D\\
V=A^2+B^2+C^2\\
x_2=x_1 - \frac{2AU}{V}\\
y_2=y_1 - \frac{2BU}{V}\\
z_2=z_1 - \frac{2CU}{V}
$$

$$
U=Ax_1+By_1+Cz_1+D\\
V=A^2+B^2+C^2\\
x_2=-\frac{(2A^2-V)x_1+2A(U-Ax_1)}{V}=-\frac{2AU-Vx_1}{V}
$$
