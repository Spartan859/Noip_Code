#include<iostream>
using namespace std;
int n;
char c;

void pyramid(int m,char x){
    for(int b=0;b<m;b++){//���ƽ�������߶�
	for(int c=b;c<m-1;c++){//�������������ε�����������кܶ�ո������������ո�
    cout<<" ";
}
    for(int d=0;d<=2*b;d++){//�ո���������������ש��
    cout<<x;
}
    cout<<endl;//һ������˻��н�����һ�μ����� ����˿�ʼ�� }
	}
    
}

 
int main(){
cin>>n>>c;
pyramid(n,c);
pyramid(2*n,c);
return 0; } 
