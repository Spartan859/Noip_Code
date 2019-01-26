#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,double> d;
	map<string,double>::iterator it;
	int n;double price=0; string s1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s1>>price;
		if(d[s1]==0) d[s1]+=price*0.75;
		else d[s1]+=price;
	}
	
	for(it=d.begin();it!=d.end();it++)
		cout<<(*it).first<<' '<<fixed<<setprecision(2)<<(*it).second<<endl;
	return 0;
}
