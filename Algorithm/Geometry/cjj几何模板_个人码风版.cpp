#include <bits/stdc++.h>
using namespace std;

using point_t = long double; // 全局数据类型，可修改为 long long 等
using ull = unsigned long long;
using ld = long double;

constexpr point_t INF = 1e18;
constexpr point_t eps = 1e-8;
constexpr long double PI = 3.1415926535897932384l;

// 点与向量
template<typename T> struct point {
  T x, y;

  bool operator ==(const point &a) const {return (abs(x - a.x) <= eps && abs(y - a.y) <= eps);}
  bool operator <(const point &a) const {if (abs(x - a.x) <= eps) return y < a.y - eps; return x < a.x - eps;}
  bool operator >(const point &a) const {return !(*this < a || *this == a);}
  point operator +(const point &a) const {return {x + a.x, y + a.y};}
  point operator -(const point &a) const {return {x - a.x, y - a.y};}
  point operator -() const {return {-x, -y};}
  point operator *(const T k) const {return {k * x, k * y};}
  point operator /(const T k) const {return {x / k, y / k};}
  T operator *(const point &a) const {return x * a.x + y * a.y;}  // 点积
  T operator ^(const point &a) const {return x * a.y - y * a.x;}  // 叉积，注意优先级
  int toleft(const point &a) const {const auto t = (*this) ^ a; return (t > eps) - (t < -eps);}  // to-left 测试
  T len2() const {return (*this) * (*this);}  // 向量长度的平方
  T dis2(const point &a) const {return (a - (*this)).len2();}  // 两点距离的平方

  // 涉及浮点数
  long double len() const {return sqrtl(len2());}  // 向量长度
  long double dis(const point &a) const {return sqrtl(dis2(a));}  // 两点距离
  long double ang(const point &a) const {return acosl(max(-1.0l, min(1.0l, ((*this)*a) / (len()*a.len()))));}  // 向量夹角
  point rot(const long double rad) const {return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)};}  // 逆时针旋转（给定角度）
  point rot(const long double cosr,const long double sinr) const {return {x * cosr - y * sinr,x * sinr + y *cosr};}  // 逆时针旋转（给定角度的正弦与余弦）
};

using Point = point<point_t>;

// 极角排序
struct argcmp {
  bool operator ()(const Point &a, const Point &b) const {
    const auto quad = [](const Point &a) {
      if (a.y < -eps) return 1;
      if (a.y > eps) return 4;
      if (a.x < -eps) return 5;
      if (a.x > eps) return 3;
      return 2;
    };
    const int qa = quad(a), qb = quad(b);
    if (qa != qb) return qa < qb;
    const auto t = a ^ b;
    // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
    return t > eps;
  }
};

// 直线
template<typename T> struct line {
  point<T> p, v;  // p 为直线上一点，v 为方向向量

  bool operator ==(const line &a) const {return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0;}
  int toleft(const point<T> &a) const {return v.toleft(a - p);} // to-left 测试
  bool operator <(const line &a) const { // 半平面交算法定义的排序
    if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
    return argcmp()(v, a.v);
  }

  // 涉及浮点数
  point<T> inter(const line &a) const {return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v));} // 直线交点
  long double dis(const point<T> &a) const {return abs(v ^ (a - p)) / v.len();} // 点到直线距离
  point<T> proj(const point<T> &a) const {return p + v * ((v * (a - p)) / (v * v));} // 点在直线上的投影
  point<T> refl(const point<T> &a) const {point<T> p = proj(a); return p * 2 - a;} // 点在直线上的反射点
};

using Line = line<point_t>;

//线段
template<typename T> struct segment {
  point<T> a, b;

  bool operator <(const segment &s) const {return make_pair(a, b) < make_pair(s.a, s.b);}

  // 判定性函数建议在整数域使用

  // 判断点是否在线段上
  // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
  int is_on(const point<T> &p) const {
    if (p == a || p == b) return -1;
    return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
  }

  // 判断线段直线是否相交
  // -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
  int is_inter(const line<T> &l) const {
    if (l.toleft(a) == 0 || l.toleft(b) == 0) return -1;
    return l.toleft(a) != l.toleft(b);
  }
  
  // 判断两线段是否相交
  // -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
  int is_inter(const segment<T> &s) const {
    if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
    const line<T> l{a, b - a}, ls{s.a, s.b - s.a};
    return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
  }

  // 点到线段距离
  long double dis(const point<T> &p) const {
    if ((p - a) * (b - a) < -eps || (p - b) * (a - b) < -eps) return min(p.dis(a), p.dis(b));
    const line<T> l{a, b - a};
    return l.dis(p);
  }

  // 两线段间距离
  long double dis(const segment<T> &s) const {
    if (is_inter(s)) return 0;
    return min({dis(s.a), dis(s.b), s.dis(a), s.dis(b)});
  }
};

using Segment = segment<point_t>;

// 多边形
template<typename T> struct polygon {
  vector<point<T> > p;  // 以逆时针顺序存储

  size_t nxt(const size_t i) const {return i == p.size() - 1 ? 0 : i + 1;}
  size_t pre(const size_t i) const {return i == 0 ? p.size() - 1 : i - 1;}
  
  // 回转数
  // 返回值第一项表示点是否在多边形边上
  // 对于狭义多边形，回转数为 0 表示点在多边形外，否则点在多边形内
  pair<bool,int> winding(const point<T> &a) const {
    int cnt = 0;
    for (size_t i = 0; i < p.size(); ++i) {
      const point<T> u = p[i], v = p[nxt(i)];
      if (abs((a - u) ^ (a - v)) <= eps && (a - u) * (a - v) <= eps) return {true, 0};
      if (abs(u.y - v.y) <= eps) continue;
      const Line uv = {u, v - u};
      if (u.y < v.y - eps && uv.toleft(a) <= 0) continue;
      if (u.y > v.y + eps && uv.toleft(a) >= 0) continue;
      if (u.y < a.y - eps && v.y >= a.y - eps) ++cnt;
      if (u.y >= a.y - eps && v.y < a.y - eps) --cnt;
    }
    return {false, cnt};
  }

  // 多边形面积的两倍
  // 可用于判断点的存储顺序是顺时针或逆时针
  T area() const {
    T sum = 0;
    for (size_t i = 0; i < p.size(); ++i) sum += p[i] ^ p[nxt(i)];
    return sum;
  }

  // 多边形的周长
  long double circ() const {
    long double sum = 0;
    for (size_t i = 0; i < p.size(); ++i) sum += p[i].dis(p[nxt(i)]);
    return sum;
  }
};

using Polygon = polygon<point_t>;

//凸多边形
template<typename T> struct convex: polygon<T> {
  
  // 判断点是否在凸多边形内
  // 复杂度 O(logn)
  // -1 点在多边形边上 | 0 点在多边形外 | 1 点在多边形内
  int is_in(const point<T> &a) const {
    const auto &p = this -> p;
    if (p.size() == 1) return a == p[0] ? -1 : 0;
    if (p.size() == 2) return segment<T>{p[0], p[1]}.is_on(a) ? -1 : 0; 
    if (a == p[0]) return -1;
    if ((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0]) == 1) return 0;
    const auto cmp = [&](const Point &u,const Point &v) {return (u - p[0]).toleft(v - p[0]) == 1;};
    const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
    if (i == 1) return segment<T> {p[0], p[i]}.is_on(a) ? -1 : 0;
    if (i == p.size() -1 && segment<T> {p[0], p[i]}.is_on(a)) return -1;
    if (segment<T> {p[i - 1], p[i]}.is_on(a)) return -1;
    return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
  }
};

using Convex = convex<point_t>;

// 圆
struct Circle {
  Point c;
  long double r;

  bool operator ==(const Circle &a) const {return c == a.c && abs(r - a.r) <= eps;}
  long double circ() const {return 2 * PI * r;}  // 周长
  long double area() const {return PI * r * r;}  // 面积

  // 点与圆的关系
  // -1 圆上 | 0 圆外 | 1 圆内
  int is_in(const Point &p) const {
    const long double d = p.dis(c); 
    return abs(d - r) <= eps ? -1 : d < r - eps;
  }

  // 直线与圆关系
  // 0 相离 | 1 相切 | 2 相交
  int relation(const Line &l) const {
    const long double d = l.dis(c);
    if (d > r + eps) return 0;
    if (abs(d - r) <= eps) return 1;
    return 2;
  }

  // 圆与圆关系
  // -1 相同 | 0 相离 | 1 外切 | 2 相交 | 3 内切 | 4 内含
  int relation(const Circle &a) const {
    if (*this == a) return -1;
    const long double d = c.dis(a.c);
    if (d > r + a.r + eps) return 0;
    if (abs(d - r - a.r) <= eps) return 1;
    if (abs(d - abs(r - a.r)) <= eps) return 3;
    if (d < abs(r - a.r) - eps) return 4;
    return 2;
  }

  // 直线与圆的交点
  vector<Point> inter(const Line &l) const {
    const long double d = l.dis(c);
    const Point p = l.proj(c);
    const int t = relation(l);
    if (t == 0) return vector<Point> ();
    if (t == 1) return vector<Point> {p};
    const long double k = sqrt(r * r - d * d);
    return vector<Point> {p - (l.v / l.v.len()) * k, p + (l.v / l.v.len()) * k};
  }

  // 圆与圆交点
  vector<Point> inter(const Circle &a) const {
    const long double d = c.dis(a.c);
    const int t = relation(a);
    if (t == -1 || t == 0 || t == 4) return vector<Point> ();
    Point e = a.c - c; e = e / e.len() * r;
    if (t == 1 || t == 3) {
      if (r * r + d * d - a.r * a.r >= -eps) return vector<Point> {c + e};
      return vector<Point> {c - e};
    }
    const long double costh = (r * r + d * d - a.r * a.r) / (2 * r * d), sinth = sqrt(1 - costh * costh);
    return vector<Point> {c + e.rot(costh, -sinth), c + e.rot(costh,sinth)};
  }

  // 过圆外一点圆的切线
  vector<Line> tangent(const Point &a) const {
    const int t = is_in(a);
    if (t == 1) return vector<Line> ();
    if (t == -1) {
      const Point v = {-(a - c).y, (a - c).x};
      return vector<Line>{{a, v}};
    }
    Point e = a - c; e = e / e.len() * r;
    const long double costh = r / c.dis(a), sinth = sqrt(1 - costh * costh);
    const Point t1 = c + e.rot(costh, -sinth), t2 = c + e.rot(costh, sinth);
    return vector<Line> {{a, t1 - a}, {a, t2 - a}};
  }

  // 两圆的公切线
  vector<Line> tangent(const Circle &a) const {
    const int t = relation(a);
    vector<Line> lines;
    if (t == -1 || t == 4) return lines;
    if (t == 1 || t == 3) {
      const Point p = inter(a)[0], v = {-(a.c - c).y, (a.c - c).x};
      lines.push_back({p, v});
    }
    const long double d = c.dis(a.c);
    const Point e = (a.c - c) / (a.c - c).len();
    if (t <= 2) {
      const long double costh = (r - a.r) / d, sinth = sqrt(1 - costh * costh);
      const Point d1 = e.rot(costh, -sinth), d2 = e.rot(costh, sinth);
      const Point u1 = c + d1 * r, u2 = c + d2 * r, v1 = a.c + d1 * a.r, v2 = a.c + d2 * a.r;
      lines.push_back({u1, v1 - u1}); lines.push_back({u2, v2 - u2});
    }
    if (t == 0) {
      const long double costh = (r + a.r) / d, sinth = sqrt(1 - costh * costh);
      const Point d1 = e.rot(costh, -sinth), d2 = e.rot(costh, sinth);
      const Point u1 = c + d1 * r, u2 = c + d2 * r, v1 = a.c - d1 * a.r, v2 = a.c - d2 * a.r;
      lines.push_back({u1, v1 - u1}); lines.push_back({u2, v2 - u2});
    }
    return lines;
  }

  // 三角形内切圆
  Circle getIncircle(Point p0, Point p1, Point p2) {
    Line l0 = {p0, p1 - p0}, l1 = {p0, p2 - p0};
    Line l2 = {p1, p0 - p1}, l3 = {p1, p2 - p1};
    long double ang0 = l0.v.ang(l1.v);
    Line l4 = {p0, l0.v.rot(l0.v.toleft(l1.v) * ang0 / 2)};
    long double ang1 = l2.v.ang(l3.v);
    Line l5 = {p1, l2.v.rot(l2.v.toleft(l3.v) * ang1 / 2)};
    Point o = l4.inter(l5);
    long double r = l0.dis(o);
    return Circle{o, r};
  }

  // 三角形外切圆
  Circle getCircumscribedCircle(Point p0, Point p1, Point p2) {
    Point mid_a = p0 + ((p1 - p0) / 2);
    Point mid_b = p0 + ((p2 - p0) / 2);
    Line line_a = {p0, p1 - p0}, line_b = {p0, p2 - p0};
    Point c = Line{mid_a, -line_a.v.y, line_a.v.x}.inter(Line{mid_b, -line_b.v.y, line_b.v.x});
    long double r = c.dis(p0);
    return Circle{c, r};
  }

  // 两个圆的面积并
  long double area_inter(Circle c) {
    std::vector<Circle> C = {*this, c};
    int t = C[0].relation(C[1]);
    long double inter_area = 0;
    if (t == -1) inter_area = C[0].area();
    else if (t == 3 || t == 4) inter_area = std::min(C[0].area(), C[1].area());
    else if (t == 0 || t == 1) inter_area = 0;
    else {
      std::vector<Point> inter_point = C[0].inter(C[1]);
      assert(int(inter_point.size()) == 2);
      long double d = inter_point[0].dis(inter_point[1]);
      Point mid = (inter_point[0] + inter_point[1]) / 2;
      if (mid > std::min(C[0].c, C[1].c) && mid < std::max(C[0].c, C[1].c)) {
	      for (int i = 0; i < 2; ++i) {
	        long double h = sqrtl(C[i].r * C[i].r - (d / 2) * (d / 2));
	        long double theta = PI - 2 * acosl(d / 2 / C[i].r);
	        inter_area += C[i].area() * theta / PI / 2 - d * h / 2;
	      }
	    }
	    if (C[0].c > std::min(C[1].c, mid) && C[0].c < std::max(C[1].c, mid)) std::swap(C[0], C[1]);
	    if (C[1].c > std::min(C[0].c, mid) && C[1].c < std::max(C[0].c, mid)) {
	    	long double h = sqrtl(C[0].r * C[0].r - (d / 2) * (d / 2));
        long double theta = PI - 2 * acosl(d / 2 / C[0].r);
        inter_area += C[0].area() * theta / PI / 2 - d * h / 2;
        h = sqrtl(C[1].r * C[1].r - (d / 2) * (d / 2));
        theta = PI - 2 * acosl(d / 2 / C[1].r);
        inter_area += C[1].area() - (C[1].area() * theta / PI / 2 - d * h / 2);
	    }
    }
    return inter_area;
  }
};

// 点集的凸包
// Andrew 算法，复杂度 O(nlogn)
Convex convexhull(vector<Point> p) {
  vector<Point> st;
  if (p.empty()) return Convex{st};
  sort(p.begin(), p.end());
  const auto check = [](const vector<Point> &st, const Point &u) {
    const auto back1 = st.back(), back2 = *prev(st.end(), 2);
    return (back1 - back2).toleft(u - back1) <= 0;
  };
  for (const Point &u : p) {
    while (st.size() > 1 && check(st, u)) st.pop_back();
    st.push_back(u);
  }
  size_t k = st.size();
  p.pop_back(); reverse(p.begin(), p.end());
  for (const Point &u : p) {
    while (st.size() > k && check(st, u)) st.pop_back();
    st.push_back(u);
  }
  st.pop_back();
  return Convex{st};
}

// 平面最近点对, 返回距离的平方
// 分治算法, 复杂度 O(nlogn)
point_t ClosestPair(std::vector<Point> p) {

  std::function<point_t(std::vector<int>, std::vector<int>)> Solve
  = [&](std::vector<int> p_x, std::vector<int> p_y) {
    int n = p_x.size(), m = n / 2;
    if (!n) return INF;
    
		point_t mid_x = p[p_x[m]].x;
    std::vector<int> lef_p_x, lef_p_y, rig_p_x, rig_p_y;
    for (int i = 0; i < n; ++i) {
      if (p[p_x[i]].x < mid_x) lef_p_x.emplace_back(p_x[i]);
      else if (p[p_x[i]].x > mid_x) rig_p_x.emplace_back(p_x[i]);
      
      if (p[p_y[i]].x < mid_x) lef_p_y.emplace_back(p_y[i]);
      else if (p[p_y[i]].x > mid_x) rig_p_y.emplace_back(p_y[i]);
    }

    point_t h = std::min(Solve(lef_p_x, lef_p_y), Solve(rig_p_x, rig_p_y));
    std::vector<int> mid_p_y;
    for (int i = 0; i < n; ++i) {
      if ((p[p_y[i]].x - mid_x) * (p[p_y[i]].x - mid_x) >= h) continue;
      else mid_p_y.emplace_back(p_y[i]);
    }

    point_t ans = h;
    for (int i = 0, j = 0, siz = mid_p_y.size(); i < siz; ++i) {
      while (j < siz && (p[mid_p_y[i]].y - p[mid_p_y[j]].y) * (p[mid_p_y[i]].y - p[mid_p_y[j]].y) >= ans) ++j;
      for (int k = j; k < i; ++k) ans = std::min(ans, p[mid_p_y[i]].dis2(p[mid_p_y[k]]));
    }

    return ans;
  };

	int n = p.size();
  std::vector<int> p_x(n), p_y(n);
  std::iota(p_x.begin(), p_x.end(), 0);
  std::iota(p_y.begin(), p_y.end(), 0);
  sort(p_x.begin(), p_x.end(), 
	[&](int a, int b) {return p[a].x < p[b].x;});
	sort(p_y.begin(), p_y.end(), 
	[&](int a, int b) {return p[a].y < p[b].y;});

  return Solve(p_x, p_y);
}

// 平面最近点对, 随机做法, 期望复杂度 O(n)
// long double ClosestPair(std::vector<Point> points) {
//   std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
//   std::shuffle(points.begin(), points.end(), rnd);
  
// 	struct HashTable {
// 	  const int N = 1e6 + 5, MOD = 1e6 + 5;
// 	  int tot;
// 	  std::vector<int> key, nxt, head, mem;
// 	  std::vector<std::vector<int> > val;
	
// 	  HashTable() {
// 	    tot = 0;
// 	    key = nxt = std::vector<int> (MOD);
// 	    head = std::vector<int> (N, -1);
// 	    val = std::vector<std::vector<int> > (MOD);
// 	  }
	
// 	  void clear() {
// 	    for (int x : mem) head[x] = -1;
// 	    for (int i = 0; i < tot; ++i) key[i] = nxt[i] = 0, val[i].clear();
// 	    tot = 0, mem.clear();
// 	  }
	
// 	  void Insert(ull k, int v) {
// 	    k %= N; mem.emplace_back(k);
// 	    for (int i = head[k]; ~i; i = nxt[i]) {
// 	      if (key[i] == k) {val[i].emplace_back(v); return;}
// 	    }
// 	    assert(tot < MOD);
// 	    key[tot] = k, val[tot].emplace_back(v), nxt[tot] = head[k], head[k] = tot++;
// 	  }
	
// 	  std::vector<int> Query(ull k) {
// 	    k %= N;
// 	    for (int i = head[k]; ~i; i = nxt[i]) {
// 	      if (key[i] == k) return val[i];
// 	    }
// 	    return std::vector<int> ();
// 	  };  
// 	};

//   std::function<ull(ld, ld, ld)> getBlockIdx 
//   = [&](ld x, ld y, ld s) {return (ull(floor(x / s + eps)) << 30) + ull(floor(y / s + eps));};

//   HashTable ht;
//   long double ans = INF;

//   int n = points.size();
//   for (int i = 0; i < n && ans > 0; ++i) {
//     long double x = points[i].x, y = points[i].y;
//     ull blo_idx = getBlockIdx(x, y, ans);
//     long double new_ans = INF;
//     for (int dx = -1; dx <= 1; ++dx) {
//       for (int dy = -1; dy <= 1; ++dy) {
//         ull new_blo_idx = getBlockIdx(x + dx * ans, y + dy * ans, ans);
//         for (int p_idx : ht.Query(new_blo_idx)) {
//           new_ans = std::min(new_ans, points[i].dis(points[p_idx]));
//         }
//       }
//     }
    
//     if (new_ans < ans) {
//       ans = new_ans;
//       ht.clear();
//       for (int j = 0; j <= i; ++j) {
//         ull cur_blo_idx = getBlockIdx(points[j].x, points[j].y, ans);
//         ht.Insert(cur_blo_idx, j);
//       }
//     }
//     else ht.Insert(blo_idx, i);
//   }
  
//   return ans;
// }