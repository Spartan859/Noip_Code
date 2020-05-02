#include<bits/stdc++.h>
#define N 1505
#define ll long long
using namespace std;
ll n;
ll mat[N][N];
void work(ll xa,ll ya,ll xb,ll yb){
	if(xa==xb&&ya==yb) return;
	for(ll i=xa;i<=xa+xb>>1;i++)
		for(ll j=ya;j<=ya+yb>>1;j++)
			mat[i][j]=0;
	work(xa+xb+1>>1,ya,xb,ya+yb>>1);
	work(xa+xb+1>>1,ya+yb+1>>1,xb,yb);
	work(xa,ya+yb+1>>1,xa+xb>>1,yb);		
} 
int main(){
	scanf("%lld",&n);
	ll tmp=pow(2,n);
	for(ll i=1;i<=tmp;i++)
		for(ll j=1;j<=tmp;j++) mat[i][j]=1;
	work(1,1,tmp,tmp);
	for(ll i=1;i<=tmp;i++,puts(""))
		for(ll j=1;j<=tmp;j++)
			printf("%lld ",mat[i][j]);
		
	return 0;
}
