#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>

using namespace std;
#define ll long long

static char buf[1<<22], *s=buf;
inline void read(int &x) {
	while(isspace(*s)) ++s;
	x=*s++^'0';
	while(isdigit(*s)) x=x*10+(*s++^'0');
}
char obuf[1<<20], *ooh=obuf;
inline void print(int x) {
	static int buf[30], cnt;
	if (x==0) *ooh++='0';
	else {
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) *ooh++=buf[cnt--];
	}
}

const int N = 1<<18;
const double Pi=acos(-1);
int n, m, p, l, k;
struct cp{
	double a, b;
	inline void operator +=(const cp &rhs){ a+=rhs.a, b+=rhs.b;}
	inline cp operator +(const cp &rhs)const{ return (cp){a+rhs.a, b+rhs.b};}
	inline cp operator -(const cp &rhs)const{ return (cp){a-rhs.a, b-rhs.b};}
	inline cp operator *(const cp &rhs)const{ return (cp){a*rhs.a-b*rhs.b, a*rhs.b+b*rhs.a};}
	inline cp operator *(const double rhs)const{ return (cp){a*rhs, b*rhs};}
	inline cp operator ~()const{ return (cp){a, -b};}
} a[N], b[N], c[N], d[N], f[N], g[N], h[N], w[N];
inline int Get(int n){ int p=1; while(p<=n) p<<=1; return p;}
inline void DFT_(cp *f, int n){
	for( int i=0, j=0; i<n; ++i){
		if(i>j) swap(f[i], f[j]);
		for( int k=n>>1; (j^=k)<k; k>>=1);
	}
	for( int i=1; i<n; i<<=1) for( int j=0; j<n; j+=i<<1)
		for( int k=j; k<j+i; ++k){
			cp t=w[i+k-j]*f[k+i];
			f[k+i]=f[k]-t, f[k]+=t;
		}
}
inline void DFT(cp *f, int n){
	if(n==1) return;
	n>>=1;
	static cp a[N/2];
	for( int i=0; i<n; ++i) a[i]=(cp){f[i<<1].a, f[i<<1|1].a};
	DFT_(a, n);
	for( int i=0; i<n; ++i){
		cp q=~a[(n-i)&(n-1)], x=(a[i]+q)*.5, y=(a[i]-q)*(cp){0, -.5}, t=y*w[n+i];
		f[i]=x+t, f[n+i]=x-t;
	}
}
inline void IDFT(cp *f, int n){
	if(n==1) return;
	reverse(f+1, f+n), n>>=1;
	static cp a[N/2];
	for( int i=0; i<n; ++i)
		a[i]=(f[i]+f[i+n])*.5 + (f[i]-f[i+n])*(cp){0, .5}*w[n+i];
	DFT_(a, n);
	double k=1./n;
	for( int i=0; i<n; ++i) f[i<<1]=(cp){a[i].a*k, 0}, f[i<<1|1]=(cp){a[i].b*k, 0};
}



int main() {
	fread(s, 1, 1<<22, stdin);
	read(n), read(m), read(p), l=Get(n+m);
	for( int i=0, x=0; i<=n; ++i) read(x), a[i].a=x>>15, b[i].a=x&32767;
	for( int i=0, x=0; i<=m; ++i) read(x), c[i].a=x>>15, d[i].a=x&32767;
	for( int i=1; i<l; i<<=1){
		w[i]=(cp){1, 0};
		for( int j=1; j<i; ++j)
			w[i+j]=((j&31)==1?(cp){cos(Pi*j/i), sin(Pi*j/i)}:w[i+j-1]*w[i+1]);
	}
	DFT(a, l), DFT(b, l), DFT(c, l), DFT(d, l);
	for( int i=0; i<l; ++i)
		f[i]=a[i]*c[i], g[i]=a[i]*d[i]+c[i]*b[i], h[i]=b[i]*d[i];
	IDFT(f, l), IDFT(g, l), IDFT(h, l);
	for( int i=0; i<=n+m; ++i, *ooh++=' ')
		print((((ll)(f[i].a+.5)%p<<30)+((ll)(g[i].a+.5)<<15)+(ll)(h[i].a+.5))%p);
	return fwrite(obuf, 1, ooh - obuf, stdout), 0;
}