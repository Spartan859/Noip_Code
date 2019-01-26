#include<iostream>
using namespace std;
int m,n,s=0;
int a[15000];//数组尽量开得大点
int z[10001];//数组尽量开得大
bool chazhao(int x)
{
    for(int i=0;i<m;i++)
    {
        if(z[i]==x)return true;
    }
    for(int k=0;k<m-1;k++)z[k]=z[k+1];
    z[m-1]=x;    
    return false;
}
int main()
{
    cin>>m>>n;
    for(int j=0;j<m;j++)z[j]=-1;//在第一次代码中全局数组默认值为0，而题目中说单词数是非负数，因此丢掉10分，so,这个初始值代码很重要！
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(!chazhao(a[i]))s++;            
    }
    cout<<s;
    return 0;
}
