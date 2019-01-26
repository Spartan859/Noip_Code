#include<bits/stdc++.h>
using namespace std;
struct info{
	string name;
	int cnts;
}; info inf;
struct cmp{
	bool operator()(const info &a,const info &b){
		return a.cnts<b.cnts||a.cnts==b.cnts&&a.name>b.name;
	}
};
int main(){
	map<string,int> d;
	multiset<info,cmp> ms;
	string s,str[100005],s1,s2; int i,a;
	while(cin>>s){
		for(a=0;a<s.size()-2;a++) {
			s1=s.substr(a,a+2);
			cout<<s1<<endl;
			d[s1]++;
			s2=s.substr(a,a+3);
			cout<<s2<<endl;
			d[s2]++;
		}
		s1=s.substr(a,a+2);
		cout<<s1<<endl;
		d[s1]++;
		str[i]=s;
		i++;
	}
	for(int j=0;i<i;j++){
		inf.cnts=d[str[j]];
		inf.name=str[j];
		ms.insert(inf);
	}
	cout<<(*ms.begin()).name<<endl;
	return 0;
}
