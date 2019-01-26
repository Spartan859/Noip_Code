#include<iostream>
#include<set>
#include<string>
using namespace std;
int main(){
	string ins,temp;
	int ans=0;
	multiset<string> s;
	multiset<string>::iterator it;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>ins;
	    s.insert(ins);
	}
	while(1){
		it=s.begin();
		if(s.count(*it)==0) break;
		ans+=s.count(*it)/2;
		s.erase(*it);
	}
	cout<<ans;
	return 0;
}
