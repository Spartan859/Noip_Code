#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll x[N],n,T,cnt,pos,cnt2,cnt3;
bool lr;

int main(){
	freopen("blood.in","r",stdin);
	freopen("blood.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(x,0,sizeof(x));cnt=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld",x+i);
			if(x[i]!=0) cnt++;
		} x[0]=x[n];
		if(cnt==n){
			lr=1;pos=1;
			while(1){
				if(lr&&x[pos-1]==1&&x[pos]==1){
					cout<<"YES"<<endl;
					break;
				}
				if(lr==0&&x[pos-1]==1&&x[pos]==1){
					cout<<"NO"<<endl;
					break;
				}
				if(x[pos-1]!=1){
					x[pos-1]=1;
					--pos;
					if(pos==0) pos=n;
					lr^=1;
					break;
				}
				x[pos]=1;
				++pos;
				if(pos==n+1) pos=1;
				lr^=1;
			}
		}
		else{
			cnt2=cnt3=0;
			for(ll i=n;i>=1;i++)
				if(x[i]!=0) cnt2++;
				else break;
			for(ll i=1;i<=n;i++)
				if(x[i]!=0) cnt3++;
				else break;
			if((cnt2%2)||(cnt3%2)){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
