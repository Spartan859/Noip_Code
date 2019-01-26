#include<bits/stdc++.h>
using namespace std;
string small(string a){
	for(int i=0;i<=a.length();++i)
		a[i]=tolower(a[i]);
	return a;
}
int main(){
	string s,se;
	getline(cin,se);
	getline(cin,s);
	se=small(se);
	s=small(s);
	se=' '+se+' ';
	s=' '+s+' ';
    if (s.find(se)==string::npos){
        cout<<-1<<endl;
    }
    else{
    	int ax=s.find(se);
    	int bx=s.find(se),ans=0;
    	while(bx!=string::npos){
    		++ans;
    		bx=s.find(se,bx+1);
		}
		cout<<ans<<' '<<ax<<endl;
	}
	return 0;
}
