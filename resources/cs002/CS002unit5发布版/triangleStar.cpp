#include<iostream>
using namespace std;
int i,j,n;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++)
			cout<<" ";
		for(j=0;j<i+i+1;j++)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}
