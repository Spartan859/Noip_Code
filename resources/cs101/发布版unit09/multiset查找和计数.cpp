#include<iostream>
#include<set> //����set�� 
using namespace std;
int main() {
	multiset<int> s;  //�������������multiset 
	multiset<int>::iterator it;	//��������� 
	s.insert(6); 	 
	cout<<s.count(6)<<endl;	//����6�ĸ��� 
	s.insert(6); 	
	cout<<s.count(6)<<endl;
	s.insert(6); 	
	cout<<s.count(6)<<endl;	
	cout<<s.count(7)<<endl;
	return 0;
}



