#include<bits/stdc++.h> 
using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}

int exgcd(int a, int b, int &x, int &y)
{
    if(b==0)
    {
    x=1;
    y=0;
    return a;
    }
    int r = exgcd(b, a%b, x, y);
    int t = y;
    y=x-(a/b)*y;
    x=t;

    return r;
}

int main()
{
int a, b, c;
int x, y;
int count=0;
cout<<"请输入三个参数a, b, c：";
cin>>c>>a>>b;
if(a <= 0||b <= 0||a < b)
{
    cout<<-1<<endl;
    return 0;
}
cout<<"该二元一次不定方程组为:";
printf("%dx+%dy=%d",a,b,c);
cout<<endl;

int cd = gcd(a, b);
if(c % cd == 0)
{
cout<<"方程的解为：";
exgcd(a, b, x, y);
printf("x=%d\ty=%d", x, y);
}
else
cout<<"此方程无整数解！！"<<endl;

cout<<endl;
return 0;
}
