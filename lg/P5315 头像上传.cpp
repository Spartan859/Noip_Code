#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,L,G,x,y;
double lg2G,lgtmp;
ll tmp,cf2[25];
int main(){
	scanf("%lld %lld %lld",&n,&L,&G);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&x,&y);
		if(x>G||y>G){
			while(max(x,y)>G){
				x/=2;y/=2;
			}
		}
		if(x<L||y<L) puts("Too Young\n");
		else if(x!=y) puts("Too Simple\n");
		else puts("Sometimes Naive\n");
	}
	return 0;
}
