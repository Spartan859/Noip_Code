#include<bits/stdc++.h>
using namespace std;
int main(){
	set<string> s;
	set<string>::iterator it;
	s.insert("zombie");
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		if(s.count(a)!=0) s.insert(b);
		if(s.count(b)!=0) s.insert(a);
	}
	cout<<s.size();
	return 0;
}
