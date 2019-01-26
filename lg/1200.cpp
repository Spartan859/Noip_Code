#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	int i1=1,i2=1;
	cin>>s1;
	cin>>s2;
	for(int i=0;i<s1.size();i++) i1*=s1[i]-'A'+1;
	for(int i=0;i<s2.size();i++) i2*=s2[i]-'A'+1;
	//cout<<i1<<endl<<i2<<endl;
	//cout<<s1<<endl<<s2<<endl;
	i1%=47;
	i2%=47;
	if(i1==i2) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
} 
