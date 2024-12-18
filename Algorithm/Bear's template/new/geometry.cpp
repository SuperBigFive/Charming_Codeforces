#include <bits/stdc++.h>
#define Clr(a,b) memset(a,b,sizeof(a));
#define Fill(a,b) generate(a.begin(), a.end(), [](){return b;})
#define Count(a,b) count_if(a.begin(), a.end(), [](int a##_param){return a##_param == b;})
#define mp(a,b) make_pair(a,b)
#define Rep(i,a,b) for(int i = a, i##_end = b; i <= i##_end; i ++)
#define Cnt(i,a,b) for(int i = a, i##_end = b; i >= i##_end; i --)

#define PREC 2

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> T gcd(T a, T b) {return b?gcd(b,a%b):a;}

template<typename T> T sqr(T a) {return a*a;}



typedef double GeometryType;

struct vec {
    typedef GeometryType T;
    T x, y;
    vec () {}
    vec (T x, T y): x(x), y(y) {}
    vec operator + (const vec& a) const {
        return vec(x + a.x, y + a.y);
    }
    vec operator - (const vec& a) const {
        return vec(x - a.x, y - a.y);
    }
    vec operator * (const T& a) const {
        return vec(a*x, a*y);
    }
    friend vec operator * (const T& a, const vec& b) {
        return vec(a*b.x, a*b.y);
    }
    vec operator / (const T& a) const {
        return vec(x/a, y/a);
    }
    T operator * (const vec& a) const {
        return x*a.x + y*a.y;
    }
    T operator / (const vec& a) const {
        return x*a.y - y*a.x;
    }
    T sqr() const {
        return (*this)*(*this);
    }
    T mag() const {
        return sqrt(this->sqr());
    }
    friend istream& operator >> (istream& is, vec& v) {
        return is >> v.x >> v.y;
    }
    friend ostream& operator << (ostream& os, const vec& v) {
        return os << "(" << v.x << "," << v.y << ")";
    }
    #define COMP_COORD
    //#define COMP_ANGLE
    #ifdef COMP_COORD
    bool operator < (const vec& b) const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
    bool operator == (const vec& b) const {
        return x == b.x && y == b.y;
    }
    #endif //COMP_COORD

    #ifdef COMP_ANGLE
    float quad() const {
        if(x == 0 && y == 0) return 0;
        if(y == 0){
            if(x > 0) return 0.5;
            else return 2.5;
        }
        if(x == 0) {
            if(y > 0) return 1.5;
            else return 3.5;
        }
        if(x > 0) {
            if(y > 0) return 1;
            else return 4;
        } else {
            if(y > 0) return 2;
            else return 3;
        }
    }
    bool cmp(const vec& i) const {
        float a = this->quad(), b = i.quad();
        if(a != b) return a < b;
        return this->cross(i) > 0;
    }
    bool same(const vec& i) const {
        return this->quad() == i.quad() && this->cross(i) == 0;
    }
    bool operator < (const vec& i) const {
        return this->cmp(i);
    }
    bool operator > (const vec& i) const {
        return i < (*this);
    }
    bool operator == (const vec& i) const {
        return same(i);
    }
    #endif // COMP_ANGLE
};

struct seg {
    typedef GeometryType T;
    vec p, v;
    seg() {}
    seg(vec p1, vec p2): p(p1), v(p2-p1) {}
    T mag() {
        return v.mag();
    }
    T dist(vec t) const {
        return abs((t-p)/v)/t.mag();
    }
    T dist2 (vec t) const {
        return sqr((t-p)/v)/t.sqr();
    }
    bool parallel(const seg& b) const {
        return ((this->v)/(b.v)) == 0;
    }
    vec inter(const seg& b) const {
        return (this->p)+(this->v)*((b.v/(this->p - b.p))/(this->v/b.v));
    }
    vec operator * (const seg& b) const {
        return this->inter(b);
    }
    bool between(const seg& b) const {
        T a = v/(b.p - p), z = v/((b.p + b.v) - p);
        if(a == 0 || z == 0) return true;
        return (a<0) ^ (z<0);
    }
    bool operator / (const seg& b) const{
        return this->between(b) && b.between(*this);
    }
};

struct poly : vector<vec> {
    typedef GeometryType T;

    void add(vec a) {
        this->push_back(a);
    }
    template<typename... T> void add(vec a, T... args) {
        this->push_back(a);
        add(args...);
    }

    poly() {}
    template<typename... T> poly(T... args) {
        add(args...);
    }

    T area() {
        T r = 0;
        Rep(i,0,this->size()-2) {
            r += (*this)[i]/(*this)[i+1];
        }
        r += ((*this)[this->size()-1]/(*this)[0]);
        return abs(r)/2;
    }
    #ifdef COMP_COORD
    poly convex() {
        sort(this->begin(), this->end());
        poly r;
        Rep(i,0,this->size()-1) {
            while(r.size() >= 2 && 
                ((*this)[i]-r[r.size()-2])/(r[r.size()-1]-r[r.size()-2])>=0)
                r.pop_back();
            r.add((*this)[i]);
        }
        int m = r.size();
        Cnt(i,this->size()-2,0) {
            while(r.size() >= (size_t)(1 + m) && 
                ((*this)[i]-r[r.size()-2])/(r[r.size()-1]-r[r.size()-2])>=0)
                r.pop_back();
            r.add((*this)[i]);
        }
        r.pop_back();
        return r;
    }
    #endif //COMP_COORD

    #ifdef COMP_ANGLE

    #endif
};
 
struct dyconvex {
private:
	set<vec> s;
public:
	dyconvex(){}
	void init(vec* p)
	/**
	only allow 3 points in the array p[]:p[0]~p[2]
	*/
	{
		for(int i = 0;i < 3;i ++)
			s.insert(p[i]);
		int cnt = 0;
		for(auto i = s.begin();i!=s.end();i ++)
			p[cnt++] = *i;
		if( (p[2]-p[0])/(p[1]-p[0]) >= 0 )
			s.erase( s.find(p[1]) );
	}
	bool query(vec p) {
		auto it = s.lower_bound(p);
		if(it==s.end())return false;
		if(it!=s.begin()) {
			auto ft = it;ft--;
			vec v1 = (*it)-(*ft),v2 = p-(*ft);
			if(v1/v2>=0)return true;
			else return false;
		}
		else {
			if((*it)==p)return true;
			return false;
		}
	}
	void insert(vec p)
	{
		s.insert(p);
		auto it = s.find(p);
		auto ft = it, bk = it;
		if(ft!=s.begin())
		{
			ft--;
			while(ft!=s.begin())
			{
				auto ff = ft;ff--;
				vec v1 = *it-*ff,v2 = *ft-*ff;
				if(v1/v2>=0)
					s.erase(ft);
				else break;		
				ft = ff;
			}
		}
		if(bk!=s.end())
		{
			bk++;
			while(bk!=s.end())
			{
				auto bb = bk;bb++;
				if(bb==s.end())break;
				vec v1 = *bb-*it,v2 = *bk-*it;
				if(v1/v2>=0)
					s.erase(bk);
				else break;	
				bk = bb;
			}
		}
	}
};

poly HalfPlane(vector<seg> v) {
    poly r;
    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(PREC);

    // Sample
    vec a(0,0), b(0,1), c(1,0), d(1,1);

    poly p(a,b,c,d);
    p = p.convex();
    cout << p.area() << endl;

    cin >> a;
    cout << a;

    return 0;
}
