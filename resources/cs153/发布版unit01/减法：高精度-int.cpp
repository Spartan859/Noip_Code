#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//�߾���-int���൱��a-=b��ע��ȷ��a>=b 
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

