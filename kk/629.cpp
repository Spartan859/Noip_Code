#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,ans;
int main(){
	//freopen("rib.in","r",stdin);
	//freopen("rib.out","w",stdout);
	scanf("%lld",&n);
	if(n<=3){
	    printf("0");
	    return 0;
	}
	ans=n*(n-1)*(n-2)*(n-3)/24;
	printf("%lld\n",ans);
	return 0;
}
