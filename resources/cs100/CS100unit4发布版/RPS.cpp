#include<iostream>
#include<string>
using namespace std;
string x1,x2;
int main(){
	cin>>x1>>x2;
	if(x1==x2)
		cout<<"Tie";
	else if(x1[0]=='R'&&x2[0]=='S'||x1[0]=='P'&&x2[0]=='R'||x1[0]=='S'&&x2[0]=='P')
		cout<<"Player1";
	else
		cout<<"Player2";	
	return 0;
}


