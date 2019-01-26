#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
double tmp;
ll xa,xb;
int main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	scanf("%lld %lld",&a,&b);
	tmp=a/(b*2);
	xa=floor(tmp);
	xb=floor(tmp+1);
	//if(xa==0) xa=1000;
	xa=(a-xa*b)*(xa+1);
	xb=(a-xb*b)*(xb+1);
	printf("%lld\n",max(xa,xb));
	return 0;
}
