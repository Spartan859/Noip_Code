#include<iostream>
#include<string> 
#include<set> //����set��
using namespace std;
int main() {
	set<string> s;  //�������������set 
	set<string>::iterator it;	//��������� 
	string word;
	while(cin>>word) s.insert(word);
	for(it=s.begin();it!=s.end();it++)	 
		cout<<*it<<endl;
	return 0;
}




