#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define M 25
using namespace std;
ll n,m,mod;
char t[M];
ll nxt[M];
void get_nxt(char *a){
    ll len=strlen(a+1);
    for(ll i=2,j=0;i<=len;i++){
        while(j>0&&a[j+1]!=a[i]) j=nxt[j];
        if(a[j+1]==a[i]) j++;
        nxt[i]=j;
    }
} 

ll match(ll j,char c){
    while(j>0&&t[j+1]!=c) j=nxt[j];
    if(t[j+1]==c) j++;
    return j;
}
struct matrix{
    ll x[N][N];
    void set(ll p){
        if(p==0){
            for(ll i=0;i<m;i++) for(ll j=0;j<m;j++) x[i][j]=0;
        }else{
            for(ll i=0;i<m;i++) for(ll j=0;j<m;j++) x[i][j]=0;
            for(ll i=0;i<m;i++) x[i][i]=1;
        }
    }
    void print(){
        for(ll i=0;i<m;i++){
            for(ll j=0;j<m;j++){
                printf("%lld ",x[i][j]);
            }
            printf("\n");
        }
    }
    friend matrix operator * (matrix a,matrix b){
        matrix ans;
        ans.set(0);
        for(ll i=0;i<m;i++){
            for(ll j=0;j<m;j++){
                for(ll k=0;k<m;k++){
                    ans.x[i][j]+=a.x[i][k]*b.x[k][j]%mod;
                    ans.x[i][j]%=mod;
                }
            }
        }
        return ans;
    }
};
matrix ksm(matrix x,ll k){
    matrix ans;
    ans.set(1);
    while(k){
        if(k&1) ans=ans*x;
        x=x*x;
        k>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&mod);
    scanf("%s",t+1);
    get_nxt(t);
    matrix tp,ans;
    tp.set(0);
    for(ll j=0;j<m;j++){
        for(char ch='0';ch<='9';ch++){
            ll k=match(j,ch);
            tp.x[j][k]++;
        }
    }
    ans=ksm(tp,n);
    ll res=0;
    for(ll j=0;j<m;j++){
        res+=ans.x[0][j];
        res%=mod;
    }
    printf("%lld\n",res);
    return 0;
}
