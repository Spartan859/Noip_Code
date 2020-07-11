#include<iostream>
using namespace std;
double tot;
int i,k;
int main(){
	//cout<<1+1./2+1./3+1./4+1./5+1./6+1./7+1./8+1./9+1./10+1./11;
	cin>>k;
	tot=0;
	for(i=1;tot<=k;i++)
		tot+=1.0/i;	
	cout<<i-1<<endl;
	return 0;
}
/*
1+1/2  > 1
1+1/2+1/3+1/4  >2
1+1/2+1/3+1/4+1/5+1/6+1/7+1/8+1/9+1/10+1/11 >3

*/
