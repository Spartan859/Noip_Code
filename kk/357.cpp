#include<iostream>
#define SIZE 500 
using namespace std;

void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//�߾���/int, �൱��a/=n��Ҫ��n>0 
void div(int *a, int n) { 
	//c����ÿһλ�ı����� 	
	for(int i=SIZE-1,c=0; i>=0; i--) {//��λ��� 
		c = c%n*10 + a[i];  //��λ������������λ 
		a[i] = c/n;  //�� 
	}
}
//�߾���%int, �൱��a%=n��Ҫ��n>0 
int mod(int *a, int n) {
	int r=0;
	for(int i=SIZE-1;i>=0;i--)
		r=(r*10+a[i])%n;
	return r;
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
int ans[SIZE];
int main(){
	int n;
	cin>>n;
	converts(ans,"1");
	if(n==0) cout<<1;
	for(int i=1;i<=n;i++){
		mul(ans,4*i-2);
		div(ans,i+1);
	}
	print(ans);
	return 0;
}


