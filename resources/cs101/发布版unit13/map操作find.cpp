#include<iostream>
#include<map>
using namespace std;
int main (){
  	map<char,int> d;
  	map<char,int>::iterator it;
  	d['a']=50; 	d['b']=100;
  	d['c']=150; d['d']=200;
  	it=d.find('b');
  	if(it!=d.end())
    	d.erase(it);
  	cout<<"a => "<<d.find('a')->second<<endl;
  	cout<<"c => "<<d.find('c')->second<<endl;
  	cout<<"d => "<<d.find('d')->second<<endl;
	return 0;
}


