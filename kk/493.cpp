#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    long long shu,sum=0,cj,sg;//�ǵ�sum��ʼֵ��Ϊ0��cjΪ����һ�����㣨��һ�������ĳ˻�����ֵ
    char ch=0,xg;//ch�洢��һ���������xgΪ�¶���������
    bool tf=true;
    while(tf)
    {
        scanf("%lld",&shu);
        tf=scanf("%c",&xg)==1?true:false;//�����һ��û��������ˣ���tf=false���ȱ�֤�˴˴�ѭ�����������У���������һ��ѭ������
        if(ch==0)cj=shu;//����Ǹտ�ʼ���룬��ֱ�Ӹ�ֵ
        if(ch=='+')sum=(sum+cj)%10000,cj=shu;//�����һ�������Ǽӷ�����ǰһ�ε�ֵ���뵽sum�У�Ȼ���ٸ��´��¶ε�ֵ
        if(ch=='*')cj=(cj*shu)%10000;//�����һ���������ǳ˷����򽫴������뱾�ε�ֵ��
        if(!tf)sum=(sum+cj)%10000;//��������һ��Ԫ�أ���������ĸ���
        ch=xg;//����һ��������������Ϊ�µ�һ��ѭ������һ���������������ѭ��
    }
    printf("%lld",sum);//���
    return 0;
}
