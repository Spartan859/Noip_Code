#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a,int *b,int len=SIZE){//a+=b
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//进位 
			a[i+1]++;
			a[i]-=10;
		}
}
//高精度*高精度,相当于c=a*b，注意c不可以为a,b之一 
void mul(int *c,int *a,int *b) {
	converts(c,"0");
	for(int i=0;i<SIZE;i++) 
		for(int j=0; j<b[i]; j++)
			add(c+i, a, SIZE-i);
} 
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE],z[SIZE];
int main() {
	string s1,s2;
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	mul(z,x,y);
	print(z);
	return 0;
}


