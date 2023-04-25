#include <bits/stdc++.h>
#define T_ ll
#define ll long long
#define ull unsigned long long
#define ld long double
#define Point Vector
#define pb push_back
using namespace std;
const int maxn = 1e5 + 5;
const T_ eps = 1e-8;

//——————————————————————————————//
/*定义点/向量，重载运算符*/
struct Vector {
	T_ x, y;
	Vector (T_ a = 0, T_ b = 0) : x (a), y (b) {}
};

Vector operator + (Vector a,Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a,Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a,T_ p) { return Vector(a.x * p, a.y * p); }
Vector operator / (Vector a,T_ p) { return Vector(a.x / p,a.y / p); }

//——————————————————————————————//
/*内积、外积、向量模长、两点间的距离、三点两边叉乘*/ 
inline T_ dot (Vector a, Vector b) {return a.x * b.x + a.y * b.y;}
inline T_ cross (Vector a, Vector b) {return a.x * b.y - a.y * b.x;}
inline T_ length (Vector a) {return sqrt (a.x * a.x + a.y * a.y);}
inline T_ dist (Point a, Point b) {return length (a - b);}
inline T_ multiply (Point a, Point b, Point c) {return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);}

//——————————————————————————————//
/*定义直线、线段、多边形*/
struct Line {
	Point p;
	Vector s;
	Line (Point a, Vector b) : p (a), s (b) {}
	Line () {}
}; 

struct Segment {
	Point p1;
	Point p2;
	Segment (Point a, Point b) : p1 (a), p2 (b) {}
	Segment () {}
};

struct Polygon {
	//顶点默认逆序 
	int siz;
	vector <Point> p;
	Polygon (int a = 0) : siz (a) {}
};

//——————————————————————————————//
/*方向向量转换为单位向量、判断向量平行、判断点在直线哪边*/
/*判断线段是否相交、两直线交点、多边形周长、面积、判断点是否在线段上*/
/*求点到直线的垂足、求点关于某直线的对称点、求线段之间的距离*/ 
Vector trans (Vector s) {return s / length (s);}
inline bool isParallel (Vector a, Vector b) {return a.x * b.y == a.y * b.x;}
bool whichSide (Line a, Point b) {return cross (a.s, b - a.p) > 0;}

bool SegmentIntersect (Segment a, Segment b) {
	return ((max (a.p1.x, a.p2.x) >= min (b.p1.x, b.p2.x))&&//排斥实验 
		(max (b.p1.x, b.p2.x) >= min (a.p1.x, a.p2.x))&& 
		(max (a.p1.y, a.p2.y) >= min(b.p1.y, b.p2.y))&& 
		(max (b.p1.y, b.p2.y) >= min(a.p1.y, a.p2.y))&& 
		((multiply (a.p1, a.p2, b.p1)) * multiply (a.p1, a.p2, b.p2) <= 0) &&          
		((multiply (b.p1, b.p2, a.p1)) * multiply (b.p1, b.p2, a.p2) <= 0)); 
}

Point GetIntersectionPoint (Line a, Line b) {
	Vector c = a.p - b.p;
	T_ tmp = cross(b.s, c) / cross(a.s, b.s);
	return a.p + a.s * tmp;
}
 
T_ cal_c (Polygon a) {
	Point b, c;
	T_ res = 0;
	b = a.p[1];
	for (int i = 0; i < a.p.size (); ++i) {
		c = a.p[i % a.siz + 1];
		res += length (b - c);
		b = c;
	}
	return res;
}
T_ cal_s (Polygon a) {
	T_ res = 0;
	for (int i = 2; i < a.siz; ++i) {
		res += cross (a.p[i] - a.p[1], a.p[i + 1] - a.p[1]);
	}
	return res / 2;
}
//判断点是否在线段上
bool onSegment (Segment a, Point b) {return ((abs (multiply (a.p1, a.p2, b)) <= eps) && ((min (a.p1.x, a.p2.x) <= b.x) && (max (a.p1.x, a.p2.x) >= b.x)) && ((min (a.p1.y, a.p2.y) <= b.y) && (max (a.p1.y, a.p2.y) >= b.y)));} 
//移动直线上的特定点到垂足处 
Point GetFootPointLine (Line a, Point b) {return a.p + a.s * (dot ((b - a.p), a.s));}
Point GetFootPointSegment (Segment a, Point b) {
	if (!(multiply (a.p1, a.p2, b))) return abs (b.x - a.p1.x) <= abs (b.x - a.p2.x) ? a.p1 : a.p2;
	return a.p1 + (a.p2 - a.p1) * (dot ((b - a.p1), (a.p2 - a.p1))) / (length (a.p2 - a.p1) * length (a.p2 - a.p1));}
//找某点关于某直线的对称点 
Point ReflectionPoint (Line a, Point b) {
	Point tmp = GetFootPointLine (a, b);
	tmp.x = 2.0 * tmp.x - b.x;
	tmp.y = 2.0 * tmp.y - b.y;
	return tmp;
}
//计算线段之间的距离 
T_ MinSegmentDist (Segment a, Segment b) {
	if (SegmentIntersect (a, b)) return 0;
	else {
		T_ res = LONG_MAX;
		Point tmp;
		tmp = GetFootPointSegment (b, a.p1);
		if (!onSegment (b, tmp)) tmp = dist (tmp, b.p1) <= dist (tmp, b.p2) ? b.p1 : b.p2;
		res = min (res, dist (tmp, a.p1));
		tmp = GetFootPointSegment (b, a.p2);
		if (!onSegment (b, tmp)) tmp = dist (tmp, b.p1) <= dist (tmp, b.p2) ? b.p1 : b.p2;
		res = min (res, dist (tmp, a.p2));
		tmp = GetFootPointSegment (a, b.p1);
		if (!onSegment (a, tmp)) tmp = dist (tmp, a.p1) <= dist (tmp, a.p2) ? a.p1 : a.p2;
		res = min (res, dist (tmp, b.p1));
		tmp = GetFootPointSegment (a, b.p2);
		if (!onSegment (a, tmp)) tmp = dist (tmp, a.p1) <= dist (tmp, a.p2) ? a.p1 : a.p2;
		res = min (res, dist (tmp, b.p2));
		return res;
	}
}
//——————————————————————————————//
/*极角排序*/
bool cmp (Point a, Point b) {return cross(a, b) ? cross (a, b) : a.x < b.x;} 
void angle_sort (Point *p, int num) {sort (p + 1, p + 1 + num, cmp);}

int n;
Point plot[105][3];
vector <Point> P;
map <Point, bool> exist;
Polygon figure;

void charming () {
	cin >> n;
	int x1, y1, x2, y2, x3, y3;
	for (int i = 1; i <= n; ++i) {
		cin >> plot[i][0].x >> plot[i][0].y;
		cin >> plot[i][1].x >> plot[i][1].y;
		cin >> plot[i][2].x >> plot[i][2].y;
		P.pb (plot[i][0]), P.pb (plot[i][1]), P.pb (plot[i][2]);
		exist[plot[i][0]] = true;
		exist[plot[i][1]] = true;
		exist[plot[i][2]] = true;
	}
	Segment a, b;
	Point c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 2; ++j) {
			a = {plot[i][j], plot[i][(j + 1) % 3]};
			for (int k = i + 1; k <= n; ++k) {
				for (int p = 0; p <= 2; ++p) {
					b = {plot[k][p], plot[k][(p + 1) % 3]};
					if (SegmentIntersect (a, b)) {
						c = GetIntersectionPoint ({a.p1, a.p1 - a.p2}, {b.p1, b.p1 - b.p2});
						if (!exist[c]) exist[c] = true;
						P.pb (c);
					}
				}
			}
		}
	}
}

signed main () {
	charming ();
	return 0;
}
