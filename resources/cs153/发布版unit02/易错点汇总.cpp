#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int //a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i];//
	for(i=0;i<SIZE;i++) a[i]=0;
}
void add(int a,int b,int len=SIZE){
	for(int i=0;i<SIZE;i++)
		if((a[i]+b[i])>=10){
			a[i+1]++; 
			a[i]-=10;
		}
}
void mul(int *c,int *a,int *b) {
	for(int i=0;i<SIZE;i++) 
		for(int j=0; j<b[i]; j++)
			add(c, a, SIZE);
} 
void print(int *a){
	int i;
	for(i=SIZE-1;i>=0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE];
int main() {
	string s1,s2;
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	mul(x,x,y);
	print(x);
	return 0;
}

