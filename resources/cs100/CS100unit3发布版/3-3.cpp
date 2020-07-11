#include<iostream>
#include<string>
using namespace std;
string n;
int main(){
	cin>>n;
	if(n[0]==45){
		cout<<"-";
		for(int j=n.size()-1;j>=1;j--) {
		if(n[n.size()-1]==48)
		n.erase(n.size()-1);
		else
		cout<<n[j];
		
}
	}
	else{
	for(int i=n.size()-1;i>=0;i--) {
		if(n[n.size()-1]==48)
		n.erase(n.size()-1);
		else
		cout<<n[i];
}
}
    return 0;
}









