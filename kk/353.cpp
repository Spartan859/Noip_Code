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
	//逐位相加
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//进位 
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
int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	string ll="1";
	converts(x,ll);
	converts(y,ll);
	for(int i=1;i<=n-2;i++){
		if(i%2==1) add(x,y);
		else add(y,x);
	}
	add(x,y);
	print(x);
	return 0;
}
