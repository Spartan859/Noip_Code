#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> s;
	s.insert(9); s.insert(8);
	s.insert(6); s.insert(6); 
	int x=*(s.begin());
	s.erase(x);
	int ans=*(s.begin());
	cout<<ans<<endl;
	return 0;
}


