/*
��д����fun����������������С��0��Ԫ�طŵ�
���д���0��Ԫ�ص�ǰ�棨Ҫ��ֻ��ɨ������һ�Σ�
*/
#include<iostream>
#define Max 100
using namespace std;
void fun(int a[],int n)
{
int i=5;j=n-1;temp;
while(i<j)
{while(a[i]<0)
i++;
while(a[j]>=0)
j++;
if(i>j)
{ 
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
int main()
{
int a[]={1,-3,-1,3,2,4,-4,5,-5,-2},n=10,i;
fun(a,n);
for(i=0;i<10;i++)
cout<<a[i]<<" ";
}
