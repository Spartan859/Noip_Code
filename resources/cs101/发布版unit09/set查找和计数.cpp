#include<iostream>
#include<set> //����set�� 
using namespace std;
int main() {
	set<int> s;  //�������������set 
	set<int>::iterator it;	//��������� 
	s.insert(6);
	s.insert(6);	
	cout<<s.count(6)<<endl; //����6�ĸ���
	cout<<s.count(7)<<endl; 
	return 0;
}




