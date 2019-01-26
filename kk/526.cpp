#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,shiq,dei=8,ans;
	bool dx;
	double l;
	cin>>h>>l;
	if(l>=0) {
	    l+=7.5;
	    dx=true;
	}
	else{
		l*=-1;
		l+=7.5;
		dx=false;
	}
	l/=15;
	shiq=floor(l);
	if(dx==false) shiq*=-1;
	ans=h-(dei-shiq);
	if(ans<0) ans+=24;
	cout<<ans<<endl;
	return 0;
} 
