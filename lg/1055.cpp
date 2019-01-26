#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; int ans;
	cin>>s;
	ans=(s[0]-'0')+(s[2]-'0')*2+(s[3]-'0')*3+(s[4]-'0')*4+(s[6]-'0')*5+(s[7]-'0')*6+(s[8]-'0')*7+(s[9]-'0')*8+(s[10]-'0')*9;
	ans%=11;
	if((s[12]-'0'==ans)||(s[12]=='X'&&ans==10)) {cout<<"Right"; return 0;}
	else if(ans==10) s[12]='X';
	else s[12]=ans+'0';
	cout<<s<<endl;
	return 0;
}
