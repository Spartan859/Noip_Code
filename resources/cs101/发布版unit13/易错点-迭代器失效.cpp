#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> s;
	multiset<int>::iterator it;
	s.insert(8); s.insert(9);
	s.insert(6); s.insert(7); 
	for(it=s.begin();it!=s.end();it++){
		int x=*it;
		cout<<x<<endl;
		if(x>=100) break;
		s.erase(it);
		s.insert(x+10);
	}
	return 0;
}

