#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getnum(ll nn,ll mm){
	ll ans=0,num=1;
	while(num<nn*mm) num*=2,++ans;
	return ans;
}//1073741822926258175
ll getnum2(ll x){
	ll ans;
	ll max=0;
	ll c=getnum(1,(int)x);
	//printf("%lld %lld\n",x,(ll)pow(2,(int)c));
	if(x<10000){
		for(int i=0;i<x;++i){
			ans=i ^ (i >> 1);
			if(ans>max) max=ans;
		}
		return max;
	}
	//if(x-pow(2,(int)c-1)<pow(2,(int)c-2)) return pow(2,(int)c)-1;
	int i=pow(2,(int)(c-1))-1;
	ll temp=x;
	ll d=c;
	if(temp-pow(2,(int)(c-1))<pow(2,(int)(c-2))) return pow(2,c)-1;
	else{
		temp-=pow(2,(int)(d-1));
		--d;
		if(temp-pow(2,(d-1))>=pow(2,d-2)){
			i+=pow(2,(int)(d-2))-1;
			temp-pow(2,(d-1));
			--d;
			if(temp-pow(2,(int)(d-1))<pow(2,(int)(d-2))) return pow(2,c)-1;
		}
		else i+=pow(2,(int)(d-3))-1;
	}
	for(i;i<x;++i){
		ans=i ^ (i >> 1);
		if(ans>max) max=ans;
	}
	//printf("%lld\n",c);
	return max;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m;
		scanf("%lld%lld",&n,&m);//int no = clock();
		ll temp;
		if(n>m){
			temp=n;
			n=m;
			m=temp;
		}
		ll km,K;
		K=getnum(n,m);
		km=getnum(1,m);
		ll diff=K-km;
		ll b;
		if(pow(2,diff)>=n) b=getnum2(n);
		else b=0;
		ll ans=((m-1)<<diff)+b;
		printf("%lld\n",ans);
		//cout << clock() - no << "ms" << endl;
	}
	return 0;
}
