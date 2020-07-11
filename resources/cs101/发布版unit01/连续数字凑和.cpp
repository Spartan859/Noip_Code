#include<iostream>
#define N 5000
using namespace std;
int n,m,i,j,base,s[N],d[N];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>d[i];
	s[0]=d[0];
	for(i=1;i<n;i++) s[i]=s[i-1]+d[i];
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(i==0) base=0;//防止数组越界 
			else base=s[i-1];
			if(s[j]-base==m){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	cout<<"No"<<endl;	
	return 0;
}
	
