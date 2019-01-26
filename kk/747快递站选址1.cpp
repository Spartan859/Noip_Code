//不想用计数排序，勿喷。 
#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,x[N],ans;
int main(){
	freopen("location1.in","r",stdin);
	freopen("location1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	sort(x+1,x+n+1);
	int exp=x[n/2+1];
	for(int i=1;i<=n;i++) ans+=abs(exp-x[i]);
	printf("%d\n",ans);
	return 0;
}
