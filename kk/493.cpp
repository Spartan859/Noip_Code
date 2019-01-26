#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    long long shu,sum=0,cj,sg;//记得sum初始值赋为0；cj为其中一段运算（即一段连续的乘积）的值
    char ch=0,xg;//ch存储上一个运算符，xg为新读入的运算符
    bool tf=true;
    while(tf)
    {
        scanf("%lld",&shu);
        tf=scanf("%c",&xg)==1?true:false;//如果下一个没有运算符了，则tf=false，既保证了此次循环的正常运行，又能在下一遍循环跳出
        if(ch==0)cj=shu;//如果是刚开始读入，则直接赋值
        if(ch=='+')sum=(sum+cj)%10000,cj=shu;//如果上一个操作是加法，则将前一段的值加入到sum中，然后再更新此新段的值
        if(ch=='*')cj=(cj*shu)%10000;//如果上一个运算仍是乘法，则将此数乘入本段的值中
        if(!tf)sum=(sum+cj)%10000;//如果是最后一个元素，则进行最后的更新
        ch=xg;//将下一个读入的运算符作为新的一个循环的上一个运算符，并继续循环
    }
    printf("%lld",sum);//输出
    return 0;
}
