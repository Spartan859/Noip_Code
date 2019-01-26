#include<bits/stdc++.h>
using namespace std;
int main(){
	set<string> a;
	set<string>::iterator ita;
	set<string> b;
	set<string>::iterator itb;
	string x,y;
	bool xx=0;
	int ans=0;
	while(cin>>x){
		if(x[0]>='a'&&x[0]<='z') a.insert(x);
		if(x[x.length()-1]==':'&&xx==0) xx=1;
		else if(x[x.length()-1]==':'&&xx==1) break;
	}
	while(cin>>y)
	    if(y[0]>='a'&&y[0]<='z') b.insert(y);
	for(itb=b.begin();itb!=b.end();itb++)
	    if(a.count(*itb)!=0) ans++;
	cout<<ans<<'/'<<b.size();
	return 0;
}
