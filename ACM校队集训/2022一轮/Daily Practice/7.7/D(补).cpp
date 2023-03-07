#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define Point Vector
#define eps 1e-5
using namespace std;
const int maxn = 1e5 + 5;

//——————————————————————————————//
/*定义点/向量，重载运算符*/
struct Vector {
	double x, y;
	Vector (double a = 0, double b = 0) : x (a), y (b) {}
};

Vector operator + (Vector a,Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a,Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a,double p) { return Vector(a.x * p, a.y * p); }
Vector operator / (Vector a,double p) { return Vector(a.x / p,a.y / p); }

//——————————————————————————————//
/*内积、外积、向量模长、两点间的距离、三点两边叉乘*/ 
double dot (Vector a, Vector b) {return a.x * b.x + a.y * b.y;}
double cross (Vector a, Vector b) {return a.x * b.y - a.y * b.x;}
double length (Vector a) {return sqrt (a.x * a.x + a.y * a.y);}
double dist (Point a, Point b) {return length (a - b);}
double multiply (Point a, Point b, Point c) {return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);}

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
	int p_siz;
	Point p[100];
	Polygon (int a = 0) : p_siz (a) {}
};

//——————————————————————————————//
/*方向向量转换为单位向量、判断向量平行、判断点在直线哪边*/
/*判断线段是否相交、两直线交点、多边形周长、面积、判断点是否在线段上*/
/*求点到直线的垂足、求点关于某直线的对称点、求线段之间的距离*/ 
Vector trans (Vector s) {return s / length (s);}
inline bool isParallel (Vector a, Vector b) {return a.x * b.y == a.y * b.x;}
bool whichSide (Line a, Point b) {return cross (a.s, b - a.s) > 0;}
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
	double tmp = cross(b.s, c) / cross(a.s, b.s);
	return a.p + a.s * tmp;
} 
double cal_c (Polygon a) {
	Point b, c;
	double res = 0;
	b = a.p[1];
	for (int i = 1; i <= a.p_siz; ++i) {
		c = a.p[i % a.p_siz + 1];
		res += length (b - c);
		b = c;
	}
	return res;
}
double cal_s (Polygon a) {
	double res = 0;
	for (int i = 2; i <= a.p_siz; ++i) {
		res += cross (a.p[i] - a.p[1], a.p[i + 1] - a.p[1]);
	}
	return res / 2;
}
//判断点是否在线段上
bool onSegment (Segment a, Point b) {return (abs (multiply (a.p1, a.p2, b) < eps) && (b.x - a.p1.x) * (b.x - a.p2.x) <= 0 && (b.y - a.p1.y) * (b.y - a.p2.y) <= 0) ? true : false;} 
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
double MinSegmentDist (Segment a, Segment b) {
	if (SegmentIntersect (a, b)) return 0;
	else {
		double res = LONG_MAX;
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

Point p[maxn];
int unmatch[maxn];

void charming () {
	int n, tot = 0;
	cin >> n;
	double x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		p[i].x = x, p[i].y = y;
	}
	if (n <= 4) {
		cout << "YES" << endl;
		return;
	}
	int now;
	Line l;
	bool ok = false;
	for (int i = 1; i <= 50 && !ok; ++i) {
		now = rand () % n + 1;
		for (int j, k = 1; k <= 50 && !ok; ++k) {
			j = rand () % n + 1;
			if (j == now) continue;
			l.p = p[now], l.s = p[now] - p[j];
			for (int a = 1, b; a <= 50 && !ok; ++a) {
				b = rand () % n + 1;
				if (b == now || b == j) continue;
				if (isParallel (l.s, p[now] - p[b])) ok = true;;
			} 
		}
		if (i == 50) {
			cout << "NO" << endl;
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i != now && !isParallel (l.s, p[now] - p[i])) 
			unmatch[++tot] = i;
	}
	Line l2;
	l2.p = p[unmatch[1]], l2.s = p[unmatch[2]] - p[unmatch[1]];
	for (int i = 3; i <= tot; ++i) {
		if (!isParallel (l2.s, p[unmatch[i]] - p[unmatch[1]])) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl; 
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
