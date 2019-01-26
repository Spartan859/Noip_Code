#include<bits/stdc++.h>
#define g 10
using namespace std;
int main(){
	double v,siga,t,xxt,xyt;
	cin>>v>>siga;
	t=v*cos(siga)/g;
	xxt=v*sin(siga)*t;
	xyt=g*t*t/2;
	cout<<xxt<<' '<<xyt<<endl;
	return 0;
} 
