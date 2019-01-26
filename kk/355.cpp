#include<bits/stdc++.h>
#define SIZE 200
using namespace std;

int x[SIZE],ans[SIZE],n,s1;
string nu,s2;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a, int *b, int len=SIZE) {
	int i;
	for (i=0; i<len; i++) {
		if ((a[i]+=b[i])>=10) {
			a[i+1]++;
			a[i]-=10;
		}
	}
}
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

int main(){
	converts(ans,"0");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nu>>s1>>s2;
		converts(x,s2);
		mul(x,s1);
		add(ans,x);
	}
	print(ans);
	return 0;
}
