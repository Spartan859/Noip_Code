#include<iostream>
using namespace std;
int m,n,s=0;
int a[15000];//���龡�����ô��
int z[10001];//���龡�����ô�
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
    for(int j=0;j<m;j++)z[j]=-1;//�ڵ�һ�δ�����ȫ������Ĭ��ֵΪ0������Ŀ��˵�������ǷǸ�������˶���10�֣�so,�����ʼֵ�������Ҫ��
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(!chazhao(a[i]))s++;            
    }
    cout<<s;
    return 0;
}
