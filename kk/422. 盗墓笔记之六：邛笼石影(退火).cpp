#include<bits/stdc++.h>
#define M 105
#define ERR 0.01
#define ll long long
#define T 50
using namespace std;
ll m;
double w,h,x[M],y[M];
double px,py,d,theta,tx,ty,td;
double fnx,fny,fn;
inline double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	cin>>w>>h>>m;
	for(ll i=1;i<=m;i++) cin>>x[i]>>y[i];
	for(ll k=1;k<=T;k++){
		px=(rand()%1000+1.0)/1000.0*w,py=(rand()%1000+1.0)/1000.0*h;
		d=1e9+1.0;
		for(ll i=1;i<=m;i++) d=min(d,dist(px,py,x[i],y[i]));
		for(double dt=1.0*max(w,h)/sqrt(m);dt>ERR;dt*=0.9){
			for(ll i=1;i<=T;i++){
				theta=(rand()%1000+1.0)/1000.0*360;
				tx=max(0.0,min(w,px+dt*cos(theta)));
				ty=max(0.0,min(h,py+dt*sin(theta)));
				td=1e9+1.0;
				for(ll j=1;j<=m;j++) td=min(td,dist(tx,ty,x[j],y[j]));
				if(td>d) px=tx,py=ty,d=td;
			}
		}
		if(d>fn) fn=d,fnx=px,fny=py;
	}
	cout<<fixed<<setprecision(1)<<fnx<<' '<<fny<<endl;
	return 0;
}
