#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
const double eps=1e-3;
struct point{
	double x,y,z;
}a[maxn];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	double r=1e9,T=1000.0,rate=0.999985;
	point p=(point){0.0,0.0,0.0};
	while(T>eps){
		double maxdis=0.0;
		int t=0;
		for(int i=1;i<=n;i++)
		if(dis(p,a[i])>maxdis)maxdis=dis(p,a[i]),t=i;
		r=min(r,maxdis);
		if(!t)break;
		p.x+=(a[t].x-p.x)*T/1000.0;
		p.y+=(a[t].y-p.y)*T/1000.0;
		p.z+=(a[t].z-p.z)*T/1000.0;
		T*=rate;
		cnt++;
	}
	printf("%.9lf",r);
	return 0;
}
