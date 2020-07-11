#include<iostream>
#include<string>
using namespace std;
int cnt;
string s;
int main(){
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9') cnt++;
	cout<<cnt;
	return 0;
}
