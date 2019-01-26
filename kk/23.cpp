#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<char> ms;
	multiset<char>::iterator it;
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++) ms.insert(s[i]);
	if(ms.count('(')==ms.count(')')) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
} 
