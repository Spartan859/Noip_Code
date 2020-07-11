#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//高精度/int, 相当于a/=n，要求n>0 
void div(int *a, int n) { 
	//c代表每一位的被除数 	
	for(int i=SIZE-1,c=0; i>=0; i--) {//逐位相除 
		c = c%n*10 + a[i];  //高位的余数留给低位 
		a[i] = c/n;  //商 
	}
}
//高精度%int, 相当于a%=n，要求n>0 
int mod(int *a, int n) {
	int r=0;
	for(int i=SIZE-1;i>=0;i--)
		r=(r*10+a[i])%n;
	return r;
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
	cout<<mod(x,n)<<endl; 
	div(x,n);
	print(x);
	return 0;
}

