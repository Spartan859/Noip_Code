#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
bool le(int *a, int *b, int len=SIZE) {
	int i;
	for(i=len-1; i>=0&&a[i]==b[i]; i--) ;
	return i<0 || a[i]<b[i];
}
bool jian(string jx,string jy){
	int x[SIZE],y[SIZE];
	converts(x,jx);
	converts(y,jy);
	if(le(y,x)) return 1;
	else return 0;
}
int main() {
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	if(jian(s1,s2)==1&&jian(s1,s3)==1) cout<<s1;
	else if(jian(s2,s1)==1&&jian(s2,s3)==1) cout<<s2;
	else if(jian(s3,s2)==1&&jian(s3,s1)==1) cout<<s3;
	return 0;
}
