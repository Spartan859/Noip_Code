#include<bits/stdc++.h>
#define SIZE 500
using namespace std;
int ansj,anso;
int x[SIZE],y[SIZE],z[SIZE];
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
int mod(int *a, int n) {
	int i, r=0;
	for (i=SIZE-1; i>=0; r=(r*10+a[i--])%n);
	return r;
}
void printx(int *a){
	int i,jo;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	jo=1;
	for(;i>=0;i--){
		if(jo%2==1) ansj+=a[i];
		else anso+=a[i];
		jo++;
	}
}

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	converts(x,s1);
	converts(y,s2);
	mul(z,x,y);
	printx(z);
	cout<<ansj<<anso;
	return 0;
}
