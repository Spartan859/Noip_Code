#include<iostream>
#include<map>
using namespace std;
int main(){
  	map<char,int> d;
  	map<char,int>::iterator it;
	d['b'] = 100;
  	d['a'] = 200;
  	d['c'] = 300;
  	if(d['x']==250) cout<<"haha"<<endl;
	// show content:
  	for(it=d.begin();it!=d.end();++it)
    	cout<<it->first<<" "<<it->second<<endl;
  	for(it=d.begin();it!=d.end();++it)
    	cout<<(*it).first<<" "<<(*it).second<<endl;
	return 0;
}

