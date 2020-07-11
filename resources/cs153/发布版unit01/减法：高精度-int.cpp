#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//高精度-int，相当于a-=b，注意确保a>=b 
void sub(int *a, int b) {
	//逐位相减，循环条件：b有剩余 或者 a[i]结果需借位 
	for(int i=0; b || a[i]<0; b/=10, i++) {
		if((a[i]-=b%10)<0) {  //借位 
			a[i+1]--;
			a[i]+=10;
		}
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
	sub(x,n);
	print(x);
	return 0;
}

