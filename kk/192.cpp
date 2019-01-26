#include<bits/stdc++.h>
#define SIZE 3500
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

int x[SIZE],ans[SIZE];
int main(){
	converts(x,"1");
    converts(ans,"0");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    mul(x,i);
	    add(ans,x);
	}
	print(ans);
	return 0;
}

