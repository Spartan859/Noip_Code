#include<bits/stdc++.h>
#define SIZE 205
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//�߾���*int, �൱��a*=b, Ҫ��b>0 
void mul(int *a, int b) {
	for(int i=0,c=0; i<SIZE; i++){ 
		c = c/10 + a[i]*b;
		a[i] = c%10;
	}
}
void sub(int *a, int b) {
	//��λ�����ѭ��������b��ʣ�� ���� a[i]������λ 
	for(int i=0; b || a[i]<0; b/=10, i++) {
		if((a[i]-=b%10)<0) {  //��λ 
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
int main(){
	int n; int ans[SIZE];
	converts(ans,"1");
	cin>>n;
	for(int i=1;i<=n+1;i++) mul(ans,2);
	sub(ans,2);
	print(ans);
	return 0;
}