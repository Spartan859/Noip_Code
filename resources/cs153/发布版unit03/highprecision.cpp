#include <iostream>
#include <string>
#define SIZE 1024
using namespace std;

int a[SIZE];  //0~SIZE-1�����δӵ�λ����λ�������� 

//����ת�߾����� 
void converti(int *a, int x) {
	int i;
	for (i=0; x; i++) {  //��x>0ʱ��ȡÿһλ���� 
		a[i] = x % 10;  
		x /= 10;
	}
	for (; i<SIZE; a[i++]=0); 
}

//�ַ���ת�߾�����
void converts(int *a, string s) {
	int i, l;
	for (l=s.size(), i=0; i<l; a[i]=s[l-1-i]-'0', i++);
	for (; i<SIZE; a[i++]=0);
}

//�߾��������ƣ�a = b
void copy(int *a, int *b) {
	int i;
	for (i=0; i<SIZE; a[i]=b[i], i++);
}

//�߾���+int, �൱��a+=n
void add(int *a, int n) {
	int i;
	for(i=0; n || a[i]>=10; n/=10, i++) {
		if ((a[i] += n%10) >= 10) { //��λ 
			a[i+1]++;  
			a[i]-=10;
		}
	}
} 

//�߾���-int���൱��a-=n��Ҫ��a>=n 
void sub(int *a, int n) {
	int i;
	for (i=0; n || a[i]<0; n/=10, i++) {
		if ((a[i] -= n%10) < 0) {  //��λ 
			a[i+1]--;
			a[i]+=10;
		}
	}
} 

//�߾���*int, �൱��a*=n, Ҫ��n>0 
void mul(int *a, int n) {
	int i, c=0;
	for (i=0; i<SIZE; i++) {  //��ʽ�˷� 
		c = c/10 + a[i]*n;
		a[i] = c%10;
	}
} 

//�߾���/int, �൱��a/=n��Ҫ��n>0 
void div(int *a, int n) { 
	int i, c=0;
	for (i=SIZE-1; i>=0; i--) {  //ģ����ʽ���� 
		c = c%n*10 + a[i];  //ȡ�������Ҽ���һλ 
		a[i] = c/n;  //�� 
	}
}

//�߾���%int, �൱��a%=n��Ҫ��n>0 
int mod(int *a, int n) {
	int i, r=0;
	for (i=SIZE-1; i>=0; r=(r*10+a[i--])%n);
	return r;
} 

//�߾���==�߾���
bool eq(int *a, int *b) {
	int i;
	for (i=0; i<SIZE && a[i]==b[i]; i++);
	return i==SIZE;
} 

//�߾���<=�߾��� 
bool lte(int *a, int *b, int len=SIZE) {
	int i;
	for (i=len-1; i>=0 && a[i]==b[i]; i--);
	return i<0 || a[i]<b[i];
}

//�߾���+�߾���, �൱��a+=b 
void add(int *a, int *b, int len=SIZE) {
	int i;
	for (i=0; i<len; i++) {
		if ((a[i]+=b[i])>=10) {
			a[i+1]++;
			a[i]-=10;
		}
	}
}

//�߾���-�߾��ȣ��൱��a-=b, Ҫ��a>=b 
void sub(int *a, int *b, int len=SIZE) {
	int i;
	for (i=0; i<len; i++) {
		if ((a[i]-=b[i])<0) {
			a[i+1]--;
			a[i]+=10;
		}
	}
} 

//�߾���*�߾���, �൱��c=a*b
void mul(int *c, int *a, int *b) {
	int i, j;
	converti(c, 0);
	for(i=0;i<SIZE;i++) 
		for(j=0; j<a[i]; add(c+i, b, SIZE-i), j++);
} 

//�߾���/��%�߾��ȣ�q=a/b, r=a%b��Ҫ��b>0 
void division(int *q, int *r, int *a, int *b) {
	int i;
	converti(q, 0);
	copy(r, a);
	for (i=SIZE-1; !b[i]; i--);
	for (i=SIZE-1-i; i>=0; i--) {
		for (; lte(b, r+i, SIZE-i); sub(r+i, b, SIZE-i), q[i]++);
	}
} 

//��ӡ�߾�����
void print(int *a) {
	int i;
	for (i=SIZE-1; i>0 && !a[i]; i--);  //���Ը�λ��0
	for (; i>=0; cout << char(a[i--]+'0')); 
} 

int main() {
	int b[SIZE], c[SIZE], d[SIZE];
	converti(a, 1234);
	converti(b, 99);
	division(c, d, a, b);
	print(a); cout << "/"; print(b); cout << endl;
	print(c); cout << endl;
	print(d); cout << endl;
	
	
//	cout << "test int to bigint "; converti(a, 1234567890);  
//	print(a); cout << endl;  
//	converts(b, "12345678900000000000000000000001");  
//	cout << "test string to bigint "; print(b); cout << endl;
//	cout << "test copy "; copy(c, a);  
//	print(c); cout << endl; 
//	cout << "test bigint + int "; add(a, 20);  
//	print(a); cout << endl;
//	cout << "test bigint - int "; sub(a, 20); 
//	print(a); cout << endl;  
//	cout << "test bigint * int "; mul(a, 10); 
//	print(a); cout << endl;  
//	cout << "test bigint / int "; div(a, 100); 
//	print(a); cout << endl;  
//	cout << "test bigint % int " << mod(a, 38); 
//	cout << endl;
//	converts(a, "1234567890123456789");
//	converts(b, "9876543210987654321");
//	cout << "test bigint + bigint "; add(a, b);
//	print(a); cout << endl;
//	cout << "test bigint - bigint "; sub(a, b);
//	print(a); cout << endl;
//	cout << "test bigint * bigint "; mul(c, a, b);
//	print(c); cout << endl;
//	converts(a, "9876543210987654321");
//	converts(b, "1234567890123456789");
//	cout << "test bigint /% bigint "; division(d, c, a, b);
//	print(d); cout << " ";
//	print(c); cout << endl;
	return 0;
} 

 
