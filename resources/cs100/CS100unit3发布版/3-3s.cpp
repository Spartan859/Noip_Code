#include<iostream>
#include<string>
using namespace std;
string s;
int i,l;
int main(){
	cin>>s;
	if(s[0=='-']){
		cout<<'-';
		s.erase(0,1);
	}
	l=s.size();
	for(i=l-1;i>=1;i--)
	    if(s[i]!='0') break;
    for(;i>=0;i--)
        cout<<s[i];
    return 0;
}
