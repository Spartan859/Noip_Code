#include<iostream>
#include<algorithm>
#define N 200000
using namespace std;
struct point{
	int x,y,key;
};
point d[N],tower[2];
int n,i,best,t0,t1,tot;
int cmp(const point &a, const point &b){
	return a.key<b.key;
}
int sq_dist(const point &a, const point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	cin>>tower[0].x>>tower[0].y>>tower[1].x>>tower[1].y;
	cin>>n; 
	for(i=0;i<n;i++) {
		cin>>d[i].x>>d[i].y;
		d[i].key=sq_dist(d[i],tower[0]);
	}
	sort(d,d+n,cmp);
	best=t0=d[n-1].key;  t1=0;
	for(i=n-1;i>=0;i--){
		t1=max(t1, sq_dist(d[i],tower[1]) );
		if(i==0) t0=0; else t0=d[i-1].key; 
		tot=t0+t1;
		if(tot<best) best=tot;		
	}
	cout<<best<<endl;
	return 0;
}
