#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//高精度复制 a=b; 
void copy(int *a, int *b) {
	for(int i=0;i<SIZE;i++)a[i]=b[i];
}
//判断a<=b 
bool le(int *a, int *b, int len=SIZE) {
	int i;
	for(i=len-1; i>=0&&a[i]==b[i]; i--);
	return i<0 || a[i]<b[i];
}
//高精度-高精度，相当于a-=b，注意确保a>=b 
void sub(int *a, int *b, int len=SIZE) {
	for(int i=0;i<len;i++) 
		if((a[i]-=b[i])<0){//借位  
			a[i+1]--;
			a[i]+=10;
		}
} 
//高精度/和%高精度，q=a/b, r=a%b，要求b>0 
void div(int *q,int *r,int *a,int *b){
	converts(q,"0");	//初始化商 
	copy(r,a);			//初始化余数
	int j;
	for(j=SIZE-1; b[j]==0; j--) ; //找b最高非零位置j 
	for(int i=SIZE-1-j; i>=0; i--) 
		for( ;le(b,r+i,SIZE-i); q[i]++)   
			sub(r+i,b,SIZE-i);
}
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE],s[SIZE],t[SIZE];
int main() {
	string s1,s2;
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	sub(x+2,y,SIZE-2);
	print(x);
	return 0;
}

