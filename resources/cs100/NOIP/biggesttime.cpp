#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;
int part(string str1,int num){
	string ans1,ans2;
	int out1,out2,out;
	ans1=str1.substr(0,num);
	ans2=str1.substr(num+1);
	out1=atoi(ans1.c_str());
	out2=atoi(ans2.c_str());
	out=out1*out2;
	return out;
}
int main(){
	string in;
	int ans;
	cin>>in;
	for(int i=1;i<in.size();i++)
	    if(part(in,i)>ans) ans=part(in,i);
	cout<<ans;
	return 0;
}
