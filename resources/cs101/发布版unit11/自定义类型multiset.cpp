#include<iostream>
#include<set> //����set�� 
using namespace std;
struct hero{int rp; string name;};//�Զ���hero���� 
struct cmp{//�Զ���cmp()�ȽϹ��� 
	bool operator()(const hero& a,const hero& b)const{
		return a.rp>b.rp||a.rp==b.rp&&a.name<b.name;
	}
};
int main() {
	multiset<hero,cmp> s;  //����multiset�ͱȽϹ��� 
	multiset<hero,cmp>::iterator it;	//��������� 
	hero x1={70,"SUPERMAN"};
	hero x2={70,"CAPTAINAMERICA"};
	hero x3={100,"DORAEMON"};
	hero x4={70,"SUPERMAN"};
	s.insert(x1);	s.insert(x2);
	s.insert(x3); 	s.insert(x4); 
	for(it=s.begin();it!=s.end();it++)	 
		cout<<(*it).name<<" "<<(*it).rp<<endl;
	return 0;
}






