三维凸包

`get_first_edge()`：首先选出凸包的一条棱。

1. 选择$x$坐标最小的点，如果有很多个则选择$y$坐标最小的点，如果还有很多个选择$z$坐标最小的点，如果还有很多个就把出题人他🐎杀了。这样的点一定是凸包的顶点，记其为$u$。
2. 因为三维凸包$H$在$xOy$上的投影$H'$中的顶点同时也是$H$的顶点，所以选择$xOy$极角序最小的点。这一类点均属于某个平面。若这一类点有多个则选取该平面上极角序最小的点，如果还有多个则选取最远的点。

