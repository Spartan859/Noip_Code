#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> s;
	s.insert(8); s.insert(8);
	s.insert(6); s.insert(6); 
	multiset<int>::iterator it;
	it=s.end(); it--;
	cout<<*it<<endl;
	return 0;
}

