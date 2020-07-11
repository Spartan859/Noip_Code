#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> s;
	multiset<int>::iterator it;
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.erase(1);
	for(it=s.begin();it!=s.end();it++) cout<<*it<<' ';
	return 0;
}
