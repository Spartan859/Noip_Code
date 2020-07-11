#include<iostream>
#include<string>
using namespace std;
string n;
int main(){
	getline(cin,n);
	for(int i=0;i<n.size();++i) {
		if(n[i]<='z'&&n[i]>='a') n[i]+='A'-'a';
		else if(n[i]<='Z'&&n[i]>='A') n[i]-='A'-'a';
		else continue;
}
    cout<<n;
    return 0;
}
