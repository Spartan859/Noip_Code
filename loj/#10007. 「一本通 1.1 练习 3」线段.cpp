#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
struct xd{
	int a,b;//lft,rght
	friend bool operator < (const xd &x,const xd &y){
		return x.b<y.b||x.b==y.b&&x.a<y.a;
	}
}xds[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&xds[i].a,&xds[i].b);
	sort(xds+1,xds+n+1);
	int nowrt=0,ans=0;
	for(int i=1;i<=n;i++)
		if(xds[i].a>=nowrt) ans++,nowrt=xds[i].b;
	printf("%d\n",ans);
	return 0;
}

