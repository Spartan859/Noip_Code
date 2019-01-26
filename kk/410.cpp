#include<bits/stdc++.h>
using namespace std;
string s; int cnt[4],ans;
int main(){
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='l') cnt[0]++;
		else if(s[i]=='o') cnt[1]++;
		else if(s[i]=='v') cnt[2]++;
		else if(s[i]=='e') cnt[3]++;
		else if(s[i]=='w') cnt[2]+=2;
	}
	ans=cnt[0];
	for(int i=1;i<4;i++)
	    ans=min(ans,cnt[i]);
	cout<<ans<<endl;
	//for(int i=0;i<4;i++) cout<<cnt[i]<<' ';
	return 0;
} 
