#include<bits/stdc++.h>
using namespace std;
int main(){
	map<char,char> d;
	string a,b;
	getline(cin,a);
	getline(cin,b);
	b=b+b[0];
	for(int i=0;i<b.size()-1;i++){
		d[b[i]]=b[i+1];
	}
	for(int i=0;i<a.size();i++){
		if(d.count(a[i])) cout<<d[a[i]];
		else cout<<a[i];
	}
	return 0;
}
