#include<bits/stdc++.h>
#define INF 2e9
#define N 20005
using namespace std;
int n,d[N];
struct point{
	int x;
	int y;
};point p[N];
bool cmp(const point &a,const point &b){
	return a.x<b.x||a.x==b.x&&a.y>b.y;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>p[i].x>>p[i].y;
	sort(p,p+n,cmp);
	fill(d,d+n,INF);
	for(int i=0;i<n;i++)
		*upper_bound(d,d+n,-p[i].y)=-p[i].y;
	int cnt=lower_bound(d,d+n,INF)-d;
	cout<<cnt<<endl;
	return 0;
}
