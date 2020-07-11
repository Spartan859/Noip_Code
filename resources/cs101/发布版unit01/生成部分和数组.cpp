#include<iostream>
#define N 5
using namespace std;
int s[N],x[N],i;
int main(){
	for(i=0;i<N;i++) cin>>x[i];
	s[0]=x[0];
	for(i=1;i<N;i++) s[i]=s[i-1]+x[i];
	for(i=0;i<N;i++) cout<<s[i]<<' ';	
	return 0;
}
	
