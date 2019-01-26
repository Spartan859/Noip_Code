#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
struct node
{
    int s,b;
    bool operator < (const node &x) const
    {
        if(x.s!=s)
            return x.s>s;     //从小到大
        else
            return x.b<b;     //从大到小
    }
 
}A[100];
 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&A[i].s,&A[i].b);
    }
    sort(A+1,A+1+n);
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",A[i].s,A[i].b);
    }
    return 0;
}
 
/*
5
1 2
2 3
3 4
3 1
3 6
*/

