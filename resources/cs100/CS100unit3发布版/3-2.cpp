#include<iostream>
#include<string>
using namespace std;
string n;
int main(){
	getline(cin,n);
	for(int i=0;i<n.length();++i){
		if(n[i]>=97&&n[i]<=121) n[i]=n[i]+1;
		if(n[i]==32) continue;
		if(n[i]==122) n[i]=97;
		
	}
	cout<<n;
	
	return 0;
}
