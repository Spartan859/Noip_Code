/*
���õݹ麯�����÷�ʽ�����������5���ַ���
���෴˳���ӡ������
*/
#include<iostream>
using namespace std;
void palin(int n);
int main()
{
int i=5;
palin(i);
cout<<endl;
return 0;
}
void palin(int n)
{
int next;
if(n<=1)
{
next!=cin.get();
cout<<endl;
cout<<next;
}
else
{
next=cin.get();
palin(n);
cout<<next;
}
}
