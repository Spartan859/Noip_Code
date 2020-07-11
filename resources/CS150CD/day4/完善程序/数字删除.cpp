#include<iostream>
using namespace std;
int delnum(char *s) {
	int i,j;
	j=0;
	for(i=0; s[i]!='\0';i++)
		if(s[i]<'0'___(1)_____s[i]>'9'){
			s[j]=s[i];
			_____(2)______;
		}
	return ______(3)________;
}
const int SIZE=30;
int main() {
	char s[SIZE];
	int len,i;
	cin.getline(s,sizeof(s));
	len=delnum(s);
	for(i=0;i<len;i++) cout<<____(4)_______;
	cout<<endl;
	return 0;
} 
