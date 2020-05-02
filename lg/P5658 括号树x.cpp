#include<bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,ans;
ll ndw[N],pre[N],f[N],stk[N],top,SUM[N];
int main(){
	scanf("%lld",&n);
	getchar();
	for(ll i=1;i<=n;i++){
		char c=getchar();
		if(c=='('){
			ndw[i]=1;
			stk[++top]=i;
			f[i]=-100;
		}
		else{
			ndw[i]=0;
			if(top!=0) pre[i]=stk[top]-1,--top;
			else f[i]=-100;
		}	
	}
	//for(ll i=1;i<=n;i++) cout<<pre[i]<<' ';
	for(ll i=1;i<=n;i++){
		if(f[i]!=-100) f[i]=max(f[pre[i]],0)+1;
		SUM[i]=SUM[i-1]+max(f[i],0);
		ans^=i*SUM[i];
	} 
	printf("%lld\n",ans);
	return 0;
}

