#include<iostream>
using namespace std;
char n1,n2,n3;
int main(){
	cin>>n1>>n2>>n3;
	cout<<char((n1-'a'+1)%26+'a')<<" ";
	cout<<char((n2-'a'+1)%26+'a')<<" ";
	cout<<char((n3-'a'+1)%26+'a')<<endl;
	return 0;
}
