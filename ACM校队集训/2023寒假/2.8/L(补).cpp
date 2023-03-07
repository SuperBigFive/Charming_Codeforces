#include <bits/stdc++.h>
#define T_ double
#define ll long long
#define ull unsigned long long
#define ld long double
#define Point Vector
#define pb push_back
using namespace std;
const int maxn = 1e5 + 5;
const T_ eps = 1e-8;

int t;

//——————————————————————————————//
/*定义点/向量，重载运算符*/
struct Vector {
	T_ x, y;
	Vector (T_ a = 0, T_ b = 0) : x (a), y (b) {}
	T_ operator ^ (const Vector &a) const {return x * a.y - y * a.x;}
	int toleft (Vector a) {const auto t = (*this) ^ a; return (t > eps) - (t < -eps);}
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
	int toleft (const Point a) {return s.toleft(a-p);}
}; 

struct Segment {
	Point p1;
	Point p2;
	Segment (Point a, Point b) : p1 (a), p2 (b) {}
	Segment () {}
};

struct Tria {
	Vector p[3];
	T_ get_len (Vector &a, Vector &b) {
		return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	T_ get_s () {
		T_ a = get_len (p[0], p[1]);
		T_ b = get_len (p[1], p[2]);
		T_ c = get_len (p[0], p[2]);
		T_ p = (a + b + c) / 2;
		return sqrt (p * (p - a) * (p - b) * (p - c));
	}
};

inline bool isParallel (Vector a, Vector b) {return a.x * b.y == a.y * b.x;}

Point GetIntersectionPoint (Line a, Line b) {
	Vector c = a.p - b.p;
	T_ tmp = cross(b.s, c) / cross(a.s, b.s);
	return a.p + a.s * tmp;
}
//判断点是否在线段上
bool onSegment (Segment a, Point b) {return ((abs (multiply (a.p1, a.p2, b)) <= eps) 
&& ((min (a.p1.x, a.p2.x) <= b.x) && (max (a.p1.x, a.p2.x) >= b.x)) 
&& ((min (a.p1.y, a.p2.y) <= b.y) && (max (a.p1.y, a.p2.y) >= b.y)));} 

void init () {}

void charming (int case_cnt) {
	init ();
	Point p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;
	Line l1 (p1, p2 - p1), l2 (p3, p4 - p3);
	Point p0 = GetIntersectionPoint (l1, l2);
	if (onSegment ({p1, p2}, p3) || onSegment ({p1, p2}, p4)) {
		cout << "Case " << case_cnt << ": inf" << endl;
		return;
	}
	else if (onSegment ({p3, p4}, p1) || onSegment ({p3, p4}, p2)) {
		cout << "Case " << case_cnt << ": 0" << endl;
		return;
	}
	else if (!isParallel (l1.s, l2.s) && onSegment ({p3, p4}, p0)) {
		cout << "Case " << case_cnt << ": 0" << endl;
		return;
	}
	else if (!isParallel (l1.s, l2.s) && onSegment ({p1, p2}, p0)) {
		cout << "Case " << case_cnt << ": inf" << endl;
		return;
	}
	l1 = {p1, p4 - p1}, l2 = {p2, p3 - p2};
	p0 = GetIntersectionPoint (l1, l2);
	if (onSegment ({p1, p4}, p0)) {
		l1 = {p1, p3 - p1}, l2 = {p2, p4 - p2};
		p0 = GetIntersectionPoint (l1, l2);
	}
	if (isParallel (l1.s, l2.s)) {
		Line l5 = {p1, p2 - p1};
		if (isParallel (l1.s, l5.s)) cout << "Case " << case_cnt << ": 0" << endl;
		else cout << "Case " << case_cnt << ": inf" << endl;
		return;
	}
	Tria tria1, tria2;
	tria1.p[0] = p1, tria1.p[1] = p2, tria1.p[2] = p0;
	tria2.p[0] = p3, tria2.p[1] = p4, tria2.p[2] = p0;
	T_ s1 = tria1.get_s(), s2 = tria2.get_s ();
	if (s1 > s2) {
		cout << "Case " << case_cnt << ": inf" << endl;
		return;
	}
	else cout << setprecision (15) << "Case " << case_cnt << ": " << s1 << endl;
}

signed main () {
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}