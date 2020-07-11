#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> s;
	multiset<int>::iterator it;
	int n,x; cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x; s.insert(x);
	}
	while(s.size()>1){
		it=s.end(); it--;
		int a=*it; s.erase(it);
		it=s.end(); it--;
		int b=*it; s.erase(it);
		s.insert(a*b+1);		
	}
	cout<<*(s.begin())<<endl;	
	return 0;
}

