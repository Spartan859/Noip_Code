#include<iostream>
#include<set> //����set�� 
using namespace std;
int main() {
	multiset<int> s;  //�������������multiset 
	multiset<int>::iterator it;	//��������� 
	s.insert(8);	//����Ԫ�� 
	s.insert(6); s.insert(6); s.insert(6);
	s.erase(s.find(6));  	//ɾ��һ��6
	for(it=s.begin();it!=s.end();it++)	 
		cout<<*it<<' '; 
	cout<<endl;
	s.erase(6);  	//ɾ������6
	for(it=s.begin();it!=s.end();it++)	 
		cout<<*it<<' ';
	return 0;
}



