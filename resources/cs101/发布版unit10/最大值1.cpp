#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> s;
	s.insert(8); s.insert(8);
	s.insert(6); s.insert(6); 
	int biggest=*(s.rbegin());
	cout<<biggest<<endl;
	return 0;
}

