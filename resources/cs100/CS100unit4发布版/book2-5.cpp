#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		int c=0;
		for(int j=0;j<s.size();j++)
			if(s[j]==s[i]) c++;
		if(c==1) {
			cout<<s[i];
			return 0;
		}
	}
	cout<<"no";
	return 0;
}
