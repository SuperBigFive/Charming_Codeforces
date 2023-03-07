#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=1e5+15;
const int sqn=sqrt(maxn);

int n,block,len;
int arr[maxn],temp[maxn],arr_deal[maxn],num[maxn];
int bl[maxn],cnt[sqn][maxn],temp_cnt[sqn][maxn];
int f[sqn][sqn];//f[i][j]表示在第i个分块和第j个分块之间的众数
//bl[i] 第i点所属分块编号
//cnt[i][j] 第j个点在前i个分块中的数量

void build_cnt();
void build_f();
int query(int l,int r);

int main(){
    scanf("%d",&n);
    block=2*sqrt(n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&arr[i]),temp[i]=arr[i];
        bl[i]=(i-1)/block+1;
    }
    sort(arr+1,arr+1+n);
    len=unique(arr+1,arr+1+n)-arr-1;
    for(int i=1;i<=n;++i) {
        arr_deal[i]=lower_bound(arr+1,arr+1+len,temp[i])-arr;
        ++temp_cnt[bl[i]][arr_deal[i]];//记录每个点在每个分块的数量
        //根据cnt[i][j]=cnt[i-1][j]+temp[i][j]求出cnt[][]
    }
    //for(int i=1;i<=n;++i) printf("B:%d;A:%d\n",temp[i],arr_deal[i]);
    build_cnt();
    build_f();
    /*for(int i=1;i<=bl[n];++i){
        for(int j=i;j<=bl[n];++j)
            printf("f[%d][%d]:%d  ",i,j,f[i][j]);
    }*/
    int l,r;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}

void build_cnt(){
    for(int i=1;i<=bl[n];++i){
        for(int j=1;j<=len;++j){
            cnt[i][j]=cnt[i-1][j]+temp_cnt[i][j];
            //printf("cnt[%d][%d]:%d\n",i,j,cnt[i][j]);
        }
    }
}
void build_f(){//f[i][j]:i~j的众数，它一定是f[i][j-1]的众数或者j-1分块里的某个数
    for(int i=1;i<=bl[n];++i){
        memset(num,0,sizeof num);
        int max_num=-1;
        int max_value=-1;
        for(int j=(i-1)*block+1;j<=n;++j){
            ++num[arr_deal[j]];
            if(num[arr_deal[j]]>max_value||(num[arr_deal[j]]==max_value&&arr_deal[j]<max_num)){
                max_num=arr_deal[j];
                max_value=num[arr_deal[j]];
            }
            if(bl[j+1]!=bl[j]) f[i][bl[j]]=max_num;
        }
    }
}
int query(int l,int r){
    int bll=bl[l],blr=bl[r];
    if(bll==blr||blr-bll==1){
        memset(num,0,sizeof num);
        int max_num=-1;
        int max_value=-1;
        for(int i=l;i<=r;++i){
            ++num[arr_deal[i]];
            if(num[arr_deal[i]]>max_value||(num[arr_deal[i]]==max_value&&arr_deal[i]<max_num)){
                max_num=arr_deal[i];
                max_value=num[arr_deal[i]];
            }
        }
        return arr[max_num];
    }
    else{
        int max_num=f[bll+1][blr-1];
        int max_value=cnt[blr-1][max_num]-cnt[bll][max_num];
        int ll=l,rr=bl[l]*block;
        memset(num,0,sizeof num);
        int all_num;
        for(int i=ll;i<=rr;++i){
            ++num[arr_deal[i]];
            all_num=num[arr_deal[i]]+cnt[blr-1][arr_deal[i]]-cnt[bll][arr_deal[i]];
            if(all_num>max_value||(all_num==max_value&&arr_deal[i]<max_num)){
                max_value=all_num;
                max_num=arr_deal[i];
            }
        }
        ll=(blr-1)*block+1,rr=r;
        for(int i=ll;i<=rr;++i){
            ++num[arr_deal[i]];
            all_num=num[arr_deal[i]]+cnt[blr-1][arr_deal[i]]-cnt[bll][arr_deal[i]];
            if(all_num>max_value||(all_num==max_value&&arr_deal[i]<max_num)){
                max_value=all_num;
                max_num=arr_deal[i];
            }
        }
        return arr[max_num];
    }
}

