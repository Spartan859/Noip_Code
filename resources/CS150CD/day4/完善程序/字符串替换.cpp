#include<iostream>
#include<cstring>
using namespace std;
char change[26],str[5000];
void CheckChangeRule() {
	int i;
	for(i=0;i<26;i++) {
		if(_____(1)_____)
			change[i]-='A'-'a';
	}
}
void ChangeString() {
	int i;
	for(i=0;i<strlen(str);i++) {
		if(_____(2)____)
			str[i]=change[str[i]-'A']-'a'+'A';
		else
			____(3)_____;
	}
}
int main() {
	int i;
	cin>>str;
	cin>>change;
	CheckChangeRule();
	____(4)____;
	cout<<str<<endl;
	return 0;
}


/*

*/
