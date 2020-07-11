#include<iostream>
#include<string>
using namespace std;
string n;
long long temp;
int main(){
	cin>>n;
	for(int i=0;i<n.size();i++)
	    if(n[i]=='6') temp++;
	for(int j=0;j<temp;j++) cout<<'6';
	if(temp==0) cout<<"Unhappy";
	return 0;
}
