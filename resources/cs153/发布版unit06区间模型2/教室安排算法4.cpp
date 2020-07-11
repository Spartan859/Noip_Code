#include<bits/stdc++.h>
#define N 205
using namespace std;
struct dd{int s,t;};
bool cmp(const dd& a,const dd& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
dd d[N];
int main(){
	int n,m,i,j,x[N],cnt=0;
	cin>>n>>m;	
	for(i=0;i<n;i++) cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<cnt;j++)
			if(d[i].s>=x[j]) break;
		if(j<cnt) x[j]=d[i].t;
		else x[cnt++]=d[i].t;
	}
	if(cnt<=m) cout<<"逃过一劫，继续上区间模型";
	else if(cnt>m&&cnt<m+3) cout<<cnt-m<<'/'<<3;
	else if(cnt>=m+3) cout<<"Mike Chen被终结了"; 
	return 0;
}


