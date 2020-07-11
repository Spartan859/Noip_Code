#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//高精度*int, 相当于a*=b, 要求b>0 
void mul(int *a, int b) {
	for(int i=0,c=0; i<SIZE; i++){ 
		c = c/10 + a[i]*b;
		a[i] = c%10;
	}
}
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE];
int main() {
	string s;
	int n;
	cin>>s>>n;
	converts(x,s);
	mul(x,n);
	print(x);
	return 0;
}

