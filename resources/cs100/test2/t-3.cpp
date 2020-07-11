#include<iostream>
using namespace std;
int main(){
	int x,m,i;
	double n;
	cin>>n>>x>>m;
	if(x>=n&&n*0.01>=m) cout<<0;
	for(i=0;x<n;i++){
		n*=1.01;
	    x+=m;
	    if(n*0.01>=m&&x<n){
	    	cout<<"Mission Impossible";
	    	break;
		}
	}
	if(n*0.01<m)
	    cout<<i;
	return 0;
}
