#include<bits/stdc++.h>
using namespace std;

int sum;

void count(int a,int b)
{
    for(int i=a;i<b;i++)
    {
        if(b%i==0&&i<=b/i)
        {
            sum++;
            count(i,b/i);//�ݹ����
        }
        if(i>b/i) break;
    }
}
int main()
{
    int a;
    sum = 1;
    cin >> a;
    count(2,a);
    cout<<sum<<endl;
    return 0;
}

