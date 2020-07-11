#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a,int b){//a+=b
	//逐位相加，循环条件：b有剩余 或者 a[i]结果需进位 
	for(int i=0; b || a[i]>=10; b/=10, i++)  
		if((a[i]+=b%10)>=10) { //进位 
			a[i+1]++;  
			a[i]-=10;
		}
}
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE];
int main() {
	string s;
	int n;
	cin>>s>>n;
	converts(x,s);
	add(x,n);
	print(x);
	return 0;
}

