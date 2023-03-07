#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;

struct node{
    int Time;
    int pos;
    ll val;
}card[maxn],temp[maxn];
int n;
ll a[maxn],c[maxn],ans[maxn],Time[maxn];

int lowbit(int x);
void update(int pos,int val);
ll get_sum(int l,int r);
void cdq(int l,int r);

int main(){
    scanf("%d",&n);
    ll v;
    for(int i=1;i<=n;++i){
        scanf("%lld",&v);
        a[i]=v;
    }
    ll p;
    for(int i=1;i<=n;++i){
    	scanf("%lld",&p);
        Time[p]=i;
    }
    for(int i=1;i<=n;++i){
        card[i].val=a[i];
        card[i].pos=i;
        card[i].Time=Time[a[i]];
    }
    cdq(1,n);
    printf("%d\n",ans[1]);
    for(int i=2;i<=n;++i){
        ans[i]+=ans[i-1];
        printf("%lld\n",ans[i]);
    }
    return 0;
}

int lowbit(int x){
    return x&(-x);
}
void update(int pos,int val){
    while(pos<=n){
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
ll get_sum(int l,int r){
    ll suml=0;
    while(l>0){
        suml+=c[l];
        l-=lowbit(l);
    }
    ll sumr=0;
    while(r>0){
        sumr+=c[r];
        r-=lowbit(r);
    }
    return sumr-suml;
}
void cdq(int l,int r){
	if(l>=r) return;
    int mid=(l+r)/2;
    for(int i=l;i<=r;++i){
        temp[i]=card[i];
    }
    int ll=l,rr=mid+1,num=0;
    for(int i=l;i<=r;++i){
        if(temp[i].Time<=mid) card[ll++]=temp[i];
        else card[rr++]=temp[i];
    }
    for(ll=l,rr=mid+1;ll<=mid||rr<=r;){
        if(rr>r||ll<=mid&&card[ll].pos<card[rr].pos){
            update(card[ll].val,1);
            ++ll;
            ++num;
        }
        else{
            ans[card[rr].Time]+=num-get_sum(0,card[rr].val);
            ++rr;
        }
    }
    for(int i=l;i<=mid;++i){
        update(card[i].val,-1);
    }
    for(ll=mid,rr=r;ll>=l||rr>=mid+1;){
        if(rr<=mid||ll>=l&&card[ll].pos>card[rr].pos){
            update(card[ll].val,1);
            --ll;
        }
        else{
            ans[card[rr].Time]+=get_sum(0,card[rr].val);
            --rr;
        }
    }
    for(int i=mid;i>=l;--i){
        update(card[i].val,-1);
    }
    cdq(l,mid);
    cdq(mid+1,r);
}

