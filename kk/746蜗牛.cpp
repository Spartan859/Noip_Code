#include<bits/stdc++.h>
using namespace std;
int h,x,y,presh,ans;
int main(){
	freopen("snail.in","r",stdin);
	freopen("snail.out","w",stdout);
	scanf("%d %d %d",&h,&x,&y);
	if(y>=x&&x<h){printf("-1\n");return 0;}
	while(1){
		presh+=x;ans++;
		if(presh>=h) break;
		presh-=y;
	}
	printf("%d\n",ans);
	return 0;
} 
