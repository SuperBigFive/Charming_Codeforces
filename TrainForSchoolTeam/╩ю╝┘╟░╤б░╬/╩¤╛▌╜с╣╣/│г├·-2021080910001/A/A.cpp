#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
const int maxk=100+5;

ll n,key_num,power,m,tot;
ll match[maxn],cnt[maxk];
ll sugar[maxn],key[maxk],Key[maxk],sum_key[maxk][maxn];
bool flag[maxk];

void move_same();
void match_Key();
void figure_sum();
ll find_key(int l,int r);

int main(){
	scanf("%d%d%d%d",&n,&key_num,&power,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&sugar[i]);
	}
	ll val,ccnt=0;
	for(int i=1;i<=key_num;++i){
		scanf("%lld",&val);
		if(val) key[++ccnt]=val;
		//scanf("%lld",&key[i]);
	}
	key_num=ccnt;
	move_same();
	match_Key();
	figure_sum();
	/*
	printf("\n");
	for(int i=1;i<=tot;++i){
		printf("%lld ",Key[i]); 
	}
	printf("\n");
	for(int i=1;i<=n;++i){
		printf("%d ",match[i]);
	}
	printf("\n");
	for(int i=1;i<=tot;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",sum_key[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	ll l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",find_key(l,r));
	}
	return 0;
}

void move_same(){
	sort(key+1,key+1+key_num);
	for(int i=1;i<=key_num;++i){
		if(!flag[i]){
			ll temp;
			for(int j=i+1;j<=key_num;++j){
				temp=key[j];
				while(temp>=key[i]){
					if(temp==key[i]){
						flag[j]=true;
						break;
					}
					temp/=power;
				}
			}
		}
	}
	for(int i=1;i<=key_num;++i){
		if(!flag[i]) Key[++tot]=key[i];
	}
}
void match_Key(){
	ll lb=Key[1],ub=Key[tot];
	ll temp1,temp2;
	for(int i=1;i<=n;++i){
		temp1=sugar[i];
		while(temp1>ub){
			temp1/=power;
		}
		while(temp1>=lb){
			temp2=lower_bound(Key+1,Key+tot+1,temp1)-Key;
			if(Key[temp2]==temp1) {
				match[i]=temp2;
				break;
			}
			temp1/=power;
		}
	}
}
void figure_sum(){
	for(int i=1;i<=n;++i){
		sum_key[match[i]][i]=++cnt[match[i]];
		for(int j=1;j<=tot;++j){
			sum_key[j][i]=cnt[j];
		}
	}
}
ll find_key(int l,int r){
	ll ans=0;
	for(int i=1;i<=tot;++i){
		if(sum_key[i][r]-sum_key[i][l-1]>0) ++ans;
	}
	return ans;
}
