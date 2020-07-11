#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> s;
	multiset<int>::iterator it;
	int n,L,cost=0; 
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>L; s.insert(L);
	}
	while(s.size()>1){
		it=s.begin(); 
		int a=*it; s.erase(it);
		it=s.begin(); 
		int b=*it; s.erase(it);
		s.insert(a+b);	
		cost += a+b;	
	}
	cout<<cost<<endl;	
	return 0;
}

