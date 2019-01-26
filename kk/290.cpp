#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	string ins;
	set<string> s;
	set<string>::iterator it;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ins;
		if(ins[0]=='+'){
			ins.erase(0,1);
			s.insert(ins);
		}
		else if(ins[0]=='-'){
			ins.erase(0,1);
			s.erase(ins); 
		}
	}
	for(it=s.begin();it!=s.end();it++) cout<<*it<<endl;
	return 0;
}
