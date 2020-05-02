#include<bits/stdc++.h>
#define MOD 1000000007
#define N 100
#define ll long long
using namespace std;

struct Matrix{
    ll a[N+5][N+5];
    Matrix() {}
    Matrix(ll val){
        memset(a,0,sizeof a);
        for(ll i=0;i<=N;i++)
            a[i][i]=val;
    }
    ll* operator [] (ll i){
        return a[i];
    }
    friend Matrix operator * (Matrix x,Matrix y){
        Matrix z(0);
        for(ll i=0;i<=N;i++)
            for(ll j=0;j<=N;j++)
                for(ll k=0;k<=N;k++)
                    z[i][j]=(z[i][j]+x[i][k]*y[k][j])%MOD;
        return z;
    }
    friend Matrix Quick_Power(Matrix x,ll y){
    	Matrix re(1);
    	while(y){
        	if(y&1) re=re*x;
        	x=x*x; y>>=1;
    	}
    	return re;
	}
};

ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	Matrix A(0);
	Matrix f;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			scanf("%lld",&A.a[i][j]);
	f=Quick_Power(A,k);
	for(ll i=1;i<=n;i++,cout<<endl)
		for(ll j=1;j<=n;j++){
			printf("%lld",f.a[i][j]);
			if(j!=n) cout<<' ';
		}
	return 0;
}

