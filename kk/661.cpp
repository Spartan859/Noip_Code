#include<bits/stdc++.h>
using namespace std;
double L,u,v;
int main(){
	cin>>L>>u>>v;
	cout<<fixed<<setprecision(2)<<max(100.00-(L*2)/(u+v),0.00)<<endl;
	return 0;
}
